// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "steve/parser.hpp"
#include "steve/builder.hpp"
#include "steve/lookup.hpp"

namespace steve
{

namespace
{

// -------------------------------------------------------------------------- //
//                            Variable declarations

// Parse a type clause.
//
//    type-clause ::= ':' type
Type const*
parse_type_clause(Parser& p, Token_stream& ts)
{
  if (expect_token(p, ts, colon_tok))
    return parse_type(p, ts);
  else
    return make_error_node<Type>();
}



// Parse an initializer clause. The initializer clause determines
// the initialization semantics of a variable declaration.
//
//    initializer-clause ::=
//        ';'
//      | '=' default ';'       # TODO
//      | '=' expression ';'
//      | '{' argument-list '}' # TODO
//      | '(' argument-list ')' # TODO
//
// TODO: Support aggregate initialization, possibly with
// designated initializers as in C+99.
Expr const*
parse_initializer_clause(Parser& p, Token_stream& ts)
{
  // Match default initialization
  if (Token const* tok = match_token(ts, semicolon_tok))
    return p.on_default_init(tok);

  // Match direct initialization
  if (Token const* tok = match_token(ts, equal_tok)) {
    if (Required<Expr> expr = parse_expr(p, ts)) {
      
      // Check for the trailing semicolon, but don't fail
      // outright if we can't find it. We can probably parse
      // the next statement without it.
      if (!match_token(ts, semicolon_tok))
        error("expected ';' after initializer");
      
      return p.on_direct_init(tok, *expr);
    } else {
      return make_error_node<Expr>();
    }
  }

  error("expected initializer-clause but got '{}'", ts.peek());
  return make_error_node<Expr>();
}


// Parse a variable declaration.
//
//    variable-declaration ::= 
//        'var' identifier type-clause initializer-clause
Decl const*
parse_variable_decl(Parser& p, Token_stream& ts)
{
  Token const* tok = require_token(ts, var_kw);

  // Match the variable name.
  Token const* id = expect_token(p, ts, identifier_tok);
  if (!id)
    return make_error_node<Decl>();

  // Match the variable type.
  Required<Type> type = parse_type_clause(p, ts);
  if (!type)
    return make_error_node<Decl>();

  // Point of declaration. The variable is declared prior
  // to the initializer.
  Required<Decl> decl = p.on_variable_decl(tok, id, *type);
  if (!decl)
    return make_error_node<Decl>();

  // Match the initialzer.
  Required<Expr> init = parse_initializer_clause(p, ts);
  if (!init)
    return make_error_node<Decl>();

  return p.on_variable_init(*decl, *init);
}


// -------------------------------------------------------------------------- //
//                          Function declarations


// Parse a parameter declaration.
//
//    parameter-declaration ::= identifier type-clause
//
// TODO: Support default arguments.
Decl const*
parse_parameter_decl(Parser& p, Token_stream& ts)
{
  if (Token const* id = expect_token(p, ts, identifier_tok))
    if (Required<Type> type = parse_type_clause(p, ts))
      return p.on_parameter_decl(id, *type);
  return make_error_node<Decl>();
}


using Parm_seq = Sequence_term<Decl>;
using Parm_clause = Enclosed_term<Parm_seq>;


// Parse a parameter declaration list.
//
//    parameter-list ::= parameter-decl [',' parameter-decl]*
Parm_seq const*
parse_parameter_list(Parser& p, Token_stream& ts)
{
  return parse_list(p, ts, comma_tok, parse_parameter_decl);
}


// Parse a parameter clause.
//
//    parameter-clause ::= '(' parameter-list ')'
Parm_clause const*
parse_parameter_clause(Parser& p, Token_stream& ts)
{
  return parse_paren_enclosed(p, ts, parse_parameter_list);
}


// Parse a return clause.
//
//    return-clause ::= '-> type'
Type const*
parse_return_clause(Parser& p, Token_stream& ts)
{
  if (expect_token(p, ts, minus_gt_tok))
    return parse_type(p, ts);
  else
    return make_error_node<Type>();
}


// Represents a parsed function signature.
struct Signature : Term<>
{
  Signature(Decl_seq const& ps, Type const* t)
    : first(std::move(ps)), second(t)
  { }

  char const* node_name() const { return "signature"; }

  Decl_seq const& parms() const { return first; }
  Type const*     type() const { return second; }

  Decl_seq    first;
  Type const* second;
};


// Parse a function signature.
//
//    function-signature ::= parameter-clause return-clause
Signature const*
parse_signature(Parser& p, Token_stream& ts)
{
  if (Required<Parm_clause> c = parse_parameter_clause(p, ts))
    if (Required<Type> t = parse_return_clause(p, ts))  {
      // This invokes a copy. Moving would require const-casting.
      return gc().make<Signature>(*c->term(), *t);
    }
  return make_error_node<Signature>();
}


// Parse a function definition.
//
//    function-definition ::=
//        '=' expression ';'
//        block-stmt
//
// The definition of the form `= e` is equivalent to the function
// definition `{ return e; }`
Stmt const*
parse_function_def(Parser& p, Token_stream& ts)
{
  // Match a simple definition. 
  if (match_token(ts, equal_tok)) {
    if (Required<Expr> expr = parse_expr(p, ts)) {

      // This is required, but we can probably continue
      // parsing without it.
      expect_token(p, ts, semicolon_tok);

      // TODO: Enclose in blocks?
      return p.on_return_stmt(*expr);
    }

  }
  error(ts.location(), "expected function-definition");
  return make_error_node<Stmt>();
}


// Parse a function definition.
//
//    function-declaration ::= 
//        'def' identifier function-signature function-definition
//
//    return-clause ::= '->' type
Decl const*
parse_function_decl(Parser& p, Token_stream& ts)
{
  Token const* tok = require_token(ts, def_kw);
  
  // Match the function name.
  // TODO: Support operator overloading.
  Token const* id = expect_token(p, ts, identifier_tok);
  if (!id)
    return make_error_node<Decl>();

  // Match the function signature.
  Required<Signature> sig = parse_signature(p, ts);
  if (!sig)
    return make_error_node<Decl>();
  
  // Point of declaration. Declare the function in the
  // current scope.
  Decl_seq const& parms = sig->parms();
  Type const* ret = sig->type();
  Decl const* fn = p.on_function_decl(tok, id, parms, ret);

  // Enter function scope and declare the parameters.
  Stmt const* def;
  { 
    Local_scope scope;
    if (!declare(parms))
      return make_error_node<Decl>();

    // Consume the function definition.
    Required<Stmt> body = parse_function_def(p, ts);
    if (!body)
      return make_error_node<Decl>();
    def = *body;
  }
  
  // Update the function definition.
  return p.on_function_def(fn, def);
}


// Parse decode body
//    decode-body ::-
//      block-stmt
Stmt const*
parse_decode_body(Parser& p, Token_stream& ts)
{

}


// Parse decode-decl
//    decode-decl ::=
//        'decode' identifier '('type-id')' [(optional) requires-clause] decode-body
Decl const*
parse_decode_decl(Parser& p, Token_stream& ts)
{
  return nullptr;
}


// Parse flow instruction block
//    instr-block-stmt ::=
//        '{' instruction-stmt;+ '}'
Stmt const*
parse_flow_instructions(Parser& p, Token_stream& ts)
{

}


// Parse flow declaration
//    flow-declaration ::=
//        <dot-expr,+> => instr-block-stmt
Decl const*
parse_flow_decl(Parser& p, Token_stream& ts)
{
  return nullptr;
}


// Parse table-initializer
//    table-initializer ::=
//        '{' flow-decl,+ '}'
Decl_seq const&
parse_table_initializer(Parser& p, Token_stream& ts)
{

}


// Parse table-key-fields
//    table-key-fields ::=
//        '<' dot-expr,+ '>'
Expr_seq const&
parse_key_field(Parser& p, Token_stream& ts)
{

}


// Parse table declarations
//    table-declaration ::=
//        'table' identifier table-key-fields [(optional) requires-clause]
//          table-initializer
Decl const*
parse_table_decl(Parser& p, Token_stream& ts)
{
  return nullptr;
}


} // namespace


// Parse a top-level declaration.
//
//    declaration ::=
//        variable-decl
//        function-decl
//        decode-decl
//        table-decl
//
// Note that this is only called from the statement parser.
// We are guaranteed to match a top-level declaration here.
Decl const*
parse_decl(Parser& p, Token_stream& ts)
{
  switch (next_token_kind(ts)) {
    case var_kw:
      return parse_variable_decl(p, ts);
    case def_kw:
      return parse_function_decl(p, ts);
    case decode_kw:
      return parse_decode_decl(p, ts);
    case table_kw:
      return parse_table_decl(p, ts);

    default:
      break;
  }
  lingo_unreachable();
}



Decl const*
parse_decl(Token_stream& ts)
{
  Parser p;
  return parse_decl(p, ts);
}


} // namespace steve


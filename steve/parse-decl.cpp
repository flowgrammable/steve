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
parse_initializer_clause(Parser& p, Token_stream& ts, Type const* type)
{
  // Match default initialization
  if (Token const* tok = match_token(ts, semicolon_tok))
    return p.on_default_init(tok, type);

  // Match direct initialization
  if (Token const* tok = match_token(ts, eq_tok)) {
    if (Required<Expr> expr = parse_expr(p, ts)) {
      
      // Check for the trailing semicolon, but don't fail
      // outright if we can't find it. We can probably parse
      // the next statement without it.
      if (!match_token(ts, semicolon_tok))
        error(ts.location(), "expected ';' after initializer");
      
      return p.on_direct_init(tok, *expr);
    } else {
      return make_error_node<Expr>();
    }
  }

  error(ts.location(), "expected initializer-clause but got '{}'", ts.peek());
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
  Required<Expr> init = parse_initializer_clause(p, ts, *type);
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
//    return-clause ::= '->' type
Type const*
parse_return_clause(Parser& p, Token_stream& ts)
{
  if (expect_token(p, ts, arrow_tok))
    if (Required<Type> type = parse_type(p, ts))
      return *type;
  return make_error_node<Type>();
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
  // Match but don't consume the '{'.
  if (next_token_is(ts, lbrace_tok))
    return parse_stmt(p, ts);
  
  // Match and consume the '=' token, so that we parse
  // the full expression statement (including the ';').
  if (match_token(ts, eq_tok))
    return parse_stmt(p, ts);
  
  error(ts.location(), "expected function-definition, but got '{}'", ts.peek());
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

  // match the identifier.
  Token const* id = expect_token(p, ts, identifier_tok);
  if (!id)
    return make_error_node<Decl>();

  // Parse the parameter declaration clause.
  // Note that the clause may be '()', in which
  // case the inner term is null. That's not good.
  Required<Parm_clause> clause = parse_parameter_clause(p, ts);
  if (!clause)
    return make_error_node<Decl>();
  Decl_seq parms = clause->term() ? Decl_seq(*clause->term()) : Decl_seq();

  // Match the type clause.
  Required<Type> type = parse_return_clause(p, ts);
  if (!type)
    return make_error_node<Decl>();

  // Point of declaration. Having a name, parameters, and return
  // type, we can declare the function.
  Required<Decl> fn = p.on_function_decl(tok, id, parms, *type);
  if (!fn)
    return make_error_node<Decl>();

  // Enter the function scope and cause the parameters to be 
  // declared.
  Local_scope scope;
  fn = p.on_function_start(*fn);
  if (!fn)
    return make_error_node<Decl>();

  // Parse the function definition.
  Required<Stmt> body = parse_expected(p, ts, parse_function_def);
  if (!body)
    return make_error_node<Decl>();

  return p.on_function_finish(*fn, *body);
}



Decl const*
parse_member_decl(Parser& p, Token_stream& ts)
{
  if (Token const* id = expect_token(p, ts, identifier_tok))
    if (Required<Type> type = parse_type_clause(p, ts))
      if (expect_token(p, ts, semicolon_tok))
        return p.on_member_decl(id, *type);

  return make_error_node<Decl>();
}


Sequence_term<Decl> const*
parse_member_list(Parser& p, Token_stream& ts)
{
  using Member_seq = Sequence_term<Decl>;
  Member_seq mems;
  while (!ts.eof()) {
    if (next_token_is(ts, rbrace_tok))
      break;

    if (Required<Decl> mem = parse_member_decl(p, ts))
      mems.push_back(*mem);
    else
      break;
  }
  return Member_seq::make(std::move(mems));
}


Decl const*
parse_record_decl(Parser& p, Token_stream& ts)
{
  require_token(ts, record_kw);

  Token const* name = expect_token(p, ts, identifier_tok);
  if(!name)
    return make_error_node<Decl>();

  using Term = Enclosed_term<Sequence_term<Decl>>;

  // TODO: support forward declaration of records
  Required<Term> body = parse_brace_enclosed(p, ts, parse_member_list);
  if (!body)
    return make_error_node<Decl>();

  Decl_seq members = body->term() ? Decl_seq(*body->term()) : Decl_seq();

  return p.on_record_decl(name, members);
}


// Parse decode body
//    decode-body ::=
//      block-stmt
Stmt const*
parse_decode_body(Parser& p, Token_stream& ts)
{

}


// Parses a list of comma seperated types
Sequence_term<Type> const*
parse_type_seq(Parser& p, Token_stream& ts)
{
  return parse_list(p, ts, comma_tok, parse_type);
}


// Parse the headers which the decoder handles
//    decode-headers ::=
//      '(' type-seq ')'
Enclosed_term<Sequence_term<Type>> const*
parse_decode_headers(Parser& p, Token_stream& ts)
{
  return parse_paren_enclosed(p, ts, parse_type_seq);
}


// Parse decode-decl
//    decode-decl ::=
//        'decode' identifier '('type-id')' [(optional) requires-clause] decode-body
Decl const*
parse_decode_decl(Parser& p, Token_stream& ts)
{
  // consume the decode keyword
  Token const* decode = get_token(ts);

  Token const* name = expect_token(p, ts, identifier_tok);
  if (!name)
    return make_error_node<Decl>();

  using Header_seq = Enclosed_term<Sequence_term<Type>>;

  Required<Header_seq> headers = parse_decode_headers(p, ts);

  Type_seq hdr_types = headers->term() ? Type_seq(*headers->term()) : Type_seq();

  // FIXME: support multiple decodes
  return p.on_decode_decl(decode, name, hdr_types.front(), nullptr);
}


// Parse flow instruction block
//    instr-block-stmt ::=
//        '{' instruction-stmt;+ '}'
Stmt const*
parse_flow_instructions(Parser& p, Token_stream& ts)
{
  return nullptr;
}


// Parse flow declaration
//    flow-declaration ::=
//        {Value,...} => instr-block-stmt
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
  return {};
}


// Parse table-key-fields
//    table-key-fields ::=
//        '(' dot-expr,+ ')'
Expr_seq const&
parse_key_field(Parser& p, Token_stream& ts)
{
  return {};
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
    case record_kw:
      return parse_record_decl(p, ts);
    case decode_kw:
      return parse_decode_decl(p, ts);
    // case decode_kw:
    //   return parse_decode_decl(p, ts);
    // case table_kw:
    //   return parse_table_decl(p, ts);

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


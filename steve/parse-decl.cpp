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
//                             Statement parsers

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


// Parse an initializer clause. The initializer clause determines
// the initialization semantics of a variable declaration.
//
//    initializer-clause ::=
//        ';'
//      | '=' expression ';'
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
    }
    else
      return make_error_node<Expr>();
  }

  error("expected initializer-clause but got '{}'", ts.peek());
  return make_error_node<Expr>();
}


// Parse a variable declaration.
//
//    variable-declaration ::= 
//        'var' identifier type-clause initializer-clause
//
//
Decl const*
parse_variable_decl(Parser& p, Token_stream& ts)
{
  Token const* tok = require_token(ts, var_kw);
  if (Token const* id = expect_token(p, ts, identifier_tok))
    if (Required<Type> type = parse_type_clause(p, ts))
      if (Required<Expr> init = parse_initializer_clause(p, ts))
        return p.on_variable_decl(tok, id, *type, *init);
  return make_error_node<Decl>();
}


// Parse a function definition.
//
//    function-declaration ::= 
//        'def' identifier function-signature '=' expression
//      | 'def' identifier function-signature block-stmt
//
//    function-signature ::= parameter-clause return-clause
//
//    parameter-clause ::= '(' parameter-list ')'
//
//    parameter-list ::= parameter-decl [',' parameter-decl]*
//
//    return-clause ::= '->' type
Decl const*
parse_function_decl(Parser& p, Token_stream& ts)
{
  return nullptr;
}


} // namespace


// Parse a top-level declaration.
//
//    declaration ::=
//        variable-decl
//        function-decl
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


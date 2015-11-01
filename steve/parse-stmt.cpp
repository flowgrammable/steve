// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "steve/parser.hpp"
#include "steve/builder.hpp"
#include "steve/lookup.hpp"

#include <iostream>

namespace steve
{

namespace
{

// -------------------------------------------------------------------------- //
//                             Statement parsers

// Parse a declaration statment.
//
//    declaration-statement ::= declaration
Stmt const*
parse_declaration_stmt(Parser& p, Token_stream& ts)
{
  if (Required<Decl> d = parse_decl(p, ts))
    return p.on_declaration_stmt(*d);
  return make_error_node<Stmt>();
}


} // namespace


// Parse a statement.
//
//    statement ::=
//        declaration-statement
//      | block-statement
//      | return-statement
//      | if-statemnt
//      | match-statement
//      | case-statement
//      | do-statement
//
// TODO: Implement these!
Stmt const*
parse_stmt(Parser& p, Token_stream& ts)
{
  switch (next_token_kind(ts)) {
    case var_kw:
    case def_kw:
      return parse_declaration_stmt(p, ts);

    // case match_kw:
    //   return parse_match_stmt(p, ts);
    // case case_kw

    default:
      break;
  }
  error(Location::none, "expected statement but got '{}'", ts.peek());
  return make_error_node<Stmt>();
}



Stmt const*
parse_stmt(Token_stream& ts)
{
  Parser p;
  return parse_stmt(p, ts);
}


} // namespace steve


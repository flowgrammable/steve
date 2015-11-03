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


// Parse the empty statement.
//
//    empty-stmt ::= ';'
Stmt const*
parse_empty_stmt(Parser& p, Token_stream& ts)
{
  Token const* tok = require_token(ts, semicolon_tok);
  return p.on_empty_stmt(tok);
}


// Parse a sequence of statements.
//
//    statement-seq ::= stmt [',' stmt*]
Sequence_term<Stmt> const*
parse_statement_seq(Parser& p, Token_stream& ts)
{
  using Result = Sequence_term<Stmt>;
  Result result;
  while (!ts.eof()) {
    if (next_token_is(ts, rbrace_tok))
      break;

    if (Required<Stmt> term = parse_stmt(p, ts))
      result.push_back(*term);
    
    // Continue parsing even though we got an error, continue
    // parsing. This will allow us to diagnose as many errors
    // as possible in a block statement.
    else if (term.is_error())
      continue;
    
    // We should probably never have this state.
    else if (term.is_empty())
      continue;
  }
  return Result::make(std::move(result));
}


// Parse a block statement.
//
//    block-stmt ::= '{' stmt-seq '}'
//
// Each block defines a new local scope.
Stmt const*
parse_block_stmt(Parser& p, Token_stream& ts)
{
  Local_scope scope; // Enter a new local scope.

  using Term = Enclosed_term<Sequence_term<Stmt>>;
  if (Required<Term> enc = parse_brace_enclosed(p, ts, parse_statement_seq)) {
    // Note that enc->term() may be empty (null) if there are
    // no statements in the block.
    if (enc->term())
      return p.on_block_stmt(enc->open(), enc->close(), *enc->term());
    else
      return p.on_block_stmt(enc->open(), enc->close(), {});
  }
  else
    return make_error_node<Stmt>();
}


Stmt const*
parse_return_stmt(Parser& p, Token_stream& ts)
{
  if (expect_token(p, ts, return_kw))
    if (Expr const* e = parse_expr(p, ts))
      if (expect_token(p, ts, semicolon_tok))
        return p.on_return_stmt(e);
}

} // namespace


// Parse a statement.
//
//    statement ::=
//        declaration-statement
//      | expr-statement
//      | empty-statement
//      | block-statement
//      | return-statement
//      | if-statemnt
//      | match-statement
//      | case-statement
//      | do-statement
//
//
// TODO: Implement these!
Stmt const*
parse_stmt(Parser& p, Token_stream& ts)
{
  switch (next_token_kind(ts)) {
    case var_kw:
    case def_kw:
    case record_kw:
    case decode_kw:
    case table_kw:
      return parse_declaration_stmt(p, ts);
    case return_kw:
      return parse_return_stmt(p, ts);

    case lbrace_tok:
      return parse_block_stmt(p, ts);

    // case match_kw:
    //   return parse_match_stmt(p, ts);
    // case case_kw

    case semicolon_tok:
      return parse_empty_stmt(p, ts);

    default:
      if (Expr const* e = parse_expr(p, ts)) {
        // consume the semicolon
        if (expect_token(p, ts, semicolon_tok))
          return p.on_expr_stmt(e);
      }
      break;
  }

  error(ts.location(), "expected statement but got '{}'", *ts.peek().str());
  return nullptr;
}



Stmt const*
parse_stmt(Token_stream& ts)
{
  Parser p;
  return parse_stmt(p, ts);
}


} // namespace steve


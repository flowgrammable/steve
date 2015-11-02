// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#ifndef STEVE_PARSER_HPP
#define STEVE_PARSER_HPP

// The parser module defines the syntactic analysis of
// the Steve grammar.

#include "steve/prelude.hpp"
#include "steve/token.hpp"
#include "steve/type.hpp"

#include "lingo/parsing.hpp"

namespace steve
{

// A sequence of function arguments.
using Arg_seq = Sequence_term<Expr>;


// The parser is responsible for constructing syntax nodes
// from information provided by parse functions.
//
// Note that the members of this class expose certain hooks in
// the grammar.
struct Parser
{
  using result_type = void*;

  String const* on_name(Token const*);

  Type const* on_id_type(Token const*);
  Type const* on_void_type(Token const*);
  Type const* on_boolean_type(Token const*);
  Type const* on_integer_type(Token const*, int, Integer_sign, Integer_order);
  Type const* on_constant_type(Token const*, Type const*);
  Type const* on_reference_type(Token const*, Type const*);

  Expr const* on_id_expr(Token const*);
  Expr const* on_boolean_expr(Token const*);
  Expr const* on_integer_expr(Token const*);
  Expr const* on_tuple_expr(Token const*, Expr_seq const&);
  Expr const* on_call_expr(Token const*, Expr const*, Arg_seq const*);
  Expr const* on_member_expr(Token const*, Expr const*, Expr const*);
  Expr const* on_unary_expr(Token const*, Expr const*);
  Expr const* on_binary_expr(Token const*, Expr const*, Expr const*);

  Expr const* on_default_init(Token const*, Type const*);
  Expr const* on_direct_init(Token const*, Expr const*);

  Decl const* on_variable_decl(Token const*, Token const*, Type const*);
  Decl const* on_variable_init(Decl const*, Expr const*);
  
  Decl const* on_parameter_decl(Token const*, Type const*);
  Decl const* on_function_decl(Token const*, Token const*, Decl_seq const&, Type const*);
  Decl const* on_function_def(Decl const*, Stmt const*);
  Decl const* on_function_start(Decl const*);
  Decl const* on_function_finish(Decl const*, Stmt const*);
  Decl const* on_record_decl(Token const*, Decl_seq const&);
  Decl const* on_member_decl(Token const*, Type const*);
  Decl const* on_decode_decl(Token const*, Token const*, Type const*, Stmt const*);

  Stmt const* on_empty_stmt(Token const*);
  Stmt const* on_block_stmt(Token const*, Token const*, Stmt_seq const&);
  Stmt const* on_declaration_stmt(Decl const*);
  Stmt const* on_expr_stmt(Expr const*);
  Stmt const* on_return_stmt(Expr const*);
};


// ---------------------------------------------------------------------------//
//                          Parsing support

// Parse a paren-enclosed term.
template<typename Parser, 
         typename Stream, 
         typename Rule,
         typename Term = Term_type<Parser, Stream, Rule>>
Enclosed_term<Term> const*
parse_paren_enclosed(Parser& p, Stream& ts, Rule rule)
{
  return parse_enclosed(p, ts, lparen_tok, rparen_tok, rule);
}


// Parse a brace-enclose term.
template<typename Parser, 
         typename Stream, 
         typename Rule,
         typename Term = Term_type<Parser, Stream, Rule>>
Enclosed_term<Term> const*
parse_brace_enclosed(Parser& p, Stream& ts, Rule rule)
{
  return parse_enclosed(p, ts, lbrace_tok, rbrace_tok, rule);
}


// Parse a comma-separated list of terms.
template<typename Parser, 
         typename Stream, 
         typename Rule,
         typename Term = Term_type<Parser, Stream, Rule>>
inline Sequence_term<Term> const*
parse_comma_list(Parser& p, Stream& ts, Rule rule)
{
  return parse_list(p, ts, comma_tok, rule);
}


// The type of a parse function. Use to disambiguate
// overloads in certain cases.
using Parse_fn = Expr const* (*)(Parser&, Token_stream&);


// Top-level parser entry points
// Type const* parse_type(Token_stream&);
Type const* parse_type(Parser&, Token_stream&);

// Expr const* parse_expr(Token_stream&);
Expr const* parse_expr(Parser&, Token_stream&);

// Stmt const* parse_stmt(Token_stream&);
Stmt const* parse_stmt(Parser&, Token_stream&);

// Decl const* parse_decl(Token_stream&);
Decl const* parse_decl(Parser&, Token_stream&);

Stmt_seq    parse_file(Token_stream&);


void init_grammar();


} // namespace steve


#endif

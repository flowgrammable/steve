// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#ifndef STEVE_PARSER_HPP
#define STEVE_PARSER_HPP

// The parser module defines the syntactic analysis of
// the Steve grammar.

#include "steve/prelude.hpp"
#include "steve/token.hpp"
#include "steve/type.hpp"

namespace steve
{


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
  Expr const* on_call_expr(Token const*, Expr const*, Expr_seq const&);
  Expr const* on_member_expr(Token const*, Expr const*, Expr const*);
  Expr const* on_unary_expr(Token const*, Expr const*);
  
  void* on_error();
  void* on_expected(char const*);
  void* on_expected(Location, char const*);
  void* on_expected(Location, char const*, Token const&);
};


// Top-level parser entry points
Type const* parse_type(Token_stream&);
Expr const* parse_expr(Token_stream&);
Decl const* parse_decl(Token_stream&);
Stmt const* parse_stmt(Token_stream&);
Stmt_seq    parse_file(Token_stream&);


void init_grammar();


} // namespace steve


#endif

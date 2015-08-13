// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "steve/parser.hpp"
#include "steve/builder.hpp"
#include "steve/lookup.hpp"

namespace steve
{


// -------------------------------------------------------------------------- //
//                              File parser


Stmt_seq
parse_file(Parser& p, Token_stream& ts)
{
  Stmt_seq stmts;
  while (!ts.eof()) {
    if (Required<Stmt> s = parse_stmt(p, ts))
      stmts.push_back(*s);
  }
  return stmts;
}


Stmt_seq
parse_file(Token_stream& ts)
{
  Parser p;
  return parse_file(p, ts);
}



// -------------------------------------------------------------------------- //
//                              Name semantics

String const* 
Parser::on_name(Token const* tok)
{
  return tok->str();
}


// -------------------------------------------------------------------------- //
//                              Type semantics


Type const*
Parser::on_id_type(Token const* tok)
{
  Decl const* decl = lookup_decl(tok->str());
  if (!decl)
    return get_error_type();

  // TODO: Support type aliases.
  return get_user_defined_type(decl);
}


Type const*
Parser::on_void_type(Token const*)
{
  return get_void_type();
}


Type const*
Parser::on_boolean_type(Token const*)
{
  return get_boolean_type();
}


Type const*
Parser::on_integer_type(Token const*, int p, Integer_sign s, Integer_order o)
{
  return get_integer_type(p, s, o);
}


Type const*
Parser::on_constant_type(Token const*, Type const* t)
{
  return get_constant_type(t);
}


Type const*
Parser::on_reference_type(Token const*, Type const* t)
{
  return get_reference_type(t);
}


// -------------------------------------------------------------------------- //
//                            Expression semantics

Expr const*
Parser::on_id_expr(Token const* tok)
{
  Overload const* ovl = lookup(tok->str());
  if (ovl && ovl->is_singleton())
    return make_id_expr(tok->location(), ovl->front());
  else
    return make_lookup_expr(tok->location(), tok->str());
}


Expr const*
Parser::on_boolean_expr(Token const* tok)
{
  return make_bool_expr(tok->location(), as_boolean(*tok));
}


Expr const*
Parser::on_integer_expr(Token const* tok)
{
  return make_int_expr(tok->location(), as_integer(*tok));
}


Expr const*
Parser::on_tuple_expr(Token const* tok, Expr_seq const& elems)
{
  return nullptr;
}


Expr const*
Parser::on_call_expr(Token const* tok, Expr const* fn, Arg_seq const* args)
{
  // FIXME: If fn is a lookup-expr, then we need to perform
  // overload resolution.
  return make_call_expr(tok->location(), fn, *args);
}


Expr const*
Parser::on_member_expr(Token const* tok, Expr const* obj, Expr const* mem)
{
  // FIXME: The member could be either an id-expr, a field expr,
  // or an integer expression. Determine what's actually meant.

  // FIXME: If we use '.' for nested name specifiers, this could also
  // be part of a nested name specifier.
  return make_member_expr(tok->location(), obj, mem);
}


Expr const*
Parser::on_unary_expr(Token const* tok, Expr const* e)
{
  Location loc = tok->location();
  switch (tok->kind()) {
  case plus_tok: 
    return make_unary_expr(loc, num_pos_op, e);
  case minus_tok: 
    return make_unary_expr(loc, num_neg_op, e);
  case tilde_tok: 
    return make_unary_expr(loc, bit_not_op, e);
  case bang_tok: 
    return make_unary_expr(loc, log_not_op, e);
  default:
    break;
  }
  lingo_unreachable();
}


// FIXME: Implement me.
Expr const*
Parser::on_binary_expr(Token const* tok, Expr const* e1, Expr const* e2)
{
  Location loc = tok->location();
  switch (tok->kind()) {
  case plus_tok: 
    return make_binary_expr(loc, num_add_op, e1, e2);
  case minus_tok: 
    return make_binary_expr(loc, num_sub_op, e1, e2);
  case star_tok: 
    return make_binary_expr(loc, num_mul_op, e1, e2);
  case slash_tok: 
    return make_binary_expr(loc, num_div_op, e1, e2);
  case percent_tok: 
    return make_binary_expr(loc, num_mod_op, e1, e2);
  case eq_eq_tok: 
    return make_binary_expr(loc, rel_eq_op, e1, e2);
  case bang_eq_tok: 
    return make_binary_expr(loc, rel_ne_op, e1, e2);
  case lt_tok: 
    return make_binary_expr(loc, rel_lt_op, e1, e2);
  case gt_tok: 
    return make_binary_expr(loc, rel_gt_op, e1, e2);
  case lt_eq_tok: 
    return make_binary_expr(loc, rel_le_op, e1, e2);
  case gt_eq_tok: 
    return make_binary_expr(loc, rel_ge_op, e1, e2);
  case amp_tok: 
    return make_binary_expr(loc, bit_and_op, e1, e2);
  case caret_tok: 
    return make_binary_expr(loc, bit_xor_op, e1, e2);
  case bar_tok: 
    return make_binary_expr(loc, bit_or_op, e1, e2);
  case lt_lt_tok: 
    return make_binary_expr(loc, bit_lsh_op, e1, e2);
  case gt_gt_tok: 
    return make_binary_expr(loc, bit_rsh_op, e1, e2);
  case amp_amp_tok: 
    return make_binary_expr(loc, log_and_op, e1, e2);
  case bar_bar_tok: 
    return make_binary_expr(loc, log_or_op, e1, e2);
  default:
    break;
  }
  lingo_unreachable();
}


// Returns a new default initilizer. Note that the type
// of the initialized expression is  null. We need to adjust
// type to match the variable before creating it.
//
// The token is the ';'.
//
// TODO: This is almost like type deduction in reverse.
Expr const*
Parser::on_default_init(Token const* tok)
{
  Expr const* expr = make_default_expr(tok->location(), nullptr);
  return make_init_expr(default_init, expr);
}


// Returns a new direct initializer.
//
// The token is the '=' token. This is currently
// unused.
//
// TODO: If `e` is "default", then this should return a
// value initializer (performs zero initialization).
Expr const*
Parser::on_direct_init(Token const*, Expr const* e)
{
  return make_init_expr(direct_init, e);
}


// Returns a new variable declaration. Note that the expression
// must be an initializer.
Decl const*
Parser::on_variable_decl(Token const* d, Token const* n, Type const* t, Expr const* e)
{
  lingo_assert(is<Init_expr>(e));

  // If this is a default initializer, make its type match that
  // of the declaration.
  //
  // TODO: Make this part of conversion?
  Init_expr const* init = cast<Init_expr>(e);
  if (init->init() == default_init) {
    lingo_assert(is<Default_expr>(init->expr()));
    Default_expr const* expr = cast<Default_expr>(init->expr());

    // Adjust the types.
    const_cast<Init_expr*>(init)->type_ = t;
    const_cast<Default_expr*>(expr)->type_ = t;
  }


  Decl const* var = make_variable_decl(d->location(), n->str(), t, e);
  declare(var);
  return var;
}


// Create a new declaration statement.
Stmt const*
Parser::on_declaration_stmt(Decl const* d)
{
  return make_decl_stmt(d);
}


// Install the grammar rule/name associations.
//
// TODO: Actually add grammar names.
void
init_grammar()
{
  
}


} // namespace steve


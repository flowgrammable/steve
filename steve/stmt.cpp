// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "decl.hpp"
#include "expr.hpp"
#include "type.hpp"
#include "stmt.hpp"
#include "debug.hpp"

#include "lingo/memory.hpp"


namespace steve
{

// Returns a textual representation of the node's name.
char const*
get_stmt_name(Stmt_kind k)
{
  switch (k) {
  case expr_stmt: return "expr_stmt";
  case decl_stmt: return "decl_stmt";
  case block_stmt: return "block_stmt";
  case return_stmt: return "return_stmt";
  case match_stmt: return "match_stmt";
  case case_stmt: return "case_stmt";
  default:
    lingo_unreachable("unhandled node kind ({})", (int)k);
  }
}


// -------------------------------------------------------------------------- //
//                             Statement builders

Empty_stmt*
make_empty_stmt(Location loc)
{
  return gc().make<Empty_stmt>(loc);
}


Expr_stmt* 
make_expr_stmt(Expr const* e)
{
  return gc().make<Expr_stmt>(e);
}


Decl_stmt* 
make_decl_stmt(Decl const* d)
{
  return gc().make<Decl_stmt>(d);
}


Block_stmt* 
make_block_stmt(Location start, Location end, Stmt_seq const& seq)
{
  return gc().make<Block_stmt>(start, end, seq);
}


Return_stmt*
make_return_stmt(Location loc, Expr const* e)
{
  return gc().make<Return_stmt>(loc, e);
}


// TODO: Verify that the `e` is a constant expression.
Case_stmt*
make_case_stmt(Location loc, Expr const* e, Stmt const* s)
{
  return gc().make<Case_stmt>(loc, e, s);
}


Match_stmt*
make_match_stmt(Location loc, Expr const* e, Stmt_seq const& s)
{
  if (!check_match_stmt(e, s))
    return nullptr;
  
  return gc().make<Match_stmt>(loc, e, s);
}


// -------------------------------------------------------------------------- //
//                             Garbage collection

void
mark(Stmt const* s)
{
  lingo_assert(is_valid_node(s));
  switch (s->kind()) {
  case expr_stmt: return mark(cast<Expr_stmt>(s));
  case decl_stmt: return mark(cast<Decl_stmt>(s));
  case block_stmt: return mark(cast<Block_stmt>(s));
  case match_stmt: return mark(cast<Match_stmt>(s));
  case case_stmt: return mark(cast<Case_stmt>(s));
  case instruct_stmt: return mark(cast<Instruct_stmt>(s));
  default:
    lingo_unreachable("unevaluated node '{}'", s->node_name());
  }
}


} // namespace steve


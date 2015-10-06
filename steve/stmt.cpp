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

String
Stmt::node_name() const
{
  return type_str(*this);
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
  // FIXME: using the GC causes an ambiguous call error
  return new Block_stmt(start, end, seq);
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
  if (is<Expr_stmt>(s))
    return mark(cast<Expr_stmt>(s));
  if (is<Decl_stmt>(s))
    return mark(cast<Decl_stmt>(s));
  // somehow ambiguous
  // if (is<Block_stmt>(s))
  //   return mark(cast<Block_stmt>(s));
  if (is<Match_stmt>(s))
    return mark(cast<Match_stmt>(s));
  if (is<Case_stmt>(s))
    return mark(cast<Case_stmt>(s));
  if (is<Instruct_stmt>(s))
    return mark(cast<Instruct_stmt>(s));

  lingo_unreachable("unevaluated node '{}'", s->node_name());
}


} // namespace steve


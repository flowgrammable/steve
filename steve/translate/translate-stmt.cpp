#include "translate-stmt.hpp"

#include <cassert>

namespace steve
{


// ---------------------------------------------------------- //
//          Utility functions

namespace
{

// Special translation from case stmt to
// c++ case stmt
//
// Since C++ case stmts require breaks at the
// end, this function injects 'break;' at the end
// of all case stmt bodies
cxx::Stmt*
translate_case_body(Stmt const* body)
{
  cxx::Stmt_seq stmt_seq;
  // the body can either be a block stmt or a single stmt
  // if its a block stmt
  if (is<Block_stmt>(body)) {
    Block_stmt const* block = as<Block_stmt>(body);
    // converts block stmt into c++ block expr
    for (auto stmt : *block) {
      cxx::Expr* cstmt = translate(stmt);
      assert(cxx::is<cxx::Stmt>(cstmt));
      stmt_seq.push_back(cxx::as<cxx::Stmt>(cstmt));
    }

    // then we push a break stmt at the end
    stmt_seq.push_back(new cxx::Break_stmt());
  }
  // otherwise it was just a single stmt
  else {
    cxx::Expr* stmt = translate(body);

    assert(cxx::is<cxx::Stmt>(stmt));
    stmt_seq.push_back(cxx::as<cxx::Stmt>(stmt));
    // then we push a break stmt at the end
    stmt_seq.push_back(new cxx::Break_stmt());
  }

  return new cxx::Block_stmt(nullptr, stmt_seq);
}

} // namespace


struct Stmt_translator
{
  // decl stmt
  cxx::Expr* operator()(Decl_stmt const* s) 
  {
    return translate(s->decl());
  }

  // expr stmt
  cxx::Expr* operator()(Expr_stmt const* s) 
  {
    cxx::Expr* expr = translate(s->expr());
    assert(expr);

    return new cxx::Expr_stmt(expr);
  }

  // empty stmt
  cxx::Expr* operator()(Empty_stmt const* s) 
  {
    return new cxx::Empty_stmt();
  }

  // block stmt
  cxx::Expr* operator()(Block_stmt const* s) 
  {
    cxx::Stmt_seq stmt_seq;
    // converts block stmt into c++ block expr
    for (auto stmt : *s) {
      cxx::Expr* cstmt = translate(stmt);
      assert(cxx::is<cxx::Stmt>(cstmt));
      stmt_seq.push_back(cxx::as<cxx::Stmt>(cstmt));
    }

    return new cxx::Block_stmt(nullptr, stmt_seq);
  }

  // return stmt
  cxx::Expr* operator()(Return_stmt const* s) 
  {
    return nullptr;
  }

  // match stmt
  // translates into a c++ switch stmt
  // FIXME: making the assumption that the value
  // being matched on is always an integer value
  cxx::Expr* operator()(Match_stmt const* s) 
  {
    cxx::Expr* cond = translate(s->cond());
    cxx::Expr* block = translate(make_block_stmt(s->cases()));

    if (cxx::is<cxx::Block_stmt>(block)) {
      // placeholder
      return new cxx::Switch_stmt(cond, cxx::as<cxx::Block_stmt>(block)); 
    }

    return nullptr;
  }

  // case stmt
  cxx::Expr* operator()(Case_stmt const* s) 
  {
    cxx::Expr* label = translate(s->label());
    cxx::Stmt* stmt = translate_case_body(s->stmt()); 

    return new cxx::Case_stmt(label, stmt);
  }

  // instruct stmt (to be removed)
  cxx::Expr* operator()(Instruct_stmt const* s) 
  {
    return nullptr;
  }
};


cxx::Expr*
translate(Stmt const* s)
{
  Stmt_translator stmt_fn;
  return apply(s, stmt_fn);
}

}

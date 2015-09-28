#include "translate-stmt.hpp"

namespace steve
{

struct Stmt_translator
{
  // decl stmt
  cxx::Expr* operator()(Decl_stmt const* s) 
  {
    return nullptr;
  }

  // expr stmt
  cxx::Expr* operator()(Expr_stmt const* s) 
  {
    return nullptr;
  }

  // empty stmt
  cxx::Expr* operator()(Empty_stmt const* s) 
  {
    return nullptr;
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
  cxx::Expr* operator()(Match_stmt const* s) 
  {
    return nullptr;
  }

  // case stmt
  cxx::Expr* operator()(Case_stmt const* s) 
  {
    return nullptr;
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

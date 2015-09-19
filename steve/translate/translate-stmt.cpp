#include "translate-stmt.hpp"

namespace steve
{

struct Stmt_translator
{
  // decl stmt
  std::string operator()(Decl_stmt const* s) 
  {
    return "";
  }

  // expr stmt
  std::string operator()(Expr_stmt const* s) 
  {
    return "";
  }

  // empty stmt
  std::string operator()(Empty_stmt const* s) 
  {
    return "";
  }

  // block stmt
  std::string operator()(Block_stmt const* s) 
  {
    return "";
  }

  // return stmt
  std::string operator()(Return_stmt const* s) 
  {
    return "";
  }

  // match stmt
  std::string operator()(Match_stmt const* s) 
  {
    return "";
  }

  // case stmt
  std::string operator()(Case_stmt const* s) 
  {
    return "";
  }

  // instruct stmt (to be removed)
  std::string operator()(Instruct_stmt const* s) 
  {
    return "";
  }
};


std::string
translate(Stmt const* s)
{
  Stmt_translator stmt_fn;
  return apply(s, stmt_fn);
}

}

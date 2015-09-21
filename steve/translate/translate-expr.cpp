#include "translate-expr.hpp"

namespace steve
{

// The expression visitor.
struct Expr_translator
{
  cxx::Expr*
  operator()(Id_expr const*)
  { 
    return nullptr;
  }


  cxx::Expr*
  operator()(Constant_expr const*)
  { 
    return nullptr;
  }


  cxx::Expr*
  operator()(Lookup_expr const*)
  { 
    return nullptr;
  }


  cxx::Expr*
  operator()(Default_expr const*)
  { 
    return nullptr;
  }


  cxx::Expr*
  operator()(Init_expr const*)
  { 
    return nullptr;
  }


  cxx::Expr*
  operator()(Value_expr const*)
  { 
    return nullptr;
  }


  cxx::Expr*
  operator()(Unary_expr const*)
  { 
    return nullptr;
  }


  cxx::Expr*
  operator()(Binary_expr const*)
  { 
    return nullptr;
  }


  cxx::Expr*
  operator()(Call_expr const*)
  { 
    return nullptr;
  }


  cxx::Expr*
  operator()(Tuple_expr const*)
  { 
    return nullptr;
  }


  cxx::Expr*
  operator()(Index_expr const*)
  { 
    return nullptr;
  }


  cxx::Expr*
  operator()(Member_expr const*)
  { 
    return nullptr;
  }


  cxx::Expr*
  operator()(Field_expr const*)
  { 
    return nullptr;
  }


  cxx::Expr*
  operator()(Convert_expr const*)
  { 
    return nullptr;
  }


  cxx::Expr*
  operator()(Lengthof_expr const*)
  { 
    return nullptr;
  }


  cxx::Expr*
  operator()(Offsetof_expr const*)
  { 
    return nullptr;
  }


  cxx::Expr*
  operator()(Headerof_expr const*)
  { 
    return nullptr;
  }


  cxx::Expr*
  operator()(Do_expr const*)
  { 
    return nullptr;
  }


  cxx::Expr*
  operator()(Insert_expr const*)
  { 
    return nullptr;
  }


  cxx::Expr*
  operator()(Delete_expr const*)
  { 
    return nullptr;
  }


  cxx::Expr*
  operator()(Field_idx_expr const*)
  { 
    return nullptr;
  }


  cxx::Expr*
  operator()(Header_idx_expr const*)
  { 
    return nullptr;
  }
};


cxx::Expr*
translate(Expr const* s)
{
  Expr_translator expr_fn;
  return apply(s, expr_fn);
}

}
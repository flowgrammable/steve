#include "translate-expr.hpp"

namespace steve
{

// The expression visitor.
struct Expr_translator
{
  cxx::Expr*
  operator()(Id_expr const* e)
  { 
    cxx::Basic_id* name = new cxx::Basic_id(*e->name());
    
    cxx::Type* type = translate(e->type());

    // FIXME: We really don't need to translate the underlying decl
    // for translation do we?
    //
    // cxx::Expr* d = translate(e->decl());
    // assert(cxx::is<cxx::Decl>(d));
    // assert(type);
    return new cxx::Id_expr(type, cxx::lvalue_cat, name, nullptr);
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


  // Returns the expression with the appropriate value
  cxx::Expr*
  operator()(Value_expr const* e)
  { 
    cxx::Type* type = translate(e->type());

    if (e->type() == get_bool_type()) {
      bool b = e->value().get_boolean();
      return new cxx::Bool_expr(type, b);
    }

    if (e->value().is_integer()) {
      Integer_value const& val = e->value().get_integer();
      return new cxx::Int_expr(type, val.gets());
    }

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

  // Call expr
  // look at the name of the call expr
  cxx::Expr*
  operator()(Call_expr const* e)
  { 
    cxx::Type* type = translate(e->type());
    assert(type);

    // steve id expr
    assert(is<Id_expr>(e->fn())); 
    steve::Id_expr const* id = as<steve::Id_expr>(e->fn());

    // make the c++ name
    cxx::Basic_id* name = new cxx::Basic_id(*id->name());
    assert(name);

    // translate the args
    cxx::Expr_seq args;
    for (auto a : e->args()) {
      args.push_back(translate(a));
    }

    // Calls are rvalue
    // TODO: Right not we do not create the Id_expr which
    // points to the translated function declaration
    // For the sake of translating, all we care about is 
    // the name of the function and the arguments.
    // We rely on steve to get the semantics correct before translating
    // into c++
    return new cxx::Call_expr(type, cxx::rvalue_cat, nullptr, args, name);
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
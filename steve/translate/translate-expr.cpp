#include "translate-expr.hpp"
#include "steve/evaluate.hpp"

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
    std::cout << "lookup\n";
    return nullptr;
  }


  cxx::Expr*
  operator()(Default_expr const*)
  { 
    std::cout << "default\n";
    return nullptr;
  }


  cxx::Expr*
  operator()(Init_expr const*)
  { 
    std::cout << "init\n";
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
    std::cout << "unary\n";
    return nullptr;
  }


  cxx::Expr*
  operator()(Binary_expr const* e)
  { 
    cxx::Expr* e1 = translate(e->left());
    cxx::Expr* e2 = translate(e->right());

    cxx::Type* type = translate(e->type());

    assert(e1);
    assert(e2);

    print(e);

    switch(e->op()) {
      case num_add_op: return new cxx::Binary_expr(type, cxx::unknown_cat, nullptr, cxx::add_op, e1, e2); // e1 + e2
      case num_sub_op: return new cxx::Binary_expr(type, cxx::unknown_cat, nullptr, cxx::sub_op, e1, e2); // e1 - e2
      case num_mul_op: return new cxx::Binary_expr(type, cxx::unknown_cat, nullptr, cxx::mul_op, e1, e2); // e1 * e2
      case num_div_op: return new cxx::Binary_expr(type, cxx::unknown_cat, nullptr, cxx::div_op, e1, e2); // e1 / e2
      case num_mod_op: return new cxx::Binary_expr(type, cxx::unknown_cat, nullptr, cxx::mod_op, e1, e2); // e1 % e2
      case bit_and_op: return new cxx::Binary_expr(type, cxx::unknown_cat, nullptr, cxx::band_op, e1, e2); // e1 & e2
      case bit_or_op: return new cxx::Binary_expr(type, cxx::unknown_cat, nullptr, cxx::bor_op, e1, e2);  // e1 | e2
      case bit_xor_op: return new cxx::Binary_expr(type, cxx::unknown_cat, nullptr, cxx::bxor_op, e1, e2); // e1 ^ e2
      case bit_lsh_op: return new cxx::Binary_expr(type, cxx::unknown_cat, nullptr, cxx::lsh_op, e1, e2); // e1 << e2
      case bit_rsh_op: return new cxx::Binary_expr(type, cxx::unknown_cat, nullptr, cxx::rsh_op, e1, e2); // e1 >> e2
      case rel_eq_op: return new cxx::Binary_expr(type, cxx::unknown_cat, nullptr, cxx::eq_op, e1, e2);  // e1 == e2
      case rel_ne_op: return new cxx::Binary_expr(type, cxx::unknown_cat, nullptr, cxx::ne_op, e1, e2);  // e1 != e2
      case rel_lt_op: return new cxx::Binary_expr(type, cxx::unknown_cat, nullptr, cxx::lt_op, e1, e2);  // e1 < e2
      case rel_gt_op: return new cxx::Binary_expr(type, cxx::unknown_cat, nullptr, cxx::gt_op, e1, e2);  // e2 > e2
      case rel_le_op: return new cxx::Binary_expr(type, cxx::unknown_cat, nullptr, cxx::le_op, e1, e2);  // e1 <= e2
      case rel_ge_op: return new cxx::Binary_expr(type, cxx::unknown_cat, nullptr, cxx::ge_op, e1, e2);  // e1 >= e2
      case log_and_op: return new cxx::Binary_expr(type, cxx::unknown_cat, nullptr, cxx::and_op, e1, e2); // e1 && e2
      case log_or_op: return new cxx::Binary_expr(type, cxx::unknown_cat, nullptr, cxx::or_op, e1, e2);  // e1 || e2
    }

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
      // if (!translate(a)) {
      //   print(a);
      //   print(a->type());
      // }

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
    std::cout << "tuple\n";
    return nullptr;
  }


  cxx::Expr*
  operator()(Index_expr const*)
  { 
    std::cout << "index\n";
    return nullptr;
  }


  // FIXME: Does this work with nested field exprs?
  cxx::Expr*
  operator()(Member_expr const* e)
  { 
    cxx::Expr* e1 = translate(e->object());
    cxx::Expr* e2 = translate(e->selector());
    cxx::Type* type = translate(e->type());

    return new cxx::Dot_expr(type, cxx::unknown_cat, e1, e2);
  }


  cxx::Expr*
  operator()(Field_expr const*)
  { 
    std::cout << "field\n";
    return nullptr;
  }


  cxx::Expr*
  operator()(Convert_expr const* e)
  { 
    Value v = evaluate(e);
    cxx::Type* type = translate(e->type());

    if (e->type() == get_bool_type()) {
      bool b = v.get_boolean();
      return new cxx::Bool_expr(type, b);
    }

    if (v.is_integer()) {
      Integer_value const& val = v.get_integer();
      return new cxx::Int_expr(type, val.gets());
    }

    return nullptr;
  }


  cxx::Expr*
  operator()(Lengthof_expr const*)
  { 
    std::cout << "lengthof\n";
    return nullptr;
  }


  cxx::Expr*
  operator()(Offsetof_expr const*)
  { 
    std::cout << "offsetof\n";
    return nullptr;
  }


  cxx::Expr*
  operator()(Headerof_expr const*)
  { 
    std::cout << "headerof\n";
    return nullptr;
  }


  cxx::Expr*
  operator()(Do_expr const*)
  { 
    std::cout << "do\n";
    return nullptr;
  }


  cxx::Expr*
  operator()(Insert_expr const*)
  { 
    std::cout << "insert\n";
    return nullptr;
  }


  cxx::Expr*
  operator()(Delete_expr const*)
  { 
    std::cout << "delete\n";
    return nullptr;
  }


  cxx::Expr*
  operator()(Field_idx_expr const*)
  { 
    std::cout << "fldidx\n";
    return nullptr;
  }


  cxx::Expr*
  operator()(Header_idx_expr const*)
  { 
    std::cout << "hdridx\n";
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
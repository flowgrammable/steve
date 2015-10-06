#include "translate-decl.hpp"
#include "steve/length.hpp"
#include "steve/evaluate.hpp"

namespace steve
{

namespace
{


struct Decl_translator
{
  cxx::Expr* 
  operator()(Variable_decl const* d) 
  { 
    return nullptr;
  }


  cxx::Expr* 
  operator()(Constant_decl const* d) 
  { 
    return nullptr;
  }

  // functions in c++ are composed of
  // - a return type
  // - a name
  // - a parameter list
  // - (possibly) a body depending on if its a forward declaration
  cxx::Expr* 
  operator()(Function_decl const* d) 
  { 
    // translate return type
    cxx::Type* ret_t = translate(d->ret_type());
    cxx::Basic_id* name = new cxx::Basic_id(*d->name());

    cxx::Decl_seq parms;

    for (auto p : d->parms()) {
      cxx::Expr* parm = translate(p);
      assert(cxx::is<cxx::Parameter_decl>(parm));
      parms.push_back(cxx::as<cxx::Parameter_decl>(parm));
    }

    cxx::Expr* body = translate(as<Block_stmt>(d->body()));

    return new cxx::Function_decl(cxx::simple_type_spec, name, parms, ret_t, body);
  }


  cxx::Expr* 
  operator()(Parameter_decl const* d) 
  { 
    cxx::Type* type = translate(d->type());
    cxx::Basic_id* name = new cxx::Basic_id(*d->name());

    assert(type);

    return new cxx::Parameter_decl(cxx::simple_type_spec, name, type);
  }


  // A record decl translates into a C++
  // class with the same name.
  //
  // Non byte aligned characters are
  // aggregated until they reach byte alignment otherwise
  // we have an error.
  cxx::Expr* 
  operator()(Record_decl const* d) 
  { 
    cxx::String str_name(*d->name());
    cxx::Basic_id* name = new cxx::Basic_id(str_name);

    cxx::Decl_seq struct_mems; 

    for (auto member : d->members()) {
      cxx::Expr* mem = translate(member);
      assert(cxx::is<cxx::Decl>(mem));

      struct_mems.push_back(cxx::as<cxx::Decl>(mem));
    }

    cxx::Type* class_t = new cxx::Class_type(name, {}, struct_mems);
    return new cxx::Type_decl(class_t);
  }


  // Return a variable with the same type, name, and init as the member decl
  cxx::Expr* 
  operator()(Member_decl const* d) 
  { 
    // get the name
    cxx::Basic_id* mem_name = new cxx::Basic_id(*d->name());

    // translate the type
    cxx::Type* type = translate(d->type());
    assert(type);

    // FIXME: not sure if we need to change that decl spec
    // NOTE: no expression is given as an initializer.
    return new cxx::Variable_decl(cxx::simple_type_spec, mem_name, type, nullptr);
  }


  cxx::Expr* 
  operator()(Variant_decl const* d) 
  { 
    return nullptr;
  }


  cxx::Expr* 
  operator()(Enum_decl const* d) 
  { 
    return nullptr;
  }


  cxx::Expr*
  operator()(Forward_decl const* d)
  {
    return nullptr;
  }

  // we lower these into regular function calls
  // then translate them into c++
  // i dont think this ever gets called because
  // we lower before the translation phase
  // this just has to be here for the visitor pattern
  cxx::Expr* 
  operator()(Decode_decl const* d) 
  { 
    return nullptr;
  }


  // lowering of table declarations should handle this
  // before we translated
  //
  // However, for now we'll do all the work here
  cxx::Expr*
  operator()(Table_decl const* d) 
  { 
    cxx::Basic_id* name = new cxx::Basic_id(*d->name());

    cxx::Type* type = translate(d->type());

    assert(type);

    // we translate each flow decl into
    // an init expr of the form
    // {make_key(...), Flow(...)}
    //
    // The initializer list for tables
    // thus ends up being an init expr list containing
    // a sequence of init expr
    //
    // Hash_table t = {
    //    init_expr,
    //    init_expr,...
    // }
    cxx::Expr_seq seq;

    for (auto decl : d->body()) {
      assert(is<Flow_decl>(decl));
      seq.push_back(translate(decl));
    }

    // Init_expr have unknown type
    cxx::Init_expr* init = new cxx::Init_expr(nullptr, seq);

    return new cxx::Variable_decl(cxx::simple_type_spec, name, type, init);
  }


  // lowering of flow declarations should handle this before we translate
  //
  // however for now we'll do all the work here
  //
  // A flow decl becomes a pair initializer for a map when translated into
  // C++.
  // The first element of the pair is the key which is synthesized by a function
  // and the second element is the length of the key.
  //
  // {subkey1, subkey2, subkey3} => { flow_instructions }
  // becomes an initializer expression of the form
  // {make_key(subkey1, subkey2, subkey3), Flow({})}
  cxx::Expr* 
  operator()(Flow_decl const* d) 
  { 
    cxx::Expr_seq subkeys;

    for (auto val : d->keys()) {
      subkeys.push_back(translate(val));
    }

    // the return type is meaningless here
    // we're never going to get a type other than Key
    // unless the program was malformed
    static cxx::Basic_id* name = new cxx::Basic_id("make_key");
    cxx::Call_expr* make_key = new cxx::Call_expr(nullptr, cxx::unknown_cat, nullptr, subkeys, name);

    // Flow constructor
    // FIXME: currently only a placeholder

    static cxx::Basic_id flow_type_name("Flow");
    static cxx::Class_type flow_type(&flow_type_name, {}, {}); 
    cxx::Construct_expr* flow_construct = new cxx::Construct_expr(&flow_type, {});

    return new cxx::Init_expr(nullptr, {make_key, flow_construct});
  }


  cxx::Expr* 
  operator()(Extracts_decl const* d) 
  { 
    return nullptr;
  }


  cxx::Expr* 
  operator()(Rebind_decl const* d) 
  { 
    return nullptr;
  }
};


} // namespace

cxx::Expr*
translate(Decl const* d)
{
  Decl_translator decl_fn;
  return apply(d, decl_fn);
}

} // namespace steve

#include "translate-decl.hpp"
#include "steve/length.hpp"
#include "steve/evaluate.hpp"

namespace steve
{

namespace
{

// Construct a c++ integer member variable
// cxx::Decl* 
// cxx_integer_var(cxx::Name* name, Value precision)
// {
//   // Construct an integer with the appropriate type and precision
//   if (precision.is_integer()) {
//     Integer_value const& byte_len = precision.get_integer();

//     cxx::Type* type;
//     // switch on the number of bytes
//     // TODO: we don't actually handle 5, 7, 9-15 byte long fields
//     // I don't believe these are frequent enough to matter
//     switch (byte_len.gets()) {
//       case 1: 
//         type = cxx::get_uint8_type();
//         break;
//       case 2:
//         type = cxx::get_uint16_type();
//         break;
//       case 3:
//         type = cxx::get_uint24_type();
//         break;
//       case 4:
//         type = cxx::get_uint32_type();
//         break;
//       case 6:
//         type = cxx::get_uint48_type();
//         break;
//       case 8:
//         type = cxx::get_uint64_type();
//         break;
//       case 16:
//         type = cxx::get_uint128_type();
//         break;
//       default:
//         type = nullptr;
//         break;
//     }
    
//     // if we got an integer type
//     if (type)  {
//       // construct a variable declaration with that type
//       // and default initializer
//       return new cxx::Variable_decl(cxx::simple_type_spec, name, type, nullptr);
//     }   
//   }

//   error("no variable decl");
//   return nullptr;
// }


// Takes a c++ type and guesses the declaration specifier
// cxx::Decl_spec
// derive_decl_spec(cxx::Type const* t)
// {
//   switch (t->kind) {
//     // any integer type returns the simple_type spec
//   }

//   return cxx::simple_type_spec;
// }


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
  cxx::Expr* 
  operator()(Table_decl const* d) 
  { 
    return nullptr;
  }

  // lowering of flow declarations should hande this before we translate
  cxx::Expr* 
  operator()(Flow_decl const* d) 
  { 
    return nullptr;
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

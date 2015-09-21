#include "translate-decl.hpp"
#include "steve/length.hpp"
#include "steve/evaluate.hpp"

namespace steve
{

namespace
{

// Construct a c++ integer member variable
cxx::Decl* 
cxx_integer_var(cxx::Name* name, Value precision)
{
  // Construct an integer with the appropriate type and precision
  if (precision.is_integer()) {
    Integer_value const& byte_len = precision.get_integer();

    cxx::Type* type;
    // switch on the number of bytes
    // TODO: we don't actually handle 5, 7, 9-15 byte long fields
    // I don't believe these are frequent enough to matter
    switch (byte_len.base()) {
      case 1: 
        type = cxx::get_uint8_type();
        break;
      case 2:
        type = cxx::get_uint16_type();
        break;
      case 3:
        type = cxx::get_uint24_type();
        break;
      case 4:
        type = cxx::get_uint32_type();
        break;
      case 6:
        type = cxx::get_uint48_type();
        break;
      case 8:
        type = cxx::get_uint64_type();
        break;
      case 16:
        type = cxx::get_uint128_type();
        break;
      default:
        type = nullptr;
        break;
    }
    
    // if we got an integer type
    if (type)  {
      // construct a variable declaration with that type
      // and default initializer
      return new cxx::Variable_decl(cxx::simple_type_spec, name, type, nullptr);
    }   
  }


  return nullptr;
}

} // namespace

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


  cxx::Expr* 
  operator()(Function_decl const* d) 
  { 
    return nullptr;
  }


  cxx::Expr* 
  operator()(Parameter_decl const* d) 
  { 
    return nullptr;
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
      // determine the length of the member
      Expr const* e = get_length(member->type());

      cxx::Basic_id* mem_name = new cxx::Basic_id(*member->name());

      // if its an integer type
      if (is<Integer_type>(member->type()))
        // push it onto the members
        struct_mems.push_back(cxx_integer_var(mem_name, evaluate(e))); 
    }

    cxx::Type* class_t = new cxx::Class_type(name, {}, struct_mems);
    return new cxx::Type_decl(class_t);
  }


  cxx::Expr* 
  operator()(Member_decl const* d) 
  { 
    return nullptr;
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
  operator()(Decode_decl const* d) 
  { 
    return nullptr;
  }


  cxx::Expr* 
  operator()(Table_decl const* d) 
  { 
    return nullptr;
  }


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


cxx::Expr*
translate(Decl const* d)
{
  Decl_translator decl_fn;
  return apply(d, decl_fn);
}

}

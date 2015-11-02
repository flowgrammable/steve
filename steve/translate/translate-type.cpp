#include "translate-type.hpp"

namespace steve
{

namespace
{

cxx::Type*
unsigned_int_type(int precision)
{
  // switch on the number of bytes
  // TODO: we don't actually handle 5, 7, 9-15 byte long fields
  // I don't believe these are frequent enough to matter
  switch (precision / 8) {
    case 1: 
      return cxx::get_uint8_type();
    case 2:
      return cxx::get_uint16_type();
    case 3:
      return cxx::get_uint24_type();
    case 4:
      return cxx::get_uint32_type();
    case 6:
      return cxx::get_uint48_type();
    case 8:
      return cxx::get_uint64_type();
    case 16:
      return cxx::get_uint128_type();
    default:
      return nullptr;
  }
}

cxx::Type*
signed_int_type(int precision)
{
  return cxx::get_int_type();
}

}

struct Type_translator
{
  cxx::Type* 
  operator()(Void_type const* t) 
  { 
    return new cxx::Void_type();
  }


  cxx::Type* 
  operator()(Kind_type const* t) 
  { 
    return nullptr;
  }


  cxx::Type* 
  operator()(Boolean_type const* t) 
  { 
    return new cxx::Bool_type();
  }

  // We have to return the correct integer
  // Type based on the byte precision
  cxx::Type* 
  operator()(Integer_type const* t) 
  {     
    if (t->is_unsigned())
      return unsigned_int_type(t->precision());
    if (t->is_signed())
      return signed_int_type(t->precision());

    return nullptr;
  }


  cxx::Type* 
  operator()(Constant_type const* t) 
  { 
    return nullptr;
  }


  cxx::Type* 
  operator()(Function_type const* t) 
  { 
    return nullptr;
  }


  cxx::Type* 
  operator()(Reference_type const* t) 
  { 
    cxx::Type* type = translate(t->type());

    return new cxx::Lvalue_reference_type(type);
  }


  cxx::Type* 
  operator()(Array_type const* t) 
  { 
    return nullptr;
  }


  cxx::Type* 
  operator()(Tuple_type const* t) 
  { 
    return nullptr;
  }

  // return class type based on record declaration
  cxx::Type* 
  operator()(Record_type const* t) 
  { 
    Record_decl const* d = as<Record_decl>(t->decl());

    cxx::String str_name(*d->name());
    cxx::Basic_id* name = new cxx::Basic_id(str_name);

    cxx::Decl_seq struct_mems; 

    for (auto member : d->members()) {
      cxx::Expr* mem = translate(member);
      assert(cxx::is<cxx::Decl>(mem));

      struct_mems.push_back(cxx::as<cxx::Decl>(mem));
    }

    return new cxx::Class_type(name, {}, struct_mems);
  }


  cxx::Type* 
  operator()(Variant_type const* t) 
  { 
    return nullptr;
  }


  cxx::Type* 
  operator()(Enum_type const* t) 
  { 
    return nullptr;
  }


  cxx::Type* 
  operator()(Match_type const* t) 
  { 
    return nullptr;
  }


  cxx::Type* 
  operator()(If_type const* t) 
  { 
    return nullptr;
  }


  cxx::Type* 
  operator()(Seq_type const* t) 
  { 
    return nullptr;
  }


  cxx::Type* 
  operator()(Buffer_type const* t) 
  { 
    return nullptr;
  }


  cxx::Type* 
  operator()(Until_type const* t) 
  { 
    return nullptr;
  }


  cxx::Type* 
  operator()(Table_type const* t) 
  { 
    static cxx::Basic_id name("Exact_table");
    return new cxx::Class_type(&name, {}, {});
  }


  cxx::Type* 
  operator()(Flow_type const* t) 
  { 
    return nullptr;
  }


  cxx::Type*
  operator()(Port_type const* t)
  {
    static cxx::Basic_id name("Port");
    return new cxx::Class_type(&name, {}, {});
  }
};

cxx::Type*
translate(Type const* s)
{
  Type_translator type_fn;
  return apply(s, type_fn);
}

} // namespace steve
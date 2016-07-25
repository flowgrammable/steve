// Copyright (c) 2015 Andrew Sutton
// All rights reserved

#include "beaker/type.hpp"
#include "beaker/decl.hpp"
#include "beaker/less.hpp"
#include "beaker/value.hpp"
#include "beaker/evaluator.hpp"

#include <set>


// Return a reference type for this type.
Type const*
Type::ref() const
{
  return get_reference_type(this);
}


// Return the non-reference type for this type.
Type const*
Type::nonref() const
{
  return this;
}


Type const*
Reference_type::ref() const
{
  return this;
}


Type const*
Reference_type::nonref() const
{
  return first;
}


Record_decl*
Record_type::declaration() const
{
  return cast<Record_decl>(decl_);
}


Scope*
Record_type::scope() const
{
  return declaration()->scope();
}



// Returns the size of the array as an
// integer value.
int
Array_type::size() const
{
  Value v = evaluate(extent());
  return v.get_integer();
}


// -------------------------------------------------------------------------- //
// Type accessors

template<typename T>
struct Type_less
{
  bool operator()(T const& a, T const& b) const
  {
    return is_less(&a, &b);
  }
};


template<typename T>
using Type_set = std::set<T, Type_less<T>>;


// Note that id types are not canonicalized.
// They don't need to be since they never
// escape elaboration.
Type const*
get_id_type(Symbol const* s)
{
  return new Id_type(s);
}


Type const*
get_boolean_type()
{
  static Boolean_type t;
  return &t;
}


Type const*
get_character_type()
{
  static Character_type t;
  return &t;
}


Type const*
get_integer_type(int precision, Integer_sign s, Integer_order o)
{
  static Type_set<Integer_type> fn;
  auto ins = fn.emplace(precision, s, o);
  return &*ins.first;
}


Type const*
get_integer_type()
{
  return get_integer_type(32, signed_int, native_order);
}


Type const*
get_function_type(Type_seq const& t, Type const* r, bool v)
{
  static Type_set<Function_type> fn;
  auto ins = fn.emplace(t, r, v);
  return &*ins.first;
}


// Non-variable args
Type const*
get_function_type(Type_seq const& t, Type const* r)
{
  return get_function_type(t, r, false);
}


Type const*
get_function_type(Decl_seq const& d, Type const* r)
{
  Type_seq t;
  t.reserve(d.size());
  for (Decl* d1 : d)
    t.push_back(d1->type());
  return get_function_type(t, r);
}


Type const*
get_record_type(Record_decl* r)
{
  static Type_set<Record_type> ts;
  auto ins = ts.emplace(r);
  return &*ins.first;
}


Type const*
get_array_type(Type const* t, Expr* n)
{
  static Type_set<Array_type> ts;
  auto ins = ts.emplace(t, n);
  return &*ins.first;
}


Type const*
get_block_type(Type const* t)
{
  static Type_set<Block_type> ts;
  auto ins = ts.emplace(t);
  return &*ins.first;
}


// FIXME: Don't allow references to non-object types.
Type const*
get_reference_type(Type const* t)
{
  static Type_set<Reference_type> ts;
  auto ins = ts.emplace(t);
  return &*ins.first;
}


Type const*
get_void_type()
{
  static Void_type t;
  return &t;
}


Type const*
get_opaque_type()
{
  static Opaque_type t;
  return &t;
}


Type const*
get_varargs_type()
{
  static Varargs_type t;
  return &t;
}

// ------------------------------------------------------------ //
//        Network specific types

Type const*
get_layout_type(Layout_decl* l)
{
  static Type_set<Layout_type> ts;
  auto ins = ts.emplace(l);
  return &*ins.first;
}


Type const*
get_context_type()
{
  static Context_type t;
  return &t;
}


Type const*
get_table_type(Decl_seq const& d, Type_seq const& t)
{
  static Type_set<Table_type> ts;
  auto ins = ts.emplace(d, t);
  return &*ins.first;
}


Type const*
get_opaque_table()
{
  return get_table_type({}, {});
}


Type const*
get_flow_type(Type_seq const& t)
{
  static Type_set<Flow_type> ts;
  auto ins = ts.emplace(t);
  return &*ins.first;
}


Type const*
get_port_type()
{
  static Port_type t;
  return &t;
}


Type const*
get_key_type()
{
  static Key_type t;
  return &t;
}

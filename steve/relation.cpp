// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "steve/relation.hpp"
#include "steve/type.hpp"
#include "steve/expr.hpp"
#include "steve/decl.hpp"
#include "steve/stmt.hpp"

#include <algorithm>
#include <typeindex>


namespace steve
{

namespace
{


// Compare two integer values.
inline bool
less(Integer const& a, Integer const& b)
{
  return a < b;
}


inline bool
less(Value const& a, Value const& b) 
{
  return a < b;
}


// String pointers in nodes are required to be unique.
inline bool
less(String const* a, String const* b)
{
  std::less<String const*> cmp;
  return cmp(a, b);
}



template<typename T>
struct Term_less
{
  bool operator()(T const* a, T const* b) const;
};


// Compare vectors of T.
// Note that T must be the root of an inheritance hierarchy.
template<typename T>
inline bool
less(std::vector<T const*> const& a, std::vector<T const*> const& b)
{
  Term_less<T> cmp;
  return std::lexicographical_compare(a.begin(), a.end(),
                                      b.begin(), b.end(), cmp);
}


template<typename T>
typename std::enable_if<is_nullary_node<T>(), bool>::type
less(T const* a, T const* b)
{
  return false;
}


template<typename T>
typename std::enable_if<is_unary_node<T>(), bool>::type
less(T const* a, T const* b)
{
  return less(a->first, b->first);
}


template<typename T>
typename std::enable_if<is_binary_node<T>(), bool>::type
less(T const* a, T const* b)
{
  if (less(a->first, b->first))
    return true;
  if (less(b->first, a->first))
    return false;
  return less(a->second, b->second);
}


template<typename T>
typename std::enable_if<is_ternary_node<T>(), bool>::type
less(T const* a, T const* b)
{
  if (less(a->first, b->first))
    return true;
  if (less(b->first, a->first))
    return false;

  if (less(a->second, b->second))
    return true;
  if (less(b->second, a->second))
    return false;

  return less(a->third, b->third);
}


// User-defined types are ordered by their underlying
// declarations.
//
// TODO: This could be made generic by making "user-defined type"
// a constant!
template<typename T>
bool
less_udt(T const* a, T const* b)
{
  std::less<Decl const*> cmp;
  return cmp(a->decl(), b->decl());
}


// Retursn true when one id expression is less than the other.
// This is determined by the refernce to the underlying decl.
inline bool
less(Id_expr const* a, Id_expr const* b)
{
  return less(a->decl(), b->decl());
}


inline bool
less(Do_expr const* a, Do_expr const* b)
{
  if (a->do_what() < b->do_what())
    return true;
  else if (b->do_what() < a->do_what())
    return false;

  return less(a->target(), b->target());
}


template<typename T>
bool 
Term_less<T>::operator()(T const* a, T const* b) const
{
  return less(a, b);
}


// Dispatch to an appropriate function.
struct Less_type_fn
{
  Less_type_fn(Type const* t)
    : t2(t)
  { }

  bool operator()(Kind_type const* t1) const
  {
    return less(t1, static_cast<Kind_type const*>(t2));
  }

  bool operator()(Void_type const* t1) const
  { 
    return less(t1, static_cast<Void_type const*>(t2)); 
  }
  
  bool operator()(Boolean_type const* t1) const
  { 
    return less(t1, static_cast<Boolean_type const*>(t2)); 
  }
  
  bool operator()(Integer_type const* t1) const
  { 
    return less(t1, static_cast<Integer_type const*>(t2)); 
  }

  bool operator()(Constant_type const* t1) const
  {
    return less(t1, static_cast<Constant_type const*>(t2));
  }

  bool operator()(Reference_type const* t1) const
  {
    return less(t1, static_cast<Reference_type const*>(t2));
  }
  
  bool operator()(Function_type const* t1) const
  { 
    return less(t1, static_cast<Function_type const*>(t2)); 
  }

  bool operator()(Array_type const* t1) const
  {
    return less(t1, static_cast<Array_type const*>(t2));
  }

  bool operator()(Tuple_type const* t1) const
  {
    return less(t1, static_cast<Tuple_type const*>(t2));
  }

  bool operator()(Record_type const* t1) const
  {
    return less(t1, static_cast<Record_type const*>(t2));
  }

  bool operator()(Variant_type const* t1) const
  {
    return less_udt(t1, static_cast<Variant_type const*>(t2));
  }

  bool operator()(Enum_type const* t1) const
  {
    return less_udt(t1, static_cast<Enum_type const*>(t2));
  }

  bool operator()(If_type const* t1) const
  {
    return less(t1, static_cast<If_type const*>(t2));
  }

  bool operator()(Match_type const* t1) const
  {
    return less(t1, static_cast<Match_type const*>(t2));
  }

  bool operator()(Seq_type const* t1) const
  {
    return less(t1, static_cast<Seq_type const*>(t2));
  }

  bool operator()(Buffer_type const* t1) const
  {
    return less(t1, static_cast<Buffer_type const*>(t2));
  }

  bool operator()(Until_type const* t1) const
  {
    return less(t1, static_cast<Until_type const*>(t2));
  }

  bool operator()(Table_type const* t1) const
  {
    return less(t1, static_cast<Table_type const*>(t2));
  }

  bool operator()(Flow_type const* t1) const
  {
    return less(t1, static_cast<Flow_type const*>(t2));
  }

  Type const* t2;
};


struct Less_expr_fn
{
  Less_expr_fn(Expr const* t)
    : t2(t)
  { }

  bool operator()(Value_expr const* t1) const
  {
    return less(t1, cast<Value_expr>(t2));
  }

  bool operator()(Id_expr const* t1) const
  {
    return less(t1, cast<Id_expr>(t2));
  }

  bool operator()(Lookup_expr const* t1) const
  {
    return less(t1, cast<Lookup_expr>(t2));
  }

  bool operator()(Constant_expr const* t1) const
  {
    return less(t1, cast<Lookup_expr>(t2));
  }

  bool operator()(Default_expr const* t1) const
  {
    return less(t1, cast<Default_expr>(t2));
  }

  bool operator()(Init_expr const* t1) const
  {
    return less(t1, cast<Init_expr>(t2));
  }

  bool operator()(Unary_expr const* t1) const
  {
    return less(t1, cast<Unary_expr>(t2));
  }

  bool operator()(Binary_expr const* t1) const
  {
    return less(t1, cast<Binary_expr>(t2));
  }

  bool operator()(Call_expr const* t1) const
  {
    return less(t1, cast<Call_expr>(t2));
  }

  bool operator()(Tuple_expr const* t1) const
  {
    return less(t1, cast<Tuple_expr>(t2));
  }

  bool operator()(Index_expr const* t1) const
  {
    return less(t1, cast<Index_expr>(t2));
  }

  bool operator()(Member_expr const* t1) const
  {
    return less(t1, cast<Member_expr>(t2));
  }

  bool operator()(Field_expr const* t1) const
  {
    return less(t1, cast<Field_expr>(t2));
  }

  bool operator()(Convert_expr const* t1) const
  {
    return less(t1, cast<Convert_expr>(t2));
  }

  bool operator()(Lengthof_expr const* t1) const
  {
    return less(t1, cast<Lengthof_expr>(t2));
  }

  bool operator()(Offsetof_expr const* t1) const
  {
    return less(t1, cast<Offsetof_expr>(t2));
  }

  bool operator()(Headerof_expr const* t1) const
  {
    return less(t1, cast<Headerof_expr>(t2));
  }

  bool operator()(Insert_expr const* t1) const
  {
    return less(t1, cast<Insert_expr>(t2));
  }

  bool operator()(Delete_expr const* t1) const
  {
    return less(t1, cast<Delete_expr>(t2));
  }

  bool operator()(Do_expr const* t1) const
  {
    return less(t1, cast<Do_expr>(t2));
  }

  bool operator()(Field_idx_expr const* t1) const
  {
    return less(t1, cast<Field_idx_expr>(t2));
  }

  bool operator()(Header_idx_expr const* t1) const
  {
    return less(t1, cast<Header_idx_expr>(t2));
  }

  Expr const* t2;
};


} // namespace


// Returns true if one type is less than another.
bool 
less(Type const* a, Type const* b)
{
  // Abritrarily order types by their type information.
  std::type_index t1 = typeid(*a);
  std::type_index t2 = typeid(*b);
  if (t1 < t2)
    return true;
  if (t2 < t1)
    return false;

  // If two types are equivalent, then dispatch to
  // an appropriate function.
  return apply(a, Less_type_fn(b));
}


bool
less(Expr const* a, Expr const* b)
{
  // Abritrarily order types by their type information.
  std::type_index t1 = typeid(*a);
  std::type_index t2 = typeid(*b);
  if (t1 < t2)
    return true;
  if (t2 < t1)
    return false;

  // If two types are equivalent, then dispatch to
  // an appropriate function.
  return apply(a, Less_expr_fn(b));
}


bool
less(Value const* a, Value const* b)
{
  return &a < &b;
}


// Declarations are unique based on their representation, not
// their structure.
bool
less(Decl const* a, Decl const* b)
{
  std::less<Decl const*> cmp;
  return cmp(a, b);
}

} // namespace steve

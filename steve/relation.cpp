// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "steve/relation.hpp"
#include "steve/type.hpp"
#include "steve/expr.hpp"
#include "steve/decl.hpp"
#include "steve/stmt.hpp"

#include <algorithm>


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


template<typename T>
bool 
Term_less<T>::operator()(T const* a, T const* b) const
{
  return less(a, b);
}


} // namespace


bool 
less(Type const* a, Type const* b)
{
  if (a->kind() < b->kind())
    return true;
  if (b->kind() < a->kind())
    return false;
  
  switch (a->kind()) {
    case kind_type:
    case void_type:
    case boolean_type:
      // Ground types are equivalent.
      return false;

    case integer_type:
      return less(cast<Integer_type>(a), cast<Integer_type>(b));
    
    case constant_type:
      return less(cast<Constant_type>(a), cast<Constant_type>(b));

    case reference_type:
      return less(cast<Reference_type>(a), cast<Reference_type>(b));

    case function_type: 
      return less(cast<Function_type>(a), cast<Function_type>(b));

    case array_type: 
      return less(cast<Array_type>(a), cast<Array_type>(b));

    case tuple_type:
      return less(cast<Tuple_type>(a), cast<Tuple_type>(b));

    case record_type:
      return less_udt(cast<Record_type>(a), cast<Record_type>(b));

    case variant_type:
      return less_udt(cast<Variant_type>(a), cast<Variant_type>(b));

    case enum_type:
      return less_udt(cast<Enum_type>(a), cast<Enum_type>(b));

    case if_type:
      return less(cast<If_type>(a), cast<If_type>(b));

    case match_type:
      return less(cast<Match_type>(a), cast<Match_type>(b));

    case seq_type:
      return less(cast<Seq_type>(a), cast<Seq_type>(b));
    
    case buffer_type:
      return less(cast<Buffer_type>(a), cast<Buffer_type>(b));

    case until_type:
      return less(cast<Until_type>(a), cast<Until_type>(b));

    case table_type:
      return less_udt(cast<Table_type>(a), cast<Table_type>(b));

    case flow_type:
      return less_udt(cast<Flow_type>(a), cast<Flow_type>(b));
  }  
  lingo_unreachable("unhandled type '{}'", a->node_name());
}


bool
less(Expr const* a, Expr const* b)
{
  if (a->kind() < b->kind())
    return true;
  if (b->kind() < a->kind())
    return false;

  switch(a->kind()) {
    case value_expr:
      return less(cast<Value_expr>(a), cast<Value_expr>(b));
    
    case id_expr: 
      // FIXME: I don't think that this is right because it
      // always returns false (Id_expr is actually nullary).
      // Determining when id expressions are equivalent would
      // be helpful in determining when they are less. Note
      // that different contexts may need different answers.
      return less(cast<Id_expr>(a), cast<Id_expr>(b));

    case lookup_expr: 
      return less(cast<Lookup_expr>(a), cast<Lookup_expr>(b));

    case default_expr: 
      return false;

    case init_expr: 
      return less(cast<Init_expr>(a), cast<Init_expr>(b));
    
    case unary_expr: 
      return less(cast<Unary_expr>(a), cast<Unary_expr>(b));
    
    case binary_expr:
      return less(cast<Binary_expr>(a), cast<Binary_expr>(b));
    
    case call_expr:
      return less(cast<Call_expr>(a), cast<Call_expr>(b));
    
    case tuple_expr: 
      return less(cast<Tuple_expr>(a), cast<Tuple_expr>(b));
    
    case index_expr: 
      return less(cast<Index_expr>(a), cast<Index_expr>(b));
    
    case member_expr:
      return less(cast<Member_expr>(a), cast<Member_expr>(b));

    case convert_expr:
      return less(cast<Convert_expr>(a), cast<Convert_expr>(b));

    case lengthof_expr:
      return less(cast<Lengthof_expr>(a), cast<Lengthof_expr>(b));

    case offsetof_expr:
      return less(cast<Offsetof_expr>(a), cast<Offsetof_expr>(b));

    case action_expr:
      return less(cast<Action_expr>(a), cast<Action_expr>(b));
  }

  lingo_unreachable("unhandled expression '{}'", a->node_name());
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

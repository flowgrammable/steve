// Copyright (c) 2015 Andrew Sutton
// All rights reserved

#include "beaker/less.hpp"
#include "beaker/type.hpp"
#include "beaker/expr.hpp"
#include "beaker/value.hpp"
#include "beaker/builtin.hpp"

#include <algorithm>
#include <typeindex>

// FIXME: will this cause issues with the
// templates? Will there be ambiguous type conflicts
// at some point?
inline bool
is_less(bool a, bool b)
{
  return a < b;
}


inline bool
is_less(int a, int b)
{
  return a < b;
}


// -------------------------------------------------------------------------- //
// Generic comparisons


template<typename T>
inline bool
is_less(std::vector<T> const& a, std::vector<T> const& b)
{
  auto cmp = [](T const& x, T const& y) { return is_less(x, y); };
  return std::lexicographical_compare(a.begin(), a.end(),
                                      b.begin(), b.end(), cmp);
}


template<typename T>
typename std::enable_if<is_nullary_node<T>(), bool>::type
is_less(T const* a, T const* b)
{
  return false;
}


template<typename T>
typename std::enable_if<is_unary_node<T>(), bool>::type
is_less(T const* a, T const* b)
{
  return is_less(a->first, b->first);
}


template<typename T>
typename std::enable_if<is_binary_node<T>(), bool>::type
is_less(T const* a, T const* b)
{
  if (is_less(a->first, b->first))
    return true;
  if (is_less(b->first, a->first))
    return false;
  return is_less(a->second, b->second);
}


template<typename T>
typename std::enable_if<is_ternary_node<T>(), bool>::type
is_less(T const* a, T const* b)
{
  if (is_less(a->first, b->first))
    return true;
  if (is_less(b->first, a->first))
    return false;
  if (is_less(a->second, b->second))
    return true;
  if (is_less(b->second, a->second))
    return false;
  return is_less(a->third, b->third);
}


// -------------------------------------------------------------------------- //
// Comparison of types


inline bool
is_less(Record_type const* a, Record_type const* b)
{
  std::less<void const*> cmp;
  return cmp(a->declaration(), b->declaration());
}


inline bool
is_less(Id_type const* a, Id_type const* b)
{
  std::less<void const*> cmp;
  return cmp(a->symbol(), b->symbol());
}


inline bool
is_less(Layout_type const* a, Layout_type const* b)
{
  std::less<void const*> cmp;
  return cmp(a->declaration(), b->declaration());
}


// Two table types are equal if all of their key fields
// are equal
inline bool
is_less(Table_type const* a, Table_type const* b)
{
  Decl_seq const& a_fields = a->field_names();
  Decl_seq const& b_fields = b->field_names();

  auto cmp = [](Decl const* x, Decl const* y) { return is_less(x->type(), y->type()); };
  return std::lexicographical_compare(a_fields.begin(), a_fields.end(),
                                      b_fields.begin(), b_fields.end(), cmp);
}


// Two flow types are equal if each of their key types
// are equal
inline bool
is_less(Flow_type const* a, Flow_type const* b)
{
  return is_less(a->key_types(), b->key_types());
}


inline bool
is_less(Reference_type const* a, Reference_type const* b)
{
  return is_less(a->first, b->first);
}


bool
is_less(Type const* a, Type const* b)
{
  struct Fn
  {
    Type const* b;

    bool operator()(Id_type const* a) { return is_less(a, cast<Id_type>(b)); }
    bool operator()(Boolean_type const* a) { return false; }
    bool operator()(Character_type const* a) { return false; }
    bool operator()(Integer_type const* a) { return is_less(a, cast<Integer_type>(b)); }
    bool operator()(Function_type const* a) { return is_less(a, cast<Function_type>(b)); }
    bool operator()(Array_type const* a) { return is_less(a, cast<Array_type>(b)); }
    bool operator()(Block_type const* a) { return is_less(a, cast<Block_type>(b)); }
    bool operator()(Reference_type const* a) { return is_less(a, cast<Reference_type>(b)); }
    bool operator()(Record_type const* a) { return is_less(a, cast<Record_type>(b)); }
    bool operator()(Void_type const* a) { return false; }

    // network specific types
    bool operator()(Layout_type const* a) { return is_less(a, cast<Layout_type>(b)); }
    bool operator()(Context_type const* a) { return false; }
    bool operator()(Table_type const* a) { return is_less(a, cast<Table_type>(b)); }
    bool operator()(Flow_type const* a) { return is_less(a, cast<Flow_type>(b)); }
    bool operator()(Port_type const* a) { return false; }
    bool operator()(Key_type const* a) { return false; }
  };

  std::type_index t1 = typeid(*a);
  std::type_index t2 = typeid(*b);
  if (t1 < t2)
    return true;
  if (t2 < t1)
    return false;
  return apply(a, Fn{b});
}


// -------------------------------------------------------------------------- //
// Comparison of values


// FIXME: Use a visitor for values. Also, push this into
// a header file somewhere.
bool
is_less(Value const& a, Value const& b)
{
  if (a.kind() < b.kind())
    return true;
  if (b.kind() < a.kind())
    return false;

  switch (a.kind()) {
    case error_value:
      return false;

    case integer_value:
      return a.get_integer() < b.get_integer();

    case function_value: {
      std::less<void const*> cmp;
      return cmp(a.get_function(), b.get_function());
    }

    case reference_value:
      return is_less(*a.get_reference(), *b.get_reference());

    case array_value:
    case tuple_value:
      // FIXME: Implement me!
      return false;
  }
  throw std::runtime_error("unhandled value");
}


// -------------------------------------------------------------------------- //
// Comparison of expressions


inline bool
is_less(Literal_expr const* a, Literal_expr const* b)
{
  return is_less(a->value(), b->value());
}


// Compare two decl expressions based on the identity
// of the referred-to declarations.
inline bool
is_less(Decl_expr const* a, Decl_expr const* b)
{
  std::less<void const*> cmp;
  return cmp(a->declaration(), b->declaration());
}


// FIXME: Actually implement this!
bool
is_less(Expr const* a, Expr const* b)
{
  struct Fn
  {
    Expr const* b;

    bool operator()(Literal_expr const* a) { return is_less(a, cast<Literal_expr>(b)); }
    bool operator()(Id_expr const* a) { lingo_unreachable(); }
    bool operator()(Decl_expr const* a) { return is_less(a, cast<Decl_expr>(b));; }
    bool operator()(Add_expr const* a) { lingo_unreachable(); }
    bool operator()(Sub_expr const* a) { lingo_unreachable(); }
    bool operator()(Mul_expr const* a) { lingo_unreachable(); }
    bool operator()(Div_expr const* a) { lingo_unreachable(); }
    bool operator()(Rem_expr const* a) { lingo_unreachable(); }
    bool operator()(Neg_expr const* a) { lingo_unreachable(); }
    bool operator()(Pos_expr const* a) { lingo_unreachable(); }
    bool operator()(Eq_expr const* a) { lingo_unreachable(); }
    bool operator()(Ne_expr const* a) { lingo_unreachable(); }
    bool operator()(Lt_expr const* a) { lingo_unreachable(); }
    bool operator()(Gt_expr const* a) { lingo_unreachable(); }
    bool operator()(Le_expr const* a) { lingo_unreachable(); }
    bool operator()(Ge_expr const* a) { lingo_unreachable(); }
    bool operator()(And_expr const* a) { lingo_unreachable(); }
    bool operator()(Or_expr const* a) { lingo_unreachable(); }
    bool operator()(Not_expr const* a) { lingo_unreachable(); }
    bool operator()(Call_expr const* a) { lingo_unreachable(); }
    bool operator()(Dot_expr const* a) { lingo_unreachable(); }
    bool operator()(Field_expr const* a) { lingo_unreachable(); }
    bool operator()(Method_expr const* a) { lingo_unreachable(); }
    bool operator()(Index_expr const* a) { lingo_unreachable(); }
    bool operator()(Value_conv const* a) { lingo_unreachable(); }
    bool operator()(Block_conv const* a) { lingo_unreachable(); }
    bool operator()(Promotion_conv const* a) { lingo_unreachable(); }
    bool operator()(Demotion_conv const* a) { lingo_unreachable(); }
    bool operator()(Default_init const* a) { lingo_unreachable(); }
    bool operator()(Copy_init const* a) { lingo_unreachable(); }
    bool operator()(Reference_init const* a) { lingo_unreachable(); }
    bool operator()(Field_name_expr const* a) { lingo_unreachable(); }
    bool operator()(Field_access_expr const* a) { lingo_unreachable(); }
    bool operator()(Reinterpret_cast const* a) { lingo_unreachable(); }
  };

  std::type_index t1 = typeid(*a);
  std::type_index t2 = typeid(*b);
  if (t1 < t2)
    return true;
  if (t2 < t1)
    return false;
  return apply(a, Fn{b});
}

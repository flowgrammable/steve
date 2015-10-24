// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "steve/convert.hpp"
#include "steve/expr.hpp"
#include "steve/type.hpp"
#include "steve/decl.hpp"

namespace steve
{

// Returns the common type of the converted pair.
Type const* 
Converted_pair::type() const
{
  return first->type();
}


namespace
{

// -------------------------------------------------------------------------- //
//                            Type promotions


// Performs a boolean promotion.
//
// A value of type `bool` can be converted to a value of type `int`
// such that `false` is 0 and `true` is one.
Expr const*
boolean_promotion(Expr const* e, Boolean_type const*)
{
  return make_convert_expr(e->location(), get_int_type(), boolean_prom, e);
}


// Performs integer promotion, if possible. 
//
// A value of enumeration type can be converted to value of its 
// underlying type. Note that this conversion is conceptual;
// it does not alter the bit pattern of the source value.
Expr const*
enumeration_promotion(Expr const* e, Enum_type const* t)
{
  Type const* t1 = t->decl()->base();
  return make_convert_expr(e->location(), t1, enumeration_prom, e);
}


// Apply promotions, if any.
Expr const*
type_promotion(Expr const* e, Type const* t)
{
  if (Boolean_type const* t1 = as<Boolean_type>(t))
    return boolean_promotion(e, t1);
  if (Enum_type const* t1 = as<Enum_type>(t))
    return enumeration_promotion(e, t1);
  return e;
}


// -------------------------------------------------------------------------- //
//                           Type conversions


// Returns the type of an integer expression.
Integer_type const*
integer_expr_type(Expr const* e)
{
  lingo_assert(is_integer_expr(e));
  return cast<Integer_type>(e->type());
}


// Returns a new integer type with the precision and sign of `t`,
// but a different byte order.
inline Integer_type const*
change_byte_order(Integer_type const* t, Integer_order k)
{
  return get_integer_type(t->precision(), t->sign(), k);
}


// Returns a new integer type with the precision and byte order 
// of `t`, but a different sign.
inline Integer_type const*
change_sign(Integer_type const* t, Integer_sign s)
{
  return get_integer_type(t->precision(), s, t->order());
}


// Returns true if `src` can be widended to `dst`. This is
// the case when `src` and `dst` have the same byte order
// and sign, and `dst` has precision greater than or equal
// to that of `src`.
inline bool
can_widen(Integer_type const* src, Integer_type const* dst)
{
  return src->order() == dst->order()
      && src->sign() == dst->sign()
      && src->precision() <= dst->precision();
}


// Widen an expression to a type having the same byte order
// and precision as that of `e`, but a greater precision.
//
// This is an integer conversion.
Expr const*
widen(Expr const* e, Integer_type const* dst)
{
  lingo_assert(can_widen(integer_expr_type(e), dst));
  return make_convert_expr(e->location(), dst, integer_conv, e);
}


// Convert an expression `e` the given integer type of
// the same precision.
//
// This is an integer conversion.
Expr const*
reinterpret(Expr const* e, Integer_type const* dst)
{
  return make_convert_expr(e->location(), dst, integer_conv, e);
}


// Performs integer conversion, if possible.
//
// A value of integer type can be converted to a value of a 
// different integer type with the byte order whose precision 
// is greater than or equal to that of the source integer.
Expr const*
integer_conversion(Expr const* e, Integer_type const* src, Integer_type const* dst)
{
  // No narrowing conversions are possible.
  if (src->precision() > dst->precision())
    return e;

  // If the precision is less, we can widen to a value of
  // of an integer type the precision and sign of the 
  // destination type, but having the same order as the
  // source type.
  if (src->precision() < dst->precision()) {
    Type const* t = change_byte_order(dst, src->order());
    return make_convert_expr(e->location(), t, integer_conv, e);
  }

  // If the precisions are equal, but the signs are 
  // different, then we can convert to a value with
  // same precision and order as the source, but the
  // sign of the destiniation type.
  if (src->sign() != dst->sign()) {
    Type const* t = change_sign(src, dst->sign());
    return make_convert_expr(e->location(), t, integer_conv, e);
  }

  return e;
}


// Performs tuple conversion, if possible.
//
// A value of tuple type can be converted to the value of a record 
// type, where the type of each member matches the type of the 
// corresponding elements in the tuple value.
Expr const*
record_conversion(Expr const* e, Tuple_type const* src, Record_type const* dst)
{
  Tuple_type const* t = get_tuple_type(dst);
  if (src == t)
    return make_convert_expr(e->location(), dst, record_conv, e);
  else
    return e;
}


// Apply type conversions, if any.
Expr const*
type_conversion(Expr const* e, Type const* src, Type const* dst)
{
  // Check for integer conversions.
  if (Integer_type const* t1 = as<Integer_type>(src))
    if (Integer_type const* t2 = as<Integer_type>(dst))
      return integer_conversion(e, t1, t2);

  // Check for tuple conversions.
  if (Tuple_type const* t1 = as<Tuple_type>(src))
    if (Record_type const* t2 = as<Record_type>(dst))
      return record_conversion(e, t1, t2);

  return e;
}


// -------------------------------------------------------------------------- //
//                          Value transformations


// Perform integer transformation, if possible.s
//
// A value of integer type can be converted to a value of a
// different integer type with the same signedness and precision
// but a different byte ordering.
Expr const*
integer_transformation(Expr const* e, Integer_type const* src, Integer_type const* dst)
{
  if (src->sign() == dst->sign() && src->precision() == dst->precision())
    return make_convert_expr(e->location(), dst, integer_xform, e);
  else
    return e;
}


// Apply value conversions, if any.
Expr const*
value_transformation(Expr const* e, Type const* src, Type const* dst)
{
  if (Integer_type const* t1 = as<Integer_type>(src))
    if (Integer_type const* t2 = as<Integer_type>(dst))
      return integer_transformation(e, t1, t2);

  return e;
}


// Apply conversions to transform `e` into an expression
// of type `dst`. 
Expr const*
perform_conversions(Expr const* e, Type const* dst)
{
  Type const* src = e->type();

  // If the source and destination typs match, no conversion
  // is performed.
  if (src == dst)
    return e;

  // Perform conversions.
  Expr const* c = e;

  c = type_promotion(c, c->type());
  if (c->type() == dst)
    return c;
  
  c = type_conversion(c, c->type(), dst);
  if (c->type() == dst)
    return c;
  
  c = value_transformation(c, c->type(), dst);
  if (c->type() == dst)
    return c;
  
  return nullptr;  
}


} // namespace


// -------------------------------------------------------------------------- //
//                            Implicit conversion


// Applies promotions to `e`, if any.
Expr const*
promote(Expr const* e)
{
  return type_promotion(e, e->type());
}


// Determine a sequence of conversions to `e` in order to make
// it have the destination type `t`. Returns the converted
// expression e.
Expr const* 
convert(Expr const* e, Type const* dst)
{
  // Try to convert.
  if (Expr const* c = perform_conversions(e, dst))
    return c;

  // If, affter applying conversions, the result type must
  // match the destination type. Otherwise, `e` cannot
  // be converted to `dst`.
  error(e->location(), 
        "cannot convert '{}' (type '{}') to '{}'", 
        e, e->type(), dst);
  return nullptr;
}



// -------------------------------------------------------------------------- //
//                          Boolean conversions


Expr const*
convert_to_boolean_type(Expr const* e)
{
  if (is_boolean_expr(e))
    return e;

  // The expression is promoted.
  Expr const* c = promote(e);

  // Integer conversion to booil.
  if (is_integer_expr(c))
    return make_convert_expr(e->location(), get_bool_type(), boolean_conv, c);

  // Can't find a suitable conversion.
  error(e->location(), 
        "cannot convert '{}' (of type '{}') to 'bool'", 
        e, e->type());
  return nullptr;
}


// -------------------------------------------------------------------------- //
//                            Common type

namespace
{

// Apply the rules for converting two integer expressions to
// their common type.
Converted_pair
integer_common_type(Expr const* c1, Expr const* c2)
{
  Integer_type const* t1 = integer_expr_type(c1);
  Integer_type const* t2 = integer_expr_type(c2);

  // Apply byte order conversions, preferring native.
  // Update the types after conversion.
  if (!t1->is_native_order()) {
    Integer_type const* t = change_byte_order(t1, native_order);
    c1 = integer_transformation(c1, t1, t);
  } 
  if (!t2->is_native_order()) {
    Integer_type const* t = change_byte_order(t2, native_order);
    c2 = integer_transformation(c2, t2, t);
  }
  t1 = integer_expr_type(c1);
  t2 = integer_expr_type(c2);

  // If the byte orders differ, then there is no common type.
  // Basically, we don't prefer MSBF or LSBF over the other.
  if (t1->order() != t2->order()) {
    error(c1->location(), "different byte order for '{}' for '{}'", t1, t2);
    return {};
  }

  // If, after conversion the types are the same, we're done.
  if (t1 == t2)
    return {c1, c2};

  // Convert to the widest type.
  if (t1->sign() == t2->sign()) {
    if (t1->precision() < t2->precision())
      c1 = widen(c1, t2);
    if (t2->precision() < t1->precision())
      c2 = widen(c2, t1);

    // We guarantee that the reuslt of this conversion
    // gives c1 and c2 the same type.
    return {c1, c2};
  }

  // Prefer to convert to unsigned of the greatest precision.
  // Note that one of these cases must be true.
  int prec = std::max(t1->precision(), t2->precision());
  Integer_type const* t = get_integer_type(prec, unsigned_int, t1->order());
  c1 = reinterpret(c1, t);
  c2 = reinterpret(c2, t);

  // We guarantee a common type here.
  lingo_assert(c1->type() == c2->type());
  
  return {c1, c2};
}


} // namespace


// Return a pair of expressions converted to the common type.
Converted_pair
convert_to_common_type(Expr const* e1, Expr const* e2)
{
  if (e1->type() == e2->type())
    return {e1, e2};

  // Promote both expressions.
  Expr const* c1 = type_promotion(e1, e1->type());
  Expr const* c2 = type_promotion(e2, e2->type());
  if (c1->type() == c2->type())
    return {c1, c2};

  // If e1 and e2 are integer expressions...
  if (is<Integer_type>(c1->type()))
    if (is<Integer_type>(c2->type()))
      return integer_common_type(c1, c2);

  // TODO: Support other formulae for determining common types.

  error(e1->location(), "no common type for '{}' and '{}'", c1->type(), c2->type());
  return {};
}


// Returns the common type of the expressions `e1` and `e2`.
Type const*
common_type(Expr const* e1, Expr const* e2)
{
  if (Converted_pair p = convert_to_common_type(e1, e2))
    return p.first->type();
  return nullptr;
}



// -------------------------------------------------------------------------- //
//                          Argument conversion


namespace
{

// Check that the call site does not provide too many arguments.
bool
check_too_many_args(Location loc, Expr_seq const& args, Type_seq const& parms)
{
  if (args.size() > parms.size()) {
    error(loc, 
          "too many arguments for call (expected {} but got {})",
          parms.size(), args.size());
    return false;
  }
  return true;
}


// Check that the call site does not provide too few arguments.
bool
check_too_few_args(Location loc, Expr_seq const& args, Type_seq const& parms)
{
  if (args.size() < parms.size()) {
    error(loc, 
          "not enough arguments for call (expected {} but got {})",
          parms.size(), args.size());
    return false;
  }
  return true;
}


// Convert a single argument.
Expr const*
convert_argument(int n, Expr const* a, Type const* p)
{
  if (Expr const* c = perform_conversions(a, p))
    return c;

  // Provide a nice diagnostic.
  error(a->location(),
        "cannot convert argument {} (type '{}') to '{}'", 
        n + 1, a->type(), p);
  return nullptr;
}


// Convert each argument in turn.  
Converted_args
convert_arguments(Expr_seq const& args, Type_seq const& parms)
{
  bool ok = true;
  Converted_args err { nullptr };
  Converted_args result(args.size());
  for (std::size_t i = 0; i < args.size(); ++i) {
    result[i] = convert_argument(i, args[i], parms[i]);
    if (!result[i])
      ok = false;
  }

  if (ok)
    return result;
  else
    return err;

}

} // namespace


// Convert a sequence of arguments to a corresponding sequence
// of parameter types, if possible.
//
// Each argument shall be converted, in turn the type of the
// corresponding parameter.
Converted_args
convert_to_parameter_types(Location loc, Expr_seq const& args, Type_seq const& parms)
{
  // Make sure we have just enough arguments.
  Converted_args err { nullptr };
  if (!check_too_many_args(loc, args, parms))
    return err;
  if (!check_too_few_args(loc, args, parms))
    return err;

  return convert_arguments(args, parms);
}


} // namespace steve

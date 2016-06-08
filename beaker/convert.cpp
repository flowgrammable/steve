// Copyright (c) 2015 Andrew Sutton
// All rights reserved

#include "beaker/convert.hpp"
#include "beaker/type.hpp"
#include "beaker/expr.hpp"
#include "beaker/decl.hpp"

#include <iostream>


// Determines how to convert a scalar type to another scalar type.
// TODO: Does not currently convert with bools or chars.
Type const*
get_scalar_conversion_target(Expr* e1, Expr* e2)
{
  assert(e1->type());
  assert(e2->type());
  Type const* t1 = e1->type()->nonref();
  Type const* t2 = e2->type()->nonref();

  // If they're already equal.
  if (t1 == t2)
    return t1;

  // If they're both integers.
  if (is<Integer_type>(t1) && is<Integer_type>(t2))
  {
    Integer_type const* int1 = as<Integer_type>(t1);
    Integer_type const* int2 = as<Integer_type>(t2);

    // Check precision.
    int prec1 = int1->precision();
    int prec2 = int2->precision();
    int largest_prec = prec1;
    if (prec1 < prec2)
      largest_prec = prec2;

    // Check sign.
    Integer_sign sign = signed_int;
    if (int1->is_unsigned() || int2->is_unsigned())
      sign = unsigned_int;

    // Return the integer type with the correct sign and precision.
    return get_integer_type(largest_prec, sign, native_order);
  }

  // If e1 has integer type, try to return that and convert e2 to it later.
  if (!is<Integer_type>(t1) && is<Integer_type>(t2))
    return t2;
  if (is<Integer_type>(t1) && !is<Integer_type>(t2))
    return t1;

  // Default return nullptr.
  return nullptr;
}


// Determines how to convert a scalar type to another scalar type.
// TODO: Does not currently convert with bools or chars.
Type const*
get_scalar_conversion_target(Type const* t1, Type const* t2)
{
  // If they're already equal.
  if (t1 == t2)
    return t1;

  // If they're both integers.
  if (is<Integer_type>(t1) && is<Integer_type>(t2))
  {
    Integer_type const* int1 = as<Integer_type>(t1);
    Integer_type const* int2 = as<Integer_type>(t2);

    // Check precision.
    int prec1 = int1->precision();
    int prec2 = int2->precision();
    int largest_prec = prec1;
    if (prec1 < prec2)
      largest_prec = prec2;

    // Check sign.
    Integer_sign sign = unsigned_int;
    if (int1->is_signed() || int2->is_signed())
      sign = signed_int;

    // Return the integer type with the correct sign and precision.
    return get_integer_type(largest_prec, sign, native_order);
  }

  // If e1 has integer type, try to return that and convert e2 to it later.
  if (!is<Integer_type>(t1) && is<Integer_type>(t2))
    return t2;
  if (is<Integer_type>(t1) && !is<Integer_type>(t2))
    return t1;

  // Default return nullptr.
  return nullptr;
}


// If e has reference type T&, return a conversion
// to the value type T. Otherwise, no conversions
// are required and e is returned.
Expr*
convert_to_value(Expr* e)
{
  if (Reference_type const* t = as<Reference_type>(e->type())) {
    // Do not perform value conversion on types that get translated to opaque type.
    if (is_opaque_translated_type(t->nonref()))
      return e;
    // Otherwise, perform regular value conversion.
    else
      return new Value_conv(t->nonref(), e);
  }
  else
    return e;
}


// If e has type T[N], return a conversion to
// the chunk T[]. Otherwise, just return e.
Expr*
convert_to_block(Expr* e)
{
  if (Array_type const* a = as<Array_type>(e->type()))
    return new Block_conv(get_block_type(a->type()), e);
  else
    return e;
}


// Perform integer conversion
//
// FIXME: All conversions are brute force conversions from one integer type to
//        another. Loss of precision is unhandled.
//
// TODO: see if truncation of integers does not result in loss of precision.
//       Is this even possible on non-constant integers? Seems unlikely.
//
// - Promotion of e's type to t if e's precision is less
//   than t's precision.
//
// - Truncation of e's type to t if e's value can fit within the
//   range possible by t's type.
//
// TODO: support signed and unsigned conversions
//
// - Signed conversion if e is unsigned but it needs to be signed.
//
// Allow LLVM to do the conversions for us.
Expr*
convert_integer_type(Expr* e, Integer_type const* dst)
{
  Integer_type const* src = as<Integer_type>(e->type());
  assert(src);

  return new Promotion_conv(dst, e);
}


// Converting ports to integer types allows us to form keys using port
// identifiers.
Expr*
convert_to_integer_type(Expr* e, Integer_type const* dst)
{
  return new Integer_conv(dst, e);
}


// Find a conversion from e to t. If no such
// conversion exists, return nullptr. Diagnostics
// a better handled in the calling context.
Expr*
convert(Expr* e, Type const* t)
{
  // If e has type t, no conversions are needed.
  if (e->type() == t)
    return e;
  Expr* c = e;

  // Ojbect/value transformations

  // If t is a non-reference type, try an
  // object-to-value conversion:
  //
  //    A& -> B
  if (!is<Reference_type>(t)) {
    c = convert_to_value(c);

    if (c->type() == t)
      return c;
  }

  // Type conversions

  if (is<Port_type>(c->type()) && is<Integer_type>(t)) {
    c = convert_to_integer_type(c, as<Integer_type>(t));

    if (c->type() == t)
      return c;
  }

  // Integer conversions
  if (is<Integer_type>(c->type()) && is<Integer_type>(t)) {
    c = convert_integer_type(c, as<Integer_type>(t));

    if (c->type() == t)
      return c;
  }

  // Determine if we can apply an array-to-chunk
  // conversion. This is the case when we have
  //
  //    A[N] -> B[]
  if (is<Block_type>(t)) {
    c = convert_to_block(c);
    if (c->type() == t)
      return c;
  }

  // If we've exhaused all possible conversions
  // without matching the type, then just return
  // nullptr.

  return nullptr;
}


// Convert a seequence of arguments to a corresponding
// parameter type. The conversion is successful only
// when all individual conversions are successful.
// This is the case when the result vector contains
// no null pointers.
Expr_seq
convert(Expr_seq const& args, Type_seq const& parms)
{
  Expr_seq conv(args.size(), nullptr);

  // If there is a mismatch in size, just return.
  //
  // TODO: Handle variadic funcitons and default
  // arguments.
  if (args.size() < parms.size())
    return conv;
  if (parms.size() < args.size())
    return conv;

  // Convert each argument in turn.
  //
  // TODO: Note that we actually perform initialization
  // for each argument. How does that interoperate with
  // conversions?
  for (std::size_t i = 0; i < parms.size(); ++i)
    conv[i] = convert(args[i], parms[i]);

  return conv;
}

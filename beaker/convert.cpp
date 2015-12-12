// Copyright (c) 2015 Andrew Sutton
// All rights reserved

#include "beaker/convert.hpp"
#include "beaker/type.hpp"
#include "beaker/expr.hpp"
#include "beaker/decl.hpp"

#include <iostream>


// If e has reference type T&, return a conversion
// to the value type T. Otherwise, no conversions
// are required and e is returned.
Expr*
convert_to_value(Expr* e)
{
  if (Reference_type const* t = as<Reference_type>(e->type()))
    return new Value_conv(t->nonref(), e);
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
// - Unsigned conversion if e is a signed positive value which can fit within
//   the range possible by t's type.
//
// - Signed conversion if e is unsigned.
Expr*
convert_integer_type(Expr* e, Integer_type const* dst)
{
  Integer_type const* src = as<Integer_type>(e->type());
  assert(src);

  // Perform narrowing conversion.
  // This truncates the expression to the dst type.
  if (src->precision() > dst->precision()) {
    return new Demotion_conv(dst, e);
  }

  // If the precision is less, we can widen to a value of
  // of an integer type to the dst precision.
  if (src->precision() < dst->precision()) {
    return new Promotion_conv(dst, e);
  }

  return e;
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

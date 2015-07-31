// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#ifndef STEVE_CONVERT_HPP
#define STEVE_CONVERT_HPP

// This module defines conversions and conversion sequences.

#include "steve/prelude.hpp"

namespace steve
{

// The conversion kind enumerates the kind of conversion 
// being applied. Note that the specific properties of
// the conversion depend on the source and target types.
enum Conversion_kind
{
  // Type promotions
  boolean_prom,       // Promotion of enum to base type
  enumeration_prom,   // Promotion of enum to base type
  
  // Type conversions
  boolean_conv,       // Conversion to bool
  integer_conv,       // Sign or precision conversion
  record_conv,        // Convert a tuple to a record
  
  // Value transformations
  integer_xform,      // Byte order transformation
};


// A converted argument sequence is a sequence of arguments
// that have been convertted to a set of parameter types.
struct Converted_args : Expr_seq
{
  using Expr_seq::Expr_seq;
};


// A converted piar is a pair of converted expressions
// resulting from the conversion to a common type. Note
// conversion to common type can fail, in which case,
// both members are null.
struct Converted_pair : std::pair<Expr const*, Expr const*>
{
  using std::pair<Expr const*, Expr const*>::pair;

  // Contextually converts to `true` when conversion
  // has succeeded.
  explicit operator bool() { return first != nullptr; }

  Type const* type() const;
};


Expr const*    promote(Expr const*);
Expr const*    convert(Expr const*, Type const*);
Expr const*    convert_to_boolean_type(Expr const*);
Converted_args convert_to_parameter_types(Location, Expr_seq const&, Type_seq const&);
Converted_pair convert_to_common_type(Expr const*, Expr const*);
Type const*    common_type(Expr const*, Expr const*);



} // namespace steve

#endif

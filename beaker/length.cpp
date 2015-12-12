// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "beaker/builder.hpp"
#include "beaker/evaluator.hpp"
#include "beaker/type.hpp"

#include <cmath>
#include <stdexcept>


// -------------------------------------------------------------------------- //
//                              Constant length
//
// Determines if an object type has constant length.
bool has_constant_length(Type const* t)
{
  struct Fn
  {
    bool operator()(Id_type const* t) { return false; }
    bool operator()(Boolean_type const* t) { return true; }
    bool operator()(Character_type const* t) { return true; }
    bool operator()(Integer_type const* t) { return true; }
    bool operator()(Function_type const* t) { return false; }
    bool operator()(Block_type const* t) { return false; }
    bool operator()(Array_type const* t) { return true; }
    bool operator()(Reference_type const* t) { return true; }

    bool operator()(Record_type const* t)
    {
      for (Decl* d : t->declaration()->fields())
        if (!has_constant_length(d->type()))
          return false;
      return true;
    }

    bool operator()(Void_type const* t)
    {
      return false;
    }

    // network specific types
    bool operator()(Layout_type const* t)
    {
      for (Decl* d : t->declaration()->fields())
        if (!has_constant_length(d->type()))
          return false;
      return true;
    }


    // these should never be called
    bool operator()(Context_type const* t) { throw std::runtime_error("non-const length"); }
    bool operator()(Table_type const* t) { throw std::runtime_error("non-const length"); }
    bool operator()(Flow_type const* t) { throw std::runtime_error("non-const length"); }
    bool operator()(Port_type const* t) { throw std::runtime_error("non-const length"); }
    bool operator()(Key_type const* t) { throw std::runtime_error("non-const length"); }
  };

  return apply(t, Fn());
}



// -------------------------------------------------------------------------- //
//                              Bit precision
//
// Computes the bit precision of a constant-sized type. Behior
// is not defined for types that do not have constant width.

// TODO: There are a lot of computations involving multiples of 8.
// Perhaps we should abstract the notion of bits per byte (CHAR_BIT
// in C/C++) into a separate facility.

int precision(Type const* t)
{
  struct Fn
  {
    // should never be called
    // FIXME: throw exceptions
    int operator()(Id_type const* t) { throw std::runtime_error("unsupported length"); }
    int operator()(Function_type const* t) { throw std::runtime_error("unsupported length"); }
    int operator()(Void_type const* t) { throw std::runtime_error("unsupported length"); }
    int operator()(Context_type const* t) { throw std::runtime_error("unsupported length"); }
    int operator()(Table_type const* t) { throw std::runtime_error("unsupported length"); }
    int operator()(Flow_type const* t) { throw std::runtime_error("unsupported length"); }
    int operator()(Port_type const* t) { throw std::runtime_error("unsupported length"); }
    int operator()(Key_type const* t) { throw std::runtime_error("unsupported length"); }

    // dynamic type
    // FIXME: do this right
    int operator()(Block_type const* t) { return 0; }

    // static type
    int operator()(Boolean_type const* t) { return 8; }
    int operator()(Character_type const* t) { return 8; }
    int operator()(Integer_type const* t) { return t->precision(); }
    int operator()(Array_type const* t) { return t->size(); }
    int operator()(Reference_type const* t) { return precision(t->ref()); }

    int operator()(Record_type const* t)
    {
      int n = 0;
      for (Decl* d : t->declaration()->fields())
        n += precision(d->type());
      return n;
    }

    // network specific types
    int operator()(Layout_type const* t)
    {
      int n = 0;
      for (Decl* d : t->declaration()->fields())
        n += precision(d->type());
      return n;
    }
  };

  return apply(t, Fn());
}


// -------------------------------------------------------------------------- //
//                              Byte length
//
// Returns an expression that computes the byte length
// of an object.


Expr* length(Type const* t)
{
  struct Fn
  {
    // should never be called
    Expr* operator()(Id_type const* t) { throw std::runtime_error("no length type"); }
    Expr* operator()(Function_type const* t) { throw std::runtime_error("no length type"); }
    Expr* operator()(Void_type const* t) { throw std::runtime_error("no length type"); }
    Expr* operator()(Context_type const* t) { throw std::runtime_error("no length type"); }
    Expr* operator()(Table_type const* t) { throw std::runtime_error("no length type"); }
    Expr* operator()(Flow_type const* t) { throw std::runtime_error("no length type"); }
    Expr* operator()(Port_type const* t) { throw std::runtime_error("no length type"); }
    Expr* operator()(Key_type const* t) { throw std::runtime_error("no length type"); }

    // dynamic type
    // FIXME: do this right
    Expr* operator()(Block_type const* t) { return zero(); }

    // static type
    Expr* operator()(Boolean_type const* t) { return one(); }
    Expr* operator()(Character_type const* t) { return one(); }

    Expr* operator()(Integer_type const* t)
    {
      double p = t->precision();
      double w = 8;
      double b = std::ceil(p / w);
      return make_int(b);
    }

    Expr* operator()(Array_type const* t)
    {
      double p = t->size();
      double w = 8;
      double b = std::ceil(p / w);
      return make_int(b);
    }

    Expr* operator()(Reference_type const* t)
    {
      return length(t->ref());
    }

    Expr* operator()(Record_type const* t)
    {
      Evaluator eval;
      Expr* e = zero();
      for (Decl* d : t->declaration()->fields()) {
        Type const* t1 = d->type();

        // If member is constant, just add in the constant value
        if (has_constant_length(t1))
          e = add(e, make_int(precision(t1)));

        // Otherwise, we have to form a call to the function
        // that would compute this type.
        else
          // FIXME: Do this right!
          e = add(e, zero());
      }


      // Compute ceil(e / 8).
      Expr* b = make_int(8); // bits per byte
      Expr* r = div(sub(add(e, b), one()), b);

      // Try folding the result. If it works, good. If not,
      // just return the previously computed expression.
      //
      // TODO: Maximally reduce the expression so that we only
      // add the constant bits to the non-constant bits. Since
      // addition is associative and commutative, we can
      // partition the sequence of terms into constants and
      // non-constants, and then sum the constant parts.
      try {
        Value v = eval.eval(r);
        if (v.is_integer())
          return make_int(v.get_integer().gets());
        else
          throw std::runtime_error("failed to synth length");
      }
      catch(...) {
        return r;
      }
    }

    // network specific types
    Expr* operator()(Layout_type const* t)
    {
      Evaluator eval;
      Expr* e = zero();
      for (Decl* d : t->declaration()->fields()) {
        Type const* t1 = d->type();

        // If member is constant, just add in the constant value
        if (has_constant_length(t1))
          e = add(e, make_int(precision(t1)));

        // Otherwise, we have to form a call to the function
        // that would compute this type.
        else
          // FIXME: Do this right!
          e = add(e, zero());
      }


      // Compute ceil(e / 8).
      Expr* b = make_int(8); // bits per byte
      Expr* r = div(sub(add(e, b), one()), b);

      // Try folding the result. If it works, good. If not,
      // just return the previously computed expression.
      //
      // TODO: Maximally reduce the expression so that we only
      // add the constant bits to the non-constant bits. Since
      // addition is associative and commutative, we can
      // partition the sequence of terms into constants and
      // non-constants, and then sum the constant parts.
      try {
        Value v = eval.eval(r);
        if (v.is_integer())
          return make_int(v.get_integer().gets());
        else
          throw std::runtime_error("failed to synth length");
      }
      catch(...) {
        return r;
      }
    }
  };

  return apply(t, Fn());
}


// -------------------------------------------------------------------------- //
//                             Function synthesis

// This module is responsible for the synthesis of a length function
// for a given type. The language requests the lookup and possible
// synthesis of these functions in particular contexts, but that
// lookup is always expressed in terms of type.
//
// The general definition of a length function is:
//
//    def: lengthof(T t) -> uint{ ... }
//
// where `T` is the type under consideration.
//
// TODO: Make that a constant reference to T so we don't try
// to copy the record. Naturally, this means we now have to
// support reference types and qualified types. Ugh.



// Build a length function with the following definition.
//
//    def lengthof(t : T) { return <length T>; }
//
// where <length T> is the length of the given type (see
// `length` above).
// struct Synth_fn
// {
//   template<typename T>
//   Decl* operator()(T const* t) { return dispatch(t); }

//   // Fail on non-object types.
//   template<typename T>
//     static typename std::enable_if<!is_object_type<T>(), Decl*>::type
//   dispatch(T const* t)
//   {
//     throw std::runtime_error("unreachable synth");
//   }

//   template<typename T>
//     static typename std::enable_if<is_object_type<T>(), Decl*>::type
//   dispatch(T const* t)
//   {
//     Stmt* r = ret(length(t));
//     Decl* p = make_parm("t", t);
//     return make_fn("lengthof", {p}, get_integer_type(), {r});
//   }
// };


// Synthesize a length function for the given object type.
// Behavior is undefined if `t` is not an object type.
// Decl*
// synthesize_length(Type const* t)
// {
//   assert(is_object_type(t));
//   Synth_fn f;
//   return apply(t, f);
// }


// Returns an expression that computes the length in bytes
// of a packet.
Expr*
get_length(Expr const* e)
{
  return length(e->type());
}

// Returns an expression that computes the length of a
// type in bytes
Expr*
get_length(Type const* t)
{
  return length(t);
}


Expr*
get_length(Layout_decl const* layout)
{
  Evaluator eval;

  Expr* e = 0;
  for (Decl* d : layout->fields()) {
    Type const* t1 = d->type();

    // If member is constant, just add in the constant value
    if (has_constant_length(t1))
      e = add(e, make_int(precision(t1)));

    // Otherwise, we have to form a call to the function
    // that would compute this type.
    else {
      // FIXME: Do this right!
      throw std::runtime_error("unimplemented dynamic length calc.");
      e = add(e, zero());
    }
  }


  // Compute ceil(e / 8).
  Expr* b = make_int(8); // bits per byte
  Expr* r = div(sub(add(e, b), one()), b);

  // Try folding the result. If it works, good. If not,
  // just return the previously computed expression.
  //
  // TODO: Maximally reduce the expression so that we only
  // add the constant bits to the non-constant bits. Since
  // addition is associative and commutative, we can
  // partition the sequence of terms into constants and
  // non-constants, and then sum the constant parts.
  try {
    Value v = eval.eval(r);
    if (v.is_integer())
      return make_int(v.get_integer());
    else
      throw std::runtime_error("failed to synth length");
  }
  catch(...) {
    return r;
  }
}


// The length of a field is the length
// of the type of the field name expr.
Expr*
get_length(Field_name_expr const* e)
{
  return get_length(e->declarations().back()->type());
}


// Gets the length of a sequence of declarations
// by summing the length of their types in turn
Expr*
get_length(Decl_seq const& d)
{
  Expr* length = zero();

  for (auto decl : d) {
    assert(decl->type());
    Expr* sublen = get_length(decl->type());
    length = add(length, sublen);
  }

  return length;
}

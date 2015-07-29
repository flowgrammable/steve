// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#ifndef STEVE_VALUE_HPP
#define STEVE_VALUE_HPP

// The value module defines the representation of values
// formed during the evaluation of expressions. 
//
// Note that the Value system has the same logical organization
// as every other term in the language. Here, we use a discriminated
// union instead of a hierarchy in order to try avoid unnecessary
// indirections, and because the set of values is very small.


#include "steve/prelude.hpp"


namespace steve
{

struct Value;


// Enumerate the different kinds of values.
enum Value_kind
{
  error_value,     // An erroneos computation
  integer_value,   // An integer value
  composite_value, // A sequence of values
};


// The error value represents an error in computation.
struct Error_value { };


// An integer value.
using Integer_value = Integer;


// A fixed-length sequence of values. This represents
// values of tuple and array type.
struct Composite_value
{
  explicit Composite_value(int);
  Composite_value(Composite_value const&);
  Composite_value(Composite_value&&);
  ~Composite_value();

  // Iterators
  Value const* begin() const;
  Value const* end() const;

  int    size;
  Value* elems;
};


// The underlying representation of a value. Note that
// all construction and destruction is managed by the
// Value class (since that's where the discriminator
// is).
union Value_impl
{
  Value_impl() { }
  ~Value_impl() { }

  Error_value     x;
  Integer_value   z;
  Composite_value c;
};


// The value class stores the abstract representation of
// a value of an arbitrary type. This is a (relatively)
// simple data structure that stores scalar values (e.g., 
// integers) and composite values (e.g., tuples of values)
// in a tree-like data structure. A special kind of
// value, the error value is used to indicate errors
// that arise during evaluation.
struct Value
{
  static Value error;

  Value();
  Value(Error_value);
  
  Value(Integer_value const&);
  Value(Integer_value&&);
  
  Value(Composite_value const&);
  Value(Composite_value&&);

  Value(Value const&);
  Value(Value&&);

  Value& operator=(Value const&);
  Value& operator=(Value&&);
  
  ~Value();

  explicit operator bool() const { return !is_error(); }

  Value_kind kind() const { return kind_; }
  bool is_error() const { return kind_ == error_value; }
  bool is_integer() const { return kind_ == integer_value; }
  bool is_composite() const { return kind_ == composite_value; }

  bool                   get_boolean() const;
  Integer_value const&   get_integer() const;
  Composite_value const& get_composite() const;

private:
  void init(Value const&);
  void init(Value&&);
  void clear();

private:
  Value_kind kind_;
  Value_impl impl_;
};


// Initialize the value to have `n` elements. These
// elements are default initialized (so error values).
inline
Composite_value::Composite_value(int n)
  : size(n), elems(new Value[size])
{ }


// Copy initialize with the values of `c`.
inline
Composite_value::Composite_value(Composite_value const& c)
  : size(c.size), elems(new Value[size])
{
  std::copy(c.elems, c.elems + size, elems);
}


// Move initialize with the values of `c`.
inline
Composite_value::Composite_value(Composite_value&& c)
  : size(c.size), elems(c.elems)
{
  c.size = 0;
  c.elems = nullptr;
}


inline
Composite_value::~Composite_value()
{
  delete [] elems;
}


inline Value const* 
Composite_value::begin() const 
{ 
  return elems; 
}


inline Value const* 
Composite_value::end() const
{ 
  return elems + size; 
}


inline
Value::Value()
  : kind_(error_value)
{
  new (&impl_.x) Error_value();
}


inline
Value::Value(Integer_value const& n)
  : kind_(integer_value)
{
  new (&impl_.z) Integer_value(n);
}


inline
Value::Value(Integer_value&& n)
  : kind_(integer_value)
{
  new (&impl_.z) Integer_value(std::move(n));
}


inline
Value::Value(Composite_value const& c)
  : kind_(composite_value)
{
  new (&impl_.c) Composite_value(c);
}


inline
Value::Value(Composite_value&& c)
  : kind_(composite_value)
{
  new (&impl_.c) Composite_value(std::move(c));
}


inline
Value::Value(Value const& v)
  : kind_(v.kind_)
{
  init(v);
}


inline
Value::Value(Value&& v)
  : kind_(v.kind_)
{
  init(std::move(v));
}


inline Value&
Value::operator=(Value const& v)
{
  clear();
  kind_ = v.kind_;
  init(v);
  return *this;
}


inline Value&
Value::operator=(Value&& v)
{
  clear();
  kind_ = v.kind_;
  init(std::move(v));
  return *this;
}


inline
Value::~Value()
{
  clear();
}


// Returns the truth-value represntation of an integer
// value. That is returns true when non-zero and false
// otherwise.
inline bool
Value::get_boolean() const
{
  return get_integer().truth_value();
}


// Returns the integer representation of the value.
inline Integer_value const&
Value::get_integer() const
{
  lingo_assert(is_integer());
  return impl_.z;
}


// Returns the integer representation of the value.
inline Composite_value const& 
Value::get_composite() const
{
  lingo_assert(is_composite());
  return impl_.c;
}


inline void
Value::init(Value const& v)
{
  switch (kind_) {
    case error_value:
      new (&impl_.x) Error_value(v.impl_.x);
      break;
    case integer_value: 
      new (&impl_.z) Integer_value(v.impl_.z);
      break;
    case composite_value: 
      new (&impl_.c) Composite_value(v.impl_.c);
      break;
  }
}


inline void
Value::init(Value&& v)
{
  switch (kind_) {
    case error_value:
      new (&impl_.x) Error_value(std::move(v.impl_.x));
      break;
    case integer_value: 
      new (&impl_.z) Integer_value(std::move(v.impl_.z));
      break;
    case composite_value: 
      new (&impl_.c) Composite_value(std::move(v.impl_.c));
      break;
  }
}


inline void
Value::clear()
{
  switch (kind_) {
    case error_value:
      impl_.x.~Error_value();
      break;
    case integer_value: 
      impl_.z.~Integer_value();
      break;
    case composite_value: 
      impl_.c.~Composite_value();
      break;
  }
}


// -------------------------------------------------------------------------- //
//                               Operations


bool operator==(Value const&, Value const&);
bool operator<(Value const&, Value const&);


inline bool
operator!=(Value const& a, Value const& b)
{
  return !(a == b);
}


inline bool
operator>(Value const& a, Value const& b)
{
  return !(a == b);
}


inline bool
operator<=(Value const& a, Value const& b)
{
  return !(a == b);
}


inline bool
operator>=(Value const& a, Value const& b)
{
  return !(a == b);
}


// -------------------------------------------------------------------------- //
//                              Support functions

// Don't mark values for garbage collection.
inline void
mark(Value const&) { }


void print(Printer& p, Value const&);
void debug(Printer& p, Value const&);


} // namespace steve


#endif

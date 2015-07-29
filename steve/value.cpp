// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "value.hpp"


namespace steve
{


// The static error value.
Value Value::error{};


// -------------------------------------------------------------------------- //
//                           Relations


bool
operator==(Value const& a, Value const& b)
{
  if (a.kind() != b.kind())
    return false;
  switch (a.kind()) {
    case error_value:
      // There is only one error value, so this is true.
      return true;
    
    case integer_value:
      // Two integers are equal when this is true.
      return a.get_integer() == b.get_integer();
    
    case composite_value: {
      // Composite values are compared for memberwise equality.
      Composite_value const& a0 = a.get_composite();
      Composite_value const& b0 = b.get_composite();
      if (a0.size != b0.size)
        return false;
      else
        return std::equal(a0.elems, a0.elems + a0.size, b0.elems);
    }
  }
  lingo_unreachable();
}


bool
operator<(Value const& a, Value const& b)
{
  if (a.kind() < b.kind())
    return true;
  if (b.kind() < a.kind())
    return false;
  
  switch (a.kind()) {
    case error_value:
      // There is only one error value, so this is false.
      return false;
    
    case integer_value:
      // Two integers are equal when this is true.
      return a.get_integer() < b.get_integer();
    
    case composite_value: {
      // Composite values are compared for lexicographically.
      Composite_value const& a0 = a.get_composite();
      Composite_value const& b0 = b.get_composite();
      return std::lexicographical_compare(a0.elems, a0.elems + a0.size, 
                                          b0.elems, b0.elems + b0.size);
    }
  }
  lingo_unreachable();
}


// -------------------------------------------------------------------------- //
//                                Output


// TODO: Recursively print an object!
void
print(Printer& p, Value const& v)
{
  switch (v.kind()) {
  case error_value: 
    print(p, "<error>");
    return;
  
  case integer_value: 
    print(p, v.get_integer());
    return;
  
  case composite_value:
    print(p, '{');
    print_nested(p, v.get_composite());
    print(p, '}');
    return;
  }
  lingo_unreachable();
}


void
debug(Printer& p, Value const& v)
{
  print(p, v);
}


} // namespace steve

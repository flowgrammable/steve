// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

// Tests for unary and binary expression.

#include "utility.hpp"

#include <iostream>

void 
test_1()
{
  Decl_seq parms {
    make_parm("n", get_int_type()),
    make_parm("b", get_bool_type())
  };
  Decl const* fn = make_fn("f1", parms);


  // Various arguments.
  Expr const* u32 = make_int(0, get_uint_type());


  Expr const* c1 = call(fn, {zero(), truth()});
  lingo_assert(c1);
  debug(c1); // No conversions.


  Expr const* c2 = call(fn, {u32, truth()});
  lingo_assert(c2);
  debug(c2); // 1. Conversion to signed.


  Expr const* c3 = call(fn, {truth(), zero()}); // error
  lingo_assert(!c3);
}


void 
test_2()
{
  Decl_seq parms {
    make_parm("n", get_reference_type(get_int_type())),
    make_parm("b", get_bool_type())
  };
  Decl const* fn = make_fn("f1", parms);


  Expr const* c1 = call(fn, {zero(), truth()});
}


int
main()
{
  // test_1();
  test_2();
}

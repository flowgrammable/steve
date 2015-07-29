// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "utility.hpp"

#include <iostream>


// TODO: Actually test evaluation.


// Integer conversions.
void
test_1()
{
  // Check integer widening.
  Expr const* e1 = make_int(1, get_short_type());
  Expr const* c1 = convert(e1, get_long_type());
  lingo_assert(c1);
  debug(c1);
  debug(c1->type());

  // Check sign conversion with widening.
  Expr const* c2 = convert(e1, get_ulong_type());
  lingo_assert(c2);
  debug(c2);
  debug(c2->type());

  // Check just sign conversion
  Expr const* c3 = convert(e1, get_ushort_type());
  lingo_assert(c3);
  debug(c3);
  debug(c3->type());

  // Make sure that we don't narrow.
  Expr const* e2 = make_int(5);
  Expr const* c4 = convert(e2, get_short_type());
  lingo_assert(!c4);
}


// Value transformations.
void
test_2()
{
  Expr const* e1 = make_int(1, get_int_type());
  
  Expr const* c1 = convert(e1, get_msbf_type(32));
  debug(c1);
  debug(c1->type());
  
  Expr const* c2 = convert(e1, get_lsbf_type(32));
  debug(c2);
  debug(c2->type());
}


// Test conversion sequences.
void
test_3()
{
  Expr const* e1 = make_short(1);

  Expr const* c1 = convert(e1, get_umsbf_type(32));
  lingo_assert(c1);
  debug(c1);
  debug(c1->type());

  Expr const* c2 = convert(e1, get_ulsbf_type(64));
  lingo_assert(c2);
  debug(c2);
  debug(c2->type());


  Expr const* e2 = make_lsbf(5, 16);
  Expr const* c3 = convert(e2, get_ulong_type());
  lingo_assert(c3);
  debug(c3);
  debug(c3->type());
}


int
main()
{
  test_1();
  test_2();
  test_3();
}



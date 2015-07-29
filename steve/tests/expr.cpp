// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

// Tests for unary and binary expression.

#include "utility.hpp"

#include <iostream>

void 
test_1()
{
  Expr* i16 = make_short(0);
  Expr* i32 = make_int(0);
  Expr* i64 = make_long(0);
  Expr* u32 = make_uint(0);
  Expr* b = truth();

  Expr* e1 = neg(i16);
  debug(e1);
  debug(e1->type());

  Expr* e2 = neg(i32);
  debug(e2);
  debug(e2->type());
  
  Expr* e3 = neg(i64);
  debug(e3);
  debug(e3->type());
  
  Expr* e4 = neg(u32);
  debug(e4);
  debug(e4->type());

  Expr* e5 = neg(b);
  debug(e5);
  debug(e5->type());

  Expr* e6 = lnot(b);
  debug(e6);
  debug(e6->type());

  Expr* e7 = lnot(i32);
  debug(e7);
  debug(e7->type());
}


void
test_2()
{
  Expr* i16 = make_short(0);
  Expr* i32 = make_int(0);
  Expr* i64 = make_long(0);
  Expr* u32 = make_uint(0);
  Expr* b = truth();

  Expr const* e1 = add(i16, i32);
  debug(e1);
  debug(e1->type());

  Expr const* e2 = add(i32, u32);
  debug(e2);
  debug(e2->type());

  Expr const* e3 = add(u32, i64);
  debug(e3);
  debug(e3->type());

  Expr const* e4 = add(b, b);
  debug(e4);
  debug(e4->type());

  Expr const* e5 = land(b, b);
  debug(e5);
  debug(e5->type());

  Expr const* e6 = land(i64, u32);
  debug(e6);
  debug(e6->type());
}



int
main()
{
  // test_1();
  test_2();
}

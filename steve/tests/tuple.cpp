// Copyright (c) 2015 Andrew Sutton
// All rights reserved

#include "utility.hpp"

#include <iostream>


// Basic tests for construction, typing.
void
test_1()
{
  Type const* t = get_tuple_type({
    get_bool_type(), get_int_type(), get_bool_type()
  });
  print(t);

  Expr const* e1 = make_tuple_expr({
    truth(), one(), falsity()
  });
  print(e1);
  print(e1->type());
  lingo_assert(e1->type() == t);

  Expr const* e2 = make_tuple_expr({zero(), e1});
  print(e2);
  print(e2->type());
  lingo_assert(e2->type() != e1->type());
}


// Evaluation.
void
test_2()
{
  Expr const* e1 = make_tuple_expr({truth(), one(), falsity()});
  Value v1 = evaluate(e1);
  print(v1);

  Expr const* e2 = make_tuple_expr({zero(), e1});
  Value v2 = evaluate(e2);
  print(v2);
}


// Index selection.
void
test_3()
{
  Frame_guard g;

  Expr const* e1 = make_tuple_expr({truth(), make_int(20), falsity()});
  Expr const* i0 = make_index_expr(e1, zero());
  Expr const* i1 = make_index_expr(e1, one());
  print("{} ~> {}", i0, evaluate(i0));
  print("{} ~> {}", i1, evaluate(i1));


  // Make and evaluate a variable.
  Decl const* v = make_var("v", e1->type(), e1);
  evaluate(v);

  Expr const* vi0 = make_index_expr(id(v), zero());
  Expr const* vi1 = make_index_expr(id(v), one());
  print("{} ~> {}", vi0, evaluate(vi0));
  print("{} ~> {}", vi1, evaluate(vi1));


  Expr const* e2 = make_tuple_expr({zero(), e1}); // {0, {true, 20, false}}
  Expr* i2 = make_index_expr(e2, one());  // {0, xxx}.1
  Expr* i3 = make_index_expr(i2, one()); // ({0, xxx}.1).0
  print(i3);
  print(evaluate(i3));
}


void
test_4()
{
  Expr const* e1 = make_tuple_expr({truth(), make_int(20), falsity()});
  Expr const* i1 = make_index_expr(e1, add(zero(), one()));
  print(i1);
  print(evaluate(i1));
}


int
main()
{
  test_1();
  test_2();
  test_3();
  test_4();

  // FIXME: Add tests for ill-formed member access.
}


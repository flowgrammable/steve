// Copyright (c) 2015 Andrew Sutton
// All rights reserved

#include "utility.hpp"

#include <iostream>


Record_decl*
make_record()
{
  Decl_seq mem {
    make_bool_member("m1"),
    make_int_member("m2"),
  };
  return make_record("Rec0", mem);
}


void 
test1()
{
  Scope_guard g(global_scope);

  Decl_seq mem {
    make_bool_member("m1"),
    make_int_member("m2"),
  };
  print(mem[0]);
  print(mem[1]);
  debug(mem[0]);
  debug(mem[1]);

  Decl* r = make_record("My_type", mem);
  print(r);
  debug(r);

  Type const* t = get_record_type(r);
  print(t);
  lingo_assert(get_record_type(r) == get_record_type(r));


}


void
test2()
{
  Decl* r = make_record();  // record { m1 : bool; m2 : int }
  Type const* t = get_record_type(r);
  print(r);

  Expr* e1 = make_tuple_expr({truth(), zero()});
  Expr* e2 = make_tuple_expr({one(), falsity()});

  Decl* v1 = make_var("v1", t, e1);
  lingo_assert(is_valid_node(v1));
  print(v1);

  Decl* v2 = make_var("v2", t, e2);
  lingo_assert(!is_valid_node(v2));
}


void
test3()
{
  Frame_guard g;

  Record_decl* r = make_record();  // record { m1 : bool; m2 : int }
  Decl const* m0 = r->members()[0];  
  Decl const* m1 = r->members()[1];  

  Expr* init = make_tuple_expr({truth(), make_int(5)});
  Decl* v1 = make_var("v1", get_record_type(r), init);
  evaluate(v1);

  Expr* e1 = make_member_expr(id(v1), id(m0));
  Expr* e2 = make_member_expr(id(v1), id(m1));
  print("{} ~> {}", e1, evaluate(e1));
  print("{} ~> {}", e2, evaluate(e2));

  // Just for fun.
  Expr const* e3 = add(e2, e2);
  print("{} ~> {}", e3, evaluate(e3));
}


int
main()
{
  test1();
  test2();
  test3();  
}


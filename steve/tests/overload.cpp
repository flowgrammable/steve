// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

// Tests for overloading and redefinition.

#include "utility.hpp"
#include "steve/overload.hpp"

#include <iostream>

void 
test_1()
{
  Decl_seq p1 {
    make_parm("n", get_int_type()),
    make_parm("b", get_bool_type())
  };
  Decl const* f1 = make_fn("f", p1);


  Decl_seq p2 {
    make_parm("b", get_bool_type()),
    make_parm("n", get_int_type())
  };
  Decl const* f2 = make_fn("f", p2);


  Decl_seq p3 {
    make_parm("b", get_bool_type()),
    make_parm("n", get_int_type())
  };
  Decl const* f3 = make_fn("f", p3, get_int_type(), {
    ret(zero())
  });

  Decl const* v = make_int_var("x", zero());
  print(v);


  Overload ovl {f1};
  overload_decl(&ovl, f2);
  print(&ovl);
  lingo_assert(ovl.size() == 2);

  bool b1 = overload_decl(&ovl, f2); // error: redefinition of f2
  lingo_assert(!b1);
  lingo_assert(ovl.size() == 2);
  
  bool b2 = overload_decl(&ovl, f3); // error: vary in return type
  lingo_assert(!b2);
  lingo_assert(ovl.size() == 2);

  bool b3 = overload_decl(&ovl, v); // error: different kind
  lingo_assert(!b3);
  lingo_assert(ovl.size() == 2);
}


int
main()
{
  test_1();
}

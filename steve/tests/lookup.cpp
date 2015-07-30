// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

// Tests for overloading and redefinition.

#include "utility.hpp"
#include "steve/lookup.hpp"

#include <iostream>

void 
test_1()
{
  Decl const* v1 = make_int_var("a", zero());
  Decl const* v2 = make_int_var("b", zero());
  Decl const* v3 = make_bool_var("a", falsity());


  Global_scope global;
  declare(v1);
  declare(v2);
  print_name_bindings();
  print("~~~~~~~~~~~~~~~~~~~~~~");

  {
    Local_scope local;
    declare(v3);
    print_name_bindings();
    print("~~~~~~~~~~~~~~~~~~~~~~");
  }

  print_name_bindings();

}


int
main()
{
  test_1();
}

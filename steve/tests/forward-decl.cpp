
#include "utility.hpp"

#include <iostream>


void
test1()
{
  Decl_seq parms {
    make_parm("n", get_int_type()),
    make_parm("b", get_bool_type())
  };
  Decl const* fn = make_function_decl(get_identifier("f1"), parms, get_void_type());
  declare(fn->name(), fn);
  print(fn);

  Decl const* fn2 = make_function_decl(get_identifier("f1"), parms, get_void_type(), block({}));
  declare(fn2->name(), fn2);
  print(fn);
}


void
test2()
{
  Variable_decl* var1 = make_variable_decl(get_identifier("v1"), get_int_type());
  declare(var1->name(), var1);
  Decl const* d = lookup_decl(var1->name());
  print(d);

  Variable_decl* var2 = make_variable_decl(get_identifier("v1"), get_int_type(), one());
  declare(var2->name(), var2);
  print(d);
}


int 
main()
{
  Global_scope g;
  // test1();
  test1();
  test2();
  return 0;
}

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
  print(lookup_decl(fn->name()));

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


// Forward decl made and used but not defined
void
test3()
{
  Decl_seq parms {
    make_parm("n", get_int_type()),
    make_parm("b", get_bool_type())
  };
  Decl const* fn = make_function_decl(get_identifier("f2"), parms, get_void_type());
  declare(fn->name(), fn);
  print(lookup_decl(fn->name()));
}


// Forward decl made but NOT used and not defined
void
test4()
{
  Decl_seq parms {
    make_parm("n", get_int_type()),
    make_parm("b", get_bool_type())
  };
  Decl const* fn = make_function_decl(get_identifier("f3"), parms, get_void_type());
  declare(fn->name(), fn);
}


int 
main()
{
  Global_scope g;
  test1();
  test2();
  test3();
  test4();
  check_forward();
  return 0;
}
// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "utility.hpp"

#include <iostream>


Decl*
make_enum(char const* n, Type const* b, Decl_seq const& d)
{
  return make_enumeration_decl(get_identifier(n), get_int_type(), d);
}

Decl*
make_const(char const* n, Type const* t, Expr const* e)
{
  return make_constant_decl(get_identifier(n), t, e);
}


void 
test1()
{
  Scope_guard g(global_scope);

  Type const* t = get_int_type();
  Decl_seq es {
    make_const("A", t, make_int(0, t)),
    make_const("B", t, make_int(1, t))
  };
  Decl* d = make_enum("E", t, es);


  print(d);

}


int
main()
{
  test1();
}


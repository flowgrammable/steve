// Copyright (c) 2015 Andrew Sutton
// All rights reserved

#include "utility.hpp"

#include <iostream>


Match_term const* 
match(Expr const* e, Type const* t)
{
  return make_match_term(e, t);
}


void 
test_1()
{
  Decl* d = make_int_var("x", zero());
  print(d);

  Match_seq ms {
    match(zero(), get_bool_type()),
    match(one(), get_int_type())
  };
  Match_type const* t = get_match_type(id(d), ms);
  debug(t);
  print(t);
}



int
main()
{
  test_1();  
}


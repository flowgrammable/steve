// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "utility.hpp"

#include <iostream>



void 
test1()
{
  Type const* t0 = get_int_type();
  Type const* t1 = get_int_type(64);
  Type const* t2 = get_msbf_type(16);
  Type const* t3 = get_lsbf_type(16);
  
  Type const* t4 = get_uint_type();
  Type const* t5 = get_uint_type(64);
  Type const* t6 = get_umsbf_type(16);
  Type const* t7 = get_ulsbf_type(16);

  print(t0);
  print(t1);
  print(t2);
  print(t3);
  print(t4);
  print(t5);
  print(t6);
  print(t7);
}


int
main()
{
  test1();
}


// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "utility.hpp"

#include <iostream>


void
debug(Converted_pair p)
{
  debug(p.first);
  debug(p.second);
  debug(p.type());
  print("-------");
}


void
test_1()
{
  Expr const* i16 = make_short(0);
  Expr const* i32 = make_int(0);
  Expr const* i64 = make_long(0);
  Expr const* u32 = make_uint(0);

  Expr const* msbf32 = make_msbf(0);
  Expr const* lsbf32 = make_lsbf(0);
  Expr const* umsbf128 = make_umsbf(0, 128);

  // C(int, int) -> int
  Converted_pair c1 = convert_to_common_type(i32, i32);
  lingo_assert(c1 && c1.type() == i32->type());
  debug(c1);

  // C(int, long) -> long
  Converted_pair c2 = convert_to_common_type(i32, i64);
  lingo_assert(c2 && c2.type() == i64->type());
  debug(c2);

  // C(int, uint) -> uint
  Converted_pair c3 = convert_to_common_type(i32, u32);
  lingo_assert(c3 && c3.type() == u32->type());
  debug(c3);

  // C(uint, long) -> ulong
  Converted_pair c4 = convert_to_common_type(u32, i64);
  lingo_assert(c4 && c4.type() == get_ulong_type());
  debug(c4);

  // C(msbf, int) -> int
  Converted_pair c5 = convert_to_common_type(msbf32, i32);
  lingo_assert(c5 && c5.type() == i32->type());
  debug(c5);

  // C(lsbf, int) -> int
  Converted_pair c6 = convert_to_common_type(lsbf32, i32);
  lingo_assert(c6 && c6.type() == i32->type());
  debug(c6);

  // C(msbf, lsbf) -> undefined
  Converted_pair c7 = convert_to_common_type(msbf32, lsbf32);
  lingo_assert(c7 && c7.type() == get_int_type());


  // C(umsbf128, i16) -> uint128
  Converted_pair c8 = convert_to_common_type(umsbf128, i16);
  lingo_assert(c8 && c8.type() == get_uint_type(128));
  debug(c8);
}


int
main()
{
  test_1();
}



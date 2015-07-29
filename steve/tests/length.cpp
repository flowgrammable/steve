// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

// Test the synthesis of length functions.

#include "utility.hpp"

#include "steve/length.hpp"

#include <iostream>


// TODO: Define a small evaluation context that actually computes the
// definitions of these values and checks the result.

void check(Expr const* e)
{
  Expr* len = get_length(e);
  print(e->type());
  print(len);
  print("-------");
}


void 
test_1()
{
  check(truth());                           // 1 byte
  check(zero());                            // 4 bytes
  check(make_int(1, get_uint_type(13)));    // 2 bytes
  check(make_tuple({zero(), truth()}));     // 4 + 1 == 5 bytes  

  // TODO: How do I make an expression of array type?
  // A tuple-expr with array type? Sure...


  // Records of constant size.
  // Has 1 + 3 + 1 bits, so this size is 1 byte.
  Decl const* r1 = make_record("R1", {
      make_member("m1", get_uint_type(1)),
      make_member("m2", get_uint_type(3)),
      make_member("m3", get_uint_type(1))
    }
  );
  Decl const* v1 = make_var("v", get_record_type(r1), make_tuple({ 
      zero(get_uint_type(1)), 
      zero(get_uint_type(3)), 
      zero(get_uint_type(1))
    }
  ));
  print(r1);
  check(id(v1));


  // 6 + 6 + 2 == 
  Decl const* r2 = make_record("Eth", {
      make_member("dst", get_uint_type(48)),
      make_member("src", get_uint_type(48)),
      make_member("type", get_uint_type(16))
    }
  );
  Decl const* v2 = make_var("v", get_record_type(r2), make_tuple({ 
      zero(get_uint_type(48)), 
      zero(get_uint_type(48)), 
      zero(get_uint_type(16))
    }
  ));
  print(r2);
  check(id(v2));
}


int
main()
{
  test_1();
}

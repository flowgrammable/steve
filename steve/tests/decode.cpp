#include "utility.hpp"

#include <iostream>

Record_decl*
make_record()
{
  Decl_seq mem {
    make_int_member("m1"),
    make_int_member("m2"),
  };

  return make_record("Rec0", mem);
}


Stmt_seq
make_match_cases()
{
  Stmt_seq cases {
    make_case(zero(), empty()),
    make_case(one(), empty()),
  };

  return cases;
}

Stmt*
make_match_stmt1(Record_decl const* rd, Expr const* dec)
{
  Stmt_seq cases = make_match_cases();

  return make_match(dec, cases);
}


// Should fail becaue decision type
// will not match case types
Stmt*
make_match_stmt2()
{
  Stmt_seq cases = make_match_cases();
  Expr* dec = falsity();

  return make_match(dec, cases);
}


// multiple same cases
Stmt*
make_match_stmt3(Record_decl const* rd, Expr const* dec) {
  Stmt_seq cases {
    make_case(zero(), empty()),
    make_case(one(), empty()),
    make_case(one(), empty())
  };

  return make_match(dec, cases);
}


Decl*
make_decode_decl1()
{
  Record_decl const* rd = make_record();
  print(rd);
  Record_type const* record = get_record_type(rd);
  print(record->decl());
  print(record);

  Stmt* match = make_match_stmt1(rd, one());
  Stmt* body = block({match});

  Decl* decoder = make_decode("d1", record, body);

  return decoder;
}


Decl*
make_decode_decl2()
{
  Decl* header = make_record();
  Stmt* match = make_match_stmt2();

  Type const* t = get_record_type(header);

  Decl* decoder = make_decode("d2", t, match);

  return decoder;
}


// case with multiple same values in match cases
Decl*
make_decode_decl3()
{
  Record_decl const* rd = make_record();
  Type const* record = get_record_type(rd);

  Stmt* match = make_match_stmt3(rd, one());

  Decl* decoder = make_decode("d1", record, match);

  return decoder;
}


void
test_1()
{
  Scope scope(global_scope);

  Decl* d1 = make_decode_decl1();

  print(d1);
}


// Fails to type.
void
test_2()
{
  make_decode_decl2();
}

// Fails to type the match stmt
void
test_3()
{
  make_decode_decl3();
}


int main()
{
  test_1();
  test_2();
  test_3();
	return 0;
}

#include "steve/prelude.hpp"
#include "steve/builder.hpp"
#include "steve/builtin.hpp"
#include "steve/lookup.hpp"
#include "steve/translate/translate.hpp"

#include <iostream>

using namespace steve;

Record_decl*
make_record()
{
  Decl_seq mem {
    make_bool_member("m1"),
    make_int_member("m2"),
  };
  return make_record("Rec0", mem);
}

void
test1()
{
  Record_decl* r = make_record();  // record { m1 : bool; m2 : int }
  Decl const* m0 = r->members()[0];  
  Decl const* m1 = r->members()[1];  

  Expr* init = make_tuple_expr({truth(), make_int(5)});
  Decl* v1 = make_var("v1", get_record_type(r), init);

  Expr* e1 = make_member_expr(id(v1), id(m0));
  Expr* e2 = make_member_expr(id(v1), id(m1));

  std::cout << tostring(translate(e1)) << '\n';
  std::cout << tostring(translate(e2)) << '\n';
}


int main()
{
  test1();
}
#include "utility.hpp"
#include "steve/builtin.hpp"
#include "steve/prelude.hpp"

Record_decl*
make_eth_header()
{
  Decl_seq mem {
    make_int_member("src"),
    make_int_member("dest"),
    make_int_member("protocol"),
  };

  return make_record("eth", mem);
}


void test1()
{
  init_builtins();

  Program program;

  // make the headers
  Record_decl* eth = make_eth_header();
  Field_expr* eth_src = make_field_expr(id(eth), id(eth->members()[0]));
  Field_expr* eth_src2 = make_field_expr(id(eth), id(eth->members()[0]));

  print(eth_src->name());
  print(eth_src2->name());

  String name = *eth->name() + "." + *eth->members()[0]->name();
  String name2 = *eth->name() + "." + *eth->members()[0]->name();

  assert(get_identifier(name) == get_identifier(name2));
  assert(*eth_src->name() == *eth_src2->name()); 
  assert(eth_src->name() == eth_src2->name()); 
}


int main()
{
  Global_scope global;
  test1();
}

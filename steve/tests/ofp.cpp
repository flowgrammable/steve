#include "utility.hpp"
#include "steve/lower.hpp"
#include "steve/net.hpp"
#include "steve/builtin.cpp"

#include <iostream>


Record_decl*
make_eth_header()
{
  Decl_seq mem {
    make_int_member("src"),
    make_int_member("dest"),
    make_int_member("type"),
  };

  return make_record("eth", mem);
}


// For testing nested field exprs
Record_decl*
make_ipv4_nested_header()
{
  Decl_seq mem {
    make_int_member("src"),
    make_int_member("dest"),
    make_int_member("protocol"),
    make_record_member("e", make_eth_header())
  };

  return make_record("ipv4", mem);
}


Record_decl*
make_ipv4_header()
{
  Decl_seq mem {
    make_int_member("src"),
    make_int_member("dest"),
    make_int_member("protocol"),
  };

  return make_record("ipv4", mem);
}


Record_decl*
make_ipv6_header()
{
  Decl_seq mem {
    make_int_member("src"),
    make_int_member("dest"),
    make_int_member("protocol"),
  };

  return make_record("ipv6", mem);
}


Record_decl*
make_tcp_header()
{
  Decl_seq mem {
    make_int_member("src"),
    make_int_member("dest"),
    make_int_member("port")
  };

  return make_record("tcp", mem);
}


Record_decl*
make_udp_header()
{
  Decl_seq mem {
    make_int_member("src"),
    make_int_member("dest"),
    make_int_member("port")
  };

  return make_record("udp", mem);
}


Stmt_seq
make_match_cases()
{
  Stmt_seq cases {
    make_case(zero(), empty()),
    make_case(one(), empty()),
    make_case(make_int(3), empty())
  };

  return cases;
}



Stmt*
make_match_stmt(Record_decl const* rd, Decl const* var, int index)
{
  Stmt_seq cases = make_match_cases();

  Decl const* mx = rd->members()[index];

  Expr* dec = make_member_expr(id(var), id(mx));

  return make_match(dec, cases);
}


Stmt*
make_do(Do_kind k, Decode_decl const* d)
{
  return make_expr_stmt(make_do_expr(k, id(d)));
}


Stmt*
make_do(Do_kind k, Table_decl const* d)
{
  return make_expr_stmt(make_do_expr(k, id(d)));
}


void
lower_decodes(Decode_decl const* d)
{
  Stmt_seq stmts;
  for (auto s : lower(make_decl_stmt(d), stmts)) {
    print(s);
  }
}


void
make_eth_table()
{
  
}


void
test1()
{
  init_builtins();

  // make the headers
  Record_decl* eth = make_eth_header();
  Record_decl* ipv4 = make_ipv4_header();

  print("{}", eth);
  print("{}", ipv4);

  // make some field expressions
  Expr* eth_src = make_field_expr(id(eth), id(eth->members()[0]));
  Expr* eth_dst = make_field_expr(id(eth), id(eth->members()[1]));
  Expr* eth_type = make_field_expr(id(eth), id(eth->members()[2]));

  Expr* ipv4_src = make_field_expr(id(ipv4), id(ipv4->members()[0]));
  Expr* ipv4_dst = make_field_expr(id(ipv4), id(ipv4->members()[1]));
  Expr* ipv4_proto = make_field_expr(id(ipv4), id(ipv4->members()[2]));

  // make a table
  Table_decl* table1;
  Table_decl* table2;
  
  // flows
  Decl_seq flows {
    make_flow_decl({one(), two(), one()}, Value(1), empty())
  };

  table1 = make_table_decl(get_identifier("tbl1"), { eth_src, eth_dst, ipv4_dst}, flows);
  table2 = make_table_decl(get_identifier("tbl2"), { eth_src, eth_dst, ipv4_proto}, flows);

  // make the decoders
  Decode_decl* eth_d;
  Decode_decl* ipv4_d;

  Stmt_seq ipv4_d_body {
    make_decl_stmt(make_extracts_decl(ipv4_src)),
    make_decl_stmt(make_extracts_decl(ipv4_dst)),
    make_match_stmt(ipv4_proto, 
      Stmt_seq {
        make_case(zero(), make_do(Do_kind::table, table1)),
        make_case(one(), empty()),
      }
    )
  };

  ipv4_d = as<Decode_decl>(make_decode("ipv4_d", get_record_type(ipv4), make_block_stmt(ipv4_d_body)));

  Stmt_seq eth_d_body {
    make_decl_stmt(make_extracts_decl(eth_src)),
    make_decl_stmt(make_extracts_decl(eth_dst)),
    make_decl_stmt(make_extracts_decl(eth_type)),
    make_match_stmt(eth_type, 
      Stmt_seq {
        make_case(zero(), make_do(Do_kind::decode, ipv4_d)),
        make_case(one(), make_do(Do_kind::decode, ipv4_d)),
      }
    )
  };

  // make the decoders
  eth_d = as<Decode_decl>(make_decode("eth_d", get_record_type(eth), make_block_stmt(eth_d_body)));

  // print
  print(eth_d);
  print(ipv4_d);
  print(table1);

  // some declarations
  declare(table1->name(), table1);
  declare(table2->name(), table2);

  // declare the appropriate match fn for the tables
  make_match_fn(table1->type());
  make_match_fn(table2->type());

  // check all functions declared
  print_name_bindings();

  // register stages
  register_stage(eth_d);
  register_stage(ipv4_d);
  register_stage(table1);

  check_pipeline();

  // lowering has to happen in reverse as well
  // lower_decodes(ipv4_d);
  // lower_decodes(eth_d);
}


// this test case should fail because
// - table requirement not satisfied
void
test2()
{
  init_builtins();

  // make the headers
  Record_decl* eth = make_eth_header();
  Record_decl* ipv4 = make_ipv4_header();

  print("{}", eth);
  print("{}", ipv4);

  // make some field expressions
  Expr* eth_src = make_field_expr(id(eth), id(eth->members()[0]));
  Expr* eth_dst = make_field_expr(id(eth), id(eth->members()[1]));
  Expr* eth_type = make_field_expr(id(eth), id(eth->members()[2]));

  Expr* ipv4_src = make_field_expr(id(ipv4), id(ipv4->members()[0]));
  Expr* ipv4_dst = make_field_expr(id(ipv4), id(ipv4->members()[1]));
  Expr* ipv4_proto = make_field_expr(id(ipv4), id(ipv4->members()[2]));

  // make a table
  Table_decl* table1;

  // requirements
  Expr_seq req {
    eth_src,
    eth_dst,
    ipv4_proto,
  };

  // flows
  Decl_seq flows {
    make_flow_decl({one(), two(), one()}, Value(1), empty())
  };

  table1 = make_table_decl(get_identifier("tbl1"), req, flows);

  // make the decoders
  Decode_decl* eth_d;
  Decode_decl* ipv4_d;

  Stmt_seq ipv4_d_body {
    make_decl_stmt(make_extracts_decl(ipv4_src)),
    make_decl_stmt(make_extracts_decl(ipv4_dst)),
    make_match_stmt(ipv4_proto, 
      Stmt_seq {
        make_case(zero(), make_do(Do_kind::table, table1)),
        make_case(one(), empty()),
      }
    )
  };

  ipv4_d = as<Decode_decl>(make_decode("ipv4_d", get_record_type(ipv4), make_block_stmt(ipv4_d_body)));

  Stmt_seq eth_d_body {
    make_decl_stmt(make_extracts_decl(eth_src)),
    make_decl_stmt(make_extracts_decl(eth_dst)),
    make_decl_stmt(make_extracts_decl(eth_type)),
    make_match_stmt(eth_type, 
      Stmt_seq {
        make_case(zero(), make_do(Do_kind::decode, ipv4_d)),
        make_case(one(), make_do(Do_kind::decode, ipv4_d)),
      }
    )
  };

  // make the decoders
  eth_d = as<Decode_decl>(make_decode("eth_d", get_record_type(eth), make_block_stmt(eth_d_body)));

  // print
  print(eth_d);
  print(ipv4_d);
  print(table1);

  // register stages
  register_stage(eth_d);
  register_stage(ipv4_d);
  register_stage(table1);

  check_pipeline();

  // lowering has to happen in reverse as well
  lower_decodes(ipv4_d);
  lower_decodes(eth_d);
}

// testing that table branches work
void test3()
{
  // make the headers
  Record_decl* eth = make_eth_header();
  Record_decl* ipv4 = make_ipv4_header();

  // make some field expressions
  Expr* eth_src = make_field_expr(id(eth), id(eth->members()[0]));
  Expr* eth_dst = make_field_expr(id(eth), id(eth->members()[1]));
  Expr* eth_type = make_field_expr(id(eth), id(eth->members()[2]));

  Expr* ipv4_src = make_field_expr(id(ipv4), id(ipv4->members()[0]));
  Expr* ipv4_dst = make_field_expr(id(ipv4), id(ipv4->members()[1]));
  Expr* ipv4_proto = make_field_expr(id(ipv4), id(ipv4->members()[2]));

  // make some forward declarations
  // requirements
  Expr_seq req {
    eth_src,
    eth_dst,
    eth_type,
    ipv4_proto,
  };
  // construct with no flows to begin with
  Table_decl* t1 = make_table_decl(get_identifier("t1"), req, {});
  declare(t1->name(), t1);

  // construct two decoders with no definitions yet
  Decode_decl* eth_d = make_decode_decl(get_identifier("eth_d"), get_record_type(eth), nullptr);
  Decode_decl* ipv4_d = make_decode_decl(get_identifier("ipv4_d"), get_record_type(ipv4), nullptr);

  declare(eth_d->name(), eth_d);
  declare(ipv4_d->name(), ipv4_d);

  //
  // Construct the bodies of these things
  //

  // eth_d -> t1 or ipv4
  // t1 -> ipv4
  // ipv4 -> t1

  // eth_d definition
  Stmt_seq eth_d_body {
    make_decl_stmt(make_extracts_decl(eth_src)),
    make_decl_stmt(make_extracts_decl(eth_dst)),
    make_decl_stmt(make_extracts_decl(eth_type)),
    make_match_stmt(eth_type, 
      Stmt_seq {
        make_case(zero(), make_do(Do_kind::decode, ipv4_d)),
        make_case(one(), make_do(Do_kind::table, t1)),
      }
    )
  };
  Decode_decl* eth_def = make_decode_decl(get_identifier("eth_d"), get_record_type(eth), make_block_stmt(eth_d_body));
  declare(eth_def->name(), eth_def);

  // ipv4_d definition
  Stmt_seq ipv4_d_body {
    make_decl_stmt(make_extracts_decl(ipv4_src)),
    make_decl_stmt(make_extracts_decl(ipv4_dst)),
    make_match_stmt(ipv4_proto, 
      Stmt_seq {
        make_case(zero(), make_do(Do_kind::table, t1)),
        make_case(one(), empty()),
      }
    )
  };
  Decode_decl* ipv4_def = make_decode_decl(get_identifier("ipv4_d"), get_record_type(ipv4), make_block_stmt(ipv4_d_body));
  declare(ipv4_def->name(), ipv4_def);

  // flow table initializer
  // flows
  // TODO: type check flow initializer
  Decl_seq flows {
    // cond expr, prio, stmt
    make_flow_decl({one(), two(), one()}, Value(1), make_block_stmt({make_do(Do_kind::decode, ipv4_d)}))
  };
  Table_decl* t1_def = make_table_decl(get_identifier("t1"), req, flows);
  declare(get_identifier("t1"), t1_def);

  //
  // Register and type check stages in the pipeline
  //
  register_stage(eth_d);
  register_stage(t1);
  register_stage(ipv4_d);

  check_pipeline();
}


void
test_nested()
{
  Record_decl const* ipv4 = make_ipv4_nested_header();
  Expr* nested = make_field_expr(id(ipv4), id(ipv4->members()[3]));
  Record_decl const* nested_rec = cast<Record_decl>(cast<Record_type>(cast<Member_decl>(ipv4->members()[3])->type())->decl());
  Expr* test = make_field_expr(nested, id(nested_rec->members()[1]));
  Expr* test2 = make_field_expr(nested, id(nested_rec->members()[1]));

  print(resolve_field_name(as<Field_expr>(test)));
  print(resolve_field_name(as<Field_expr>(test2)));

  std::cout << resolve_field_name(as<Field_expr>(test)) << '\n';
  std::cout << resolve_field_name(as<Field_expr>(test2)) << '\n';
}


void
test_table_types()
{
  // make the headers
  Record_decl* eth = make_eth_header();

  // make some field expressions
  Expr* eth_src = make_field_expr(id(eth), id(eth->members()[0]));
  Expr* eth_dst = make_field_expr(id(eth), id(eth->members()[1]));
  Expr* eth_type = make_field_expr(id(eth), id(eth->members()[2]));

  // requirements
  Expr_seq req {
    eth_src,
    eth_dst,
    eth_type,
  };

  Decl_seq flows {
    // This flow should fail because there are less subkeys than table
    make_flow_decl({one(), two()}, Value(1), make_block_stmt({})),
    // this flow should fail because there are mismatched types in the keys
    make_flow_decl({one(), two(), truth()}, Value(1), make_block_stmt({})),
  };

  make_table_decl(get_identifier("t1"), req, flows);
}


int main()
{
  Global_scope global;
  test1();
  // test_table_types();
  // test2();
  // test3();
}
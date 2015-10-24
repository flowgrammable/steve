#include "utility.hpp"
#include "steve/lower.hpp"
#include "steve/net.hpp"
#include "steve/builtin.hpp"
#include "steve/prelude.hpp"

#include <iostream>


// inline Stmt*
// statement(Decl const* d)
// {
//   return make_decl_stmt(d);
// }


// inline Stmt*
// statement(Expr const* e)
// {
//   return make_expr_stmt(e);
// }


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


Record_decl*
make_real_eth_header()
{
  Decl_seq mem {
    make_member("src", get_msbf_type(48)),
    make_member("dest", get_msbf_type(48)),
    make_member("type", get_msbf_type(16)),
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
make_real_ipv4_header()
{
  Decl_seq mem {
    make_member("version_ihl", get_umsbf_type(8)),
    make_member("dscp_ecn", get_umsbf_type(8)),
    make_member("len", get_umsbf_type(16)),
    make_member("id", get_umsbf_type(16)),
    make_member("frag", get_umsbf_type(16)),
    make_member("ttl", get_umsbf_type(8)),
    make_member("protocol", get_umsbf_type(8)),
    make_member("checksum", get_umsbf_type(16)),
    make_member("src", get_umsbf_type(32)),
    make_member("dst", get_umsbf_type(32)),
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


// generate c++ from the pipeline code
void
codegen(Program program)
{
  
}


void
test1()
{
  init_builtins();

  Program program;

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

  //----------------------------------------------------------------//
  //              Forward Declarations

  // construct with no flows to begin with
  Table_decl* t1 = make_table_decl(get_identifier("t1"), { eth_src, eth_dst, ipv4_dst }, {});
  Table_decl* t2 = make_table_decl(get_identifier("t2"), { eth_src, eth_dst, ipv4_proto}, {});
  declare(t1->name(), t1);
  declare(t2->name(), t2);

  // construct two decoders with no definitions yet
  Decode_decl* eth_d = make_decode_decl(get_identifier("eth_d"), get_record_type(eth), nullptr);
  Decode_decl* ipv4_d = make_decode_decl(get_identifier("ipv4_d"), get_record_type(ipv4), nullptr);

  // set the start flag
  eth_d->set_start();
  // ipv4_d->set_start();
  declare(eth_d->name(), eth_d);
  declare(ipv4_d->name(), ipv4_d);  

  //----------------------------------------------------------------//
  //              Definitions

  Variable_decl* _header_1 = make_variable_decl(
                                get_identifier("_header_"), 
                                get_record_type(eth));

  Variable_decl* _header_2 = make_variable_decl(
                                get_identifier("_header_"), 
                                get_record_type(ipv4));

  Expr* cond1 = make_member_expr(id(_header_1), id(eth->members()[2]));
  Expr* cond2 = make_member_expr(id(_header_2), id(ipv4->members()[2]));

  Stmt_seq eth_d_body {
    make_decl_stmt(make_extracts_decl(eth_src)),
    make_decl_stmt(make_extracts_decl(eth_dst)),
    make_decl_stmt(make_extracts_decl(eth_type)),
    make_match_stmt(cond1, 
      Stmt_seq {
        make_case(zero(), make_do(Do_kind::decode, ipv4_d)),
        make_case(one(), make_do(Do_kind::decode, ipv4_d)),
      }
    )
  };


  Stmt_seq ipv4_d_body {
    make_decl_stmt(make_extracts_decl(ipv4_src)),
    make_decl_stmt(make_extracts_decl(ipv4_dst)),
    make_match_stmt(cond2, 
      Stmt_seq {
        make_case(zero(), make_do(Do_kind::table, t1)),
        make_case(one(), make_do(Do_kind::decode, eth_d)),
      }
    )
  };

  // define the decoders
  declare(eth_d->name(), make_decode_decl(get_identifier("eth_d"), get_record_type(eth), block(eth_d_body)));
  declare(ipv4_d->name(), make_decode_decl(get_identifier("ipv4_d"), get_record_type(ipv4), block(ipv4_d_body)));

  // define the tables
  Decl_seq flows {
    // cond expr, prio, stmt
    make_flow_decl({one(), two(), one()}, Value(1), make_block_stmt({}))
  };
  declare(t1->name(), make_table_decl(get_identifier("t1"), { eth_src, eth_dst, ipv4_dst }, flows));
  declare(t2->name(), make_table_decl(get_identifier("t2"), { eth_src, eth_dst, ipv4_proto }, flows));

  // print
  print(eth_d);
  print(ipv4_d);
  print(t1);
  print(t2);

  // register stages
  register_stage(eth_d);
  register_stage(ipv4_d);
  register_stage(t1);
  register_stage(t2);

  // check pipeline and push only if check_pipeline succeeds
  if (check_pipeline()) {
    // lowering has to happen in reverse as well
    // FIXME: every Decode_decl should cause a forward-decl
    // for the lowered function first
    lower_decodes(eth_d);
    lower_decodes(ipv4_d);

    // IMPORTANT: the call expressions in their lowered form
    // may actually point to the decode-decl rather than it's lowered
    // function form. This should still be fine as the call is opaque during
    // translation to C++ and the declaration it points to should not matter
    // as long as the name is correct.

    // make the program
    program.push(statement(eth));
    program.push(statement(ipv4));
    program.push(statement(t1));
    program.push(statement(t2));
    program.push(statement(eth_d));
    program.push(statement(ipv4_d));
  }
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

  // make some field expressions
  Expr* eth_src = make_field_expr(id(eth), id(eth->members()[0]));
  Expr* eth_dst = make_field_expr(id(eth), id(eth->members()[1]));
  Expr* eth_type = make_field_expr(id(eth), id(eth->members()[2]));

  Expr* ipv4_src = make_field_expr(id(ipv4), id(ipv4->members()[0]));
  Expr* ipv4_dst = make_field_expr(id(ipv4), id(ipv4->members()[1]));
  Expr* ipv4_proto = make_field_expr(id(ipv4), id(ipv4->members()[2]));

  //----------------------------------------------------------------//
  //              Forward Declarations

  // construct with no flows to begin with
  Table_decl* t1 = make_table_decl(get_identifier("t1"), { eth_src, eth_dst, ipv4_dst }, {});
  declare(t1->name(), t1);

  // construct two decoders with no definitions yet
  Decode_decl* eth_d = make_decode_decl(get_identifier("eth_d"), get_record_type(eth), nullptr);
  Decode_decl* ipv4_d = make_decode_decl(get_identifier("ipv4_d"), get_record_type(ipv4), nullptr);

  declare(eth_d->name(), eth_d);
  declare(ipv4_d->name(), ipv4_d);  

  //----------------------------------------------------------------//
  //              Definitions

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

  Stmt_seq ipv4_d_body {
    make_decl_stmt(make_extracts_decl(ipv4_src)),
    make_decl_stmt(make_extracts_decl(ipv4_dst)),
    make_match_stmt(ipv4_proto, 
      Stmt_seq {
        make_case(zero(), make_do(Do_kind::table, t1)),
      }
    )
  };

  // define the decoders
  declare(eth_d->name(), make_decode_decl(get_identifier("eth_d"), get_record_type(eth), block(eth_d_body)));
  declare(ipv4_d->name(), make_decode_decl(get_identifier("ipv4_d"), get_record_type(ipv4), block(ipv4_d_body)));

  // define the tables
  Decl_seq flows {
    // cond expr, prio, stmt
    make_flow_decl({one(), two(), one()}, Value(1), make_block_stmt({}))
  };
  declare(t1->name(), make_table_decl(get_identifier("t1"), { eth_src, eth_dst, ipv4_dst }, flows));


  // register stages
  register_stage(eth_d);
  register_stage(ipv4_d);
  register_stage(t1);

  check_pipeline();
}


// testing that table branches work
// eth_d -> t1
// t1 -> ipv4
// ipv4 -> t1
// Expected: no error
void test3()
{
  init_builtins();

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

  //----------------------------------------------------------------//
  //              Forward Declarations

  // construct with no flows to begin with
  Table_decl* t1 = make_table_decl(get_identifier("t1"), { eth_src, eth_dst }, {});
  declare(t1->name(), t1);

  // construct two decoders with no definitions yet
  Decode_decl* eth_d = make_decode_decl(get_identifier("eth_d"), get_record_type(eth), nullptr);
  Decode_decl* ipv4_d = make_decode_decl(get_identifier("ipv4_d"), get_record_type(ipv4), nullptr);

  declare(eth_d->name(), eth_d);
  declare(ipv4_d->name(), ipv4_d);


  //----------------------------------------------------------------//
  //              Definitions

  Stmt_seq eth_d_body {
    make_decl_stmt(make_extracts_decl(eth_src)),
    make_decl_stmt(make_extracts_decl(eth_dst)),
    make_decl_stmt(make_extracts_decl(eth_type)),
    make_match_stmt(eth_type, 
      Stmt_seq {
        make_case(one(), make_do(Do_kind::table, t1)),
      }
    )
  };

  Stmt_seq ipv4_d_body {
    make_decl_stmt(make_extracts_decl(ipv4_src)),
    make_decl_stmt(make_extracts_decl(ipv4_dst)),
    make_match_stmt(ipv4_proto, 
      Stmt_seq {
        make_case(zero(), make_do(Do_kind::table, t1)),
      }
    )
  };

  // define the decoders
  declare(eth_d->name(), make_decode_decl(get_identifier("eth_d"), get_record_type(eth), block(eth_d_body)));
  declare(ipv4_d->name(), make_decode_decl(get_identifier("ipv4_d"), get_record_type(ipv4), block(ipv4_d_body)));

  Decl_seq flows {
    make_flow_decl({one(), two()}, Value(1), make_block_stmt({make_do(Do_kind::decode, ipv4_d)}))
  };

  declare(t1->name(), make_table_decl(get_identifier("t1"), { eth_src, eth_dst }, flows));

  // register stages
  register_stage(eth_d);
  register_stage(ipv4_d);
  register_stage(t1);

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


// Test for path finding on graphs with cycles (\\ is loop)
//       dummy
//   /            \
//  eth_d  ---   dummy2
//(loops self)
//      \\        /
//          ipv4
//           |
//           t1
void
test4()
{
  init_builtins();

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

  //----------------------------------------------------------------//
  //              Forward Declarations

  // construct with no flows to begin with
  Table_decl* t1 = make_table_decl(get_identifier("t1"), { eth_src, eth_dst, ipv4_dst }, {});
  declare(t1->name(), t1);

  // construct two decoders with no definitions yet
  Decode_decl* eth_d = make_decode_decl(get_identifier("eth_d"), get_record_type(eth), nullptr);
  Decode_decl* ipv4_d = make_decode_decl(get_identifier("ipv4_d"), get_record_type(ipv4), nullptr);

  // dummy with no extractions
  Decode_decl* dummy = make_decode_decl(get_identifier("dummy"), get_record_type(eth), nullptr);
  Decode_decl* dummy2 = make_decode_decl(get_identifier("dummy2"), get_record_type(eth), nullptr);

  declare(eth_d->name(), eth_d);
  declare(ipv4_d->name(), ipv4_d);
  declare(dummy->name(), dummy);
  declare(dummy2->name(), dummy2);

  //----------------------------------------------------------------//
  //              Definitions

  Variable_decl* _header_1 = make_variable_decl(
                                get_identifier("_header_"), 
                                get_record_type(eth));

  Variable_decl* _header_2 = make_variable_decl(
                                get_identifier("_header_"), 
                                get_record_type(ipv4));

  Expr* cond1 = make_member_expr(id(_header_1), id(eth->members()[2]));
  Expr* cond2 = make_member_expr(id(_header_2), id(ipv4->members()[2]));

  Stmt_seq eth_d_body {
    make_decl_stmt(make_extracts_decl(eth_src)),
    make_decl_stmt(make_extracts_decl(eth_dst)),
    make_decl_stmt(make_extracts_decl(eth_type)),
    make_match_stmt(cond1, 
      Stmt_seq {
        make_case(zero(), make_do(Do_kind::decode, eth_d)),
        make_case(one(), make_do(Do_kind::decode, ipv4_d)),
        make_case(two(), make_do(Do_kind::decode, ipv4_d)),
      }
    )
  };


  Stmt_seq ipv4_d_body {
    make_decl_stmt(make_extracts_decl(ipv4_src)),
    make_decl_stmt(make_extracts_decl(ipv4_dst)),
    make_match_stmt(cond2, 
      Stmt_seq {
        make_case(one(), make_do(Do_kind::decode, eth_d)),
        make_case(zero(), make_do(Do_kind::table, t1)),
      }
    )
  };


  Stmt_seq dummy_body {
    make_match_stmt(cond1, 
      Stmt_seq {
        make_case(one(), make_do(Do_kind::decode, eth_d)),
        make_case(zero(), make_do(Do_kind::decode, dummy2)),
      }
    )
  };


  Stmt_seq dummy_body2 {
    make_match_stmt(cond1, 
      Stmt_seq {
        make_case(zero(), make_do(Do_kind::decode, ipv4_d)),
        make_case(one(), make_do(Do_kind::decode, eth_d)),
      }
    )
  };

  // define the decoders
  declare(eth_d->name(), make_decode_decl(get_identifier("eth_d"), get_record_type(eth), block(eth_d_body)));
  declare(ipv4_d->name(), make_decode_decl(get_identifier("ipv4_d"), get_record_type(ipv4), block(ipv4_d_body)));
  declare(dummy->name(), make_decode_decl(get_identifier("dummy"), get_record_type(eth), block(dummy_body)));
  declare(dummy2->name(), make_decode_decl(get_identifier("dummy2"), get_record_type(eth), block(dummy_body2)));

  // define the tables
  Decl_seq flows {
    // cond expr, prio, stmt
    make_flow_decl({one(), two(), one()}, Value(1), make_block_stmt({}))
  };
  declare(t1->name(), make_table_decl(get_identifier("t1"), { eth_src, eth_dst, ipv4_dst }, flows));

  // some match functions
  // declare the appropriate match fn for the tables
  make_match_fn(t1->type());

  // print
  print(dummy);
  print(eth_d);
  print(dummy2);
  print(ipv4_d);
  print(t1);

  // register stages
  dummy->set_start();
  register_stage(dummy);
  register_stage(eth_d);
  register_stage(dummy2);
  register_stage(ipv4_d);
  register_stage(t1);

  check_pipeline();
}




int main()
{
  Global_scope global;
  // test1();
  // test_table_types();
  // test2();
  // test3();
  test4();
}
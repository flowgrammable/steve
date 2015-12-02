#include "utility.hpp"
#include "steve/lower.hpp"
#include "steve/net.hpp"
#include "steve/builtin.hpp"
#include "steve/prelude.hpp"


Record_decl*
make_eth_header()
{
  Decl_seq mem {
    make_member("src", get_umsbf_type(48)),
    make_member("dest", get_umsbf_type(48)),
    make_member("type", get_umsbf_type(16)),
  };

  return make_record("eth", mem);
}


Record_decl*
make_ipv4_header()
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


void 
test1()
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
  Expr* ipv4_dst = make_field_expr(id(ipv4), id(ipv4->members()[9]));
  Expr* ipv4_proto = make_field_expr(id(ipv4), id(ipv4->members()[4]));

  Decl_seq flows {
    // cond expr, prio, stmt
    make_flow_decl({one(), two(), zero()}, Value(1), make_block_stmt({}))
  };

  Table_decl* t1 = make_table_decl(get_identifier("t1"), { eth_src, eth_dst, ipv4_dst }, flows);

  print(t1);
}


int main()
{
  Global_scope global;
  test1();
}
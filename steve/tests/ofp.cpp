#include "utility.hpp"

#include <iostream>

// TODO: Implement this
// Not sure what this should be yet
// Should it be an expression or just a function?
Expr*
make_length_fn()
{
  return one();
}


Record_decl*
make_eth_header()
{
  Decl_seq mem {
    make_int_member("src"),
    make_int_member("dest"),
    make_int_member("type")
  };

  return make_record("eth", mem);
}


Record_decl*
make_ipv4_header()
{
  Decl_seq mem {
    make_int_member("src"),
    make_int_member("dest"),
    make_int_member("protocol")
  };

  return make_record("ipv4", mem);
}


Record_decl*
make_ipv6_header()
{
  Decl_seq mem {
    make_int_member("src"),
    make_int_member("dest"),
    make_int_member("protocol")
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


void
test1()
{
  // make the headers
  Record_decl* eth = make_eth_header();
  Record_decl* ipv4 = make_ipv4_header();
  Record_decl* ipv6 = make_ipv6_header();
  Record_decl* tcp = make_tcp_header();
  Record_decl* udp = make_udp_header();

  print("{}", eth);
  print("{}", ipv4);
  print("{}", ipv6);
  print("{}", tcp);
  print("{}", udp);

  // construct variables internal to the decoder
  Expr* init = make_tuple_expr({make_int(0), make_int(0), make_int(0)});
  Decl* eth_v = make_var("internal", get_record_type(eth), init);
  Decl* ipv4_v = make_var("internal", get_record_type(ipv4), init);
  Decl* ipv6_v = make_var("internal", get_record_type(ipv6), init);
  Decl* tcp_v = make_var("internal", get_record_type(tcp), init);
  Decl* udp_v = make_var("internal", get_record_type(udp), init);

  // make the match conditions
  Stmt* eth_m = make_match_stmt(eth, eth_v, 2);
  Stmt* ipv4_m = make_match_stmt(ipv4, ipv4_v, 2);
  Stmt* ipv6_m = make_match_stmt(ipv6, ipv6_v, 2);
  Stmt* tcp_m = make_match_stmt(tcp, tcp_v, 2);
  Stmt* udp_m = make_match_stmt(udp, udp_v, 2);

  // make the decoders
  Expr* len = make_length_fn();
  Decl* eth_d = make_decode("eth_d", get_record_type(eth), eth_m, len);
  Decl* ipv4_d = make_decode("ipv4_d", get_record_type(ipv4), ipv4_m, len);
  Decl* ipv6_d = make_decode("ipv6_d", get_record_type(ipv6), ipv6_m, len);
  Decl* tcp_d = make_decode("tcp_d", get_record_type(tcp), tcp_m, len);
  Decl* udp_d = make_decode("udp_d", get_record_type(udp), udp_m, len);

  print(eth_d);
  print(ipv4_d);
  print(ipv6_d);
  print(tcp_d);
  print(udp_d);

  // register the decoders so we can construct a parse graph
  // we need a parse graph in order to determine if ofptable
  // match fields can be validly declared together
}


void
make_ofptable(int num, char const* name, Expr_seq const& matches)
{

}


int main()
{
  test1();
}
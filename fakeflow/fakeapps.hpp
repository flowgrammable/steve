#ifndef FAKE_APPS_HPP
#define FAKE_APPS_HPP

#include "system.hpp"
#include "dataplane.hpp"
#include "context.hpp"

namespace fp
{

struct App1
{
  App1(Table* t)
    : table(dynamic_cast<Hash_table*>(t))
  { }

  Hash_table* table;

  inline void
  eth_d(Context* cxt, Port* p)
  {
    fp_bind_header(cxt, 0);
    // fp_output_port(cxt, p);
    fp_goto_table(cxt, table, 1, 0);
  }


  inline void
  pipeline(Context* cxt, Port* p)
  {
    eth_d(cxt, p);
  }
};


struct App2
{
  App2(Table* t)
    : table(dynamic_cast<Hash_table*>(t))
  { }

  Hash_table* table;

  void
  eth_d(Context* cxt, Port* p)
  {
    uint16_t type;
    fp_bind_header(cxt, 0);
    fp_bind_field(cxt, 12, 0, 6);
    fp_bind_field(cxt, 13, 6, 6);
    fp_bind_field(cxt, 14, 12, 2);
    fp::Byte* b = fp_read_field(cxt, 14);
    type = *reinterpret_cast<uint16_t*>(b);
    switch (type) {
      case 800: ipv4_d(cxt, p); break;
    }
  }


  void
  ipv4_d(Context* cxt, Port* p)
  {
    uint8_t protocol = 0;
    fp_bind_header(cxt, 1);
    fp_bind_field(cxt, 4, 4, 1);
    fp_bind_field(cxt, 5, 0, 1);
    fp_bind_field(cxt, 6, 1, 1);
    fp_bind_field(cxt, 7, 6, 2);
    fp_bind_field(cxt, 8, 5, 1);
    fp_bind_field(cxt, 9, 2, 2);
    fp_bind_field(cxt, 10, 8, 4);
    fp_bind_field(cxt, 11, 12, 4);

    fp::Byte* b = fp_read_field(cxt, 8);
    protocol = *reinterpret_cast<uint8_t*>(b);
    switch (protocol) {
      case 0: udp_d(cxt, p); break;
    }
  }


  void
  udp_d(Context* cxt, Port* p)
  {
    fp_bind_header(cxt, 2);
    fp_bind_field(cxt, 0, 0, 2);
    fp_bind_field(cxt, 1, 2, 2);
    fp_bind_field(cxt, 2, 4, 2);
    fp_bind_field(cxt, 3, 6, 2);
    fp_goto_table(cxt, table, 2, 11, 8);
  }


  void
  pipeline(Context* cxt, Port* p)
  {
    eth_d(cxt, p);
  }
};

} // namespace fp

#endif

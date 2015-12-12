#include "interface.hpp"

#include <cassert>
#include <sstream>

extern "C"
void fp_bind_header(Context* cxt, int id, int len)
{
  assert(cxt);

  std::stringstream ss;

  ss << "binding header id: ";
  ss << id;
  ss << " len: ";
  ss << len;
  ss << '\n';

  cxt->log += ss.str();
}


extern "C"
void fp_bind_field(Context* cxt, int id, int offset, int len)
{
  assert(cxt);

  std::stringstream ss;

  ss << "binding field id: ";
  ss << id;
  ss << " offset: ";
  ss << offset;
  ss << " len: ";
  ss << len;
  ss << '\n';

  cxt->log += ss.str();
}


extern "C"
uint32_t fp_load_field(Context* cxt, int id)
{
  assert(cxt);
  std::stringstream ss;
  ss << "load field id: ";
  ss << id << '\n';
  cxt->log += ss.str();

  return 0;
}


extern "C"
void fp_alias_bind()
{
}


extern "C"
void fp_advance(Context* cxt, int n)
{
  assert(cxt);
  std::stringstream ss;
  ss << "advancing by: ";
  ss << n << '\n';
  ss << "pointer now at byte: ";
  ss << cxt->ptr << '\n';
  cxt->log += ss.str();

  cxt->ptr += n;
}


extern "C"
Table* fp_get_table(int id, int key_size, int size, int kind)
{
  std::cout << "Creating table: " << id << '\n';
  return new Table("t", id);
}


extern "C"
void fp_add_flow(Table* tbl, Flow_t flow)
{
  assert(tbl);
  assert(flow);

  std::cout << "Adding flow to tbl: " << tbl->count << '\n';

  tbl->flows.push_back(flow);
}


extern "C"
Flow_t fp_goto_table(Context* cxt, Key* k, Table* tbl)
{
  assert(cxt);
  assert(k);
  assert(tbl);

  std::stringstream ss;

  ss << "Performing a match on table #"
     << tbl->count << '\n';
  cxt->log += ss.str();

  // return the first one jsut for testing
  Flow_t flow = tbl->flows.front();
  return flow;
}


extern "C"
Port* fp_get_port(char const * n)
{
  static int count = 0;
  std::cout << "Making port: " << string(n) << '\n';
  return new Port(count++);
}


extern "C"
Key* fp_gather(Context* cxt, int n, ...)
{
  assert(cxt);
  std::stringstream ss;

  ss << "Gathering key of ";
  ss << n << " elements.";
  ss << '\n';
  cxt->log += ss.str();

  return new Key(n);
}

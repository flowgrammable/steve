#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "constructs.hpp"

#include <cstdint>
#include <iostream>


extern "C" void fp_bind_header(Context* cxt, int id, int len);
extern "C" void fp_bind_field(Context* cxt, int id, int offset, int len);
extern "C" uint32_t fp_load_field(Context* cxt, int id);
extern "C" void fp_alias_bind();
extern "C" void fp_advance(Context*, int n);
extern "C" Table* fp_get_table(int id, int key_size, int size, int kind);
extern "C" void fp_add_flow(Table* tbl, Flow_t);
extern "C" Flow_t fp_goto_table(Context*, Key*, Table*);
extern "C" Port* fp_get_port(char const*);
extern "C" Key* fp_gather(Context*, int n, ...);


#endif

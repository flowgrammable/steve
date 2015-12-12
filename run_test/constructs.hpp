#ifndef CONSTRUCTS_HPP
#define CONSTRUCTS_HPP

#include <string>
#include <vector>

struct Table;
struct Context;

using string = std::string;
using Flow_t = void (*)(Table*, Context*);

// Fake table
struct Table {

  Table(char const* n, int c)
    : count(c), name(n)
  { }

  int count;
  string name;

  std::vector<Flow_t> flows;
};


// Fake context
struct Context {
  Context()
    : log(""), ptr(0)
  { }

  string log;
  int ptr;
};


// Fake port
struct Port {
  Port(int n)
    : num(n)
  { }

  int num;
};


// Fake key
struct Key
{
  Key(int s)
    : k(new int[s])
  { }

  int* k;
};


#endif

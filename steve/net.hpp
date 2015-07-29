
#ifndef STEVE_NET_HPP
#define STEVE_NET_HPP

#include "steve/prelude.hpp"

#include <set>


// This module is used to connect the decode decls
// togethers. This allows us to formt he graph to
// type check the flow tables


namespace steve {


struct Protocol_node {
  Protocol_node(Type const* t)
    : first(t)
  { }

  Type const* header_type() { return first; }

  Type const* first;
};


struct Protocol_edges : std::set<Expr*> {
  Protocol_edges()
  {

  }
};

using Proto_key = std::pair<Type*, Expr*>;

struct Edge_cmp
{
  bool operator()(Proto_key const, Proto_key const) const;
};


using Proto_map = std::map<Proto_key, Type*, Edge_cmp>;
using Proto_path = std::vector<Proto_key>;

// protocol grap describes all valid decoding paths
// specified by decode declarations
extern Proto_map Proto_graph;

void register_decoder(Decode_decl const*);

}

#endif


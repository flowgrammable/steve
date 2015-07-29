#include "net.hpp"
#include "relation.cpp"

namespace steve {
  

Proto_map Proto_graph = Proto_map();

// Custom comparator for nodes
bool
Edge_cmp::operator()(Proto_key const a, Proto_key const b) const
{
  if( less(a.first, b.first) )
    return true;
  if( less(b.first, a.first) )
    return false;

  if( less(a.second, b.second) ) {
    return true;
  }

  return false;
}


}
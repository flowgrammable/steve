// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "steve/prop.hpp"
#include "steve/expr.hpp"
#include "steve/type.hpp"


namespace steve
{

char const*
get_prop_name(Prop_kind k)
{
  switch (k) {
    case and_prop: return "and_prop";
    case or_prop: return "or_prop";
    case predicate_prop: return "predicate_prop";
    case extract_prop: return "extract_prop";
  }
  lingo_unreachable("unhandled node kind ({})", (int)k);
}


void 
mark(Prop const*)
{

}



} // namespace steve


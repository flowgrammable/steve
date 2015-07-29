// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#ifndef STEVE_RELATION_HPP
#define STEVE_RELATION_HPP

// The equivalence module defines equivalence and ordering
// relations on syntax trees.

#include "steve/prelude.hpp"


namespace steve
{

bool same(Type const*, Type const*);

bool less(Value const*, Value const*);
bool less(Type const*, Type const*);
bool less(Expr const*, Expr const*);
bool less(Decl const*, Decl const*);

} // namespace steve

#endif

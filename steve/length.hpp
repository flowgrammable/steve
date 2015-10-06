// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#ifndef STEVE_LENGTH_HPP
#define STEVE_LENGTH_HPP

namespace steve
{

Decl* synthesize_length(Type const*);

Expr* get_length(Expr const*);

Expr const* get_length(Type const*);

} // namespace steve


#endif

// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#ifndef STEVE_LENGTH_HPP
#define STEVE_LENGTH_HPP

// Decl* synthesize_length(Type const*);

Expr* get_length(Field_name_expr const*);

Expr* get_length(Type const*);
Expr* get_length(Type_seq const&);

Expr* get_length(Layout_decl const*);
Expr* get_length(Decl_seq const&);

int precision(Type const*);

#endif

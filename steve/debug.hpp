// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#ifndef STEVE_DEBUG_HPP
#define STEVE_DEBUG_HPP

// This module provides support for debug printing.

#include "steve/prelude.hpp"

#include "lingo/debug.hpp"


namespace steve
{

void debug(Printer&, Type const* t);
void debug(Printer&, Integer_type const* t);
void debug(Printer&, Function_type const* t);

void debug(Printer&, Expr const*);
void debug(Printer&, Id_expr const*);
void debug(Printer&, Value_expr const*);
void debug(Printer&, Convert_expr const*);

void debug(Printer&, Decl const*);
void debug(Printer&, Variable_decl const*);
void debug(Printer&, Function_decl const*);
void debug(Printer&, Parameter_decl const*);
void debug(Printer&, Member_decl const*);

void debug(Printer&, Stmt const*);
void debug(Printer&, Block_stmt const*);


} // namespace steve


#endif


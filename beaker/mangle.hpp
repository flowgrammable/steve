// Copyright (c) 2015 Andrew Sutton
// All rights reserved

#ifndef BEAKER_MANGLE_HPP
#define BEAKER_MANGLE_HPP

// This module supports the mangling of identifers
// suitable for linking.

#include <beaker/prelude.hpp>

String mangle(Field_access_expr const*);
String mangle(Table_decl const*, Flow_decl const*);
String mangle(Type const*);
String mangle(Decl const*);

void mangle(std::ostream&, Type const*);
void mangle(std::ostream&, Id_type const*);
void mangle(std::ostream&, Boolean_type const*);
void mangle(std::ostream&, Character_type const*);
void mangle(std::ostream&, Integer_type const*);
void mangle(std::ostream&, Function_type const*);
void mangle(std::ostream&, Array_type const*);
void mangle(std::ostream&, Block_type const*);
void mangle(std::ostream&, Reference_type const*);
void mangle(std::ostream&, Record_type const*);
void mangle(std::ostream&, Void_type const*);
void mangle(std::ostream&, Opaque_type const*);

// network specific types
void mangle(std::ostream&, Layout_type const*);
void mangle(std::ostream&, Context_type const*);
void mangle(std::ostream&, Table_type const*);
void mangle(std::ostream&, Flow_type const*);
void mangle(std::ostream&, Port_type const*);
void mangle(std::ostream&, Key_type const*);

void mangle(std::ostream&, Decl const*);
void mangle(std::ostream&, Variable_decl const*);
void mangle(std::ostream&, Function_decl const*);
void mangle(std::ostream&, Parameter_decl const*);
void mangle(std::ostream&, Record_decl const*);
void mangle(std::ostream&, Field_decl const*);
void mangle(std::ostream&, Method_decl const*);
void mangle(std::ostream&, Module_decl const*);

// network declarations
void mangle(std::ostream&, Layout_decl const*);
void mangle(std::ostream&, Decode_decl const*);
void mangle(std::ostream&, Table_decl const*);
void mangle(std::ostream&, Key_decl const*);
void mangle(std::ostream&, Flow_decl const*);
void mangle(std::ostream&, Port_decl const*);
void mangle(std::ostream&, Extracts_decl const*);
void mangle(std::ostream&, Rebind_decl const*);
void mangle(std::ostream&, Event_decl const*);

#endif

// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#ifndef STEVE_PRINT_HPP
#define STEVE_PRINT_HPP

// This module provides support for pretty printing
// terms in the language.

#include "steve/prelude.hpp"

#include "lingo/print.hpp"


namespace steve
{

// Note that that these specialized print routines are
// exported so that we don't incur runtime overhead when
// we have the most derived type.

void print(Printer&, Type const*);
void print(Printer&, Void_type const*);
void print(Printer&, Boolean_type const*);
void print(Printer&, Integer_type const*);
void print(Printer&, Constant_type const*);
void print(Printer&, Reference_type const*);
void print(Printer&, Function_type const*);
void print(Printer&, Array_type const*);
void print(Printer&, Tuple_type const*);
void print(Printer&, Record_type const*);
void print(Printer&, Variant_type const*);
void print(Printer&, Enum_type const*);
void print(Printer&, Match_type const*);
void print(Printer&, If_type const*);
void print(Printer&, Seq_type const*);
void print(Printer&, Buffer_type const*);
void print(Printer&, Until_type const*);

void print(Printer&, Expr const*);
void print(Printer&, Id_expr const*);
void print(Printer&, Value_expr const*);
void print(Printer&, Unary_expr const*);
void print(Printer&, Binary_expr const*);
void print(Printer&, Call_expr const*);
void print(Printer&, Tuple_expr const*);
void print(Printer&, Index_expr const*);
void print(Printer&, Member_expr const*);
void print(Printer&, Convert_expr const*);
void print(Printer&, Lengthof_expr const*);

void print(Printer&, Decl const*);
void print(Printer&, Variable_decl const*);
void print(Printer&, Constant_decl const*);
void print(Printer&, Function_decl const*);
void print(Printer&, Parameter_decl const*);
void print(Printer&, Member_decl const*);
void print(Printer&, Record_decl const*);
void print(Printer&, Variant_decl const*);
void print(Printer&, Enum_decl const*);
void print(Printer&, Decode_decl const*);
void print(Printer&, Enum_decl const*);

void print(Printer&, Stmt const*);
void print(Printer&, Empty_stmt const*);
void print(Printer&, Expr_stmt const*);
void print(Printer&, Decl_stmt const*);
void print(Printer&, Block_stmt const*);
void print(Printer&, Return_stmt const*);
void print(Printer&, Match_case_stmt const*);
void print(Printer&, Match_stmt const*);

void print(Printer&, Match_term const*);


inline std::ostream& 
operator<<(std::ostream& os, Type const* t)
{
  return os << to_string(t);
}


inline std::ostream&
operator<<(std::ostream& os, Expr const* e)
{
  return os << to_string(e);
}


inline std::ostream& 
operator<<(std::ostream& os, Decl const* d)
{
  return os << to_string(d);
}


inline std::ostream& 
operator<<(std::ostream& os, Stmt const* s)
{
  return os << to_string(s);
}


} // namespace steve


#endif


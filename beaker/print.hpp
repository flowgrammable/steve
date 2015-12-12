// Copyright (c) 2015 Andrew Sutton
// All rights reserved

#ifndef BEAKER_PRINT_HPP
#define BEAKER_PRINT_HPP

#include <beaker/prelude.hpp>

#include <iosfwd>

std::ostream& operator<<(std::ostream&, Stmt const&);
std::ostream& operator<<(std::ostream&, Empty_stmt const&);
std::ostream& operator<<(std::ostream&, Block_stmt const&);
std::ostream& operator<<(std::ostream&, Assign_stmt const&);
std::ostream& operator<<(std::ostream&, Return_stmt const&);
std::ostream& operator<<(std::ostream&, If_then_stmt const&);
std::ostream& operator<<(std::ostream&, If_else_stmt const&);
std::ostream& operator<<(std::ostream&, Match_stmt const&);
std::ostream& operator<<(std::ostream&, Case_stmt const&);
std::ostream& operator<<(std::ostream&, While_stmt const&);
std::ostream& operator<<(std::ostream&, Break_stmt const&);
std::ostream& operator<<(std::ostream&, Continue_stmt const&);
std::ostream& operator<<(std::ostream&, Expression_stmt const&);
std::ostream& operator<<(std::ostream&, Declaration_stmt const&);
std::ostream& operator<<(std::ostream&, Decode_stmt const&);
std::ostream& operator<<(std::ostream&, Goto_stmt const&);

std::ostream& operator<<(std::ostream& os, Action const&);
std::ostream& operator<<(std::ostream& os, Drop const&);
std::ostream& operator<<(std::ostream& os, Output const&);

std::ostream& operator<<(std::ostream&, Decl const&);
std::ostream& operator<<(std::ostream&, Variable_decl const&);
std::ostream& operator<<(std::ostream&, Function_decl const&);
std::ostream& operator<<(std::ostream&, Parameter_decl const&);
std::ostream& operator<<(std::ostream&, Record_decl const&);
std::ostream& operator<<(std::ostream&, Field_decl const&);
std::ostream& operator<<(std::ostream&, Module_decl const&);

// network declarations
std::ostream& operator<<(std::ostream&, Layout_decl const&);
std::ostream& operator<<(std::ostream&, Decode_decl const&);
std::ostream& operator<<(std::ostream&, Table_decl const&);
std::ostream& operator<<(std::ostream&, Key_decl const&);
std::ostream& operator<<(std::ostream&, Flow_decl const&);
std::ostream& operator<<(std::ostream&, Port_decl const&);
std::ostream& operator<<(std::ostream&, Extracts_decl const&);
std::ostream& operator<<(std::ostream&, Rebind_decl const&);


std::ostream& operator<<(std::ostream&, Type const&);
std::ostream& operator<<(std::ostream&, Id_type const&);
std::ostream& operator<<(std::ostream&, Boolean_type const&);
std::ostream& operator<<(std::ostream&, Character_type const&);
std::ostream& operator<<(std::ostream&, Integer_type const&);
std::ostream& operator<<(std::ostream&, Function_type const&);
std::ostream& operator<<(std::ostream&, Block_type const&);
std::ostream& operator<<(std::ostream&, Array_type const&);
std::ostream& operator<<(std::ostream&, Reference_type const&);
std::ostream& operator<<(std::ostream&, Record_type const&);
std::ostream& operator<<(std::ostream&, Void_type const&);

// network specific types
std::ostream& operator<<(std::ostream&, Layout_type const&);
std::ostream& operator<<(std::ostream&, Context_type const&);
std::ostream& operator<<(std::ostream&, Table_type const&);
std::ostream& operator<<(std::ostream&, Flow_type const&);
std::ostream& operator<<(std::ostream&, Port_type const&);
std::ostream& operator<<(std::ostream&, Key_type const&);


std::ostream& operator<<(std::ostream&, Expr const&);
std::ostream& operator<<(std::ostream&, Literal_expr const&);
std::ostream& operator<<(std::ostream&, Id_expr const&);
std::ostream& operator<<(std::ostream&, Decl_expr const&);
std::ostream& operator<<(std::ostream&, Add_expr const&);
std::ostream& operator<<(std::ostream&, Sub_expr const&);
std::ostream& operator<<(std::ostream&, Mul_expr const&);
std::ostream& operator<<(std::ostream&, Div_expr const&);
std::ostream& operator<<(std::ostream&, Rem_expr const&);
std::ostream& operator<<(std::ostream&, Neg_expr const&);
std::ostream& operator<<(std::ostream&, Pos_expr const&);
std::ostream& operator<<(std::ostream&, Eq_expr const&);
std::ostream& operator<<(std::ostream&, Ne_expr const&);
std::ostream& operator<<(std::ostream&, Lt_expr const&);
std::ostream& operator<<(std::ostream&, Gt_expr const&);
std::ostream& operator<<(std::ostream&, Le_expr const&);
std::ostream& operator<<(std::ostream&, Ge_expr const&);
std::ostream& operator<<(std::ostream&, And_expr const&);
std::ostream& operator<<(std::ostream&, Or_expr const&);
std::ostream& operator<<(std::ostream&, Not_expr const&);
std::ostream& operator<<(std::ostream&, Call_expr const&);
std::ostream& operator<<(std::ostream&, Dot_expr const&);
std::ostream& operator<<(std::ostream&, Field_expr const&);
std::ostream& operator<<(std::ostream&, Method_expr const&);
std::ostream& operator<<(std::ostream&, Index_expr const&);
std::ostream& operator<<(std::ostream&, Value_conv const&);
std::ostream& operator<<(std::ostream&, Block_conv const&);
std::ostream& operator<<(std::ostream&, Promotion_conv const&);
std::ostream& operator<<(std::ostream&, Demotion_conv const&);
std::ostream& operator<<(std::ostream&, Default_init const&);
std::ostream& operator<<(std::ostream&, Copy_init const&);
std::ostream& operator<<(std::ostream&, Dot_expr const&);
std::ostream& operator<<(std::ostream&, Reference_init const&);
std::ostream& operator<<(std::ostream&, Field_name_expr const&);
std::ostream& operator<<(std::ostream&, Field_access_expr const&);
std::ostream& operator<<(std::ostream&, Reinterpret_cast const&);

std::ostream& operator<<(std::ostream&, Get_port const&);
std::ostream& operator<<(std::ostream&, Create_table const&);

std::ostream& operator<<(std::ostream&, Decl const&);
std::ostream& operator<<(std::ostream&, Variable_decl const&);
std::ostream& operator<<(std::ostream&, Function_decl const&);
std::ostream& operator<<(std::ostream&, Parameter_decl const&);
std::ostream& operator<<(std::ostream&, Record_decl const&);
std::ostream& operator<<(std::ostream&, Field_decl const&);
std::ostream& operator<<(std::ostream&, Method_decl const&);
std::ostream& operator<<(std::ostream&, Module_decl const&);

#endif

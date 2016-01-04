// Copyright (c) 2015 Andrew Sutton
// All rights reserved

#ifndef BEAKER_PRELUDE_HPP
#define BEAKER_PRELUDE_HPP

#include <beaker/config.hpp>

#include <lingo/assert.hpp>
#include <lingo/string.hpp>
#include <lingo/node.hpp>
#include <lingo/print.hpp>
#include <lingo/io.hpp>

#include <iosfwd>
#include <vector>
#include <stdexcept>
#include <type_traits>
#include <boost/multiprecision/cpp_int.hpp>


// Bring lingo into scope.
using namespace lingo;


// Bring specific functions in as overloads
// to support argument dependent lookup.
using lingo::is;
using lingo::as;
using lingo::cast;


struct Expr;
struct Literal_expr;
struct Id_expr;
struct Decl_expr;
struct Overload_expr;
struct Add_expr;
struct Sub_expr;
struct Mul_expr;
struct Div_expr;
struct Rem_expr;
struct Neg_expr;
struct Pos_expr;
struct Eq_expr;
struct Ne_expr;
struct Lt_expr;
struct Gt_expr;
struct Le_expr;
struct Ge_expr;
struct And_expr;
struct Or_expr;
struct Not_expr;
struct Call_expr;
struct Dot_expr;
struct Field_expr;
struct Method_expr;
struct Index_expr;
struct Reinterpret_cast;
struct Conv;
struct Value_conv;
struct Block_conv;
struct Promotion_conv;
struct Demotion_conv;
struct Sign_conv;
struct Init;
struct Default_init;
struct Copy_init;
struct Reference_init;
struct Field_name_expr;
struct Field_access_expr;

struct Type;
struct Id_type;
struct Boolean_type;
struct Character_type;
struct Integer_type;
struct Function_type;
struct Array_type;
struct Block_type;
struct Reference_type;
struct Record_type;
struct Reference_type;
struct Layout_type;
struct Table_type;
struct Flow_type;
struct Port_type;
struct Void_type;
struct Context_type;
struct Key_type;
struct Opaque_type;

struct Decl;
struct Record_decl;
struct Member_decl;
struct Variable_decl;
struct Function_decl;
struct Parameter_decl;
struct Record_decl;
struct Field_decl;
struct Method_decl;
struct Module_decl;
struct Layout_decl;
struct Decode_decl;
struct Table_decl;
struct Key_decl;
struct Flow_decl;
struct Extracts_decl;
struct Rebind_decl;
struct Port_decl;

struct Stmt;
struct Empty_stmt;
struct Block_stmt;
struct Assign_stmt;
struct Return_stmt;
struct Return_void_stmt;
struct If_then_stmt;
struct If_else_stmt;
struct Match_stmt;
struct Case_stmt;
struct While_stmt;
struct Break_stmt;
struct Continue_stmt;
struct Expression_stmt;
struct Declaration_stmt;

// Network specific
struct Decode_stmt;
struct Goto_stmt;

// Builtins
struct Bind_offset;
struct Bind_header;
struct Alias_bind;
struct Load_field;
struct Create_table;
struct Delete_table;
struct Lookup;
struct Advance;

// Builtin expressions that need special code gen
struct Get_port;
struct Create_table;
struct Get_dataplane;

// Actions
struct Goto_stmt;
struct Action;
struct Drop;
struct Output;
struct Group;
struct Set_field;
struct Copy_field;
struct Write_drop_stmt;
struct Write_output_stmt;
struct Write_set_field;
struct Write_copy_field;

using Expr_seq = std::vector<Expr*>;
using Type_seq = std::vector<Type const*>;
using Decl_seq = std::vector<Decl*>;
using Stmt_seq = std::vector<Stmt*>;

using uint128_t = boost::multiprecision::checked_uint128_t;
using uint512_t = boost::multiprecision::checked_uint512_t;

#include <beaker/symbol.hpp> // TODO: Do I need this?
#include <beaker/print.hpp>

#endif

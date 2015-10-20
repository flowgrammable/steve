// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#ifndef STEVE_PRELUDE_HPP
#define STEVE_PRELUDE_HPP

// This module provides declarations used in ever module
// in the implementation. It should be the first include
// in each header file.

// Strings
#include "lingo/string.hpp"

// Arbitrary precision integers.
#include "lingo/integer.hpp"

// Runtime checks and diagnostics.
#include "lingo/error.hpp"

// AST concepts and operations.
#include "lingo/node.hpp"

// Memory facilities.
#include "lingo/memory.hpp"

// Pretty printing.
#include "lingo/print.hpp"

// Compiler debugging.
#include "lingo/debug.hpp"

// Support sequences of terms.
#include <vector>

// Supporting Program abstraction
#include <list>


namespace steve
{

// Lingo imports
using namespace lingo;

// Overloaded functions
using lingo::is;
using lingo::as;
using lingo::cast;
using lingo::modify;
using lingo::print;
using lingo::debug;
using lingo::mark;


// Steve terms
struct Type;
struct Default_type;
struct Kind_type;
struct Void_type;
struct Boolean_type;
struct Integer_type;
struct Constant_type;
struct Reference_type;
struct Function_type;
struct Array_type;
struct Tuple_type;
struct Record_type;
struct Enum_type;
struct Variant_type;
struct Match_type;
struct Decode_type;
struct If_type;
struct Seq_type;
struct Buffer_type;
struct Until_type;
struct Table_type;
struct Flow_type;

struct Prop;

struct Expr;
struct Id_expr;
struct Constant_expr;
struct Lookup_expr;
struct Default_expr;
struct Init_expr;
struct Value_expr;
struct Unary_expr;
struct Binary_expr;
struct Call_expr;
struct Tuple_expr;
struct Index_expr;
struct Member_expr;
struct Convert_expr;
struct Field_expr;
struct Do_expr;
struct Lengthof_expr;
struct Offsetof_expr;
struct Headerof_expr;
struct Insert_expr;
struct Delete_expr;
struct Field_idx_expr;
struct Header_idx_expr;
struct Header_cast_expr;

struct Decl;
struct Variable_decl;
struct Constant_decl;
struct Function_decl;
struct Parameter_decl;
struct Record_decl;
struct Member_decl;
struct Enum_decl;
struct Variant_decl;
struct Forward_decl;
struct Decode_decl;
struct Table_decl;
struct Flow_decl;
struct Extracts_decl;
struct Rebind_decl;

struct Stmt;
struct Empty_stmt;
struct Expr_stmt;
struct Decl_stmt;
struct Block_stmt;
struct Return_stmt;
struct Match_stmt;
struct Case_stmt;
struct Instruct_stmt;

struct Value;

struct Match_term;

struct Pipeline;
struct Stage;

// A sequence of types.
using Type_seq = std::vector<Type const*>;


// A sequence of expressions.
using Expr_seq = std::vector<Expr const*>;


// A sequence of declarations.
using Decl_seq = std::vector<Decl const*>;


// A list of statements.
using Stmt_seq = std::vector<Stmt const*>;


// The concept of a program is a sequence of stmts
struct Program : Stmt_seq
{
  void push(Stmt const* s) { this->push_back(s); }
};

} // namespace steve


// Include core printing.
#include "steve/print.hpp"

// Include core debugging.
#include "steve/debug.hpp"

#endif


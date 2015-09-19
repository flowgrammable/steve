// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#ifndef STEVE_BUILDER_HPP
#define STEVE_BUILDER_HPP

// The builder module provides a simplified interface for
// constructing program elements.

#include "type.hpp"
#include "expr.hpp"
#include "decl.hpp"
#include "stmt.hpp"


namespace steve
{


// Boolean constants

inline Value_expr*
truth() { return make_true_expr(); }


inline Value_expr*
falsity() { return make_false_expr(); }


// Integer constants

inline Value_expr*
make_int(int n, Type const* t) { return make_value_expr(t, Value(n)); }


inline Value_expr*
make_int(int n) { return make_int(n, get_int_type()); }


inline Value_expr*
make_short(int n) { return make_int(n, get_short_type()); }


inline Value_expr*
make_long(int n) { return make_int(n, get_long_type()); }


inline Value_expr*
make_uint(int n) { return make_int(n, get_uint_type()); }


inline Value_expr*
make_ulong(int n) { return make_int(n, get_ulong_type()); }


inline Value_expr*
make_msbf(int n, int p = 32) { return make_int(n, get_msbf_type(p)); }


inline Value_expr*
make_lsbf(int n, int p = 32) { return make_int(n, get_lsbf_type(p)); }


inline Value_expr*
make_umsbf(int n, int p = 32) { return make_int(n, get_umsbf_type(p)); }


inline Value_expr*
make_ulsbf(int n, int p = 32) { return make_int(n, get_ulsbf_type(p)); }


// Named integer constants.

inline Value_expr*
zero() { return make_int(0); }


inline Value_expr*
zero(Type const* t) { return make_int(0, t); }


inline Value_expr*
one() { return make_int(1); }


inline Value_expr*
one(Type const* t) { return make_int(1, t); }


inline Value_expr*
two() { return make_int(2); }


inline Value_expr*
two(Type const* t) { return make_int(2, t); }


// Id expressions

inline Id_expr*
id(Decl const* d) { return make_id_expr(d); }


// Arithmetic expressions

// Make the expression `e1 + e2`. If either are null,
// returns the other operand.
//
// TODO: Do this with all associative operators.
inline Expr const*
add(Expr const* e1, Expr const* e2) 
{
  lingo_assert(e1 || e2);
  if (!e1)
    return e2;
  if (!e2)
    return e1;
  return make_add_expr(e1, e2); 
}


inline Binary_expr*
sub(Expr const* e1, Expr const* e2) { return make_sub_expr(e1, e2); }


inline Binary_expr*
mul(Expr const* e1, Expr const* e2) { return make_mul_expr(e1, e2); }


inline Binary_expr*
div(Expr const* e1, Expr const* e2) { return make_div_expr(e1, e2); }


inline Binary_expr*
mod(Expr const* e1, Expr const* e2) { return make_mod_expr(e1, e2); }


inline Unary_expr*
neg(Expr const* e) { return make_neg_expr(e); }


inline Unary_expr*
pos(Expr const* e) { return make_pos_expr(e); }


// Bitwise expressions

inline Binary_expr*
band(Expr const* e1, Expr const* e2) { return make_bitwise_and_expr(e1, e2); }


inline Binary_expr*
bor(Expr const* e1, Expr const* e2) { return make_bitwise_or_expr(e1, e2); }


inline Binary_expr*
bxor(Expr const* e1, Expr const* e2) { return make_bitwise_xor_expr(e1, e2); }


inline Unary_expr*
bnot(Expr const* e) { return make_bitwise_not_expr(e); }


inline Binary_expr*
lsh(Expr const* e1, Expr const* e2) { return make_bitwise_lsh_expr(e1, e2); }


inline Binary_expr*
rsh(Expr const* e1, Expr const* e2) { return make_bitwise_rsh_expr(e1, e2); }


// Relatioal expressions

inline Binary_expr*
eq(Expr const* e1, Expr const* e2) { return make_eq_expr(e1, e2); }


inline Binary_expr*
ne(Expr const* e1, Expr const* e2) { return make_ne_expr(e1, e2); }


inline Binary_expr*
lt(Expr const* e1, Expr const* e2) { return make_lt_expr(e1, e2); }


inline Binary_expr*
gt(Expr const* e1, Expr const* e2) { return make_gt_expr(e1, e2); }


inline Binary_expr*
le(Expr const* e1, Expr const* e2) { return make_le_expr(e1, e2); }


inline Binary_expr*
ge(Expr const* e1, Expr const* e2) { return make_ge_expr(e1, e2); }


// Logical expressions

inline Binary_expr*
land(Expr const* e1, Expr const* e2) { return make_logical_and_expr(e1, e2); }


inline Binary_expr*
lor(Expr const* e1, Expr const* e2) { return make_logical_and_expr(e1, e2); }


inline Unary_expr*
lnot(Expr const* e) { return make_logical_not_expr(e); }


// Function calls

inline Call_expr*
call(Expr const* f, Expr_seq const& a)
{
  return make_call_expr(f, a);
}


inline Call_expr*
call(Decl const* f, Expr_seq const& a)
{
  return make_call_expr(id(f), a);
}


// Tuples

inline Tuple_expr*
make_tuple()
{
  return make_tuple_expr({});
}


inline Tuple_expr*
make_tuple(Expr_seq const& e)
{
  return make_tuple_expr(e);
}


// Statements

// Build the statement `;`.
inline Empty_stmt*
empty()
{
  return make_empty_stmt();
}


// Build the statement `{ s1; ...; sn }`.
inline Block_stmt*
block(Stmt_seq const& s)
{
  return make_block_stmt(s);
}


// Build the statement `return e`.
inline Return_stmt*
ret(Expr const* e)
{
  return make_return_stmt(e);
}


// Variable declarations

inline Decl* 
make_var(char const* n, Type const* t, Expr const* e)
{
  return make_variable_decl(get_identifier(n), t, e);
}


inline Decl* 
make_bool_var(char const* n, Expr const* e)
{
  return make_var(n, get_bool_type(), e);
}


inline Decl* 
make_int_var(char const* n, Expr const* e)
{
  return make_var(n, get_int_type(), e);
}


// Function declaratoins

inline Parameter_decl*
make_parm(char const* n, Type const* t)
{
  return make_parameter_decl(get_identifier(n), t);
}


inline Parameter_decl*
make_bool_parm(char const* n)
{
  return make_parm(n, get_bool_type());
}


inline Parameter_decl*
make_int_parm(char const* n)
{
  return make_parm(n, get_int_type());
}


// Defines a void function with an empty statement.
inline Function_decl*
make_fn(char const* n, Decl_seq const& p)
{
  return make_function_decl(get_identifier(n), p, get_void_type(), block({}));
}


// Defines a void function with no statement block (forward-decl)
inline Function_decl*
make_forward_fn(char const* n, Decl_seq const& p)
{
  return make_function_decl(get_identifier(n), p, get_void_type(), nullptr);
}


// Defines a function with the given parameters and type and
// a sequence of statements. This constructs a block around the
// statement sequence.
inline Function_decl*
make_fn(char const* n, Decl_seq const& p, Type const* t, Stmt_seq const& s)
{
  return make_function_decl(get_identifier(n), p, t, block({s}));
}


// Record declarations


inline Member_decl*
make_member(char const* n, Type const* t)
{
  return make_member_decl(get_identifier(n), t);
}


inline Member_decl*
make_bool_member(char const* n)
{
  return make_member(n, get_bool_type());
}


inline Member_decl*
make_int_member(char const* n)
{
  return make_member(n, get_int_type());
}


inline Record_decl*
make_record(char const* n, Decl_seq const& m)
{
  return make_record_decl(get_identifier(n), m);
}


// Other...


inline Stmt*
make_case(Expr const* e, Stmt const* s)
{
  return make_case_stmt(e, s);
}


inline Stmt*
make_match(Expr const* e, Stmt_seq const& s)
{
  return make_match_stmt(e, s);
}


inline Decl*
make_decode(char const* n, Type const* t, Stmt const* s)
{
  return make_decode_decl(get_identifier(n), t, s);
}


inline Member_decl*
make_record_member(char const* n, Record_decl* d)
{
  return make_member(n, get_record_type(d));
}


} // namespace


#endif

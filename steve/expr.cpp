// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "steve/expr.hpp"
#include "steve/type.hpp"
#include "steve/decl.hpp"
#include "steve/convert.hpp"

#include <iostream>

namespace steve
{

// Returns the name of the node. This is the same
// as the class name.
String
Expr::node_name() const
{
  return type_str(*this);
}


// -------------------------------------------------------------------------- //
//                            Node definitions

Id_expr::Id_expr(Location loc, Decl const* d)
  : Expr(loc, d->type()), decl_(d)
{ }


String const* 
Id_expr::name() const
{
  return decl_->name();
}


// FIXME: What is the type of an overload set. For now, its
// set to the void type. 
Lookup_expr::Lookup_expr(Location loc, String const* s)
  : Expr(loc, get_void_type()), first(s)
{ }


// -------------------------------------------------------------------------- //
//                            Expression builders


// Return a declration expression.
Id_expr*
make_id_expr(Location loc, Decl const* d)
{
  return new Id_expr(loc, d);
}


// Returns a new unresolved lookup expression.
Lookup_expr*
make_lookup_expr(Location loc, String const* s)
{
  return new Lookup_expr(loc, s);
}


// Returns a new default expression.
Default_expr*
make_default_expr(Location loc, Type const* t)
{
  return new Default_expr(loc, t);
}


// Returns a new initialization expression.
Init_expr*
make_init_expr(Init_kind k, Expr const* e)
{
  return new Init_expr(k, e);
}


Init_expr*
make_init_expr(Location loc, Init_kind k)
{
  return new Init_expr(loc, k);
}


// Create a baoolean expression with value `b`.
Value_expr*
make_bool_expr(Location loc, bool b)
{
  return new Value_expr(loc, get_bool_type(), Integer_value(b));
}


// Create an integer expression with value `n`.
Value_expr*
make_int_expr(Location loc, Integer const& n)
{
  // An Integer is an Integer_value, so we don't need to cast.
  return new Value_expr(loc, get_int_type(), n);
}


// Create a value expression having type `t`.
//
// TODO: Can we at all check to see if the value conforms
// to the type? Probably not.
Value_expr*
make_value_expr(Location loc, Type const* t, Value const& n)
{
  return new Value_expr(loc, t, n);
}


namespace
{

// Returns true if `e` has arithmetic or enum type.
inline bool
has_arithmetic_or_enum_type(Expr const* e) 
{
  return is_arithmetic_type(e->type()) || is_enum_type(e->type());
}


// Creeates a unary arithmetic expression. 
//
// The operand of an arithmetic unary expression shall have arithmetic 
// or enumeration type. Thee operand is promoted and the result type 
// is the type of the promoted operand.
//
// Note that we include bool in the arithmetic tpyes. This allows
// expressions like `~b` or `-b` to have meaning.
//
// TODO: Allow operator overloading for user-defined types.
Unary_expr*
make_arithmetic_expr(Location loc, Unary_op op, Expr const* e)
{
  if (!has_arithmetic_or_enum_type(e)) {
    error(loc, "invalid operand for '{}'", op);
    return nullptr;
  }

  // Promote the operand.
  Expr const* c = promote(e);

  // Build the expression.
  return gc().make<Unary_expr>(loc, c->type(), op, c);
}


// Create an arithmetic binary expression.
//
// The operand shall have arithmetic or enumeration type. The 
// operands are first converted to their common type. The result
// type is the common type.
Binary_expr*
make_arithmetic_expr(Location loc, Binary_op op, Expr const* e1, Expr const* e2)
{
  if (!has_arithmetic_or_enum_type(e1) || !has_arithmetic_or_enum_type(e2)) {
    error(loc, "invalid operands for '{}'", op);
    return nullptr;
  }

  Converted_pair c = convert_to_common_type(e1, e2);
  if (!c)
    return nullptr;
  return new Binary_expr(loc, c.type(), op, c.first, c.second);
}


// Creates a relational binary expression.
//
// The operands are converted to their common type. The result 
// type is bool.
//
// FIXME: What are the type requirements on relational expressions.
// We support == and < for arithmetic types (evne bool? sure),
// enum types, record types, tuple tpye.
Binary_expr*
make_relational_expr(Location loc, Binary_op op, Expr const* e1, Expr const* e2)
{
  Converted_pair c = convert_to_common_type(e1, e2);
  if (!c)
    return nullptr;
  return new Binary_expr(loc, get_bool_type(), op, c.first, c.second);
}


// Creates a unary logical expression.
//
// The operand of a unary logical expression is be contextually
// converted to bool. If no such conversion exists, the program
// is ill-formed. The result type is bool.
Unary_expr*
make_logical_expr(Location loc, Unary_op op, Expr const* e)
{
  Expr const* c = convert_to_boolean_type(e);
  if (!c)
    return nullptr;
  return new Unary_expr(loc, c->type(), op, c);
}


// Creates a binary logical expression.
Binary_expr*
make_logical_expr(Location loc, Binary_op op, Expr const* e1, Expr const* e2)
{
  Expr const* c1 = convert_to_boolean_type(e1);
  Expr const* c2 = convert_to_boolean_type(e2);
  if (!c1 || !c2)
    return nullptr;

  return new Binary_expr(loc, get_bool_type(), op, c1, c2);
}


} // namespace



// Creates a unary expression.
Unary_expr*
make_unary_expr(Location loc, Unary_op op, Expr const* e)
{
  switch (op) {
    case num_neg_op:
    case num_pos_op:
    case bit_not_op:
      return make_arithmetic_expr(loc, op, e);
    
    case log_not_op:
      return make_logical_expr(loc, op, e);
  }
  lingo_unreachable("invalid unary operator ({})", (int)op);
}


// Return a type-checked binary expression.
Binary_expr*
make_binary_expr(Location loc, Binary_op op, Expr const* e1, Expr const* e2)
{
  switch (op) {
    case num_add_op:
    case num_sub_op:
    case num_mul_op:
    case num_div_op:
    case num_mod_op:
    case bit_and_op:
    case bit_or_op:
    case bit_xor_op:
    case bit_lsh_op:
    case bit_rsh_op:
      return make_arithmetic_expr(loc, op, e1, e2);
    
    case rel_eq_op:
    case rel_ne_op:
    case rel_lt_op:
    case rel_gt_op:
    case rel_le_op:
    case rel_ge_op:
      return make_relational_expr(loc, op, e1, e2);

    case log_and_op:
    case log_or_op:
      return make_logical_expr(loc, op, e1, e2);
  }
  lingo_unreachable("invalid binary operator ({})", (int)op);
}


// Create a new call expression.
Call_expr*
make_call_expr(Location loc, Expr const* f, Expr_seq const& args)
{
  // Get the type of the function (expression).
  Function_type const* type = as<Function_type>(f->type());
  if (!type) {
    error(loc, "'{}' is not a callable type");
    return nullptr;
  }
  Type_seq const& parms = type->parm_types();
  Type const* ret = type->ret_type();

  // Convert arguments to operands.
  if (Converted_args conv = convert_to_parameter_types(loc, args, parms))
    return new Call_expr(loc, ret, f, conv);
  else
    return nullptr;
}



// Make a tuple expression.
Tuple_expr*
make_tuple_expr(Location loc, Expr_seq const& es)
{
  if (Required<Type> t = type_tuple_expr(es))
    return new Tuple_expr(loc, *t, es);
  else
    return make_error_node<Tuple_expr>();
}


// Make a member expression.
//
// TODO: We could actually reduce 'n' to remove redundant
// compile-time processing. Required do this in a FE optimization
// pass since nested indexes can be folded to a single offset
// expression (which we don't have yet).
Index_expr*
make_index_expr(Location loc, Expr const* e, Expr const* n)
{
  if (Required<Type> t = type_index_expr(e, n))
    return new Index_expr(loc, *t, e, n);
  else
    return make_error_node<Index_expr>();
}


// Transform a member expression into an index expression
// by resolving the member reference.
Index_expr*
make_index_expr(Location loc, Member_expr const* e)
{
  Record_type const* t = cast<Record_type>(e->object()->type());
  Record_decl const* r = cast<Record_decl>(t->decl());
  Member_decl const* m = cast<Member_decl>(e->selector()->decl());
  Expr const* n = make_int_expr(member_index(r, m));
  return make_index_expr(loc, e->object(), n);
}


// Make a member expression.
//
// TODO: We could actually reduce this to an index expression
// or an offset expression (but this requires value flattening
// and offset computations).
Member_expr*
make_member_expr(Location loc, Expr const* e, Expr const* n)
{
  if (Required<Type> t = type_member_expr(e, n))
    return new Member_expr(loc, *t, e, n);
  else
    return make_error_node<Member_expr>();
}


// Make a field expr
Field_expr*
make_field_expr(Location loc, Expr const* r, Expr const* f)
{
  if(Required<Type> t = type_field_expr(r, f))
    // Field_expr serve as indices. The type check is used later
    // to determine the type of the fld idx expr

    // FIXME: the GC or some container has to ensure the uniqueness of these
    // otherwise name resolution is undefined behavior and I have no idea how or why
    return gc().make<Field_expr>(loc, get_int_type(), *t, r, f);
  else
    return make_error_node<Field_expr>();
}


// Make a conversion expression.
//
// This function must only ever be called from convert().
Convert_expr*
make_convert_expr(Location loc, Type const* t, Conversion_kind k, Expr const* e)
{
  return new Convert_expr(loc, t, k, e);
}


// Make a length-of expression.
Expr*
make_lengthof_expr(Location loc, Expr const* e)
{
  return new Lengthof_expr(loc, get_uint_type(), e);
}


// Make a header of expr
Expr*
make_headerof_expr(Location loc, Decl const* d)
{
  lingo_assert(is<Decode_decl>(d));
  return new Headerof_expr(loc, get_kind_type(), d);
}


Insert_expr*
make_insert_expr(Location loc, Decl const* flw, Expr const* tbl)
{
  lingo_assert(is<Table_type>(tbl->type()));
  lingo_assert(is<Flow_decl>(flw));

  return new Insert_expr(loc, get_void_type(), flw, tbl);
}


Delete_expr*
make_delete_expr(Location loc, Decl const* flw, Expr const* tbl)
{
  lingo_assert(is<Table_type>(tbl->type()));
  lingo_assert(is<Flow_decl>(flw));

  return new Delete_expr(loc, get_void_type(), flw, tbl);
}


Do_expr*
make_do_expr(Location loc, Do_kind k, Expr const* e)
{
  switch(k) {
    case decode:
      if(!check_do_decode_stmt(e))
        return nullptr;
      break;
    case table:
      if(!check_do_table_stmt(e))
        return nullptr;
      break;
  }

  return new Do_expr(loc, get_void_type(), k, e);
}


// -------------------------------------------------------------------------- //
//              Resolving field expr names
String const*
resolve_field_name(Field_expr const* e)
{
  if (is<Id_expr>(e->record())) {
    String name = *(as<Id_expr>(e->record())->name()) + '.' + *(as<Id_expr>(e->field())->name());
    // std::cout << (void*) as<Id_expr>(e->record())->name() << ' ';
    // std::cout << (void*) as<Id_expr>(e->field())->name() << ' ';
    // std::cout << (void*) get_identifier(name) << ' ';
    // print(name);
    return get_identifier(name);
  }
  else if (is<Field_expr>(e->record())) {
    String name = *resolve_field_name(as<Field_expr>(e->record())) + '.' + *as<Id_expr>(e->field())->name();
    return get_identifier(name);
  }
  else
    error(e->location(), "'{}' is not a valid field.", e);

  return nullptr;
}


//
// TODO: Actually typecheck the epxression. `e` must have
// the same type as the record in which `m` is declared.
Expr*
make_offsetof_expr(Location loc, Expr const* e, Decl const* m)
{
  return new Offsetof_expr(loc, get_uint_type(), e, m);
}


Field_idx_expr*
make_fld_idx_expr(Location loc, Expr const* e)
{
  lingo_assert(is<Field_expr>(e));

  Field_expr const* f = cast<Field_expr>(e);

  return new Field_idx_expr(loc, f->field_type(), f);
}


Header_idx_expr*
make_hdr_idx_expr(Location loc, Expr const* e)
{
  lingo_assert(is<Id_expr>(e));

  Id_expr const* id = cast<Id_expr>(e);

  lingo_assert(is<Record_decl>(id->decl()));

  return new Header_idx_expr(loc, id->type(), id);
}


// -------------------------------------------------------------------------- //
//                                   Queries

// A boolean expression has type `bool`.
bool
is_boolean_expr(Expr const* e)
{
  return is<Boolean_type>(e->type());
}


// An itneger expression has type `int`.
bool
is_integer_expr(Expr const* e)
{
  return is<Integer_type>(e->type());
}


// Returns true if `e` has record type.
bool
has_record_type(Expr const* e)
{
  return is<Record_type>(e->type());
}


// Returns true if `e` has enum type.
bool
has_enum_type(Expr const* e)
{
  return is<Enum_type>(e->type());
}


// Converts a field expression
// into the member declaration it refers to
Member_decl const*
field_to_member(Field_expr const* e)
{
  Expr const* r = e->record();
  Expr const* f = e->field();
  // 'r' is either a record identifier
  // or it is an expression that has record type
  Decl const* rd; 
  
  if (is<Id_expr>(r)) {
    rd = cast<Id_expr>(r)->decl();
  }
  else if (Field_expr const* fe = as<Field_expr>(r)) {
    if (Record_type const* rt = as<Record_type>(fe->field_type()))
      rd = rt->decl();
  }
  else {
    error(r->location(), "invalid term '{}' is not a record identifier nor record type", r);
    return nullptr;
  }

  // This must be a record decl
  lingo_assert(is<Record_decl>(rd));
  Record_decl const* rec = cast<Record_decl>(rd);

  if (!is<Id_expr>(f)) {
    error(f->location(), "invalid member selector '{}'", f);
    return nullptr;
  }
  
  Decl const* mem = cast<Id_expr>(f)->decl();
  
  // The declaration had better be a member. Otherwise the program
  // is internally inconsistent: lookup of a member name returned a
  // non-member.
  lingo_assert(is<Member_decl>(mem));
  lingo_assert(has_member(rec, cast<Member_decl>(mem)));

  return cast<Member_decl>(mem);
}


} // namespace steve


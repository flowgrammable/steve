// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#ifndef STEVE_EXPR_HPP
#define STEVE_EXPR_HPP

// The expr module defines the expressions in the language
// and various tools for working with them.

#include "steve/prelude.hpp"
#include "steve/value.hpp"
#include "steve/op.hpp"
#include "steve/convert.hpp"
#include "steve/overload.hpp"

#include "lingo/integer.hpp"
#include "lingo/node.hpp"


namespace steve
{

struct Expr_visitor;

String const* resolve_field_name(Field_expr const*);

// -------------------------------------------------------------------------- //
//                                Expressions

// The Expr class represents the set of all expressions
// in the language.
//
// Every expression has a type. The type of an expression
// determines whether or not that expression is a valid
// sub-expression of a larger expression.
struct Expr
{
  Expr(Location l, Type const* t)
    : loc_(l), type_(t)
  { }

  virtual ~Expr()
  { }

  String      node_name() const;
  Location    location() const  { return loc_; }
  Type const* type() const      { return type_; }

  virtual void accept(Expr_visitor&) const = 0;

  void set_type(Type const* t) { type_ = t; }

  Location    loc_;
  Type const* type_;
};


// The expression visitor.
struct Expr_visitor
{
  virtual void visit(Id_expr const*) { }
  virtual void visit(Constant_expr const*) { }
  virtual void visit(Lookup_expr const*) { }
  virtual void visit(Default_expr const*) { }
  virtual void visit(Init_expr const*) { }
  virtual void visit(Value_expr const*) { }
  virtual void visit(Unary_expr const*) { }
  virtual void visit(Binary_expr const*) { }
  virtual void visit(Call_expr const*) { }
  virtual void visit(Tuple_expr const*) { }
  virtual void visit(Index_expr const*) { }
  virtual void visit(Member_expr const*) { }
  virtual void visit(Field_expr const*) { }
  virtual void visit(Convert_expr const*) { }
  virtual void visit(Lengthof_expr const*) { }
  virtual void visit(Offsetof_expr const*) { }
  virtual void visit(Headerof_expr const*) { }
  virtual void visit(Do_expr const*) { }
  virtual void visit(Insert_expr const*) { }
  virtual void visit(Delete_expr const*) { }
  virtual void visit(Field_idx_expr const*) { }
  virtual void visit(Header_idx_expr const*) { }
};


// A reference to a declaration. The type of the expression
// is that of the referenced declaration.
struct Id_expr : Expr
{
  Id_expr(Location, Decl const*);

  String const* name() const;
  Decl const*   decl() const { return decl_; }
  void accept(Expr_visitor& v) const { v.visit(this); }

  Decl const* decl_;
};


// An expression that holds a constant value of some type. 
// Values are represented as widest integer type of the host 
// system.
struct Constant_expr : Expr
{
  Constant_expr(Location loc, Type const* t, Value n)
    : Expr(loc, t), value_(n)
  { }

  void accept(Expr_visitor& v) const { v.visit(this); }

  Value value() const { return value_; }

  Value value_;
};


// A lookup expr is an unresolved lookup. These are 
// during translation to indicate the presence of an 
// name that that does not refer to a single declaration.
// A name may refer to mulitple declarations, or it
// may refer to no declarations (but found via ADL).
//
// TODO: What is the type of a lookup expr.
struct Lookup_expr : Expr
{
  Lookup_expr(Location, String const*);

  String const* name() const { return first; }
  void accept(Expr_visitor& v) const { v.visit(this); }

  String const* first;
};


// An expression that holds a value. Note that the "shape" of
// the value (it's layout and properties) is determined by
// its type.
struct Value_expr : Expr
{
  Value_expr(Location loc, Type const* t, Value const& v)
    : Expr(loc, t), first(v)
  { }

  Value const& value() const { return first; }
  void accept(Expr_visitor& v) const { v.visit(this); }

  Value first;
};


// The default expression is a placeholder for an expression
// to be determined by the rules of the language. This can
// appear in a number of different contexts: a default initialized
// variable, the "otherwise" case for match statement, etc.
//
// The type of a default expression is determined from the context
// in which it appears.
struct Default_expr : Expr
{
  Default_expr(Location loc, Type const* t)
    : Expr(loc, t)
  { }

  void accept(Expr_visitor& v) const { v.visit(this); }
};


// The kind of initialization.
//
// TODO: Support aggregate initialization.
enum Init_kind
{
  default_init, // Performs default initialization
  direct_init,  // Copies or converts a value
};


// An initializer expression tracks information related to
// the initializaiton of an object. 
//
// When this is a default initializer, the expression must
// be nullptr.
//
// TODO: Formalize semantics around initialization. We probably
// need separate notions of initialization, just like C++ has.
// Maybe there's a more uniform treatment, but I'm not quite
// sure.
struct Init_expr : Expr
{
  // Construct a default or zero initializer.
  Init_expr(Location loc, Init_kind k)
    : Expr(loc, nullptr), init_(k), first(nullptr)
  { }

  // Construct a direct.
  Init_expr(Init_kind k, Expr const* e)
    : Expr(e->location(), e->type()), init_(k), first(e)
  { }

  Init_kind   init() const { return init_; }
  Expr const* expr() const { return first; }
  void accept(Expr_visitor& v) const { v.visit(this); }
  
  void set_expr(Expr const* e) { first = e; }

  Init_kind   init_;
  Expr const* first;
};



// A unary expression applies an operator to a single argument.
//
// Note that the source location for a unary operation is the
// location of its operator.
struct Unary_expr : Expr
{
  Unary_expr(Location loc, Type const* t, Unary_op op, Expr const* e)
    : Expr(loc, t), first(op), second(e)
  { }

  Unary_op    op() const  { return first; }
  Expr const* arg() const { return second; }
  void accept(Expr_visitor& v) const { v.visit(this); }

  Unary_op    first;
  Expr const* second;
};


// A helper class for constructing binary expressions. A binary
// expression contains the operator token and its two operands.
//
// Note that the source location of a binary expression is the
// location of its operator.
struct Binary_expr : Expr
{
  Binary_expr(Location loc, Type const* t, Binary_op op, Expr const* l, Expr const* r)
    : Expr(loc, t), first(op), second(l), third(r)
  { }

  Binary_op   op() const    { return first; }
  Expr const* left() const  { return second; }
  Expr const* right() const { return third; }
  void accept(Expr_visitor& v) const { v.visit(this); }

  Binary_op   first;
  Expr const* second;
  Expr const* third;
};


// A function call.
//
// Note that the target of a function call is an expression.
// This is required to be resolved to a declaration during
// translation.
struct Call_expr : Expr
{
  Call_expr(Location loc, Type const* t, Expr const* f, Expr_seq const& a)
    : Expr(loc, t), first(f), second(a)
  { }

  Expr const*     fn() const   { return first; }
  Expr_seq const& args() const { return second; }
  void accept(Expr_visitor& v) const { v.visit(this); }

  Expr const* first;
  Expr_seq    second;
};


// A function call.
//
// Note that the target of a function call is an expression.
// This is required to be resolved to a declaration during
// translation.
struct Tuple_expr : Expr
{
  Tuple_expr(Location loc, Type const* t, Expr_seq const& e)
    : Expr(loc, t), first(e)
  { }

  Expr_seq const& exprs() const { return first; }
  void accept(Expr_visitor& v) const { v.visit(this); }

  Expr_seq    first;
};


// An index expression selects the nth element from a
// composite object. For example:
//
//    e.0 // selects the first element from e
//
// Here, `e` must have either record or tuple type with
// at least one member.
//
// TODO: Must e2 be constant?
struct Index_expr : Expr
{
  Index_expr(Location loc, Type const* t, Expr const* e, Expr const* n)
    : Expr(loc, t), first(e), second(n)
  { }

  Expr const* object() const { return first; }
  Expr const* index() const  { return second; }
  void accept(Expr_visitor& v) const { v.visit(this); }

  Expr const* first;
  Expr const* second;
};


// A member expression denotes the offset (or index) within 
// the composite value of some other object. For example:
//
//    (r1.m1).m2 // record member access
//    (t1.1).2   // tuple member access
//
// We represent a member access expression as a pair of 
// subexpressions: one that computes the object being 
// accessed (possibly another member expression) and an 
// id expression.
struct Member_expr : Expr
{
  Member_expr(Location loc, Type const* t, Expr const* e, Expr const* s)
    : Expr(loc, t), first(e), second(s)
  { 
    lingo_assert(lingo::is<Id_expr>(s));
  }

  Expr const*    object() const   { return first; }
  Id_expr const* selector() const { return cast<Id_expr>(second); }
  void accept(Expr_visitor& v) const { v.visit(this); }

  Expr const* first;
  Expr const* second;
};


// A field expression refers to the name of a field
// found within a record type.
//
// r.f        // member f in record r 
// (r.f1).f2  // r.f1 must resolve into a record then we look for f2
//
// This is similar to a member expression
// Except we refer to the type instead of an object of that type.
// This resolves to a record member
//
// TODO: 'record' only has to resolve into a record
// it could be another field expr which resolves into a record
//
// FIXME: Field exprs should resolve into integers which indicate
// which field they refer to in the context environment. These values
// are determined by walking the program an assigning a value to each
// field found in an extracts decl
struct Field_expr : Expr
{
  Field_expr(Location loc, Type const* t, Type const* ft, Expr const* r, Expr const* f)
    : Expr(loc, t), first(r), second(f), third(ft), name_(resolve_field_name(this))
  {
    lingo_assert(lingo::is<Id_expr>(f));
  }

  Expr const* record() const { return first; }
  Id_expr const* field() const { return cast<Id_expr>(second); }
  Type const* field_type() const { return third; }
  String const* name() const { return name_; }

  void accept(Expr_visitor& v) const { v.visit(this); }

  Expr const* first;
  Expr const* second;
  Type const* third;

  String const* name_;
};


// An implicit conversion expression conerts a value in a source 
// type to a value in a target type. Conversions are not represented
// directly in the source language.
//
// The type of the expression is that of the target type.
//
// TODO: Model this as a unary expression?
struct Convert_expr : Expr
{
  Convert_expr(Location loc, Type const* t, Conversion_kind k, Expr const* e)
    : Expr(loc, t), first(k), second(e)
  { }

  Conversion_kind conv() const { return first; }
  Expr const*     arg() const  { return second; }
  void accept(Expr_visitor& v) const { v.visit(this); }

  Conversion_kind first;
  Expr const*     second;
};


// Lengthof expression. Represents the length in bytes of an
// expression of type T. The type of a lengthof expression is
// `uint`.
//
// TODO: This expression wouldn't actually stay in a lowered
// representation of a program. It should be fully reduced
// by inlining into a single expression. It would be useful
// in a template, where we neeed to preserve non-resolvable
// expressions, but not in non-dependent contexts.
struct Lengthof_expr : Expr
{
  Lengthof_expr(Location loc, Type const* t, Expr const* e)
    : Expr(loc, t), first(e)
  { }

  Expr const* arg() const  { return first; }
  void accept(Expr_visitor& v) const { v.visit(this); }

  Expr const* first;
};


// A headerof expression evaluates and returns the type
// being decoded by a decoder
// 
// decode d1(eth);
//  headerof d1 -> eth
struct Headerof_expr : Expr
{
  Headerof_expr(Location loc, Type const* t, Decl const* d)
    : Expr(loc, t), first(d)
  { }

  Decl const* decoder() const { return first; }
  void accept(Expr_visitor& v) const { v.visit(this); }

  Decl const* first;
};


enum Do_kind {
  decode,
  table,
};


// A do statement used to chain decoders and tables together
// Either a decode or a table
// Takes an id expr to the respective decl
struct Do_expr : Expr
{
  Do_expr(Location loc, Type const* t, Do_kind d, Expr const* e)
    : Expr(loc, t), first(d), second(e)
  { }

  Do_kind     do_what()     const { return first; }
  Expr const* target()      const { return second; }
  void accept(Expr_visitor& v) const { v.visit(this); }

  Do_kind first;
  Expr const* second;
};


// Offsetof expression. Represents the offset from a base
// pointer in an expression of type T. For example:
//
//    offsetof(e, m)
//
// Returns the offset of the member `m` in `e`. Note that
// `e` must have the type of the declaration context of `m`.
//
// TODO: This expression wouldn't actually stay in a lowered
// representation of a program. 
struct Offsetof_expr : Expr
{
  Offsetof_expr(Location loc, Type const* t, Expr const* e, Decl const* m)
    : Expr(loc, t), first(e), second(m)
  { }

  Expr const* object() const  { return first; }
  Decl const* member() const  { return second; }
  void accept(Expr_visitor& v) const { v.visit(this); }

  Expr const* first;
  Decl const* second;
};


// Insert expressions are used to insert flows into tables
struct Insert_expr : Expr
{
  Insert_expr(Location loc, Type const* t, Decl const* flw, Expr const* tbl)
    : Expr(loc, t), first(flw), second(tbl)
  { }

  Decl const* flow()  const { return first; }
  Expr const* table() const { return second; }
  void accept(Expr_visitor& v) const { v.visit(this); }

  Decl const* first;
  Expr const* second;
};


struct Delete_expr : Expr
{
  Delete_expr(Location loc, Type const* t, Decl const* flw, Expr const* tbl)
    : Expr(loc, t), first(flw), second(tbl)
  { }

  Decl const* flow()  const { return first; }
  Expr const* table() const { return second; }
  void accept(Expr_visitor& v) const { v.visit(this); }

  Decl const* first;
  Expr const* second;
};


// Used to access the field within a context
// We translate to this syntax from the surface syntax
// i.e. _header_.ethertype => _header_[#]
// All field_expr resolve into integer representations
// so field access becomes a trivial array lookup
struct Field_idx_expr : Expr
{
  Field_idx_expr(Location loc, Type const* t, Expr const* f)
    : Expr(loc, t), first(f)
  { }

  Expr const* field() const { return first; }
  void accept(Expr_visitor& v) const { v.visit(this); }

  Expr const* first;
};


// Used to access a header within a context
struct Header_idx_expr : Expr
{
  Header_idx_expr(Location loc, Type const* t, Expr const* h)
    : Expr(loc, t), first(h)
  { }

  Expr const* header() const { return first; }
  void accept(Expr_visitor& v) const { v.visit(this); }

  Expr const* first;
};


// True when T is models the Expression concept. 
//
// Note that we assume that a Expression is already known 
// to be Node, so we skip the explicit check.
template<typename T>
constexpr bool
is_expr()
{
  return std::is_base_of<Expr, T>::value;
}


// -------------------------------------------------------------------------- //
//                            Generic visitor


// A parameterized visitor that dispatches to a function object.
template<typename F, typename T>
struct Generic_expr_visitor : Expr_visitor, Generic_visitor<F, T>
{
  Generic_expr_visitor(F f)
    : Generic_visitor<F, T>(f)
  { }

  void visit(Id_expr const* e) { this->invoke(e); }
  void visit(Constant_expr const* e) { this->invoke(e); }
  void visit(Lookup_expr const* e) { this->invoke(e); }
  void visit(Default_expr const* e) { this->invoke(e); }
  void visit(Init_expr const* e) { this->invoke(e); }
  void visit(Value_expr const* e) { this->invoke(e); }
  void visit(Unary_expr const* e) { this->invoke(e); }
  void visit(Binary_expr const* e) { this->invoke(e); }
  void visit(Call_expr const* e) { this->invoke(e); }
  void visit(Tuple_expr const* e) { this->invoke(e); }
  void visit(Index_expr const* e) { this->invoke(e); }
  void visit(Member_expr const* e) { this->invoke(e); }
  void visit(Field_expr const* e) { this->invoke(e); }
  void visit(Convert_expr const* e) { this->invoke(e); }
  void visit(Lengthof_expr const* e) { this->invoke(e); }
  void visit(Offsetof_expr const* e) { this->invoke(e); }
  void visit(Headerof_expr const* e) { this->invoke(e); }
  void visit(Do_expr const* e) { this->invoke(e); }
  void visit(Insert_expr const* e) { this->invoke(e); }
  void visit(Delete_expr const* e) { this->invoke(e); }
  void visit(Field_idx_expr const* e) { this->invoke(e); }
  void visit(Header_idx_expr const* e) { this->invoke(e); }
};


// Apply the function f to the expression e.
template<typename F, typename T = typename std::result_of<F(Constant_expr*)>::type>
inline T
apply(Expr const* e, F fn)
{
  Generic_expr_visitor<F, T> v(fn);
  return accept(e, v);
}


// -------------------------------------------------------------------------- //
//                             Expression builders
//
// These functions create new expressions from their arguments. 
// To the greatest extent possible, these functions attempt to 
// resolve the type of the expression from those arguments.

// Returns a node that can be used to indicate errors in
// expressions.
inline Expr const* 
get_error_expr()
{
  return make_error_node<Expr>();
}

Id_expr*         make_id_expr(Location, Decl const*);
Lookup_expr*     make_lookup_expr(Location, String const*);
Default_expr*    make_default_expr(Location, Type const*);
Init_expr*       make_init_expr(Location, Init_kind);
Init_expr*       make_init_expr(Init_kind, Expr const*);
Value_expr*      make_bool_expr(Location, bool);
Value_expr*      make_int_expr(Location, Integer const&);
Value_expr*      make_value_expr(Location, Type const*, Value const&);
Unary_expr*      make_unary_expr(Location, Unary_op, Expr const*);
Binary_expr*     make_binary_expr(Location, Binary_op, Expr const*, Expr const*);
Call_expr*       make_call_expr(Location, Expr const*, Expr_seq const&);
Tuple_expr*      make_tuple_expr(Location, Expr_seq const&);
Index_expr*      make_index_expr(Location, Expr const*, Expr const*);
Index_expr*      make_index_expr(Location, Member_expr const*);
Member_expr*     make_member_expr(Location, Expr const*, Expr const*);
Field_expr*      make_field_expr(Location, Expr const*, Expr const*);
Convert_expr*    make_convert_expr(Location, Type const*, Conversion_kind, Expr const*);
Expr*            make_lengthof_expr(Location, Expr const*);
Expr*            make_offsetof_expr(Location, Expr const*, Decl const*);
Expr*            make_headerof_expr(Location, Decl const*);
Insert_expr*     make_insert_expr(Location, Decl const*, Expr const*);
Delete_expr*     make_delete_expr(Location, Decl const*, Expr const*);
Do_expr*         make_do_expr(Location, Do_kind, Expr const*);
Field_idx_expr*  make_fld_idx_expr(Location, Expr const*);
Header_idx_expr* make_hdr_idx_expr(Location, Expr const*);


// Returns a new default expression.
inline Default_expr*
make_default_expr(Type const* t)
{
  return make_default_expr(Location::none, t);
}


// Returns the boolean literal `true`.
inline Value_expr*
make_bool_expr(bool b)
{
  return make_bool_expr(Location::none, b);
}


// Returns the boolean literal `true`.
inline Value_expr*
make_true_expr()
{
  return make_bool_expr(true);
}


// Returns the boolean literal `false`.
inline Value_expr*
make_false_expr()
{
  return make_bool_expr(false);
}


// Returns an integer literal expression.
inline Value_expr*
make_int_expr(Integer const& n)
{
  return make_int_expr(Location::none, n);
}


// Returns an integer literal expression.
inline Value_expr*
make_value_expr(Type const* t, Value const& v)
{
  return make_value_expr(Location::none, t, v);
}


// Returns a declaration expression.
inline Id_expr*
make_id_expr(Decl const* d)
{
  return make_id_expr(Location::none, d);
}


// Returns a unary expression.
inline Unary_expr*
make_unary_expr(Unary_op op, Expr const* e)
{
  return make_unary_expr(Location::none, op, e);
}


// Returns a binary expression.
inline Binary_expr*
make_binary_expr(Binary_op op, Expr const* e1, Expr const* e2)
{
  return make_binary_expr(Location::none, op, e1, e2);
}


// Make the expression `e1 + e2`.
inline Binary_expr*
make_add_expr(Expr const* e1, Expr const* e2)
{
  return make_binary_expr(Location::none, num_add_op, e1, e2);
}


// Make the expression `e1 - e2`.
inline Binary_expr*
make_sub_expr(Expr const* e1, Expr const* e2)
{
  return make_binary_expr(Location::none, num_sub_op, e1, e2);
}


// Make the expression `e1 * e2`.
inline Binary_expr*
make_mul_expr(Expr const* e1, Expr const* e2)
{
  return make_binary_expr(Location::none, num_mul_op, e1, e2);
}


// Make the expression `e1 / e2`.
inline Binary_expr*
make_div_expr(Expr const* e1, Expr const* e2)
{
  return make_binary_expr(Location::none, num_div_op, e1, e2);
}


// Make the expression `e1 % e2`.
inline Binary_expr*
make_mod_expr(Expr const* e1, Expr const* e2)
{
  return make_binary_expr(Location::none, num_mod_op, e1, e2);
}


// Make the expression `-e`.
inline Unary_expr*
make_neg_expr(Expr const* e)
{
  return make_unary_expr(Location::none, num_neg_op, e);
}


// Make the expression '`+e`
inline Unary_expr*
make_pos_expr(Expr const* e)
{
  return make_unary_expr(Location::none, num_pos_op, e);
}


// Bitwise expressions.

inline Binary_expr*
make_bitwise_and_expr(Expr const* e1, Expr const* e2)
{
  return make_binary_expr(Location::none, bit_and_op, e1, e2);
}


inline Binary_expr*
make_bitwise_or_expr(Expr const* e1, Expr const* e2)
{
  return make_binary_expr(Location::none, bit_or_op, e1, e2);
}


inline Binary_expr*
make_bitwise_xor_expr(Expr const* e1, Expr const* e2)
{
  return make_binary_expr(Location::none, bit_xor_op, e1, e2);
}


inline Unary_expr*
make_bitwise_not_expr(Expr const* e)
{
  return make_unary_expr(Location::none, bit_not_op, e);
}


inline Binary_expr*
make_bitwise_lsh_expr(Expr const* e1, Expr const* e2)
{
  return make_binary_expr(Location::none, bit_lsh_op, e1, e2);
}


inline Binary_expr*
make_bitwise_rsh_expr(Expr const* e1, Expr const* e2)
{
  return make_binary_expr(Location::none, bit_rsh_op, e1, e2);
}


// Relational expressions

// Make the expression `e1 == e2`.
inline Binary_expr*
make_eq_expr(Expr const* e1, Expr const* e2)
{
  return make_binary_expr(Location::none, rel_eq_op, e1, e2);
}


inline Binary_expr*
make_ne_expr(Expr const* e1, Expr const* e2)
{
  return make_binary_expr(Location::none, rel_ne_op, e1, e2);
}


inline Binary_expr*
make_lt_expr(Expr const* e1, Expr const* e2)
{
  return make_binary_expr(Location::none, rel_lt_op, e1, e2);
}


inline Binary_expr*
make_gt_expr(Expr const* e1, Expr const* e2)
{
  return make_binary_expr(Location::none, rel_gt_op, e1, e2);
}


inline Binary_expr*
make_le_expr(Expr const* e1, Expr const* e2)
{
  return make_binary_expr(Location::none, rel_le_op, e1, e2);
}


inline Binary_expr*
make_ge_expr(Expr const* e1, Expr const* e2)
{
  return make_binary_expr(Location::none, rel_ge_op, e1, e2);
}


// Logical expressions

// Make the expression `e1 && e2`.
inline Binary_expr*
make_logical_and_expr(Expr const* e1, Expr const* e2)
{
  return make_binary_expr(Location::none, log_and_op, e1, e2);
}


// Make the expression `e1 || e2`.
inline Binary_expr*
make_logical_or_expr(Expr const* e1, Expr const* e2)
{
  return make_binary_expr(Location::none, log_or_op, e1, e2);
}


// Make the expression `!e`.
inline Unary_expr*
make_logical_not_expr(Expr const* e)
{
  return make_unary_expr(Location::none, log_not_op, e);
}


// TODO: Finish building out constructors for these expressions.
// Don't forget to add overloads that take constructors.


inline Call_expr*
make_call_expr(Expr const* f, Expr_seq const& a)
{
  return make_call_expr(Location::none, f, a);
}


inline Tuple_expr*
make_tuple_expr(Expr_seq const& e)
{
  return make_tuple_expr(Location::none, e);
}


// Make an index expression.
inline Index_expr*
make_index_expr(Expr const* e, Expr const* n)
{
  return make_index_expr(Location::none, e, n);
}


// Make an index expression from a member expression.
inline Index_expr*
make_index_expr(Member_expr const* m)
{
  return make_index_expr(Location::none, m);
}


// Make a member expression.
inline Member_expr*
make_member_expr(Expr const* e, Expr const* s)
{
  return make_member_expr(Location::none, e, s);
}


inline Field_expr*
make_field_expr(Expr const* r, Expr const* f)
{
  return make_field_expr(Location::none, r, f);
}


inline Convert_expr*
make_convert_expr(Type const* t, Conversion_kind k, Expr const* e)
{
  return make_convert_expr(Location::none, t, k, e);
}


inline Expr*
make_lengthof_expr(Expr const* e)
{
  return make_lengthof_expr(Location::none, e);
}


inline Expr*
make_headerof_expr(Decl const* d)
{
  return make_headerof_expr(Location::none, d);
}


inline Insert_expr*
make_insert_expr(Decl const* flw, Expr const* tbl)
{
  return make_insert_expr(Location::none, flw, tbl);
}


inline Delete_expr*
make_delete_expr(Decl const* flw, Expr const* tbl)
{
  return make_delete_expr(Location::none, flw, tbl);
}


inline Do_expr*
make_do_expr(Do_kind k, Expr const* e)
{
  return make_do_expr(Location::none, k, e);
}


inline Expr*
make_offsetof_expr(Expr const* e, Decl const* m)
{
  return make_offsetof_expr(Location::none, e, m);
}


inline Expr*
make_fld_idx_expr(Expr const* e)
{
  return make_fld_idx_expr(Location::none, e);
}


inline Expr*
make_hdr_idx_expr(Expr const* e)
{
  return make_hdr_idx_expr(Location::none, e);
}


// -------------------------------------------------------------------------- //
//                                 Queries

bool is_integer_expr(Expr const*);
bool is_boolean_expr(Expr const*);

bool has_record_type(Expr const*);
bool has_enum_type(Expr const*);


// -------------------------------------------------------------------------- //
//                                  Facilities

} // namespace steve

#endif

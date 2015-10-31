// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#ifndef STEVE_TYPE_HPP
#define STEVE_TYPE_HPP

// The type module defines the main components of the
// type system.

#include "steve/prelude.hpp"
#include "steve/op.hpp"

#include "lingo/node.hpp"


namespace steve
{

// -------------------------------------------------------------------------- //
//                                Types

struct Type_visitor;

// The Type class represents the set of all types defined
// by and definable within the cmin language.
//
// Note that types do not have source locations since
// they are (as of now, fully internal).
struct Type
{
  virtual ~Type()
  { }

  String node_name() const;

  virtual void accept(Type_visitor&) const = 0;
};


// The type visitor.
struct Type_visitor
{
  virtual void visit(Void_type const* t) { }
  virtual void visit(Kind_type const* t) { }
  virtual void visit(Boolean_type const* t) { }
  virtual void visit(Integer_type const* t) { }
  virtual void visit(Constant_type const* t) { }
  virtual void visit(Function_type const* t) { }
  virtual void visit(Reference_type const* t) { }
  virtual void visit(Array_type const* t) { }
  virtual void visit(Tuple_type const* t) { }
  virtual void visit(Record_type const* t) { }
  virtual void visit(Variant_type const* t) { }
  virtual void visit(Enum_type const* t) { }
  virtual void visit(Match_type const* t) { }
  virtual void visit(If_type const* t) { }
  virtual void visit(Seq_type const* t) { }
  virtual void visit(Buffer_type const* t) { }
  virtual void visit(Until_type const* t) { }
  virtual void visit(Table_type const* t) { }  
  virtual void visit(Flow_type const* t) { }
  virtual void visit(Port_type const* t) { }
};


// The type of boolean values.
struct Void_type : Type
{
  void accept(Type_visitor& v) const { v.visit(this); }
};


// The higher-order kind of types (the type of types).
struct Kind_type : Type
{
  void accept(Type_visitor& v) const { v.visit(this); }
};


// The type of boolean values.
struct Boolean_type : Type
{
  void accept(Type_visitor& v) const { v.visit(this); }
};


// Integer sign.
enum Integer_sign
{
  signed_int,
  unsigned_int,
};


// Integer order.
enum Integer_order
{
  native_order, // Byte ordering of target system.
  msbf_order,   // Most signficant byte first
  lsbf_order,   // Least significant byte first
};


// The integer type is a constructor for all kinds of integer
// values. Every integer type has three components:
//
//    - precision: number of bits available to store values
//    - sign: signed or unsigned
//    - order: native, msbf, or lsbf
//
// For shorthand, int means "signed integer" and uint
// means "unsigned integer".
struct Integer_type : Type
{
  Integer_type(int p, Integer_sign s, Integer_order o)
    : first(p), second(s), third(o)
  { }

  int           precision() const       { return first; }
  Integer_sign  sign() const            { return second; }
  bool          is_signed() const       { return second == signed_int; }
  bool          is_unsigned() const     { return second == unsigned_int; }
  Integer_order order() const           { return third; }
  bool          is_native_order() const { return third == native_order; }
  bool          is_msbf_order() const   { return third == msbf_order; }
  bool          is_lsbf_order() const   { return third == lsbf_order; }

  void accept(Type_visitor& v) const { v.visit(this); }

  int           first;
  Integer_sign  second;
  Integer_order third;
};


// The type of a constant object. For example:
//
//    var v : const int = 0;
//
// The object `v` cannot be modified. Note that the type
// argument of `const` must be an object type.
//
// TODO: Actually support these types. The primary reason
// for adding constant types is to support reference binding
// for constants. For example:
//
//    def f1(x : ref int) { ... }
//    def f2(x : ref const int) { ... }
//
//    f1(0); // error: cannot form a refernce to 0
//    f2(0); // OK: potentially synthesize an object
struct Constant_type : Type
{
  Constant_type(Type const* t)
    : first(t)
  { }

  Type const* type() const { return first; }
  void accept(Type_visitor& v) const { v.visit(this); }

  Type const* first;
};


// The type of a reference to an object. This type does
// not define a distinct value; the value is that of the
// object referred to. For example:
//
//    var v : int = 0;
//    var r : ref int = v; // r is an alias for v
//
// Reference types may be represented as pointers, or in
// many cases, they can be erased.
struct Reference_type : Type
{
  Reference_type(Type const* t)
    : first(t)
  { }

  Type const* type() const { return first; }
  void accept(Type_visitor& v) const { v.visit(this); }

  Type const* first;
};


// A function type is that of a mapping of a sequence of
// input types to an output type.
struct Function_type : Type
{
  // TODO: Support move semantics
  Function_type(Type_seq const& a, Type const* r)
    : first(a), second(r)
  { }

  Type_seq const& parm_types() const { return first; }
  Type const*     ret_type() const   { return second; }
  void accept(Type_visitor& v) const { v.visit(this); }

  Type_seq    first;
  Type const* second;
};


// An array type describes a value composed of a sequence
// of values having the same type.
//
// TODO: Make the extent a larger integer type?
struct Array_type : Type
{
  Array_type(Type const* t, Integer const& n)
    : first(t), second(n)
  { }

  Type const* type() const   { return first; }
  Integer     extent() const { return second; }
  void accept(Type_visitor& v) const { v.visit(this); }

  Type const* first;
  Integer     second;
};


// A tuple type is a sequence of types. The values of
// tuple typ are a cross product of the componenet types.
//
// TODO: Can a tuple have members that are not byte
// aligned? That is, is this valid: `{int1, int1}`?
struct Tuple_type : Type
{
  Tuple_type(Type_seq const& t)
    : first(t)
  { }

  Type_seq const& types() const { return first; }
  void accept(Type_visitor& v) const { v.visit(this); }

  Type_seq    first;
};


// A helper class for defining user-defined types. A user-defined
// type refers to a declaration.
template<typename T>
struct User_defined_type
{
  User_defined_type(Decl const* d)
    : first(d)
  {
    lingo_assert(is<T>(d));
  }

  T const* decl() const { return cast<T>(first); }
  void accept(Type_visitor& v) const { v.visit(this); }

  Decl const* first;
};


// A record type is defined by its declaration.
//
// TODO: Support inheritance.
struct Record_type : Type, User_defined_type<Record_decl>
{
  using User_defined_type<Record_decl>::User_defined_type;

  void accept(Type_visitor& v) const { v.visit(this); }
};


// A variant type...
struct Variant_type : Type, User_defined_type<Variant_decl>
{
  using User_defined_type<Variant_decl>::User_defined_type;
  void accept(Type_visitor& v) const { v.visit(this); }
};


// An enum type...
struct Enum_type : Type, User_defined_type<Enum_decl>
{
  using User_defined_type<Enum_decl>::User_defined_type;
  void accept(Type_visitor& v) const { v.visit(this); }
};


// A type match is a member of a match type. It associates
// a constant expression with its corresponding type.
struct Match_term : std::pair<Expr const*, Type const*>
{
  using std::pair<Expr const*, Type const*>::pair;

  char const* node_name() const { return "match"; }

  Expr const* cond() const { return first; }
  Type const* type() const { return second; }
};


// A sequence of type matches. 
//
// TODO: These don't need to be pointers, but generic algorithms
// written against nodes expect pointers for term-like elements.
// Allowing non-pointer terms leads to overloading headaches.
using Match_seq = std::vector<Match_term const*>;


// Represents a match type.
//
// This is a structural and not a nominal type.
struct Match_type : Type
{
  Match_type(Expr const* e, Match_seq const& m)
    : first(e), second(m)
  { }
  
  Expr const*      disc() const    { return first; }
  Match_seq const& members() const { return second; }
  void accept(Type_visitor& v) const { v.visit(this); }

  Expr const* first;
  Match_seq   second;
};


// Represents a runtime `if` type.
struct If_type : Type
{
  If_type(Expr const* e, Type const* t)
    : first(e), second(t)
  { }
  
  Expr const* cond() const { return first; }
  Type const* type() const { return second; }
  void accept(Type_visitor& v) const { v.visit(this); }

  Expr const* first;
  Type const* second;
};


// A sequence type.
struct Seq_type : Type
{
  Seq_type(Type const* t, Expr const* e)
    : first(t), second(e)
  { }
  
  Type const* type() const { return first; }
  Expr const* elems() const { return second; }
  void accept(Type_visitor& v) const { v.visit(this); }

  Type const* first;
  Expr const* second;
};


// A sequence buffer type.
struct Buffer_type : Type
{
  Buffer_type(Type const* t, Expr const* e)
    : first(t), second(e)
  { }
  
  Type const* type() const { return first; }
  Expr const* length() const { return second; }
  void accept(Type_visitor& v) const { v.visit(this); }

  Type const* first;
  Expr const* second;
};


// A terminated sequence type.
struct Until_type : Type
{
  Until_type(Expr const* e, Type const* t)
    : first(e), second(t)
  { }
  
  Expr const* cond() const { return first; }
  Type const* type() const { return second; }
  void accept(Type_visitor& v) const { v.visit(this); }

  Expr const* first;
  Type const* second;
};


// Table types.
struct Table_type : Type
{
  Table_type(Decl_seq const& d)
    : first(d)
  { }

  Decl_seq const& key_fields() const { return first; }

  void accept(Type_visitor& v) const { v.visit(this); }

  Decl_seq const first;
};


// open flow table entry
struct Flow_type : Type
{
  Flow_type(Type_seq const& t)
    : first(t)
  { }

  Type_seq const& key_types() const { return first; }

  void accept(Type_visitor& v) const { v.visit(this); }

  Type_seq const first;
};


// Port type
struct Port_type : Type
{
  Port_type() { }

  void accept(Type_visitor& v) const { v.visit(this); }
};


// -------------------------------------------------------------------------- //
//                               Concepts

// Returns true if T is a scalar type. The scalar
// types are the `bool` type and the integer types.
template<typename T>
constexpr bool
is_scalar_type()
{
  return std::is_base_of<T, Boolean_type>::value
      || std::is_base_of<T, Integer_type>::value;
}


// Returns true if T aggregates subobjects of a
// different type. This includes arrays, tuples,
// records, variants, and match types.
template<typename T>
constexpr bool
is_aggregate_type()
{
  return std::is_base_of<T, Array_type>::value
      || std::is_base_of<T, Tuple_type>::value
      || std::is_base_of<T, Match_type>::value
      || std::is_base_of<T, Seq_type>::value
      || std::is_base_of<T, Buffer_type>::value
      || std::is_base_of<T, Until_type>::value
      || std::is_base_of<T, Record_type>::value
      || std::is_base_of<T, Variant_type>::value;
}


// Returns true if T is a user-defined type.
template<typename T>
constexpr bool
is_user_defined_type()
{
  return std::is_base_of<T, Record_type>::value
      || std::is_base_of<T, Variant_type>::value
      || std::is_base_of<T, Enum_type>::value;
}


// Returns true if the type T can define an object. The
// object types are the scalars, aggregates, and user
// defined types.
template<typename T>
constexpr bool
is_object_type()
{
  return is_scalar_type<T>()
      || is_aggregate_type<T>()
      || is_user_defined_type<T>()
      // FIXME: is a reference really an object tpye
      || std::is_base_of<T, Reference_type>::value
      || std::is_base_of<T, Constant_type>::value
      || std::is_base_of<T, Table_type>::value
      || std::is_base_of<T, Flow_type>::value
      || std::is_base_of<T, Port_type>::value;
}


// Returns true if T is dependent upon a runtime quantity.
template<typename T>
constexpr bool
is_runtime_type()
{
  return std::is_base_of<T, Match_type>::value
      || std::is_base_of<T, If_type>::value
      || std::is_base_of<T, Seq_type>::value
      || std::is_base_of<T, Buffer_type>::value
      || std::is_base_of<T, Until_type>::value;
}


// -------------------------------------------------------------------------- //
//                               Queries
//
// TODO: Unify these definitions with the concept definitions
// above. Not quite sure if there's an elegant way of doing this.

// True when T is models the Type concept. 
//
// Note that we assume that a Type is already known 
// to be Node, so we skip the explicit check.
template<typename T>
constexpr bool
is_type()
{
  return std::is_base_of<Type, T>::value;
}


// Returns ture if `t` is the boolean type.
inline bool
is_boolean_type(Type const* t)
{
  return is<Boolean_type>(t);
}


// Returns true if `t` is an integer type.
//
// The integer types are...
inline bool 
is_integer_type(Type const* t)
{
  return is<Integer_type>(t);
}


inline bool
is_scalar_type(Type const* t)
{
  return is_boolean_type(t) || is_integer_type(t);
}


inline bool
is_aggregate_type(Type const* t)
{
  return is<Array_type>(t)
      || is<Tuple_type>(t)
      || is<Match_type>(t)
      || is<Record_type>(t)
      || is<Variant_type>(t);
}


// Returns true if T is an arithmetic type.
//
// The arithmetic types are the integer types, the floating 
// point types, and the boolean type.
inline bool
is_arithmetic_type(Type const* t)
{
  return is_integer_type(t) || is_boolean_type(t);
}


// Returns true if `t` is a record type.
inline bool
is_record_type(Type const* t)
{
  return is<Record_type>(t);
}


// Returns true if `t` is a variant type.
inline bool
is_variant_type(Type const* t)
{
  return is<Variant_type>(t);
}


// Returns true if `t` is an enum type.
inline bool
is_enum_type(Type const* t)
{
  return is<Enum_type>(t);
}


// Returns true if `t` is a user-defined type.
//
// The user-defined types are the record types and enum types.
//
// Note that a match type is not a user-defined type because 
// it is not a nominal type.
inline bool
is_user_defined_type(Type const* t)
{
  return is_record_type(t) 
      || is_variant_type(t) 
      || is_enum_type(t);
}


inline bool
is_object_type(Type const* t)
{
  return is_scalar_type(t)
      || is_aggregate_type(t)
      || is_user_defined_type(t)
      // FIXME: is a reference really of object type?
      || is<Reference_type>(t)
      || is<Constant_type>(t)
      || is<Table_type>(t)
      || is<Flow_type>(t)
      || is<Port_type>(t);
}


inline bool
is_runtime_type(Type const* t)
{
  return is<Match_type>(t)
      || is<If_type>(t)
      || is<Seq_type>(t)
      || is<Buffer_type>(t)
      || is<Until_type>(t);
}


// Evalutes to true iff T1 and T2 have the same
// dynamic type
template<typename T1, typename T2>
inline bool
same_kind(T1 const* t1, T2 const* t2)
{
  return typeid(*t1) == typeid(*t2);
}



// -------------------------------------------------------------------------- //
//                               Type accessors


// Returns a type that denotes an error.
inline Type const* 
get_error_type()
{
  return make_error_node<Type>();
}


Kind_type const*      get_kind_type();
Void_type const*      get_void_type();
Boolean_type const*   get_boolean_type();
Boolean_type const*   get_bool_type();
Integer_type const*   get_integer_type(int, Integer_sign, Integer_order);

// Basic integer types
Integer_type const*   get_short_type();
Integer_type const*   get_int_type();
Integer_type const*   get_long_type();
Integer_type const*   get_ushort_type();
Integer_type const*   get_uint_type();
Integer_type const*   get_ulong_type();


// Precise integer types
Integer_type const*   get_int_type(int p);
Integer_type const*   get_uint_type(int p);
Integer_type const*   get_msbf_type(int p);
Integer_type const*   get_umsbf_type(int p);
Integer_type const*   get_lsbf_type(int p);
Integer_type const*   get_ulsbf_type(int p);

Constant_type const*  get_constant_type(Type const*);
Reference_type const* get_reference_type(Type const*);
Function_type const*  get_function_type(Type_seq const&, Type const*);
Array_type const*     get_array_type(Type const*, Integer const&);
Array_type const*     get_array_type(Type const*, Expr const*);
Tuple_type const*     get_tuple_type(Type_seq const&);
Tuple_type const*     get_tuple_type(Record_type const*);
Record_type const*    get_record_type(Decl const*);
Variant_type const*   get_variant_type(Decl const*);
Enum_type const*      get_enum_type(Decl const*);
Match_type const*     get_match_type(Expr const*, Match_seq const&);
Table_type const*     get_table_type(Decl_seq const&);
Flow_type const*      get_flow_type(Type_seq const&);
Type const*           get_user_defined_type(Decl const*);
Match_type const*     get_match_type(Expr const*, Match_seq const&);
Match_term const*     make_match_term(Expr const*, Type const*);
Seq_type const*       get_seq_type(Type const*, Expr const*);
Buffer_type const*    get_buffer_type(Type const*, Expr const*);
Until_type const*     get_until_type(Expr const*, Type const*);
Record_type const*    get_context_type();
Port_type const*      get_port_type();


// -------------------------------------------------------------------------- //
//                            Generic visitor


// A parameterized visitor that dispatches to a function 
// object. F is the type of the function and T is its
// return type.
//
// This class is never used directly. It is used only in
// the apply function below.
template<typename F, typename T>
struct Generic_type_visitor : Type_visitor, Generic_visitor<F, T>
{
  Generic_type_visitor(F f)
    : Generic_visitor<F, T>(f)
  { }

  void visit(Void_type const* t)      { this->invoke(t); }
  void visit(Kind_type const* t)      { this->invoke(t); }
  void visit(Boolean_type const* t)   { this->invoke(t); }
  void visit(Integer_type const* t)   { this->invoke(t); }
  void visit(Constant_type const* t)  { this->invoke(t); }
  void visit(Function_type const* t)  { this->invoke(t); }
  void visit(Reference_type const* t) { this->invoke(t); }
  void visit(Array_type const* t)     { this->invoke(t); }
  void visit(Tuple_type const* t)     { this->invoke(t); }
  void visit(Record_type const* t)    { this->invoke(t); }
  void visit(Variant_type const* t)   { this->invoke(t); }
  void visit(Enum_type const* t)      { this->invoke(t); }
  void visit(Match_type const* t)     { this->invoke(t); }
  void visit(If_type const* t)        { this->invoke(t); }
  void visit(Seq_type const* t)       { this->invoke(t); }
  void visit(Buffer_type const* t)    { this->invoke(t); }
  void visit(Until_type const* t)     { this->invoke(t); }
  void visit(Table_type const* t)     { this->invoke(t); }  
  void visit(Flow_type const* t)      { this->invoke(t); }
  void visit(Port_type const* t)      { this->invoke(t); }
};


// Apply the function f to the type t.
// The return type is that of the function object F.
template<typename F, typename T = typename std::result_of<F(Void_type*)>::type>
inline T
apply(Type const* t, F fn)
{
  Generic_type_visitor<F, T> v(fn);
  return accept(t, v);
}


// -------------------------------------------------------------------------- //
//                               Type checking

Type const* type_call_expr(Expr const*, Expr_seq const&);
Type const* type_tuple_expr(Expr_seq const&);
Type const* type_index_expr(Expr const*, Expr const*);
Type const* type_member_expr(Expr const*, Expr const*);
Type const* type_field_expr(Expr const*, Expr const*);
Type const* type_rebind_decl(Expr const*, Expr const*);

bool check_initializer(Type const*, Expr const*);
bool check_function_decl(Type const*, Stmt const*);
bool check_decode_decl(Type const*, Stmt const*);
bool check_flow_decl(Decl const*, Type const*);
bool check_table_initializer(Decl_seq const&, Type const*);

bool check_match_stmt(Expr const*, Stmt_seq const&);
bool check_do_decode_stmt(Expr const*);
bool check_do_table_stmt(Expr const*);


} // namespace steve


#include "steve/type.ipp"

#endif


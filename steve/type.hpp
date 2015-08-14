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
//                                 Type kinds

// Different kinds of types in the core language.
enum Type_kind
{
  kind_type,      // type of types
  void_type,      // void type
  boolean_type,   // boolean type
  integer_type,   // integer type
  constant_type,  // constant oject types: const T
  reference_type, // reference types: ref T
  function_type,  // function types: (T1, ... ,Tn) -> T
  array_type,     // array types: T[N]
  tuple_type,     // tuple types: {T1, ..., Tn}
  record_type,    // record types: record <name> { ... }
  variant_type,   // variant types: variant <name> { ... }
  enum_type,      // enum types: enum <name> [(base)] { ... }
  match_type,     // match types: match(e) { ... }
  if_type,        // if types: if(e) T
  seq_type,       // sequence types: seq T (e)
  buffer_type,    // buffer types: buf T (e)
  until_type,     // sequence until types: until(pred) T
  table_type,     // table types: table <ofptable_name>[(header fields)]
  flow_type,      // flow type: flow <ofptable_name> [conds] { instr }
};


char const* get_type_name(Type_kind);


// Adapt the generic node-kinding template to this node type.
template<Type_kind K>
using Type_impl = lingo::Kind_base<Type_kind, K>;


// -------------------------------------------------------------------------- //
//                                Types


// The Type class represents the set of all types defined
// by and definable within the cmin language.
//
// Note that types do not have source locations since
// they are (as of now, fully internal).
struct Type
{
  Type(Type_kind k)
    : kind_(k)
  { }

  virtual ~Type()
  { }

  char const* node_name() const { return get_type_name(kind_); }
  Type_kind   kind() const      { return kind_; }

  Type_kind kind_;
};


// The type of boolean values.
struct Void_type : Type, Type_impl<void_type>
{
  Void_type()
    : Type(node_kind)
  { }
};


// The higher-order kind of types (the type of types).
struct Kind_type : Type, Type_impl<kind_type>
{
  Kind_type()
    : Type(node_kind)
  { }
};


// The type of boolean values.
struct Boolean_type : Type, Type_impl<boolean_type>
{
  Boolean_type()
    : Type(node_kind)
  { }
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
struct Integer_type : Type, Type_impl<integer_type>
{
  Integer_type(int p, Integer_sign s, Integer_order o)
    : Type(node_kind), first(p), second(s), third(o)
  { }

  int           precision() const       { return first; }
  Integer_sign  sign() const            { return second; }
  bool          is_signed() const       { return second == signed_int; }
  bool          is_unsigned() const     { return second == unsigned_int; }
  Integer_order order() const           { return third; }
  bool          is_native_order() const { return third == native_order; }
  bool          is_msbf_order() const   { return third == msbf_order; }
  bool          is_lsbf_order() const   { return third == lsbf_order; }

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
struct Constant_type : Type, Type_impl<constant_type>
{
  Constant_type(Type const* t)
    : Type(node_kind), first(t)
  { }

  Type const* type() const { return first; }

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
struct Reference_type : Type, Type_impl<reference_type>
{
  Reference_type(Type const* t)
    : Type(node_kind), first(t)
  { }

  Type const* type() const { return first; }

  Type const* first;
};


// A function type is that of a mapping of a sequence of
// input types to an output type.
struct Function_type : Type, Type_impl<function_type>
{
  // TODO: Support move semantics
  Function_type(Type_seq const& a, Type const* r)
    : Type(node_kind), first(a), second(r)
  { }

  Type_seq const& parm_types() const { return first; }
  Type const*     ret_type() const   { return second; }

  Type_seq    first;
  Type const* second;
};


// An array type describes a value composed of a sequence
// of values having the same type.
//
// TODO: Make the extent a larger integer type?
struct Array_type : Type, Type_impl<array_type>
{
  Array_type(Type const* t, Integer const& n)
    : Type(node_kind), first(t), second(n)
  { }

  Type const* type() const   { return first; }
  Integer     extent() const { return second; }

  Type const* first;
  Integer     second;
};


// A tuple type is a sequence of types. The values of
// tuple typ are a cross product of the componenet types.
//
// TODO: Can a tuple have members that are not byte
// aligned? That is, is this valid: `{int1, int1}`?
struct Tuple_type : Type, Type_impl<tuple_type>
{
  Tuple_type(Type_seq const& t)
    : Type(node_kind), first(t)
  { }

  Type_seq const& types() const { return first; }

  Type_seq    first;
};


// A helper class for defining user-defined types. A user-defined
// type refers to a declaration.
template<Type_kind K, typename T>
struct User_defined_type : Type, Type_impl<K>
{
  User_defined_type(Decl const* d)
    : Type(K), first(d)
  {
    lingo_assert(is<T>(d));
  }

  T const* decl() const { return cast<T>(first); }

  Decl const* first;
};


// A record type is defined by its declaration.
//
// TODO: Support inheritance.
struct Record_type : User_defined_type<record_type, Record_decl>
{
  using User_defined_type<record_type, Record_decl>::User_defined_type;
};


// A variant type...
struct Variant_type : User_defined_type<variant_type, Variant_decl>
{
  using User_defined_type<variant_type, Variant_decl>::User_defined_type;
};


// An enum type...
struct Enum_type : User_defined_type<enum_type, Enum_decl>
{
  using User_defined_type<enum_type, Enum_decl>::User_defined_type;
};


// A type match is a member of a match type. It associates
// a constant expression with its corresponding type.
struct Match_term : Term<>, std::pair<Expr const*, Type const*>
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
struct Match_type : Type, Type_impl<match_type>
{
  Match_type(Expr const* e, Match_seq const& m)
    : Type(node_kind), first(e), second(m)
  { }
  
  Expr const*      disc() const    { return first; }
  Match_seq const& members() const { return second; }

  Expr const* first;
  Match_seq   second;
};


// Represents a runtime `if` type.
struct If_type : Type, Type_impl<match_type>
{
  If_type(Expr const* e, Type const* t)
    : Type(node_kind), first(e), second(t)
  { }
  
  Expr const* cond() const { return first; }
  Type const* type() const { return second; }

  Expr const* first;
  Type const* second;
};


// A sequence type.
struct Seq_type : Type, Type_impl<seq_type>
{
  Seq_type(Type const* t, Expr const* e)
    : Type(node_kind), first(t), second(e)
  { }
  
  Type const* type() const { return first; }
  Expr const* elems() const { return second; }

  Type const* first;
  Expr const* second;
};


// A sequence buffer type.
struct Buffer_type : Type, Type_impl<buffer_type>
{
  Buffer_type(Type const* t, Expr const* e)
    : Type(node_kind), first(t), second(e)
  { }
  
  Type const* type() const { return first; }
  Expr const* length() const { return second; }

  Type const* first;
  Expr const* second;
};


// A terminated sequence type.
struct Until_type : Type, Type_impl<until_type>
{
  Until_type(Expr const* e, Type const* t)
    : Type(node_kind), first(e), second(t)
  { }
  
  Expr const* cond() const { return first; }
  Type const* type() const { return second; }

  Expr const* first;
  Type const* second;
};


// Table types.
struct Table_type : User_defined_type<table_type, Table_decl>
{
  using User_defined_type<table_type, Table_decl>::User_defined_type;
};


// open flow table entry
struct Flow_type : User_defined_type<flow_type, Flow_decl>
{
  using User_defined_type<flow_type, Flow_decl>::User_defined_type;
};


// -------------------------------------------------------------------------- //
//                             Concepts and dispatch
//


// True when T is models the Expression concept. 
//
// Note that we assume that a Expression is already known 
// to be Node, so we skip the explicit check.
template<typename T>
constexpr bool
is_type()
{
  return std::is_base_of<Type, T>::value;
}


// Returns true if T is a scalar type. The scalar
// types are the `bool` type and the integer types.
template<typename T>
constexpr bool
is_scalar_type()
{
  return T::node_kind == boolean_type
      || T::node_kind == integer_type;
}


// Returns true if T aggregates subobjects of a
// different type. This includes arrays, tuples,
// records, variants, and match types.
template<typename T>
constexpr bool
is_aggregate_type()
{
  return T::node_kind == array_type
      || T::node_kind == tuple_type
      || T::node_kind == match_type
      || T::node_kind == seq_type
      || T::node_kind == buffer_type
      || T::node_kind == until_type
      || T::node_kind == record_type
      || T::node_kind == variant_type;
}


// Returns true if T is a user-defined type.
template<typename T>
constexpr bool
is_user_defined_type()
{
  return T::node_kind == record_type
      || T::node_kind == variant_type
      || T::node_kind == enum_type;
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
      || T::node_kind == constant_type;
}


// Returns true if T is dependent upon a runtime quantity.
template<typename T>
constexpr bool
is_runtime_type()
{
  return T::node_kind == match_type
      || T::node_kind == if_type
      || T::node_kind == seq_type
      || T::node_kind == buffer_type
      || T::node_kind == until_type;
}


// TODO: Are decode and type types user-defined? Are
// they object types? They are probably distinct
// closure types and so not subjet.


// Apply function to the type `t`.
template<typename T, typename F>
auto
apply(T const* t, F fn) 
  -> typename std::enable_if<is_type<T>(), decltype(fn((Kind_type*)0))>::type
{
  lingo_alert(is_valid_node(t), "invalid type");
  switch (t->kind()) {
    case kind_type: return fn(cast<Kind_type>(t));
    case void_type: return fn(cast<Void_type>(t));
    case boolean_type: return fn(cast<Boolean_type>(t));
    case integer_type: return fn(cast<Integer_type>(t));
    case constant_type: return fn(cast<Constant_type>(t));
    case reference_type: return fn(cast<Reference_type>(t));
    case function_type: return fn(cast<Function_type>(t));
    case array_type: return fn(cast<Array_type>(t));
    case tuple_type: return fn(cast<Tuple_type>(t));
    case record_type: return fn(cast<Record_type>(t));
    case variant_type: return fn(cast<Variant_type>(t));
    case enum_type: return fn(cast<Enum_type>(t));
    case match_type: return fn(cast<Match_type>(t));
    case if_type: return fn(cast<If_type>(t));
    case seq_type: return fn(cast<Seq_type>(t));
    case buffer_type: return fn(cast<Buffer_type>(t));
    case until_type: return fn(cast<Until_type>(t));
    case table_type: return fn(cast<Table_type>(t));
    case flow_type: return fn(cast<Flow_type>(t));
  }
  lingo_unreachable();
}


// -------------------------------------------------------------------------- //
//                               Queries
//
// TODO: Unify these definitions with the concept definitions
// above. Not quite sure if there's an elegant way of doing this.

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
      || is_user_defined_type(t);
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
Table_type const*     get_table_type(Decl const*);
Flow_type const*      get_flow_type(Decl const*);
Type const*           get_user_defined_type(Decl const*);
Match_type const*     get_match_type(Expr const*, Match_seq const&);
Match_term const*     make_match_term(Expr const*, Type const*);
Seq_type const*       get_seq_type(Type const*, Expr const*);
Buffer_type const*    get_buffer_type(Type const*, Expr const*);
Until_type const*     get_until_type(Expr const*, Type const*);
Record_type const*    get_context_type();


// -------------------------------------------------------------------------- //
//                               Type checking

Type const* type_call_expr(Expr const*, Expr_seq const&);
Type const* type_tuple_expr(Expr_seq const&);
Type const* type_index_expr(Expr const*, Expr const*);
Type const* type_member_expr(Expr const*, Expr const*);
Type const* type_field_expr(Expr const*, Expr const*);

bool check_initializer(Type const*, Expr const*);
bool check_function_decl(Type const*, Stmt const*);
bool check_decode_decl(Type const*, Stmt const*);

bool check_match_stmt(Expr const*, Stmt_seq const&);
bool check_do_decode_stmt(Expr const*);
bool check_do_table_stmt(Expr const*);


} // namespace steve


#include "steve/type.ipp"

#endif


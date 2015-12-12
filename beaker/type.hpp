// Copyright (c) 2015 Andrew Sutton
// All rights reserved

#ifndef BEAKER_TYPE_HPP
#define BEAKER_TYPE_HPP


#include <beaker/prelude.hpp>
#include <beaker/scope.hpp>
#include <beaker/decl.hpp>


// The Type class represents the set of all types in the
// language.
//
//    t ::= bool                -- boolean type
//          int                 -- integer type
//          char                -- narrow characters
//          (t1, ..., tn) -> t  -- function types
//          t[n]                -- array types
//          t[]                 -- block types
//          ref t               -- reference types
//          struct n { f* }     -- field types
//
// Note that types are not mutable. Once created, a type
// cannot be changed. The reason for this is that we
// internally canonicalize (most) types when they are
// created.
//
// The "type" type (or kind) denotes the type user-defined
// types. Although it describes the higher-level kind
// system, we include it with the type system for
// convenience.
struct Type
{
  struct Visitor;

  virtual ~Type() { }

  virtual void accept(Visitor&) const = 0;

  virtual Type const* ref() const;
  virtual Type const* nonref() const;
};


struct Type::Visitor
{
  virtual void visit(Id_type const*) = 0;
  virtual void visit(Boolean_type const*) = 0;
  virtual void visit(Character_type const*) = 0;
  virtual void visit(Integer_type const*) = 0;
  virtual void visit(Function_type const*) = 0;
  virtual void visit(Array_type const*) = 0;
  virtual void visit(Block_type const*) = 0;
  virtual void visit(Reference_type const*) = 0;
  virtual void visit(Record_type const*) = 0;
  virtual void visit(Void_type const*) = 0;

  // network specific types
  virtual void visit(Layout_type const*) = 0;
  virtual void visit(Context_type const*) = 0;
  virtual void visit(Table_type const*) = 0;
  virtual void visit(Flow_type const*) = 0;
  virtual void visit(Port_type const*) = 0;
  virtual void visit(Key_type const*) = 0;
};


// A type named by an identifier. These are Essentially
// placeholders to be determined during initialization.
struct Id_type : Type
{
  Id_type(Symbol const* s)
    : sym_(s)
  { }

  void accept(Visitor& v) const { v.visit(this); };

  Symbol const* symbol() const { return sym_; }

  Symbol const* sym_;
};


// The type bool.
struct Boolean_type : Type
{
  void accept(Visitor& v) const { v.visit(this); };
};


struct Void_type : Type
{
  void accept(Visitor& v) const { v.visit(this); };
};


// The type char.
struct Character_type : Type
{
  void accept(Visitor& v) const { v.visit(this); };
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


// The type int.
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

  void accept(Visitor& v) const { v.visit(this); };

  int           first;
  Integer_sign  second;
  Integer_order third;
};


// Represents function types (t1, ..., tn) -> t.
struct Function_type : Type
{
  Function_type(Type_seq const& t, Type const* r)
    : first(t), second(r), third(false)
  { }

  Function_type(Type_seq const& t, Type const* r, bool v)
    : first(t), second(r), third(v)
  { }

  void accept(Visitor& v) const { v.visit(this); };

  Type_seq const& parameter_types() const { return first; }
  Type const*     return_type() const     { return second; }
  bool            var_args() const        { return third; }

  Type_seq    first;
  Type const* second;
  bool        third;
};



// A fixed-length type T[N] which represents a region
// of contiguous memory containing N objects of type T.
//
// N is required to be a literal of type int.
struct Array_type : Type
{
  Array_type(Type const* t, Expr* e)
    : first(t), second(e)
  { }

  void accept(Visitor& v) const { v.visit(this); };

  Type const* type() const   { return first; }
  Expr*       extent() const { return second; }
  int         size() const;

  Type const* first;
  Expr*       second;
};


// The type T[] of a region of contiguous memory with unspecified
// size. The number of elements in a block is determined by
// the contents of memory (e.g., a null-terminated string)
// or an explicit count maintained by a program.
//
// This is equivalent to a C++ array of unknown bound.
struct Block_type : Type
{
  Block_type(Type const* t)
    : first(t)
  { }

  void accept(Visitor& v) const { v.visit(this); };

  Type const* type() const { return first; }

  Type const* first;
};


// The type of an expression that refers to an object.
struct Reference_type : Type
{
  Reference_type(Type const* t)
    : first(t)
  { }

  void accept(Visitor& v) const { v.visit(this); };

  virtual Type const* ref() const;
  virtual Type const* nonref() const;

  Type const* type() const { return first; }


  Type const* first;
};


// A record type is the type introduced by a
// record declaration.
struct Record_type : Type
{
  Record_type(Decl* d)
    : decl_(d)
  { }

  void accept(Visitor& v) const { v.visit(this); };

  Record_decl* declaration() const;
  Scope*       scope() const;

  Decl* decl_;
};



// -------------------------------------------------------------------------- //
//          Network specific types

// Layout type
//
// Is this right??? You can't have an object of layout type
// except for declaring nested members of layouts
struct Layout_type : Type
{
  Layout_type(Decl* d)
    : decl_(d)
  { }

  void accept(Visitor& v) const { v.visit(this); };

  Layout_decl* declaration() const { return as<Layout_decl>(decl_); }

  Decl* decl_;
};


// Context type
struct Context_type : Type
{
  void accept(Visitor& v) const { v.visit(this); };
};


// Key type
struct Key_type : Type
{
  void accept(Visitor& v) const { v.visit(this); }
};


// Table types.
struct Table_type : Type
{
  Table_type(Decl_seq const& d, Type_seq const& t)
    : names_(d), types_(t)
  { }

  Decl_seq const& field_names() const { return names_; }
  Type_seq const& field_types() const { return types_; }

  void accept(Visitor& v) const { v.visit(this); }

  Decl_seq const names_;
  Type_seq const types_;
};


// open flow table entry
struct Flow_type : Type
{
  Flow_type(Type_seq const& t)
    : key_types_(t)
  { }

  Type_seq const& key_types() const { return key_types_; }

  void accept(Visitor& v) const { v.visit(this); }

  Type_seq key_types_;
};


// Port type
struct Port_type : Type
{
  Port_type() { }

  void accept(Visitor& v) const { v.visit(this); }
};



// -------------------------------------------------------------------------- //
//                              Type accessors

Type const* get_type_kind();
Type const* get_id_type(Symbol const*);
Type const* get_boolean_type();
Type const* get_character_type();
Type const* get_integer_type();
Type const* get_integer_type(int, Integer_sign, Integer_order);
Type const* get_function_type(Type_seq const&, Type const*);
Type const* get_function_type(Decl_seq const&, Type const*);
Type const* get_function_type(Type_seq const&, Type const*, bool);
Type const* get_array_type(Type const*, Expr*);
Type const* get_block_type(Type const*);
Type const* get_reference_type(Type const*);
Type const* get_record_type(Record_decl*);
Type const* get_void_type();


// network specific types
Type const* get_layout_type(Layout_decl*);
Type const* get_context_type();
Type const* get_table_type(Decl_seq const&, Type_seq const&);
Type const* get_opaque_table();
Type const* get_flow_type(Type_seq const&);
Type const* get_port_type();
Type const* get_key_type();



// -------------------------------------------------------------------------- //
//                              Type queries

// The scalar types are bool, char, and int.
inline bool
is_scalar(Type const* t)
{
  return is<Boolean_type>(t)
      || is<Character_type>(t)
      || is<Integer_type>(t);
}


// The aggregate types are record types and array
// types.
//
// TODO: I don't believe that block types are aggregate.
// I think they are scalar (pointers).
inline bool
is_aggregate(Type const* t)
{
  return is<Record_type>(t)
      || is<Array_type>(t);
}


// Returns true if this is the type of a string
// literal: char[N].
inline bool
is_string(Type const* t)
{
  if (Array_type const* a = as<Array_type>(t))
    return a->type() == get_character_type();
  else
    return false;
}


// -------------------------------------------------------------------------- //
//                              Generic visitors


template<typename F, typename T>
struct Generic_type_visitor : Type::Visitor, lingo::Generic_visitor<F, T>
{
  Generic_type_visitor(F fn)
    : lingo::Generic_visitor<F, T>(fn)
  { }

  void visit(Id_type const* t) { this->invoke(t); }
  void visit(Boolean_type const* t) { this->invoke(t); }
  void visit(Character_type const* t) { this->invoke(t); }
  void visit(Integer_type const* t) { this->invoke(t); }
  void visit(Function_type const* t) { this->invoke(t); }
  void visit(Array_type const* t) { this->invoke(t); }
  void visit(Block_type const* t) { this->invoke(t); }
  void visit(Reference_type const* t) { this->invoke(t); }
  void visit(Record_type const* t) { this->invoke(t); }
  void visit(Void_type const* t) { this->invoke(t); }
  void visit(Context_type const* t) { this->invoke(t); }

  // network specific types
  void visit(Layout_type const* t) { this->invoke(t); }
  void visit(Table_type const* t) { this->invoke(t); }
  void visit(Flow_type const* t) { this->invoke(t); }
  void visit(Port_type const* t) { this->invoke(t); }
  void visit(Key_type const* t) { this->invoke(t); }
};


template<typename F, typename T = typename std::result_of<F(Boolean_type const*)>::type>
inline T
apply(Type const* t, F fn)
{
  Generic_type_visitor<F, T> v(fn);
  return accept(t, v);
}


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
  return std::is_base_of<T, Record_type>::value;
}


// Returns true if T is a user-defined type.
template<typename T>
constexpr bool
is_user_defined_type()
{
  return std::is_base_of<T, Record_type>::value;
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
      || std::is_base_of<T, Table_type>::value
      || std::is_base_of<T, Flow_type>::value
      || std::is_base_of<T, Port_type>::value;
}


template<typename T>
constexpr bool
has_length()
{
  return is_scalar_type<T>()
      || is_aggregate_type<T>()
      || is_user_defined_type<T>()
      // FIXME: is a reference really an object tpye
      || std::is_base_of<T, Reference_type>::value
      || std::is_base_of<T, Table_type>::value
      || std::is_base_of<T, Flow_type>::value
      || std::is_base_of<T, Port_type>::value
      || std::is_base_of<T, Layout_type>::value;
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
  return is<Record_type>(t);
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


// Returns true if `t` is a user-defined type.
//
// The user-defined types are the record types and enum types.
//
// Note that a match type is not a user-defined type because
// it is not a nominal type.
inline bool
is_user_defined_type(Type const* t)
{
  return is_record_type(t);
}


inline bool
is_object_type(Type const* t)
{
  return is_scalar_type(t)
      || is_aggregate_type(t)
      || is_user_defined_type(t)
      // FIXME: is a reference really of object type?
      || is<Reference_type>(t)
      || is<Table_type>(t)
      || is<Flow_type>(t)
      || is<Port_type>(t);
}


// Evalutes to true iff T1 and T2 have the same
// dynamic type
template<typename T1, typename T2>
inline bool
same_kind(T1 const* t1, T2 const* t2)
{
  return typeid(*t1) == typeid(*t2);
}


#endif

// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#ifndef STEVE_DECL_HPP
#define STEVE_DECL_HPP

// The declaration module defines the declarations
// in the language and tools for working with them.

#include "steve/prelude.hpp"
#include "steve/value.hpp"

#include "lingo/node.hpp"


namespace steve
{

// -------------------------------------------------------------------------- //
//                            Declaration kinds

// Different kinds of expressions in the core language.
enum Decl_kind
{
  variable_decl,  // variable declarations
  constant_decl,  // constant declarations
  forward_decl,   // pending declarations
  function_decl,  // function declarations
  parameter_decl, // parameter declarations
  record_decl,    // record declarations
  member_decl,    // member declarations
  variant_decl,   // variant type declaration
  enum_decl,      // enumerations
  decode_decl,    // decode declarations
  table_decl,     // table declaration
  flow_decl,      // flow declaration
  extracts_decl,  // extracts decl
  rebind_decl,    // extracts <field> as <field>
};


char const* get_decl_name(Decl_kind);


// Adapt the generic node-kinding template to this node type.
template<Decl_kind K>
using Decl_impl = lingo::Kind_base<Decl_kind, K>;


// -------------------------------------------------------------------------- //
//                                Expressions

struct Type;
struct Expr;
struct Decl;
struct Stmt;


// The Decl class is the base class of all declarations in
// the language. A declaration introduces a name binding for
// some kind of program entity.
//
// A declaration can be constrained by a logical proposition.
// These constraints are evaluated to deterimine if the declaration
// is valid, or if it can be used, depending on the kind of
// declaration.
struct Decl
{
  Decl(Decl_kind k, Location l, String const* n, Type const* t)
    : kind_(k), loc_(l), name_(n), type_(t)
  { }

  virtual ~Decl()
  { }

  char const*   node_name() const { return get_decl_name(kind_); }
  Decl_kind     kind() const      { return kind_; }
  Location      location() const  { return loc_; }
  String const* name() const      { return name_; }
  Type const*   type() const      { return type_; }
  Prop const*   prop() const      { return prop_; }

  Decl_kind     kind_;
  Location      loc_;
  String const* name_;
  Type const*   type_;
  Prop const*   prop_;
};


// A variable declares a name to be an object.
struct Variable_decl : Decl, Decl_impl<variable_decl>
{
  Variable_decl(Location loc, String const* n, Type const* t, Expr const* e)
    : Decl(node_kind, loc, n, t), first(e)
  { }

  Expr const* init() const { return first; }

  void set_init(Expr const* e) { first = e; }

  Expr const* first;
};


// A constant declares a name to be a compile-time value.
//
// Unlike variables, constants are not stored in objects, and
// their address cannot be taken. They represent compile-time
// values.
struct Constant_decl : Decl, Decl_impl<constant_decl>
{
  Constant_decl(Location loc, String const* n, Type const* t, Expr const* e)
    : Decl(node_kind, loc, n, t), first(e)
  { }

  Expr const* init() const { return first; }

  Expr const* first;
};


// A function declaration defines a mapping from a sequence
// of inputs to an output. The parameters of a function
// determine the types of inputs. The body of a function is
// a statement that computes the result.
struct Function_decl : Decl, Decl_impl<function_decl>
{
  Function_decl(Location, String const*, Type const*, Decl_seq const&, Stmt const*);

  Decl_seq const&      parms() const { return first; }
  Stmt const*          body() const  { return second; }
  Function_type const* type() const;
  Type const*          ret_type() const;

  void set_body(Stmt const* s) { second = s; }

  Decl_seq    first;
  Stmt const* second;
};


// A parameter declaration.
//
// TODO: Support default arguments.
struct Parameter_decl : Decl, Decl_impl<parameter_decl>
{
  Parameter_decl(Location loc, String const* n, Type const* t)
    : Decl(node_kind, loc, n, t)
  { }
};


// A record declaration.
struct Record_decl : Decl, Decl_impl<record_decl>
{
  Record_decl(Location loc, String const* n, Type const* t, Decl_seq const& m)
    : Decl(node_kind, loc, n, t), first(m)
  { }

  Decl_seq const& members() const { return first; }

  Decl_seq first;
};


// A member declaration.
//
// TODO: Support member initializers.
struct Member_decl : Decl, Decl_impl<member_decl>
{
  Member_decl(Location loc, String const* n, Type const* t)
    : Decl(node_kind, loc, n, t)
  { }
};


// A variant declaration defines a variant type whose value
// is determined by a set of distinct (i.e., disjoint) types.
//
// TODO: declarations of user-defined types within
// a variant:
//
//    variant V {
//      record R { ... }; // OK.
//    }
struct Variant_decl : Decl, Decl_impl<variant_decl>
{
  Variant_decl(Location loc, String const* n, Type const* t, Type_seq const& ts)
    : Decl(node_kind, loc, n, t), first(ts)
  { }

  Type_seq const& types() const { return first; }

  Type_seq first;
};


// An enumeration declaration. An enumeration may
// be parameterized over an underlying type and has
// a sequence of constant declarations.
struct Enum_decl : Decl, Decl_impl<enum_decl>
{
  Enum_decl(Location loc, String const* n, Type const* t, Type const* b, Decl_seq const& d)
    : Decl(node_kind, loc, n, t), first(b), second(d)
  { }

  Type const*     base() const    { return first; }
  Decl_seq const& members() const { return second; }

  Type const* first;
  Decl_seq    second;
};


// A decode declaration  is defined for a type and gives 
// conditions  to determine the next decoder in line.
//
// Stmt* s is a block stmt containing all stmt inside a decoder
// Type* h is the header type 
struct Decode_decl : Decl, Decl_impl<decode_decl>
{
  Decode_decl(Location loc, String const* n, Type const* t, Stmt const* s, Type const* h)
    : Decl(node_kind, loc, n, t), first(h), second(s)
  { }

  Type  const* header() const { return first; }
  Stmt  const* body()  const { return second; }

  Type const* first;
  Stmt const* second;
};


// A flow table.
struct Table_decl : Decl, Decl_impl<table_decl> 
{
  Table_decl(Location loc, String const* n, Type const* t, int num, Expr_seq const& conds)
    : Decl(node_kind, loc, n, t), first(num), second(conds)
  { }

  Table_decl(Location loc, String const* n, Type const* t, int num, Expr_seq const& conds, Decl_seq const& init)
    : Decl(node_kind, loc, n, t), first(num), second(conds), third(init)
  { }

  int             number() const     { return first; }
  Expr_seq const& conditions() const { return second; }
  Decl_seq const& body() const { return third; }

  int      first;
  Expr_seq const second;
  Decl_seq const third;
};


// An entry within a flow table.
struct Flow_decl : Decl, Decl_impl<flow_decl> 
{
  Flow_decl(Location loc, String const* n, Type const* t, Expr_seq const& conds, Value const& prio, Stmt const* i)
    : Decl(node_kind, loc, n, t), first(prio), second(conds), third(i)
  { }
  
  Value const&    priority() const { return first; }
  Expr_seq const& conditions() const { return second; }
  Stmt const*     instructions() const { return third; }

  Value first;
  Expr_seq const second;
  Stmt const* third;
};


struct Extracts_decl : Decl, Decl_impl<extracts_decl>
{
  Extracts_decl(Location loc, String const* n, Type const* t, Expr const* e)
    : Decl(node_kind, loc, n, t), first(e)
  { }

  Expr const* field() const { return first; }

  Expr const* first;
};


struct Rebind_decl : Decl, Decl_impl<extracts_decl>
{
  Rebind_decl(Location loc, String const* n, Type const* t, Expr const* e1, Expr const* e2)
    : Decl(node_kind, loc, n, t), first(e1), second(e2)
  { }

  Expr const* field1() const { return first; }
  Expr const* field2() const { return second; }

  Expr const* first;
  Expr const* second;
};


// -------------------------------------------------------------------------- //
//                           Concepts and dispatch

// True when T is models the Declaration concept. 
//
// Note that we assume that a Declaration is already known 
// to be Node, so we skip the explicit check.
template<typename T>
constexpr bool
is_decl()
{
  return std::is_base_of<Decl, T>::value;
}


// Apply function to the declaration `d`.
template<typename T, typename F>
auto
apply(T const* d, F fn)
  -> typename std::enable_if<is_decl<T>(), decltype(fn((Variable_decl*)0))>::type
{
  lingo_assert(is_valid_node(d));
  switch (d->kind()) {
    case variable_decl: return fn(cast<Variable_decl>(d));
    case constant_decl: return fn(cast<Constant_decl>(d));
    case forward_decl: return fn(cast<Forward_decl>(d));
    case function_decl: return fn(cast<Function_decl>(d));
    case parameter_decl: return fn(cast<Parameter_decl>(d));
    case record_decl: return fn(cast<Record_decl>(d));
    case member_decl: return fn(cast<Member_decl>(d));
    case variant_decl: return fn(cast<Variant_decl>(d));
    case enum_decl: return fn(cast<Enum_decl>(d));
    case decode_decl: return fn(cast<Decode_decl>(d));
    case table_decl: return fn(cast<Table_decl>(d));
    case flow_decl: return fn(cast<Flow_decl>(d));
    case extracts_decl: return fn(cast<Extracts_decl>(d));
    case rebind_decl: return fn(cast<Rebind_decl>(d));
  }
  lingo_unreachable("unhandled declaration '{}'", d->node_name());
}


// -------------------------------------------------------------------------- //
//                                  Queries

// Returns true if the record `r` contains the member `m`.
//
// TODO: This is currently a linear search. We could optimize
// this by equipping the class with a hash set that stores
// know declrations.
//
// This function is used to guarntee compiler consistency
// in the checking of member expressions.
inline bool 
has_member(Record_decl const* r, Member_decl const* m)
{
  Decl_seq const& mem = r->members();
  return std::find(mem.begin(), mem.end(), m) != mem.end();
}


// Returns the index of the member `m` in the record 
// declaration `r`.
inline int
member_index(Record_decl const* r, Member_decl const* m)
{
  Decl_seq const& mem = r->members();
  auto iter = std::find(mem.begin(), mem.end(), m);
  return iter - mem.begin();
}


// -------------------------------------------------------------------------- //
//                            Declaration builders

String const* get_identifier(String const&);

Variable_decl*  make_variable_decl(Location, String const*, Type const*);
Variable_decl*  make_variable_decl(Location, String const*, Type const*, Expr const*);
Constant_decl*  make_constant_decl(Location, String const*, Type const*, Expr const*);

Forward_decl*   make_forward_decl(Location, String const*, Type const*);

Function_decl*  make_function_decl(Location, String const*, Decl_seq const&, Type const*);
Function_decl*  make_function_decl(Location, String const*, Decl_seq const&, Type const*, Stmt const*);

Parameter_decl* make_parameter_decl(Location, String const*, Type const*);
Member_decl*    make_member_decl(Location, String const*, Type const*);
Record_decl*    make_record_decl(Location, String const*, Decl_seq const&);
Variant_decl*   make_variant_decl(Location, String const*, Type_seq const&);
Enum_decl*      make_enum_decl(Location, String const*, Type const*, Decl_seq const&);
Constant_decl*  make_enumerator_decl(Location, String const*, Type const*, Expr const*, Decl const*);
Decode_decl*    make_decode_decl(Location, String const*, Type const*, Stmt const*);
Enum_decl*      make_enumeration_decl(Location, String const*, Type const*, Decl_seq const&);
Table_decl*     make_table_decl(Location, String const*, Expr_seq const&, Decl_seq const&);
Flow_decl*      make_flow_decl(Location, Expr_seq const&, Value const, Stmt const*);
Extracts_decl*  make_extracts_decl(Location, Expr const*);
Rebind_decl*    make_rebind_decl(Location, Expr const*, Expr const*);


// Make a new variable declaration. The type of the expression shall
// match the declared type of the variable.
inline Variable_decl*
make_variable_decl(String const* n, Type const* t, Expr const* e)
{
  return make_variable_decl(Location::none, n, t, e);
}


// Make a new constant declaration.
inline Constant_decl*
make_constant_decl(String const* n, Type const* t, Expr const* e)
{
  return make_constant_decl(Location::none, n, t, e);
}


inline Forward_decl*
make_forward_decl(String const* n, Type const* t)
{
  return make_forward_decl(Location::none, n, t);
}


// Make a function declaration.
inline Function_decl* 
make_function_decl(String const* n, Decl_seq const& p, Type const* r, Stmt const* b)
{
  return make_function_decl(Location::none, n, p, r, b);
}


// Make a parameter declaration.
inline Parameter_decl*
make_parameter_decl(String const* n, Type const* t)
{
  return make_parameter_decl(Location::none, n, t);
}


// Make a member declaration.
inline Member_decl*
make_member_decl(String const* n, Type const* t)
{
  return make_member_decl(Location::none, n, t);
}


// Make a record declaration.
inline Record_decl*
make_record_decl(String const* n, Decl_seq const& m)
{
  return make_record_decl(Location::none, n, m);
}


// Make an enum declaration.
inline Enum_decl*
make_enumeration_decl(String const* n, Type const* t, Decl_seq const& m)
{
  return make_enumeration_decl(Location::none, n, t, m);
}


// Make a variant declaration.
inline Variant_decl*
make_variant_decl(String const* n, Type_seq const& t)
{
  return make_variant_decl(Location::none, n, t);
}


// Make a decoder declaration.
inline Decode_decl*
make_decode_decl(String const* n, Type const* t, Stmt const* s)
{
  return make_decode_decl(Location::none, n, t, s);
}


inline Table_decl*
make_table_decl(String const* n, Expr_seq const& e, Decl_seq const& d)
{
  return make_table_decl(Location::none, n, e, d);  
}


inline Flow_decl*
make_flow_decl(Expr_seq const& e, Value const v, Stmt const* s)
{
  return make_flow_decl(Location::none, e, v, s);
}


inline Extracts_decl*
make_extracts_decl(Expr const* e)
{
  return make_extracts_decl(Location::none, e);
}


inline Rebind_decl*
make_rebind_decl(Expr const* e1, Expr const* e2)
{
  return make_rebind_decl(Location::none, e1, e1);
}


// -------------------------------------------------------------------------- //
//                                  Facilities

// Garbage collection
void mark(Decl const*);


} // namespace steve

#endif

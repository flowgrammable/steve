// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#ifndef STEVE_DECL_HPP
#define STEVE_DECL_HPP

// The declaration module defines the declarations
// in the language and tools for working with them.

#include "steve/prelude.hpp"
#include "steve/value.hpp"
#include "steve/token.hpp"

#include "lingo/node.hpp"


namespace steve
{

struct Decl_visitor;


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
  Decl(Location l, String const* n, Type const* t)
    : loc_(l), name_(n), type_(t)
  { }

  virtual ~Decl()
  { }

  String        node_name() const;
  Location      location() const  { return loc_; }
  String const* name() const      { return name_; }
  Type const*   type() const      { return type_; }
  Prop const*   prop() const      { return prop_; }
  virtual bool  has_impl() const  { return true; }

    // Accept a declaration visitor.
  virtual void accept(Decl_visitor&) const = 0;

  Location      loc_;
  String const* name_;
  Type const*   type_;
  Prop const*   prop_;
};


// The declaration visitor.
struct Decl_visitor
{
  virtual void visit(Variable_decl const*) { }
  virtual void visit(Constant_decl const*) { }
  virtual void visit(Function_decl const*) { }
  virtual void visit(Parameter_decl const*) { }
  virtual void visit(Record_decl const*) { }
  virtual void visit(Member_decl const*) { }
  virtual void visit(Variant_decl const*) { }
  virtual void visit(Enum_decl const*) { }
  virtual void visit(Forward_decl const*) { }
  virtual void visit(Decode_decl const*) { }
  virtual void visit(Table_decl const*) { }
  virtual void visit(Flow_decl const*) { }
  virtual void visit(Extracts_decl const*) { }
  virtual void visit(Rebind_decl const*) { }
};


// A variable declares a name to be an object.
struct Variable_decl : Decl
{
  Variable_decl(Location loc, String const* n, Type const* t, Expr const* e)
    : Decl(loc, n, t), first(e)
  { }

  Expr const* init() const { return first; }
  bool        has_impl() const { return init() ? true : false; }
  void accept(Decl_visitor& v) const { v.visit(this); }

  void set_init(Expr const* e) { first = e; }

  Expr const* first;
};


// A constant declares a name to be a compile-time value.
//
// Unlike variables, constants are not stored in objects, and
// their address cannot be taken. They represent compile-time
// values.
struct Constant_decl : Decl
{
  Constant_decl(Location loc, String const* n, Type const* t, Expr const* e)
    : Decl(loc, n, t), first(e)
  { }

  Expr const* init() const { return first; }
  void accept(Decl_visitor& v) const { v.visit(this); }

  Expr const* first;
};


// A function declaration defines a mapping from a sequence
// of inputs to an output. The parameters of a function
// determine the types of inputs. The body of a function is
// a statement that computes the result.
struct Function_decl : Decl
{
  Function_decl(Location, String const*, Type const*, Decl_seq const&, Stmt const*);

  Decl_seq const&      parms() const { return first; }
  Stmt const*          body() const  { return second; }
  Function_type const* type() const;
  Type const*          ret_type() const;
  bool                 has_impl() const { return body() ? true : false; }
  bool                 is_foreign() const { return is_foreign_; }

  void set_body(Stmt const* s) { second = s; }
  void set_foreign() { is_foreign_ = true; }

  void accept(Decl_visitor& v) const { v.visit(this); }

  Decl_seq    first;
  Stmt const* second;

  bool is_foreign_;
};


// A parameter declaration.
//
// TODO: Support default arguments.
struct Parameter_decl : Decl
{
  Parameter_decl(Location loc, String const* n, Type const* t)
    : Decl(loc, n, t)
  { }

  void accept(Decl_visitor& v) const { v.visit(this); }
};


// A record declaration.
struct Record_decl : Decl
{
  Record_decl(Location loc, String const* n, Type const* t, Decl_seq const& m)
    : Decl(loc, n, t), first(m)
  { }

  Decl_seq const& members() const { return first; }
  void accept(Decl_visitor& v) const { v.visit(this); }

  Decl_seq first;
};


// A member declaration.
//
// TODO: Support member initializers.
struct Member_decl : Decl
{
  Member_decl(Location loc, String const* n, Type const* t)
    : Decl(loc, n, t)
  { }

  void accept(Decl_visitor& v) const { v.visit(this); }
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
struct Variant_decl : Decl
{
  Variant_decl(Location loc, String const* n, Type const* t, Type_seq const& ts)
    : Decl(loc, n, t), first(ts)
  { }

  Type_seq const& types() const { return first; }
  void accept(Decl_visitor& v) const { v.visit(this); }

  Type_seq first;
};


// An enumeration declaration. An enumeration may
// be parameterized over an underlying type and has
// a sequence of constant declarations.
struct Enum_decl : Decl
{
  Enum_decl(Location loc, String const* n, Type const* t, Type const* b, Decl_seq const& d)
    : Decl(loc, n, t), first(b), second(d)
  { }

  Type const*     base() const    { return first; }
  Decl_seq const& members() const { return second; }
  void accept(Decl_visitor& v) const { v.visit(this); }

  Type const* first;
  Decl_seq    second;
};


// Forward declaration placeholder
//
// Because forward declarations eventually get defined
// those decl nodes get their definitions added before the
// end of the compiling process. It is convenient to emit
// a forward declaration node where the forward declaration
// is made for the sake of easy conversion into C.
//
// This decl never gets added to scope, but rather it works as
// a placeholder for translation. Therefore, the only thing we
// need to remember is what kind of declaration was made and
// what the name of that declaration is. The original decl
// does not need to be stored here.
//
// Note: The type of a forward declaration node is actually meaningless
// we only care about its kind.
enum Fwd_kind {
  // currently supported
  function_fwd,
  decode_fwd,
  table_fwd,

  // FIXME: not yet supported
  record_fwd,
  enum_fwd,
  variant_fwd,  
};


struct Forward_decl : Decl
{
  Forward_decl(Location loc, Decl const* d, Fwd_kind k)
    : Decl(loc, d->name(), nullptr), first(d), second(k)
  { }

  Decl const* decl() const { return first; }
  Fwd_kind kind() const { return second; }

  void accept(Decl_visitor& v) const { v.visit(this); }

  Decl const* first;
  Fwd_kind second;
};


// A decode declaration  is defined for a type and gives 
// conditions  to determine the next decoder in line.
//
// Stmt* s is a block stmt containing all stmt inside a decoder
// Type* h is the header type 
struct Decode_decl : Decl
{
  Decode_decl(Location loc, String const* n, Type const* t, Stmt const* s, Type const* h)
    : Decl(loc, n, t), first(h), second(s), start_(false)
  { }

  Type  const* header() const { return first; }
  Stmt  const* body()  const { return second; }
  bool         has_impl() const { return body() ? true : false; }
  bool         is_start() const { return start_; }

  void accept(Decl_visitor& v) const { v.visit(this); }

  void set_body(Stmt const* s) { second = s; }
  void set_start() { start_ = true; }

  Type const* first;
  Stmt const* second;
  bool start_;
};


// A flow table.
struct Table_decl : Decl
{
  Table_decl(Location loc, String const* n, Type const* t, int num, Expr_seq const& conds)
    : Decl(loc, n, t), first(num), second(conds), start_(false)
  { }

  Table_decl(Location loc, String const* n, Type const* t, int num, Expr_seq const& conds, Decl_seq const& init)
    : Decl(loc, n, t), first(num), second(conds), third(init), start_(false)
  { }

  int             number() const     { return first; }
  Expr_seq const& conditions() const { return second; }
  Decl_seq const& body() const { return third; }
  bool has_impl() const { return (body().size() > 0) ? true : false; }
  bool is_start() const { return start_; }

  void accept(Decl_visitor& v) const { v.visit(this); }

  void set_body(Decl_seq const& d) { third = d; }
  void set_start() { start_ = true; }

  int      first;
  Expr_seq second;
  Decl_seq third;
  bool start_;
};


// An entry within a flow table.
//
// FIXME: We should check during compile time that the
// length of the subkey does not exceed the maximum key
// size of the table.
struct Flow_decl : Decl
{
  Flow_decl(Location loc, String const* n, Type const* t, Expr_seq const& conds, Value const& prio, Stmt const* i)
    : Decl(loc, n, t), first(prio), second(conds), third(i)
  { }
  
  Value const&    priority() const { return first; }
  Expr_seq const& keys() const { return second; }
  Stmt const*     instructions() const { return third; }
  void accept(Decl_visitor& v) const { v.visit(this); }

  void set_instructions(Stmt const* i) { third = i; }

  Value first;
  Expr_seq const second;
  Stmt const* third;
};


struct Extracts_decl : Decl
{
  Extracts_decl(Location loc, String const* n, Type const* t, Expr const* e)
    : Decl(loc, n, t), first(e)
  { }

  Expr const* field() const { return first; }
  void accept(Decl_visitor& v) const { v.visit(this); }

  Expr const* first;
};


struct Rebind_decl : Decl
{
  Rebind_decl(Location loc, String const* n, Type const* t, Expr const* e1, Expr const* e2)
    : Decl(loc, n, t), first(e1), second(e2)
  { }

  Expr const* field1() const { return first; }
  Expr const* field2() const { return second; }
  void accept(Decl_visitor& v) const { v.visit(this); }

  Expr const* first;
  Expr const* second;
};


struct Port_decl : Decl
{
  Port_decl(Location loc, String const* n, Type const* t)
    : Decl(loc, n, t)
  { }
};


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


// -------------------------------------------------------------------------- //
//                            Generic visitor

// A parameterized visitor that dispatches to a function object.
template<typename F, typename T>
struct Generic_decl_visitor : Decl_visitor, Generic_visitor<F, T>
{
  Generic_decl_visitor(F f)
    : Generic_visitor<F, T>(f)
  { }

  void visit(Variable_decl const* d) { this->invoke(d); }
  void visit(Constant_decl const* d) { this->invoke(d); }
  void visit(Function_decl const* d) { this->invoke(d); }
  void visit(Parameter_decl const* d) { this->invoke(d); }
  void visit(Record_decl const* d) { this->invoke(d); }
  void visit(Member_decl const* d) { this->invoke(d); }
  void visit(Variant_decl const* d) { this->invoke(d); }
  void visit(Enum_decl const* d) { this->invoke(d); }
  void visit(Forward_decl const* d) { this->invoke(d); }
  void visit(Decode_decl const* d) { this->invoke(d); }
  void visit(Table_decl const* d) { this->invoke(d); }
  void visit(Flow_decl const* d) { this->invoke(d); }
  void visit(Extracts_decl const* d) { this->invoke(d); }
  void visit(Rebind_decl const* d) { this->invoke(d); }
  void visit(Port_decl const* d) { this->invoke(d); }
};


// Apply the function f to the statement s.
template<typename F, typename T = typename std::result_of<F(Variable_decl*)>::type>
inline T
apply(Decl const* s, F fn)
{
  Generic_decl_visitor<F, T> v(fn);
  return accept(s, v);
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


// Returns the member decl with a specific name within a record_decl
// or nullptr if no member declaration with the given name can
// be found.
inline Member_decl const*
find_member(Record_decl const* r, String const* name)
{
  Decl_seq const& mems = r->members();
  for (auto member : mems) {
    if (member->name() == name)
      return as<Member_decl>(member);
  }

  return nullptr;
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

// String const* get_identifier(String const&);

Variable_decl*  make_variable_decl(Location, String const*, Type const*);
Variable_decl*  make_variable_decl(Location, String const*, Type const*, Expr const*);
Constant_decl*  make_constant_decl(Location, String const*, Type const*, Expr const*);

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
Port_decl*      make_port_decl(Location, String const*);

Forward_decl*   make_forward_decl(Location, Decl const*, Fwd_kind);


// Add definitions to declarations that don't have them
void define(Decode_decl*, Stmt const*);
void define(Variable_decl*, Expr const*);
void define(Function_decl*, Stmt const*);


// Make a new variable declaration. The type of the expression shall
// match the declared type of the variable.
inline Variable_decl*
make_variable_decl(String const* n, Type const* t, Expr const* e)
{
  return make_variable_decl(Location::none, n, t, e);
}


inline Variable_decl*
make_variable_decl(String const* n, Type const* t)
{
  return make_variable_decl(Location::none, n, t);
}


// Make a new constant declaration.
inline Constant_decl*
make_constant_decl(String const* n, Type const* t, Expr const* e)
{
  return make_constant_decl(Location::none, n, t, e);
}


// Make a function declaration.
inline Function_decl* 
make_function_decl(String const* n, Decl_seq const& p, Type const* r, Stmt const* b)
{
  return make_function_decl(Location::none, n, p, r, b);
}


inline Function_decl*
make_function_decl(String const* n, Decl_seq const& p, Type const* r)
{
  return make_function_decl(Location::none, n, p, r);
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


inline Decode_decl*
make_decode_decl(String const* n, Type const* t)
{
  return make_decode_decl(Location::none, n, t, nullptr);
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


// FIXME: check that the two fields have the same type
inline Rebind_decl*
make_rebind_decl(Expr const* e1, Expr const* e2)
{
  return make_rebind_decl(Location::none, e1, e2);
}


// TODO: implement the rest of forward decls
inline Forward_decl*
make_forward_decl(Decl const* d)
{
  if (is<Function_decl>(d))
    return make_forward_decl(Location::none, d, function_fwd);
  if (is<Decode_decl>(d))
    return make_forward_decl(Location::none, d, decode_fwd);
  if (is<Table_decl>(d))
    return make_forward_decl(Location::none, d, table_fwd);

  return nullptr;
}


// -------------------------------------------------------------------------- //
//                                  Queries

// Defines a set of declarations which can be rewritten
// after they've been declared. For now, this is only applicable
// to declarations which can be lowered.
inline bool
is_rewriteable(Decl const* d)
{
  return is<Decode_decl>(d);
}


// -------------------------------------------------------------------------- //
//                                  Facilities

// Garbage collection
void mark(Decl const*);


} // namespace steve

#endif

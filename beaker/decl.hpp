// Copyright (c) 2015 Andrew Sutton
// All rights reserved

#ifndef BEAKER_DECL_HPP
#define BEAKER_DECL_HPP

#include <beaker/prelude.hpp>
#include <beaker/scope.hpp>
#include <beaker/specifier.hpp>
#include <beaker/type.hpp>


// Represents the declaration of a named entity.
// Every declaration has a name and a type. Note that
// user-defined type declarations (e.g., modulues)
// have nullptr type. We use this to indicate a higher
// order type.
struct Decl
{
  struct Visitor;
  struct Mutator;

  Decl(Symbol const* s, Type const* t)
    : spec_(no_spec), name_(s), type_(t), cxt_(nullptr), declare_(false)
  { }

  Decl(Specifier spec, Symbol const* s, Type const* t)
    : spec_(spec), name_(s), type_(t), cxt_(nullptr), declare_(false)
  { }

  virtual ~Decl() { }

  virtual void accept(Visitor&) const = 0;
  virtual void accept(Mutator&) = 0;

  // Declaration specifiers
  Specifier specifiers() const { return spec_; }
  bool      is_foreign() const { return spec_ & foreign_spec; }
  bool      is_declare() const { return declare_; }

  Symbol const* name() const { return name_; }
  Type const*   type() const { return type_; }

  Decl const*   context() const { return cxt_; }

  Specifier     spec_;
  Symbol const* name_;
  Type const*   type_;
  Decl const*   cxt_;
  bool          declare_;
};


// The read-only declaration visitor.
struct Decl::Visitor
{
  virtual void visit(Variable_decl const*) = 0;
  virtual void visit(Function_decl const*) = 0;
  virtual void visit(Parameter_decl const*) = 0;
  virtual void visit(Record_decl const*) = 0;
  virtual void visit(Field_decl const*) = 0;
  virtual void visit(Method_decl const*) = 0;
  virtual void visit(Module_decl const*) = 0;

  // network declarations
  virtual void visit(Layout_decl const*) = 0;
  virtual void visit(Decode_decl const*) = 0;
  virtual void visit(Table_decl const*) = 0;
  virtual void visit(Key_decl const*) = 0;
  virtual void visit(Flow_decl const*) = 0;
  virtual void visit(Port_decl const*) = 0;
  virtual void visit(Extracts_decl const*) = 0;
  virtual void visit(Rebind_decl const*) = 0;
};


// The read/write declaration visitor.
struct Decl::Mutator
{
  virtual void visit(Variable_decl*) = 0;
  virtual void visit(Function_decl*) = 0;
  virtual void visit(Parameter_decl*) = 0;
  virtual void visit(Record_decl*) = 0;
  virtual void visit(Field_decl*) = 0;
  virtual void visit(Method_decl*) = 0;
  virtual void visit(Module_decl*) = 0;

  // network declarations
  virtual void visit(Layout_decl*) = 0;
  virtual void visit(Decode_decl*) = 0;
  virtual void visit(Table_decl*) = 0;
  virtual void visit(Key_decl*) = 0;
  virtual void visit(Flow_decl*) = 0;
  virtual void visit(Port_decl*) = 0;
  virtual void visit(Extracts_decl*) = 0;
  virtual void visit(Rebind_decl*) = 0;
};


// Represents variable declarations.
struct Variable_decl : Decl
{
  Variable_decl(Symbol const* n, Type const* t, Expr* e)
    : Decl(n, t), init_(e)
  { }

  Variable_decl(Specifier spec, Symbol const* n, Type const* t, Expr* e)
    : Decl(spec, n, t), init_(e)
  { }

  void accept(Visitor& v) const { v.visit(this); }
  void accept(Mutator& v)       { v.visit(this); }

  Expr const* init() const { return init_; }
  Expr*       init()       { return init_; }

  Expr* init_;
};


// Represents function declarations.
struct Function_decl : Decl
{
  Function_decl(Symbol const* n, Type const* t, Decl_seq const& p, Stmt* b)
    : Decl(n, t), parms_(p), body_(b)
  { }

  Function_decl(Specifier spec, Symbol const* n, Type const* t, Decl_seq const& p, Stmt* b)
    : Decl(spec, n, t), parms_(p), body_(b)
  { }

  void accept(Visitor& v) const { v.visit(this); }
  void accept(Mutator& v)       { v.visit(this); }

  Decl_seq const&      parameters() const { return parms_; }

  Function_type const* type() const;
  Type const*          return_type() const;

  Stmt const* body() const { return body_; }
  Stmt*       body()       { return body_; }

  bool is_virtual() const  { return spec_ & virtual_spec; }
  bool is_abstract() const { return spec_ & abstract_spec; }
  bool is_polymorphic() const { return is_virtual() || is_abstract(); }

  Decl_seq parms_;
  Stmt*    body_;
};


// Represents parameter declarations.
struct Parameter_decl : Decl
{
  using Decl::Decl;

  void accept(Visitor& v) const { v.visit(this); }
  void accept(Mutator& v)       { v.visit(this); }
};


// Declares a user-defined record type.
//
// The record class maintains two sets of declarations:
// - fields, which constitute its actual type, and
// - another set of member declarations (e.g., methods, nested
//   types, templates, constants, etc). These aren't really part
//   of the object, just part of the scope.
//
// A record declaration defines a scope. Declarations
// within the record are cached here for use during
// member lookup.
struct Record_decl : Decl
{
  Record_decl(Symbol const* n, Decl_seq const& f, Decl_seq const& m, Type const* base)
    : Decl(n, nullptr), scope_(this), fields_(f), members_(m)
    , base_(base), vref_(nullptr), vtbl_(nullptr)
  { }

  void accept(Visitor& v) const { v.visit(this); }
  void accept(Mutator& v)       { v.visit(this); }

  Record_type const* base() const;
  Record_decl*       base_declaration() const;

  Decl_seq const& fields() const  { return fields_; }
  Decl_seq const& members() const { return members_; }

  Scope const*    scope() const { return &scope_; }
  Scope*          scope()       { return &scope_; }

  Decl const*     vref() const   { return vref_; }
  Decl*           vref()         { return vref_; }

  Decl_seq const* vtable() const { return vtbl_; }
  Decl_seq*       vtable()       { return vtbl_; }

  bool is_empty() const;
  bool is_virtual() const     { return spec_ & virtual_spec; }
  bool is_abstract() const    { return spec_ & abstract_spec; }
  bool is_polymorphic() const { return is_virtual() || is_abstract(); }

  Scope          scope_;
  Decl_seq       fields_;
  Decl_seq       members_;
  const Type*    base_;
  Decl*          vref_;
  Decl_seq*      vtbl_;
};


// A member variable of a record.
//
// TODO: Cache the field index?
struct Field_decl : Decl
{
  using Decl::Decl;

  void accept(Visitor& v) const { v.visit(this); }
  void accept(Mutator& v)       { v.visit(this); }

  Record_decl const* context() const { return cast<Record_decl>(cxt_); }

  int index() const;
};


// A member function of a record. A member function of
// a record T has an implicit parameter named 'this' whose
// type is T&.
struct Method_decl : Function_decl
{
  using Function_decl::Function_decl;

  void accept(Visitor& v) const { v.visit(this); }
  void accept(Mutator& v)       { v.visit(this); }

  Record_decl const* context() const { return cast<Record_decl>(cxt_); }
};


// A module is a sequence of top-level declarations.
struct Module_decl : Decl
{
  Module_decl()
    : Decl(nullptr, nullptr)
  { }

  Module_decl(Symbol const* n, Decl_seq const& d)
    : Decl(n, nullptr), decls_(d)
  { }

  void accept(Visitor& v) const { v.visit(this); }
  void accept(Mutator& v)       { v.visit(this); }

  Decl_seq const& declarations() const { return decls_; }

  Decl_seq decls_;
};


// A layout decl describes the layout of a
// packet header. These are similar to records, but
// objects of layouts cannot be made
// so therefore, this declaration has no intrinsic type,
// and are also discarded before code generation.
struct Layout_decl : Decl
{
  Layout_decl(Symbol const* n, Decl_seq const& f)
    : Decl(n, nullptr), fields_(f), scope_(this)
  { }

  void accept(Visitor& v) const { v.visit(this); }
  void accept(Mutator& v)       { v.visit(this); }

  Decl_seq const& fields() const { return fields_; }

  Scope*          scope()       { return &scope_; }
  Scope const*    scope() const { return &scope_; }

  Decl_seq fields_;
  Scope    scope_;
};


// A decoder declaration
// A decode declaration  is defined for a type and gives
// conditions  to determine the next decoder in line.
//
// Stmt* s is a block stmt containing all stmt inside a decoder
// Type* h is the header type
struct Decode_decl : Decl
{
  Decode_decl(Symbol const* n, Type const* t, Stmt* s, Type const* h)
    : Decl(n, t), header_(h), body_(s), start_(false)
  { }

  Decode_decl(Symbol const* n, Type const* t, Stmt* s, Type const* h, bool start)
    : Decl(n, t), header_(h), body_(s), start_(start)
  { }

  Type  const* header() const { return header_; }
  Stmt  const* body()   const { return body_; }
  Stmt*        body()        { return body_; }
  bool         is_start() const { return start_; }

  void accept(Visitor& v) const { v.visit(this); }
  void accept(Mutator& v)       { v.visit(this); }

  void set_body(Stmt* s) { body_ = s; }
  void set_start() { start_ = true; }

  Type const* header_;
  Stmt* body_;
  bool start_;
};


// A flow table.
struct Table_decl : Decl
{
  // Table kind
  enum Table_kind
  {
    exact_table,
    wildcard_table,
    prefix_table,
    string_table
  };

  // Default exact table
  Table_decl(Symbol const* n, Type const* t, int num, Decl_seq& conds,
             Decl_seq& init, Decl* miss)
    : Decl(n, t), num(num), keys_(conds), body_(init), miss_(miss),
      start_(false), kind_(exact_table)
  {
    spec_ |= foreign_spec; // mark as foreign
  }

  Table_decl(Symbol const* n, Type const* t, int num, Decl_seq& conds,
             Decl_seq& init, Decl* miss, Table_kind k)
    : Decl(n, t), num(num), keys_(conds), body_(init), miss_(miss),
      start_(false), kind_(k)
  {
    spec_ |= foreign_spec; // mark as foreign
  }


  int             number()    const { return num; }
  Decl_seq const& keys()      const { return keys_; }
  Decl_seq const& body()      const { return body_; }
  Decl*           miss_case() const { return miss_; }
  Table_kind      kind()      const { return kind_; }
  bool            is_start()  const { return start_; }

  void accept(Visitor& v) const { v.visit(this); }
  void accept(Mutator& v)       { v.visit(this); }

  int      num;
  Decl_seq keys_;
  Decl_seq body_;
  Decl* miss_;
  bool start_;
  Table_kind kind_;
};


// A subkey declared in a table's
// set of subkeys
struct Key_decl : Decl
{
  Key_decl(Expr_seq const& e, Symbol const* n)
    : Decl(n, nullptr), identifiers_(e), name_(n)
  { }

  Expr_seq const& identifiers() const { return identifiers_; }
  Decl_seq const& declarations() const { return decls_; }

  Symbol const* name() const { return name_; }
  String const& spelling() const { return name_->spelling(); }

  void accept(Visitor& v) const { v.visit(this); }
  void accept(Mutator& v)       { v.visit(this); }

  Decl_seq decls_;
  Expr_seq identifiers_;

  Symbol const* name_;
};


// An entry within a flow table.
//
// FIXME: We should check during compile time that the
// length of the subkey does not exceed the maximum key
// size of the table.
struct Flow_decl : Decl
{
  Flow_decl(Symbol const* n, Expr_seq& conds, int prio, Stmt* i)
    : Decl(n, nullptr), prio_(prio), keys_(conds), instructions_(i),
      miss_(false)
  { }

  Flow_decl(Symbol const* n, int prio, Stmt* i, bool miss = true)
    : Decl(n, nullptr), prio_(prio), keys_{}, instructions_(i),
      miss_(miss)
  { }

  int             priority() const { return prio_; }
  Expr_seq const& keys() const { return keys_; }
  Stmt*           instructions() const { return instructions_; }
  bool            miss_case() const { return miss_; }

  void accept(Visitor& v) const { v.visit(this); }
  void accept(Mutator& v)       { v.visit(this); }

  void set_instructions(Stmt* i) { instructions_ = i; }

  int prio_;
  Expr_seq keys_;
  Stmt* instructions_;
  bool miss_;
};


// Declaration for extracting a field into a context
// The name and type fields are applied during elaboration
struct Extracts_decl : Decl
{
  Extracts_decl(Expr* e)
    : Decl(nullptr, nullptr), field_(e)
  { }

  Expr* field() const { return field_; }

  void accept(Visitor& v) const { v.visit(this); }
  void accept(Mutator& v)       { v.visit(this); }

  Expr* field_;
};


// Extracts a field using the same name as another field
struct Rebind_decl : Extracts_decl
{
  Rebind_decl(Expr* e1, Expr* e2)
    : Extracts_decl(e1), f2(e2)
  { }

  Expr* alias() { return f2; }

  Symbol const* original() const { return original_; }

  void accept(Visitor& v) const { v.visit(this); }
  void accept(Mutator& v)       { v.visit(this); }

  Expr* f2;

  Symbol const* original_;
};


// Declares the name of a port
struct Port_decl : Decl
{
  Port_decl(Symbol const* n, Type const* t, Expr* e)
    : Decl(n, t), first(e)
  {
    spec_ |= foreign_spec; // mark as foreign
  }

  Expr* address() const { return first; }

  void accept(Visitor& v) const { v.visit(this); }
  void accept(Mutator& v)       { v.visit(this); }

  Expr* first;
};


// -------------------------------------------------------------------------- //
// Queries

// Returns true if v is a global variable.
inline bool
is_global_variable(Variable_decl const* v)
{
  return is<Module_decl>(v->context());
}


// Returns true if v is a local variable.
//
// TODO: This actually depends more on storage properties
// than on declaration context. For example, if the language
// allowed static local variables (as in C++), then this
// would also need to check for an appropriate declaration
// specifier.
inline bool
is_local_variable(Variable_decl const* v)
{
  return is<Function_decl>(v->context());
}


// Returns true if the declaration defines an object.
// Only variables, parameters, and fields define objects.
inline bool
is_object(Decl const* d)
{
  return is<Variable_decl>(d)
      || is<Parameter_decl>(d)
      || is<Field_decl>(d)
      || is<Table_decl>(d)
      || is<Flow_decl>(d)
      || is<Port_decl>(d);
}


// Returns true if a decl is a top-level pipeline declarations
//
//    top-level pipeline-decl -> decoders
//                               layouts
//                               tables
inline bool
is_pipeline_decl(Decl const* d)
{
  return is<Decode_decl>(d)
      || is<Layout_decl>(d)
      || is<Table_decl>(d);
}


// Returns true if the declaration is a reference.
bool is_reference(Decl const*);


// -------------------------------------------------------------------------- //
//                              Generic visitors

template<typename F, typename T>
struct Generic_decl_visitor : Decl::Visitor, lingo::Generic_visitor<F, T>
{
  Generic_decl_visitor(F fn)
    : lingo::Generic_visitor<F, T>(fn)
  { }


  void visit(Variable_decl const* d) { this->invoke(d); }
  void visit(Function_decl const* d) { this->invoke(d); }
  void visit(Parameter_decl const* d) { this->invoke(d); }
  void visit(Record_decl const* d) { this->invoke(d); }
  void visit(Field_decl const* d) { this->invoke(d); }
  void visit(Method_decl const* d) { this->invoke(d); }
  void visit(Module_decl const* d) { this->invoke(d); }

  // network declarations
  void visit(Layout_decl const* d) { this->invoke(d); }
  void visit(Decode_decl const* d) { this->invoke(d); }
  void visit(Table_decl const* d) { this->invoke(d); }
  void visit(Key_decl const* d) { this->invoke(d); }
  void visit(Flow_decl const* d) { this->invoke(d); }
  void visit(Port_decl const* d) { this->invoke(d); }
  void visit(Extracts_decl const* d) { this->invoke(d); }
  void visit(Rebind_decl const* d) { this->invoke(d); }
};


// Apply fn to the declaration d.
template<typename F, typename T = typename std::result_of<F(Variable_decl const*)>::type>
inline T
apply(Decl const* d, F fn)
{
  Generic_decl_visitor<F, T> v = fn;
  return accept(d, v);
}


template<typename F, typename T>
struct Generic_decl_mutator : Decl::Mutator, lingo::Generic_mutator<F, T>
{
  Generic_decl_mutator(F fn)
    : lingo::Generic_mutator<F, T>(fn)
  { }

  void visit(Variable_decl* d) { this->invoke(d); }
  void visit(Function_decl* d) { this->invoke(d); }
  void visit(Parameter_decl* d) { this->invoke(d); }
  void visit(Record_decl* d) { this->invoke(d); }
  void visit(Field_decl* d) { this->invoke(d); }
  void visit(Method_decl* d) { this->invoke(d); }
  void visit(Module_decl* d) { this->invoke(d); }

  // network declarations
  void visit(Layout_decl* d) { this->invoke(d); }
  void visit(Decode_decl* d) { this->invoke(d); }
  void visit(Table_decl* d) { this->invoke(d); }
  void visit(Key_decl* d) { this->invoke(d); }
  void visit(Flow_decl* d) { this->invoke(d); }
  void visit(Port_decl* d) { this->invoke(d); }
  void visit(Extracts_decl* d) { this->invoke(d); }
  void visit(Rebind_decl* d) { this->invoke(d); }
};


// Apply fn to the propositoin p.
template<typename F, typename T = typename std::result_of<F(Variable_decl*)>::type>
inline T
apply(Decl* d, F fn)
{
  Generic_decl_mutator<F, T> v = fn;
  return accept(d, v);
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
has_member(Record_decl const* r, Field_decl const* m)
{
  Decl_seq const& mem = r->fields();
  return std::find(mem.begin(), mem.end(), m) != mem.end();
}


// Returns the member decl with a specific name within a Record_decl
// or nullptr if no member declaration with the given name can
// be found.
inline Field_decl const*
find_member(Record_decl const* r, Symbol const* name)
{
  Decl_seq const& mems = r->fields();
  for (auto member : mems) {
    if (member->name() == name)
      return as<Field_decl>(member);
  }

  return nullptr;
}


// Returns the index of the member `m` in the record
// declaration `r`.
inline int
member_index(Record_decl const* r, Field_decl const* m)
{
  Decl_seq const& mem = r->fields();
  auto iter = std::find(mem.begin(), mem.end(), m);
  return iter - mem.begin();
}


inline bool
has_field(Layout_decl const* r, Field_decl const* m)
{
  Decl_seq const& mem = r->fields();
  return std::find(mem.begin(), mem.end(), m) != mem.end();
}


// Returns the member decl with a specific name within a Layout_decl
// or nullptr if no member declaration with the given name can
// be found.
inline Field_decl*
find_field(Layout_decl const* r, Symbol const* name)
{
  Decl_seq const& mems = r->fields();
  for (auto member : mems) {
    if (member->name() == name)
      return as<Field_decl>(member);
  }

  return nullptr;
}


// Returns the index of the member `m` in the record
// declaration `r`.
inline int
field_index(Layout_decl const* r, Field_decl const* m)
{
  Decl_seq const& mem = r->fields();
  auto iter = std::find(mem.begin(), mem.end(), m);
  return iter - mem.begin();
}


#endif

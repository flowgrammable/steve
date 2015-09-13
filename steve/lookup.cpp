// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "steve/lookup.hpp"
#include "steve/decl.hpp"
#include "steve/print.hpp"

#include "lingo/symbol.hpp"
#include "lingo/error.hpp"

#include <forward_list>
#include <unordered_map>
#include <iostream>


namespace steve
{

namespace
{


// The (name) environment provides a global mapping of 
// names to declarations.
struct Environment : std::unordered_map<String const*, Scope::Binding*>
{
  Overload* push(String const*, Scope*, Decl const*);
  void      pop(String const*);

  Scope::Binding* binding(String const*);
};


// The scope stack is a stack of scopes.
struct Stack : std::forward_list<Scope*>
{
  Scope&       top()       { return *front(); }
  Scope const& top() const { return *front(); }
};


// List of known forward declarations
// if this isn't empty by the end of the scope 
// then you have an undefined declaration
struct Forward_decls : std::unordered_map<String const*, Decl const*>
{
  void push(String const*, Decl const*);
  void pop(String const*);
  bool is_empty() { return (size() > 0) ? false : true; }
};


void
Forward_decls::push(String const* s, Decl const* d)
{
  this->insert({s, d});
}


void
Forward_decls::pop(String const* s)
{
  this->erase(s);
}


// The global binding environment and scope stack.
Environment env_;
Stack       stack_;
Forward_decls fwd_;


// Push a new name binding into the context. This creates
// a new overload set for the binding.
Overload*
Environment::push(String const* n, Scope* s, Decl const* d)
{
  auto ins = insert({n, nullptr});
  Scope::Binding*& b = ins.first->second;

  // Ensure that we haven't created a new overload set for the 
  // same scope.
  lingo_assert(!ins.second ? b->scope != s : true);

  // Chain the new binding to the previous and update.
  b = new Scope::Binding{new Overload{d}, s, b};
  return b->ovl;
}


// Pop the innermost binding for this name. If this we pop
// all bindings, then remove the entry altogether.
void
Environment::pop(String const* n)
{
  auto iter = find(n);
  Scope::Binding* e = iter->second;
  if (e->prev)
    iter->second = e->prev;
  else
    erase(iter);
  delete e;
}


// Returns the binding for the name `n`. If `n` has no current
// binding, returns nullptr.
Scope::Binding*
Environment::binding(String const* n)
{
  auto iter = find(n);
  if (iter != end())
    return iter->second;
  else
    return nullptr;
}


void
track_forward(Overload* ovl)
{
  for (Decl const* d: *ovl)
  {
    if (!d->has_impl())
      fwd_.push(d->name(), d);
  }
}


} // namespace


// Used to check if any used forward declarations
// are referenced but not defined by the end of the
// program
void
check_forward()
{
  if (!fwd_.is_empty()) {
    for (auto pair : fwd_) {
      error(pair.second->location(), "{} used but not defined.", pair.second);
    }
  }
}


// When constructing a scope, place it on the scope stack.
Scope::Scope(Scope_kind k)
  : kind_(k)
{
  stack_.push_front(this);
}


// Pop all scope bindings and leave the scope whenever
// a scope is destroyed.
Scope::~Scope()
{
  for (String const* s : *this)
    env_.pop(s);
  stack_.pop_front();
}


// Push a new, innermost binding for the given name.
Overload const*
Scope::bind(String const* n, Decl const* d)
{
  push_back(n);
  return env_.push(n, this, d);
}


// Returns the innermost declaration bound to `s` or 
// nullptr if no such declaration exists.
Overload const*
Scope::lookup(String const* s) const
{
  if (Scope::Binding* b = env_.binding(s)) {
    // everytime a lookup is done
    // we need to check if that decl has a definition
    // if its a forward decl
    // we need to keep track of all forward decls that are used (i.e. looked up)
    track_forward(b->ovl);
    return b->ovl;
  }
  else
    return nullptr;
}


// Returns the innermost declaration bound to `s` or 
// nullptr if no such declaration exists.
Scope::Binding*
Scope::binding(String const* s) const
{
  if (Scope::Binding* b = env_.binding(s))
    return b;
  else
    return nullptr;
}


// -------------------------------------------------------------------------- //
//                           Scope management

// Returns the current stack.
Scope& 
current_scope()
{
  return stack_.top();
}


// -------------------------------------------------------------------------- //
//                             Declarations


Decl const*
define(Decl const* d1, Decl const* d2)
{
  fwd_.pop(d1->name());
  if (is<Variable_decl>(d1)) return define_variable(cast<Variable_decl>(d1), cast<Variable_decl>(d2));
  if (is<Function_decl>(d1)) return define_function(cast<Function_decl>(d1), cast<Function_decl>(d2));
  if (is<Decode_decl>(d1))   return define_decode(cast<Decode_decl>(d1), cast<Decode_decl>(d2));
  if (is<Table_decl>(d1))    return define_table(cast<Table_decl>(d1), cast<Table_decl>(d2));

  return nullptr;
}


// A declaration can be defined if it has no implementation
// and has the same type as the new declaration
// note: d2 is the new decl
bool
can_define(Decl const* d1, Decl const* d2)
{
  if (d1->type() == d2->type()) {
    if (!d1->has_impl()) {
      define(d1, d2);
      return true;
    }
    else {
      error(d2->location(), "redefinition of non-forward declaration '{}'", d2->name());
      note(d1->location(), "    previous definition here");
      return false;
    }
  }

  return false;
}


// Handling for forward declarations
//
// If we already have a declaration in this scope
// and that declaration cannot be overloaded
// check whether or not that declaration is a forward declaration and then
// proceed to define it
bool
forward_decl(Overload* ovl, Decl const* decl)
{
  for (Decl const* d : *ovl) {
    if (can_define(d, decl))
      return true;
  }

  return false;
}


// Create a name binding for the declaration.
//
// If we've already found a declaration in this scope,
// then try to overload it.
//
// Note that `str` must be a unique object in the system. This
// can be guaranteed by getting the string as an identifier from
// the symbol table.
Overload const*
declare(String const* n, Decl const* d)
{
  Scope* s = &current_scope();

  // If we already have a binding in this scope, then
  // try to overload the given declaration. Note that
  // this will emit diagnostics on failure.
  Scope::Binding* b = env_.binding(n);
  if (b && b->scope == s) {
    if (overload_decl(b->ovl, d))
      return b->ovl;
    if (forward_decl(b->ovl, d))
      return b->ovl;
    else
      return nullptr;
  }
  
  // Otherwise, create a new binding.
  return s->bind(n, d);
}


// Declare the variable with the given name into
// the current scope.
Overload const*
declare(Decl const* d)
{
  return declare(d->name(), d);
}


// Register bindings for a sequence of declarations.
// Returns true if all declarations were successful.
bool
declare(Decl_seq const& ds)
{
  for (Decl const* d : ds)
    if (!declare(d))
      return false;
  return true;
}


// Finds the string, removes the declaration from the table and
// environment. Replaces it with a new declaration.
Overload const*
rewrite_declare(String const* n, Decl const* d)
{ 
  Scope* s = &current_scope();

  // if d is rewritable
  // and if d has a binding and is in the current scope
  Scope::Binding* b = env_.binding(n);
  // attempt to overwrite the binding
  if (b && b->scope == s) {
    if (is_rewriteable(b->ovl->front())) {
      b->ovl->clear();
      b->ovl->push_back(d);
    }
  }
  
  
  return nullptr;
}


// -------------------------------------------------------------------------- //
//                             Name lookup


// Returns the declaration bound `name` or nullptr if
// no such declaration exists.
Overload const*
lookup(String const* n)
{
  return current_scope().lookup(n);
}


// Returns the declaration bound to the given name, or nullptr
// if no such declaration exists.
Overload const*
lookup(char const* n)
{
  return lookup(get_string(n));
}


// Looks up the single declaration corresponding to the given
// name. If there are multiple declarations associated with
// the name, emit a diagnostic and return nullptr.
Decl const*
lookup_decl(String const* n)
{
  if (Overload const* ovl = lookup(n)) {
    if (ovl->is_singleton())
      return ovl->front();

    // FIXME: Write out declarations.
    error("resolution of '{}' is ambiguous", n);
  }
  return nullptr;
}


// -------------------------------------------------------------------------- //
//                             Defining

// the 2nd param is always the defining declaration
Decl const*
define_variable(Variable_decl const* v1, Variable_decl const* v2)
{
  // strip the const
  // this should be safe since the initial declaration was non-const
  Variable_decl* var = const_cast<Variable_decl*>(v1);
  var->set_init(v2->init());

  return var;
}


Decl const*
define_function(Function_decl const* f1, Function_decl const* f2)
{
  // strip the const
  // this should be safe since the initial declaration was non-const
  Function_decl* fn = const_cast<Function_decl*>(f1);
  fn->set_body(f2->body());

  return fn;
}


Decl const*
define_decode(Decode_decl const* d1, Decode_decl const* d2)
{
  // strip the const
  // this should be safe since the initial declaration was non-const
  Decode_decl* dec = const_cast<Decode_decl*>(d1);
  dec->set_body(d2->body());

  return dec;
}


Decl const*
define_table(Table_decl const* t1, Table_decl const* t2)
{
  // strip the const
  // this should be safe since the initial declaration was non-const
  Table_decl* t = const_cast<Table_decl*>(t1);
  t->set_body(t2->body());

  return t;
}


// -------------------------------------------------------------------------- //
//                       Printing and debugging


// Print all of the declarations whose visibility does not
// exceed `s`.
void
print(Printer& p, Scope const* s)
{
  for (String const* n : *s) {
    Scope::Binding const* b = env_.binding(n);
    print(p, b->ovl);
  }
}


void
print_name_bindings()
{
  Printer p(default_print_stream());
  print_name_bindings(p);
}


// Print all of the declarations visible from `s`.
void
print_name_bindings(Printer& p)
{
  for (auto const& x : env_) {
    Scope::Binding const* b = x.second;
    print(p, b->ovl);
  }
}


} // namespace steve

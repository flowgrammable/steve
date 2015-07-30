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
  void push(String const*, Scope*, Decl const*);
  void pop(String const*);

  Scope::Binding* entry(String const*);
};


// The scope stack is a stack of scopes.
struct Stack : std::forward_list<Scope*>
{
  Scope&       top()       { return *front(); }
  Scope const& top() const { return *front(); }
};


// The global binding environment and scope stack.
Environment env_;
Stack       stack_;


// Returns the entry for the name `n`. If `n` has no current
// entry, returns nullptr.
Scope::Binding*
Environment::entry(String const* n)
{
  auto iter = find(n);
  if (iter != end())
    return iter->second;
  else
    return nullptr;
}


// Returns true if a new entry for `n` would hide a binding
// in the current scope. This is the case when the the
// scope of the current entry for `n` is the same as `s`.
inline bool
is_name_in_scope(String const* n, Scope* s)
{
  if (Scope::Binding* e = env_.entry(n))
    return e->scope == s;
  else
    return true;
}


// Push a new name binding into the context. The new declaration
// `d` shall not replace a previous declaration in the same scope.
// This requirement must be ensured by the caller.
//
// TODO: Relaxing this requirement allows for overloading. 
// Specifically, multiple declarations in the same scope could
// be added to an overload set (requiring a change to the
// binding class).
void
Environment::push(String const* n, Scope* s, Decl const* d)
{
  lingo_alert(is_name_in_scope(n, s), "'{}' already declared", d->name());
  auto ins = insert({n, nullptr});
  ins.first->second = new Scope::Binding{d, s, ins.first->second};
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


} // namespace


// When constucting a scope, place it on the scope stack.
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
void
Scope::bind(String const* n, Decl const* d)
{
  env_.push(n, this, d);
  push_back(n);
}


// Returns the innermost declaration bound to `s` or 
// nullptr if no such declaration exists.
Scope::Binding*
Scope::entry(String const* s) const
{
  if (Scope::Binding* b = env_.entry(s))
    return b;
  else
    return nullptr;
}


// Returns the innermost declaration bound to `s` or 
// nullptr if no such declaration exists.
Decl const*
Scope::lookup(String const* s) const
{
  if (Scope::Binding* b = env_.entry(s))
    return b->decl;
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

namespace
{

// Returns true if `n` does not hide an existing declaration
// in the same scope. Otherwise, emits a diagnostic and returns
// false.
bool
check_redeclaration(String const* n, Decl const* decl)
{
  Scope* s = &current_scope();
  Scope::Binding* e = env_.entry(n);

  if (e && e->scope == s) {
    Decl const* prev = e->decl;
    error(decl->location(), "'{}' is already declared", n);
    note(prev->location(), "previous declaration is '{}'", prev);
    return false;
  }
  return true;
}

} // namespace


// Create a name binding for the declaration.
//
// Note that `str` must be a unique object in the system. This
// can be guaranteed by getting the string as an identifier from
// the symbol table.
bool
declare(String const* s, Decl const* d)
{
  if (check_redeclaration(s, d)) {
    current_scope().bind(s, d);
    return true;
  }
  return false;
}


// Declare the variable with the given name into
// the current scope.
bool 
declare(Decl const* d)
{
  return declare(d->name(), d);
}


// -------------------------------------------------------------------------- //
//                             Name lookup


// Returns the declaration bound `name` or nullptr if
// no such declaration exists.
Decl const*
lookup(String const* name)
{
  return current_scope().lookup(name);
}


// Returns the declaration bound to the given name, or nullptr
// if no such declaration exists.
Decl const*
lookup(char const* name)
{
  return lookup(get_string(name));
}


} // namespace steve

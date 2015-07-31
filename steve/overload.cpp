// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "steve/overload.hpp"
#include "steve/type.hpp"
#include "steve/decl.hpp"

namespace steve
{

String const*
Overload::name() const
{
  return front()->name();
}


namespace
{

// Emit a diagnostic explaining why d1 cannot be 
// overloaded with d2. This always returns false.
bool
diagnose_error(Decl const* d1, Decl const* d2, std::string const& reason)
{
  error(d1->location(), "cannot overload '{}'", d1->name());
  note(d2->location(), "    with previous declaration");
  // FIXME: Show tjhe previous declaration
  note(d1->location(), ("    " + reason).c_str()); // FIXME: Add overloads
  return false;
}


// Returns true if `t1` and `t2` vary only in their return type.
//
// TODO: Don't use == and !=? All types are unique values, so this
// may be okay.
bool
vary_only_in_return_type(Function_type const* t1, Function_type const* t2)
{
  return t1->parm_types() == t2->parm_types() 
      && t1->ret_type() != t2->ret_type();
}


// Determine if functions f1 and f2 can be overloaded.
//
//    - Two functions f1 and f2 whose types vary only the in
//      return type cannot be overloaded.
//
// TODO: Extend to include constraints.
bool
can_overload_functions(Function_decl const* f1, Function_decl const* f2)
{
  Function_type const* t1 = f1->type();
  Function_type const* t2 = f2->type();

  if (vary_only_in_return_type(t1, t2))
    return diagnose_error(f1, f2, "functions vary only in their return types");

  return true;
}



// Attempt to insert d into the overload set ovl. Returns
// ovl if successful and nullptr otherwise. Emits an error
// on failure.
//
// The following rules apply to overloaded declarations.
//
//    - Only functions can be overloaded.
//
// Note that d2 is the previous declaration.
bool
can_overload(Decl const* d1, Decl const* d2)
{
  // If the types are the same, these declare the same function.
  //
  // TOOD: Allow forward declarations. This is only a redefinition
  // if there is no previous definition.
  if (d1->type() == d2->type()) {
    error(d1->location(), "redefinition of '{}'", d1->name());
    note(d2->location(), "    previous definition here");
    // FIXME: Show the previous definition.
    return false;
  }

  if (!is<Function_decl>(d1))
    return diagnose_error(d1, d2, "declaration of a different kind");
  if (!is<Function_decl>(d2))
    return diagnose_error(d1, d2, "declaration of a different kind");

  Function_decl const* f1 = cast<Function_decl>(d1);
  Function_decl const* f2 = cast<Function_decl>(d2);
  return can_overload_functions(f1, f2);
}

} // namespace


// Attempt to overload the given declaration with each of
// the declarations in the overload set. Returns true
// if `decl` can be overloaded and false otherwise, When
// `decl` can be overloaded the declaration is added to `ovl`,
// otherwise no action is takne.
bool
overload_decl(Overload* ovl, Decl const* decl)
{
  // Check that ovl will be a distinct overload.
  for (Decl const* d : *ovl) {
    if (!can_overload(d, decl))
      return false;
  }
  ovl->push_back(decl);
  return true;
}


// -------------------------------------------------------------------------- //
//                               Printing

void 
print(Printer& p, Overload const* ovl)
{
  print("=== overload set for {} ===", ovl->name());
  for (Decl const* d : *ovl) {
    print(p, d);
    print(p, '\n');
  }
}


// FIXME: Make this an sexpr.
void 
debug(Printer& p, Overload const* ovl)
{
  for (Decl const* d : *ovl) {
    debug(p, d);
    debug(p, '\n');
  }
}


} // namespace steve
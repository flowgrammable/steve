// Copyright (c) 2015 Andrew Sutton
// All rights reserved

#ifndef BEAKER_SPECIFIER_HPP
#define BEAKER_SPECIFIER_HPP


// Declaration specifiers. These determine the
// semantics of declarations.
//
// TODO: Other specifiers? Virtual?
enum Specifier
{
  // No specifiers present.
  no_spec      = 0,

  // The declaration has foreign language linkage.
  // This affects  how the symbol is generated during
  // translation. By default, a declaration with the
  // foreign specifier has C language linkage.
  // The virtual specifier indicates an overridable method,
  // that a record is polymorphic, or a dispatched parameter
  // of a multimethod.
  //
  // Note that a record cannot (currently) be declared
  // virtual, only its members. A class with at least one
  // virtual method is polymorphic.
  virtual_spec  = 1 << 5,

  // The abstract specifier indicates an abstract method
  // or base class.
  abstract_spec = 1 << 6,

  // The declaration has foreign language linkage.
  // This affects  how the symbol is generated during
  // translation. By default, a declaration with the
  // foreign specifier has C language linkage.
  // Otherwise, it has Beaker language linkage.
  //
  // Only functions and variables can have foreign
  // language linkage.
  //
  // TODO: Support foreign language linkage for other
  // other languages?
  foreign_spec = 1 << 10,
  meta_spec = 1 << 11,
};


inline Specifier&
operator|=(Specifier& a, Specifier b)
{
  unsigned x = a | b;
  a = Specifier(x);
  return a;
}


#endif

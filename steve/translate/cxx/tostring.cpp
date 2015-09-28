#include "string.hpp"
#include "tostring.hpp"
#include "name.hpp"

#include <iostream>
#include <cassert>

namespace cxx
{


// -------------------------------------------------- //
//            Utilities

std::string const
tostring(Basic_id const* n)
{
  return n->name().str();
}


std::string const
tostring(Name const* n)
{
  switch (n->kind) {
    case basic_id: return tostring(as<Basic_id>(n));
    default:
      return "<error>";
  }
}


template<typename T>
std::string const
tostring_paren_seq(T seq)
{
  std::string str = "(";
  // all but last element
  for (auto mem = seq.begin(); mem < seq.end() - 1; ++mem) {
    str += tostring(*mem) + ", ";
  }
  //last element
  str += tostring(*(seq.end() - 1)) + ')'; 
  return str;
}


namespace
{

const std::string indent = "  ";

// unsigned integers
const std::string uint8 = "uint8_t";
const std::string uint16 = "uint16_t";
const std::string uint32 = "uint32_t";
const std::string uint64 = "uint64_t";
const std::string uint128 = "uint128_t";
const std::string uint24 = "uint24_t";
const std::string uint48 = "uint48_t";

// Fundamental types
const std::string int_ = "int";
const std::string void_ = "void";
const std::string bool_ = "bool";
const std::string char_ = "char";

}

// -------------------------------------------------- //
//            Declarations

// Type declarations
std::string const
tostring(Type_decl const* d)
{
  return tostring(d->type());
}


// Variable declarations
std::string const
tostring(Variable_decl const* d)
{
  std::string var_ = tostring(d->type()) + ' ' + tostring(d->name());
  if (d->init()) {
    var_ += " = " + tostring(d->init()); 
  }

  var_ += ";\n";
  return var_;
}


// Function declarations
std::string const
tostring(Function_decl const* d)
{
  std::string fn = tostring(d->ret_type()) + ' ' + tostring(d->name());
  fn += tostring_paren_seq(d->parms());

  if (d->body()) {
    fn += tostring(d->body());
  }
  else
    fn += ";\n";

  return fn;
}


// Parameter declrations
std::string const
tostring(Parameter_decl const* d)
{
  return tostring(d->type()) + ' ' + tostring(d->name());
}


std::string const
tostring(Decl const* d)
{
  switch (d->kind) {
    case type_decl:     return tostring(as<Type_decl>(d));
    case variable_decl: return tostring(as<Variable_decl>(d));
    case function_decl: return tostring(as<Function_decl>(d));
    case parameter_decl: return tostring(as<Parameter_decl>(d));
    default:
      return "<error>";
  }

  return "<error>";
}

// -------------------------------------------------- //
//            Types

std::string const
tostring(Class_type const* t)
{
  // class type
  std::string struct_ = "struct ";

  assert(is<cxx::Basic_id>(t->name()));
  cxx::Basic_id* id = as<cxx::Basic_id>(t->name());

  // class name
  struct_ += tostring(id); 

  // braces
  struct_ += "\n{\n";

  // members all public
  for (auto mem : t->members())
  {
    assert(is<Variable_decl>(mem));
    struct_ += indent + tostring(mem);
  }

  // close brace
  struct_ += "};\n";
  return struct_;
}


inline std::string const
tostring(Uint8_t const* t)
{
  return uint8;
}

inline std::string const
tostring(Uint16_t const* t)
{
  return uint16;
}

inline std::string const
tostring(Uint32_t const* t)
{
  return uint32;
}

inline std::string const
tostring(Uint64_t const* t)
{
  return uint64;
}

inline std::string const
tostring(Uint128_t const* t)
{
  return uint128;
}

// special non standard ints that will be needed for packets
inline std::string const
tostring(Uint24_t const* t)
{
  return uint24;
}

inline std::string const
tostring(Uint48_t const* t)
{
  return uint48;
}


// Fundamental types
inline std::string const
tostring(Int_type const* t)
{
  return int_;
}


inline std::string const
tostring(Void_type const* t)
{
  return void_;
}


inline std::string const
tostring(Bool_type const* t)
{
  return bool_;
}


std::string const
tostring(Type const* t)
{
  switch (t->kind) {
    case class_type: return tostring(as<Class_type>(t));
    case uint8_type: return tostring(as<Uint8_t>(t));            
    case uint16_type: return tostring(as<Uint16_t>(t));           
    case uint32_type: return tostring(as<Uint32_t>(t));           
    case uint64_type: return tostring(as<Uint64_t>(t));           
    case uint128_type: return tostring(as<Uint128_t>(t));          
    // special non standard ints that will be needed for packets
    case uint24_type: return tostring(as<Uint24_t>(t));           
    case uint48_type: return tostring(as<Uint48_t>(t));
    case void_type: return tostring(as<Void_type>(t));
    case int_type: return tostring(as<Int_type>(t));
    case bool_type: return tostring(as<Bool_type>(t));
    default:
      return "<error type>";
  }
}


// -------------------------------------------------- //
//              Stmts


std::string const
tostring(Block_stmt const* s)
{
  std::string block;
  // opening brace
  block += "\n{\n";

  // body
  for (auto stmt : s->stmts())
  {
    assert(stmt);
    block += tostring(stmt);
  }

  // closing brace
  block += "\n}\n";
  return block;
}


std::string const
tostring(Stmt const* s)
{
  switch (s->kind) {
    case block_stmt: return tostring(as<Block_stmt>(s));
    default:
      return "<error stmt>";
  }
  return "<error stmt>";
}


// -------------------------------------------------- //
//        Expressions


std::string const
tostring(Int_expr const* e)
{
  return std::to_string(e->value().gets());
}


std::string const
tostring(Bool_expr const* e)
{
  if (e->value())
    return "true";

  return "false";
}


std::string const
tostring(Id_expr const* e)
{
  return tostring(e->name());
}


std::string const
tostring(Call_expr const* e)
{
  std::string call = tostring(e->fn_name());
  call += tostring_paren_seq(e->args());
  return call;
}


std::string const
tostring(Expr const* e)
{
  assert(e);

  if (is_type_node(e->kind))
    return tostring(as<Type>(e));
  if (is_decl_node(e->kind))
    return tostring(as<Decl>(e));
  if (is_stmt_node(e->kind))
    return tostring(as<Stmt>(e));

  switch (e->kind) {
    case call_expr: return tostring(as<Call_expr>(e));
    case int_expr: return tostring(as<Int_expr>(e));
    case bool_expr: return tostring(as<Bool_expr>(e));
    case id_expr: return tostring(as<Id_expr>(e));
    default:
      return "<error expr>";
  }

  return "<error expr>";
}

} // namespace cxx

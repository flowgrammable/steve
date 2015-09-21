#include "tostring.hpp"

namespace cxx
{

// -------------------------------------------------- //
//            Declarations

std::string 
tostring(Type_decl const* d)
{
  return "type_decl";
}

std::string
tostring(Decl const* d)
{
  switch (d->kind) {
    case type_decl: return tostring(as<Type_decl>(d));
    default:
      return "";
  }
}

// -------------------------------------------------- //
//            Types

std::string 
tostring(Class_type const* t)
{
  return "class_type";
}


std::string
tostring(Type const* t)
{
  switch (t->kind) {
    case class_type: return tostring(as<Class_type>(t));
    default:
      return "";
  }
}


// -------------------------------------------------- //
//              Stmts


std::string 
tostring(Stmt const* s)
{
  return "stmt";
}


// -------------------------------------------------- //
//        Expressions

std::string 
tostring(Expr const* e)
{
  if (is_type_node(e->kind))
    return tostring(as<Type>(e));
  if (is_decl_node(e->kind))
    return tostring(as<Decl>(e));

  return "<error>";
}

} // namespace cxx

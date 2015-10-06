#include "string.hpp"
#include "tostring.hpp"
#include "name.hpp"

#include <iostream>
#include <cassert>
#include <string>

namespace cxx
{

// -------------------------------------------------- //
//            Utilities


std::string const
tostring(Binary_kind op)
{
  switch(op) {
    // Object operators
    case arrow_op: return "->";         // e1->e2
    case arrow_star_op: return "->*";   // e1->*e2
    // FIXME: subscript not right
    case subscript_op: return "[]";    // e1[e2]
    // Arithmetic operators
    case mul_op: return "*";          // e1 * e2
    case div_op: return "/";          // e1 / e2
    case mod_op: return "*";          // e1 % e2
    case add_op: return "+";          // e1 + e2
    case sub_op: return "-";          // e1 - e2
    // Bitwise expressions
    case lsh_op: return "<<";          // e1 << e2
    case rsh_op: return ">>";          // e1 >> e2
    case band_op: return "&";         // e1 & e2
    case bxor_op: return "^";         // e1 ^ e2
    case bor_op: return "|";          // e1 | e2
    // Relational expressions
    case lt_op: return "<";           // e1 < e2
    case gt_op: return ">";           // e1 > e2
    case le_op: return "<=";           // e1 <= e2
    case ge_op: return ">=";           // e1 >= e2
    case eq_op: return "==";           // e1 == e2
    case ne_op: return "!=";           // e1 != e2
    // Locigal operators
    case and_op: return "&&";          // e1 && e2
    case or_op: return "||";           // e1 || e2
    // Assignment operators
    case assign_op: return "=";       // e1 = e2
    case mul_assign_op: return "*=";   // e1 *= e2
    case div_assign_op: return "/=";   // e1 /= e2
    case mod_assign_op: return "%=";   // e1 %= e2
    case add_assign_op: return "+=";   // e1 += e2
    case sub_assign_op: return "-=";   // e1 -= e2
    case lsh_assign_op: return "<<=";   // e1 <<= e2
    case rsh_assign_op: return ">>=";   // e1 >>= e2
    case band_assign_op: return "&=";  // e1 &= e2
    case bxor_assign_op: return "^=";  // e1 ^= e2
    case bor_assign_op: return "|=";   // e1 |= e2
    // Comma operators
    case comma_op: return ",";      // e1, ..., en
  }

  return "<bad operator>";
}


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
  if (seq.size() == 0)
    return "()";

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

struct Indentor 
{
  Indentor()
    : indent_lvl(0), base_indent(2)
  { }

  void indent_level() {
    indent_lvl++;
  } 

  void undent_level() {
    assert(indent_lvl > 0);
    indent_lvl--;
  }

  std::string const indent()
  {
    return std::string(indent_lvl * base_indent, ' ');
  }

  int indent_lvl;
  int base_indent;
};

Indentor indentor;

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

} // namespace

// -------------------------------------------------- //
//            Declarations

// Class type declaration
std::string const
tostring_typedecl(Class_type const* t)
{
  // class type
  std::string struct_ = "struct ";

  assert(is<cxx::Basic_id>(t->name()));
  cxx::Basic_id* id = as<cxx::Basic_id>(t->name());

  // class name
  struct_ += tostring(id); 

  // braces
  struct_ += "\n{\n";

  indentor.indent_level();

  // members all public
  for (auto mem : t->members())
  {
    assert(is<Variable_decl>(mem));
    struct_ += indentor.indent() + tostring(mem);
  }

  indentor.undent_level();

  // close brace
  struct_ += "};\n";
  return struct_;
}


// Type declarations
// Supported type declarations are
// class | struct | union | enum
std::string const
tostring(Type_decl const* d)
{

  switch (d->type()->kind) {
    case class_type: return tostring_typedecl(as<Class_type>(d->type()));
    case union_type:
    case enum_type:
    default:
      return "<error typedecl>";
  }
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


// Class type
// 
// T n
std::string const
tostring(Class_type const* t)
{
  return tostring(t->name());
}


// Lvalue Reference type
// 
// T& n
std::string const
tostring(Lvalue_reference_type const* t)
{
  return tostring(t->referent()) + "&";
}


std::string const
tostring(Type const* t)
{
  switch (t->kind) {
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
    case class_type: return tostring(as<Class_type>(t));
    case lvalue_reference_type: return tostring(as<Lvalue_reference_type>(t));
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
  block += '\n' + indentor.indent() + "{\n";

  indentor.indent_level();

  // body
  for (auto stmt : s->stmts())
  {
    assert(stmt);
    block += indentor.indent() + tostring(stmt) + '\n';
  }

  indentor.undent_level();

  // closing brace
  block += indentor.indent() + "}\n";
  return block;
}


std::string const
tostring(Switch_stmt const* s)
{
  std::string sw = "switch (";
  sw += tostring(s->arg()) + ")";
  sw += tostring(s->body());

  return sw;
}


std::string const
tostring(Case_stmt const* s)
{
  return "case " + tostring(s->label()) + ": " + tostring(s->stmt());
}


std::string const
tostring(Expr_stmt const* s)
{
  return tostring(s->expr()) + ";";
}


std::string const
tostring(Stmt const* s)
{
  switch (s->kind) {
    case block_stmt: return tostring(as<Block_stmt>(s));
    case switch_stmt: return tostring(as<Switch_stmt>(s));
    case case_stmt: return tostring(as<Case_stmt>(s));
    case expr_stmt: return tostring(as<Expr_stmt>(s));

    // keyword stmts
    case break_stmt: return "break;";
    case empty_stmt: return ";";
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
  return (e->value()) ? "true" : "false"; 
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


// e1 (+ | - | * | ...etc) e2
std::string const
tostring(Binary_expr const* e)
{
  return tostring(e->left()) + tostring(e->op()) + tostring(e->right());
}


// obj.mem
std::string const
tostring(Dot_expr const* e)
{
  return tostring(e->object()) + "." + tostring(e->member());
}


// { e1, ..., en }
std::string const
tostring(Init_expr const* e)
{
  std::string init = "{";

  Expr_seq elems = e->elems();

  for (auto it = elems.begin(); it < elems.end() - 1; ++it) {
    init += tostring(*it) + ", ";
  }

  init += tostring(*(elems.end() - 1));

  init += "}";

  return init;
}


// T(e1, ..., en)
std::string const
tostring(Construct_expr const* e)
{
  return tostring(e->result()) + tostring_paren_seq(e->args());
}


std::string const
tostring(Expr const* e)
{
  if (!e)
    return "<null error>";

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
    case binary_expr: return tostring(as<Binary_expr>(e));
    case dot_expr: return tostring(as<Dot_expr>(e));
    case init_expr: return tostring(as<Init_expr>(e));
    case construct_expr: return tostring(as<Construct_expr>(e));
    default:
      return "<error expr>";
  }

  return "<error expr>";
}

} // namespace cxx

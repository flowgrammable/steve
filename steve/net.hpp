
#ifndef STEVE_NET_HPP
#define STEVE_NET_HPP

#include "steve/type.hpp"
#include "steve/decl.hpp"
#include "steve/expr.hpp"
#include "steve/stmt.hpp"
#include "steve/relation.hpp"

#include "lingo/symbol.hpp"

// This module is used to connect the decode decls
// togethers. This allows us to formt he graph to
// type check the flow tables
namespace steve 
{

using Decl_set = std::set<Decl const*>;


struct Extracted : std::vector<Decl const*> 
{
  Extracted(int c, Decl const* d)
    : std::vector<Decl const*>::vector { d }, count(c)
  { }

  bool is_singleton() const { return size() == 1; }
  String const* name() const { return front()->name(); }
  Decl const* latest() const { return back(); }

  void pop() { pop_back(); }
  void push(Decl const* d) { push_back(d); }

  int count;
};


// Field environment
struct Pipeline_environment : std::unordered_map<String const*, Extracted*>
{
  void       push(String const*, Decl const*);
  Extracted* pop(String const*);

  Extracted* lookup(String const*);
};


} // namespace steve



namespace steve
{

// Used to keep track of valid field/header identifiers
// which are used in the program
struct Context_scope
{
  Pipeline_environment& headers() { return first; }
  Pipeline_environment& fields() { return second; }

  // header environment
  Pipeline_environment first;
  Pipeline_environment second;
};


// Keeps track of all fields extracted
// and all headers extracted in the program
// FIXME: this probably shouldn't be here
struct Context_environment
{
  Pipeline_environment& headers() { return first; }
  Pipeline_environment& fields() { return second; }

  // header environment
  Pipeline_environment first;
  Pipeline_environment second;
};


struct Stage
{
  Stage(Decl const*, Decl_set const&);

  Decl const* decl() const { return first; }
  Expr_seq const& requirements() const { return second; }
  Decl_set const& branches() const { return third; }

  Decl const* first;
  Expr_seq second;
  Decl_set const third;

  // for dfs
  bool visited;
};


// Only decode and table decls
// Decode decls declare which tables or decoders they go to next
// through their match stmts
//
// Table decls declare which tables or decoders they go to next
// Through their table entries
// Note that this only works with statically initialized tables
// The pipeline changes dynamically during run time as entries are
// added to the tables.
struct Pipeline : std::vector<Stage*>
{
  Pipeline(Context_scope c, Context_environment e)
    : scope_(c), env_(e)
  { }

  Context_scope& scope() { return scope_; }
  Context_environment& env() { return env_; }

  Context_scope scope_;
  Context_environment env_;

  Stage* find(Decl const*) const;
};


void register_stage(Decode_decl const*);
void register_stage(Table_decl const*);
bool check_pipeline();

Value lookup_field_binding(String const* n);
Value lookup_header_binding(String const* n);

} // namespace steve

#endif


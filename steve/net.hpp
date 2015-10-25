
#ifndef STEVE_NET_HPP
#define STEVE_NET_HPP

#include "steve/type.hpp"
#include "steve/decl.hpp"
#include "steve/expr.hpp"
#include "steve/stmt.hpp"
#include "steve/relation.hpp"

#include "lingo/symbol.hpp"

#include <unordered_set>

// This module is used to connect the decode decls
// togethers. This allows us to formt he graph to
// type check the flow tables
namespace steve 
{

using Decl_set = std::set<Decl const*>;


struct Extracted : std::vector<Decl const*> 
{
  Extracted(int c, Decl const* d, String const* n)
    : std::vector<Decl const*>::vector { d }, count(c), name_(n)
  { }

  bool is_singleton() const { return size() == 1; }
  String const* name() const { return name_; }
  Decl const* latest() const { return back(); }

  void pop() { pop_back(); }
  void push(Decl const* d) { push_back(d); }

  int count;
  String const* name_;
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
// when checking the pipeline. We don't really care about
// which declaration they refer to, only that the identifier is
// a valid name
struct Context_bindings : std::unordered_set<String const*>
{
  using std::unordered_set<String const*>::unordered_set;
};


// Keeps track of all possible fields extracted
// and all headers extracted in the program
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
  Stage(Decl const*, Decl_set const&, Expr_seq const&);

  Decl const* decl() const { return first; }
  Expr_seq const& requirements() const { return second; }
  Decl_set const& branches() const { return third; }
  Expr_seq const& productions() const { return fourth; }

  Decl const* first;
  Expr_seq second;
  Decl_set const third;
  Expr_seq fourth;

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
  Pipeline(Context_bindings& c, Context_environment& e)
    : bindings_(c), env_(e)
  { }

  Context_bindings& bindings() { return bindings_; }
  Context_environment& env() { return env_; }

  Context_bindings& bindings_;
  Context_environment& env_;

  Stage* find(Decl const*) const;
};


void register_stage(Decode_decl const*);
void register_stage(Table_decl const*);
bool check_pipeline();

Value lookup_field_binding(String const*);
Value lookup_header_binding(String const*);

Pipeline const& get_pipeline();

int get_num_headers();
int get_num_fields();

// get the integer representation for a field
Value_expr* get_header_binding(String const*);
Value_expr* get_field_binding(String const*);

Decl const* pipeline_get_start();

} // namespace steve

#endif


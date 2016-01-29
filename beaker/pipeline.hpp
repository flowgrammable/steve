
#ifndef PIPELINE_HPP
#define PIPELINE_HPP

#include "beaker/prelude.hpp"
#include "beaker/elaborator.hpp"

#include <unordered_set>
#include <unordered_map>
#include <set>

// This module is used to connect the decode decls
// togethers. This allows us to formt he graph to
// type check the flow tables

struct Elaborator;
struct Stage;

using Sym_set = std::unordered_set<Symbol const*>;
using Stage_set = std::unordered_set<Stage const*>;

struct Field_env : Environment<Symbol const*, Extracts_decl const*>
{
  Field_env()
    : decl_(nullptr)
  { }

  Field_env(Extracts_decl* d)
    : decl_(d)
  { }

  Extracts_decl* decl_;
};


// Map headers to integers
struct Header_map : std::unordered_map<Layout_decl const*, int>
{
  Header_map()
    : count(0)
  { }

  void insert(Layout_decl const* l);

  int count;
};


// Map fields to integers
struct Field_map : std::unordered_map<Symbol const*, int>
{
  Field_map()
    : count(0)
  { }

  void insert(Extracts_decl const* e);
  void insert(Symbol const* s);

  int count;
};


struct Stage_stack : Stack<Field_env>
{
  using Stack<Field_env>::Stack;

  void produce(Field_env const& f) { push(f); }
};


// Represents a stage in the pipeline
// This can be either a decode decl or a table decl
struct Stage
{
  Stage(Decl const*, Stage_set const&, Field_env const&, Sym_set const&);

  Decl const* decl() const { return stage_; }
  Stage_set const& branches() const { return branches_; }
  Field_env const& productions() const { return products_; }
  Sym_set const& requirements() const { return reqs_; }

  Decl const* stage_;
  Stage_set branches_;
  Field_env products_;
  Sym_set reqs_;

  bool is_table()   const { return is<Table_decl>(stage_); }
  bool is_decoder() const { return is<Decode_decl>(stage_); }

  Table_decl const* table() const { return as<Table_decl>(stage_); }
  Decode_decl const* decoder() const { return as<Decode_decl>(stage_); }

  // for dfs
  bool visited;
};


struct Stage_less
{
  bool operator()(Stage const& a, Stage const& b) const
  {
    return a.decl() < b.decl();
  }
};


// A list of pipeline stages
struct Pipeline : std::vector<Stage*>
{
  Stage* find(Decl const*) const;
};



struct Pipeline_checker
{
  struct Stage_sentinel;

  Pipeline_checker(Elaborator& e)
    : elab(e), entry(nullptr), is_error_state(false)
  { }

  bool check_pipeline();
  void extract(Extracts_decl*);
  void header(Layout_decl*);

  // Uncover all branches within a stage
  // Branches can occur only within stmts.
  // Branches can not happen as a result of a function call.
  void discover_branches();
  Stage_set find_branches(Decode_decl const*);
  Stage_set find_branches(Table_decl const*);
  Stage_set find_branches(Flow_decl const*);

  // Register a decoding stage
  void register_stage(Decode_decl const*);
  void register_stage(Table_decl const*);
  void register_stage(Event_decl const*);
  void register_stage(Flow_decl const*, Table_decl const*);

  // Discover all productions
  Field_env get_productions(Decode_decl const*);
  Field_env get_productions(Table_decl const*);
  Field_env get_productions(Event_decl const*);
  Field_env get_productions(Flow_decl const*, Table_decl const*);

  // Discover all requirements
  Sym_set get_requirements(Decode_decl const*);
  Sym_set get_requirements(Table_decl const*);
  Sym_set get_requirements(Event_decl const*);
  Sym_set get_requirements(Flow_decl const*, Table_decl const*);

  void print_header_mappings();
  void print_field_mappings();
  void print_stages();
  void print_stage(Stage const*);

  int get_header_mapping(Layout_decl const*);
  int get_field_mapping(Symbol const*);

private:
  void check_stage(Decl const*, Sym_set const&);
  void check_progression(Stage_set const&);
  void dfs(Stage*);

  // Map headers to integers
  Header_map hdr_map;

  // Map fields to integers
  Field_map fld_map;

  // maintain a stack of fields
  // extracted
  Stage_stack stack;

  // Maintain a pipeline
  Pipeline pipeline;

  // maintain the original elaborator
  Elaborator& elab;

  // Maintain the starting stage
  Stage* entry;

  // Maintain if this is in error state
  bool is_error_state;

  // Maintain the current path for debugging purposes
  std::vector<Stage*> path;

  // Maintain the current state of highest table.
  int highest_table = 0;
};


struct Pipeline_checker::Stage_sentinel
{
  Stage_sentinel(Pipeline_checker& p, Extracts_decl* d = nullptr)
    : checker(p)
  {
    checker.stack.push(d);
  }

  ~Stage_sentinel()
  {
    checker.stack.pop();
  }

  Pipeline_checker& checker;
};

#endif

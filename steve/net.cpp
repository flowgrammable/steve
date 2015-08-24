#include "net.hpp"

namespace steve 
{

Extracted*
Pipeline_environment::lookup(String const* n)
{
  auto iter = find(n);
  if (iter != end())
    return iter->second;
  else
    return nullptr;
}


Stage*
Pipeline::find(Decl const* d) const
{
  for (Stage* s : *this) {
    if (s->decl() == d)
      return s;
  }
}


void
print(Stage* s)
{
  print("Stage: ");
  print(s->decl()->name());
  print("Branches: ");
  for (auto b : s->branches()) {
    print(b->name());
  }

  print("\n\n");
}

void
print(Extracted* e) {
  print("Extracted: {}. {} size: {} \n", e->count, e->name(), e->size());
}


namespace
{

Context_scope cxt_scope;
Context_environment cxt_env;
Pipeline pipeline(cxt_scope, cxt_env);

void
print_header_env()
{
  print("==========Headers=========");
  for (auto s : pipeline.env().headers()) {
    print(s.second);
  }
}


void
print_field_env()
{
  print("==========Fields=========");
  for (auto s : pipeline.env().fields()) {
    print(s.second);
  }
}


struct Stage_less
{
  bool operator()(Stage const& a, Stage const& b) const
  {
    return less(a.decl(), b.decl());
  }
};


struct Extracted_less
{
  bool operator()(Extracted const& a, Extracted const& b) const
  {
    return a.name() < b.name();
  }
};


Unique_factory<Stage, Stage_less> stages_;
Unique_factory<Extracted, Extracted_less> extracted_;


} // namespace

//---------------------------------------------------------------//
//                 Scoping functions


void
Pipeline_environment::push(String const* n, Decl const* d)
{
  auto search = this->find(n);

  if (search != this->end()) {
    (*search).second->push(d);
  }
  else {
    Extracted* e = extracted_.make(this->size(), d);
    this->insert(std::make_pair(n, e));
  }
}


Extracted*
Pipeline_environment::pop(String const* n)
{
  auto search = this->find(n);

  if (search != this->end()) {
    auto ret = (*search).second;
    this->erase(search);
    return ret;
  }

  return nullptr;
}


namespace
{


// Table requirements are determined by the match fields
// which they require to be decoded
void 
table_requirements(Table_decl const* d, Expr_seq& req)
{
  for (auto r : d->conditions()) {
    if(!is<Field_expr>(r))
      error(r->location(), "Invalid field requirement '{}'.", r);

    req.push_back(r);
  }
}


// TODO: Determine if decoders even have explicit requirements
void 
decode_requirements(Decode_decl const* d, Expr_seq& req)
{

}


// handle extract decls
void 
register_extract(Extracts_decl const* d)
{
  pipeline.env().fields().push(as<Field_expr>(d->field())->name(), d);
}


// A rebind declaration registers the extracted field 
// into the header environment using the aliased name
// i.e. extract vlan.type as eth.type
// creates an entry with the name eth.type
void
register_rebind(Rebind_decl const* d)
{
  pipeline.env().fields().push(as<Field_expr>(d->field1())->name(), d);
  pipeline.env().fields().push(as<Field_expr>(d->field2())->name(), d);
}


// handle decls made inside decode decl
void
process_decl_stmt(Decl_stmt const* s)
{
  switch (s->decl()->kind()) {
    case extracts_decl: 
      register_extract(as<Extracts_decl>(s->decl()));
      break;
    case rebind_decl:
      register_rebind(as<Rebind_decl>(s->decl()));
      break;
    default:
      break;
  }
}


// expr stmts
void
process_expr_stmt(Expr_stmt const* s, Expr_seq& branches)
{

}



// ------------------------------------------------------------- //
//          Check branches within a decoder

void find_branch(Block_stmt const*, Decl_set&);
void find_branch(Expr_stmt const*, Decl_set&);
void find_branch(Match_stmt const*, Decl_set&);
void find_branch(Case_stmt const*, Decl_set&);
void find_branch(Stmt const*, Decl_set&);

void find_branch(Flow_decl const*, Decl_set&);


void
find_branch(Block_stmt const* s, Decl_set& branches)
{
  for (auto stmt : *s) {
    find_branch(stmt, branches);
  }
}


// This is the only real time that branches happen
// the only things that cause branches are
// 1. do expr
// 2. flows goto
void
find_branch(Expr_stmt const* s, Decl_set& branches)
{
  if (is<Do_expr>(s->expr())) {
    // look at the expression and extract the appropriate stage
    Do_expr const* do_expr = cast<Do_expr>(s->expr());
    // sanity check
    lingo_assert(is<Id_expr>(do_expr->target()));
    Decl const* target = as<Id_expr>(do_expr->target())->decl();
    
    branches.insert(target);
  }
}


void 
find_branch(Match_stmt const* s, Decl_set& branches)
{
  for (Stmt const* c : s->cases()) {
    find_branch(as<Case_stmt>(c), branches);
  }
}


void
find_branch(Case_stmt const* s, Decl_set& branches)
{
  find_branch(s->stmt(), branches);
}


void
find_branch(Flow_decl const* d, Decl_set& branches)
{
  find_branch(d->instructions(), branches);
}


void
find_branch(Decl_stmt const* s, Decl_set& branches)
{
  // for now we will only handle flow declarations
  // used in constant initialization of flow tables
  // as being possible branches
  switch (s->decl()->kind()) {
    case flow_decl: 
      find_branch(cast<Flow_decl>(s->decl()), branches);
      break;
    default:
      break;
  }
}


// This currently only works with decoders
// Support for tables to come
// Finding branches in tables is iffy
void
find_branch(Stmt const* s, Decl_set& branches)
{
  switch (s->kind()) {
    case block_stmt: 
      find_branch(cast<Block_stmt>(s), branches);
      break;
    case expr_stmt:  
      find_branch(cast<Expr_stmt>(s), branches);
      break;
    case match_stmt: 
      find_branch(cast<Match_stmt>(s), branches);
      break;
    case case_stmt:  
      find_branch(cast<Case_stmt>(s), branches);
      break;
    case decl_stmt:  
      find_branch(cast<Decl_stmt>(s), branches);
      break;

    // the rest cannot possibly have branches otherwise we're in trouble
    default: break;
  }
}


void
check_stage(Decode_decl const* d)
{

}


void
check_stage(Table_decl const* d)
{

}


// depth first search
void
dfs(Stage* s)
{
  s->visited = true;

  // check this stage
  switch(s->decl()->kind()) {
    case table_decl: 
      check_stage(cast<Table_decl>(s->decl()));
      break;
    case decode_decl: 
      check_stage(cast<Decode_decl>(s->decl()));
      break;
    default:
      lingo_unreachable("Unsupported decl kind {}", s->decl());
  }

  for (auto decl : s->branches()) {
    Stage* stage = pipeline.find(decl);
    if(stage)
      if(stage->visited == false)
        dfs(stage);
  }
}

} // namespace


// When registering a stage
// We construct the stage by determining all
// requirements needed before moving into that stage
Stage::Stage(Decl const* d, Decl_set const& b)
  : first(d), third(b), visited(false)
{
  this->second = Expr_seq();

  switch(d->kind()) {
  case table_decl: 
    table_requirements(cast<Table_decl>(d), second); 
    break;
  case decode_decl: 
    decode_requirements(cast<Decode_decl>(d), second);
    break;
  default:
    lingo_unreachable("unhandled node kind ({})", d->kind());
  }
}


void 
register_stage(Decode_decl const* d)
{
  lingo_assert(is<Block_stmt>(d->body()));

  // Keep track of the possible branches in a decoder
  // A branch happens anytime we encounter a do expression
  Decl_set branches;

  // bind the header type into header environment
  lingo_assert(is<Record_type>(d->header()));
  Record_type const* htype = cast<Record_type>(d->header()); 
  pipeline.env().headers().push(htype->decl()->name(), htype->decl());

  // scan through the decode decl body
  //    extract decls will add fields to the context
  //    header type will be added to the context and recorded
  for (auto stmt : *as<Block_stmt>(d->body())) {
    switch (stmt->kind()) {
      case decl_stmt:
        process_decl_stmt(as<Decl_stmt>(stmt));
        break;
      default:
        break;
    }
    find_branch(stmt, branches);
  }

  Stage* stage = stages_.make(d, branches);
  pipeline.push_back(stage);
}


void 
register_stage(Table_decl const* d)
{
  Decl_set branches;

  // check that the table had a default initialization
  if (d->body().size() > 0) {
    for (auto f : d->body()) {
      // check for flow decl
      lingo_assert(is<Flow_decl>(f));
      Flow_decl const* flow = as<Flow_decl>(f);
      find_branch(flow->instructions(), branches);
    }
  }

  Stage* stage = stages_.make(d, branches);
  pipeline.push_back(stage);
}


// Checks the pipeline to confirm that it is well-formed
// Note that many additional checks are made during
// the lowering process. This check confirms the following:
// 1. That all paths into tables from decoders are guaranteed
//    to have extracted all fields required by the table at least once
// 2. Tables do not form loops with goto statements
// 3. Decoders never go back to a table that's been visited prior
bool 
check_pipeline()
{
  // make sure there are actually
  // components in the pipeline
  if (!pipeline.size() > 0) 
    return false;

  // we assume that the first declaration registered
  // is the start of the pipeline
  //
  // this should be a decoder, though be a table
  Stage* start = pipeline.front();

  dfs(start);

  // we're going to do a depth first traversal
  // until we hit a stage with no branches
  // then we'll unwind and repeat until all branches
  // have been visited

  return true;
}


Value
lookup_field_binding(String const* n)
{
  auto search = pipeline.env().fields().lookup(n);

  if (search) {
    return Value(search->count);
  }
  else
    return Value(-1);
}


Value
lookup_header_binding(String const* n)
{
  auto search = pipeline.env().headers().lookup(n);

  if (search) {
    return Value(search->count);
  }
  else
    return Value(-1);
}


} // namespace steve
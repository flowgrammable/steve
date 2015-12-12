#include "beaker/type.hpp"
#include "beaker/expr.hpp"
#include "beaker/decl.hpp"
#include "beaker/stmt.hpp"
#include "beaker/pipeline.hpp"
#include "beaker/error.hpp"

#include <iostream>


void
Pipeline_checker::check_stage(Decl const* d, Sym_set const& reqs)
{
  bool error = false;
  std::stringstream ss;

  for (auto field : reqs) {
    auto search = stack.lookup(field);

    if (!search) {
      error = true;
      ss << "Field " << *field
         << " required but not decoded.\n";
    }
  }

  if (error) {
    ss << "Broken path: ";
    for (auto stage : path)
      ss << *stage->decl()->name() << " | ";

    throw Lookup_error({}, ss.str());
  }
}

// Depth first search
// specialized to visit ALL PATHS within a
// graph instead of visiting all nodes within
// a graph.
void
Pipeline_checker::dfs(Stage* s)
{
  s->visited = true;

  // push all of its productions onto the bindings stack
  stack.produce(s->productions());

  // FIXME: Do we even care what headers are valid at any
  // given stage? It seems to me we only ever
  // care about the fields
  // push the header name onto the bindings stack
  // cxt_bindings.insert(s->decl()->name());

  // push stage onto path for debugging purposes
  path.push_back(s);

  // check this stage
  check_stage(s->decl(), s->requirements());

  for (auto br : s->branches()) {
    if (br->decl() != s->decl()) {
      Stage* stage = pipeline.find(br->decl());
      if (stage)
        if (!stage->visited)
          dfs(stage);
    }
  }

  // cleanup
  // pop off debugging stack
  path.pop_back();

  // pop all of the bindings off
  stack.pop();

  // pop the header name off bindings stack
  // cxt_bindings.erase(s->decl()->name());

  // unset the visited as you come back from recursion
  // so that we can explore all possible paths instead of
  // just one path
  s->visited = false;
}


// We construct the stage by determining all
// requirements needed before moving into that stage
Stage::Stage(Decl const* d, Stage_set const& b, Field_env const& p, Sym_set const& r)
  : stage_(d), branches_(b), products_(p), reqs_(r), visited(false)
{ }


void
Field_map::insert(Extracts_decl const* e)
{
  assert(e);

  auto ins = this->emplace(e->name(), count);
  // check for insert already
  if (ins.second)
    ++count;
}


void
Field_map::insert(Symbol const* s)
{
  assert(s);

  auto ins = this->emplace(s, count);
  // check for insert already
  if (ins.second)
    ++count;
}


void
Header_map::insert(Layout_decl const* l)
{
  assert(l);

  auto ins = this->emplace(l, count);
  // check for insert already
  if (ins.second)
    ++count;
}


// Returns the integer mapping of the header
// if there exists one. Otherwise returns -1.
int
Pipeline_checker::get_header_mapping(Layout_decl const* s)
{
  auto search = hdr_map.find(s);

  if (search != hdr_map.end())
    return search->second;

  return -1;
}


// Returns the integer mapping of a specific field
// name if there exists one. Otherwise returns -1.
int
Pipeline_checker::get_field_mapping(Symbol const* s)
{
  auto search = fld_map.find(s);

  if (search != fld_map.end())
    return search->second;

  return -1;
}


// FIXME: this is a linear search
// might be able to transform this into a map for fastter
// search time.
//
// returns pointer to stage if found or
// nullptr otherwise
Stage*
Pipeline::find(Decl const* d) const
{
  for (auto stage : *this) {
    if (stage->decl() == d)
      return stage;
  }
  return nullptr;
}


// Push an extracted field onto stack
void
Pipeline_checker::extract(Extracts_decl* d)
{
  // check if this has already been extracted
  // no reason to register an extraction
  // more than once
  if (!stack.top().lookup(d->name()))
    stack.top().bind(d->name(), d);

  // every time we register an extraction
  // we also map the field to an integer
  // if it has not been already
  fld_map.insert(d);
}


// Register a decode decl
void
Pipeline_checker::register_stage(Decode_decl const* d)
{
  Block_stmt const* body = as<Block_stmt>(d->body());

  if (!body) {
    throw Type_error({}, "Invalid decoder body.");
  }

  // bind the header decl into header map
  Layout_type const* layout_type = as<Layout_type>(d->header());
  hdr_map.insert(layout_type->declaration());

  // get productions
  Field_env product = get_productions(d);

  // get requirements
  // Right now, decoders do not have explicit requirements
  // as they do no care about what happened in the previous
  // decoder. Only tables have requirements.
  Sym_set requirements = get_requirements(d);

  Stage* stage = new Stage(d, Stage_set(), product, requirements);

  assert(d->name());

  if (d->is_start()) {
    if (!entry)
      entry = stage;
    else {
      std::cerr << "Multiple entry points found in pipeline.\n";
      std::cerr << "   First start: " << *entry->decl()->name() << '\n';
      std::cerr << "   Second start: " << *d->name() << '\n';
      is_error_state = true;
    }
  }

  pipeline.push_back(stage);
}


// Register a table decl
void
Pipeline_checker::register_stage(Table_decl const* d)
{
  // Keep track of what fields each stage produces
  // TODO: For now, tables do not produce,
  // but potentially pushing and popping headers
  // causes a production. Though its somewhat questionable
  // if we can guarantee this at compile time.
  Field_env product = get_productions(d);

  // Keep track of requirements
  // Requirements are specified by the declared
  // keys in the table.
  Sym_set requirements = get_requirements(d);

  // check that the table had a default initialization
  if (d->body().size() > 0) {
    // find branches inside flow decl
    for (auto f : d->body()) {
      // check for flow decl
      if (is<Flow_decl>(f))
        continue;
      // TODO: check for branches through flow instructions
      // Flow_decl const* flow = as<Flow_decl>(f);
      // find_branch(flow->instructions());
    }
  }

  Stage* stage = new Stage(d, Stage_set(), product, requirements);

  if (d->is_start()) {
    if (!entry)
      entry = stage;
    else {
      is_error_state = true;
      std::cerr << "This table is a multiple entry points found in pipeline.\n";
    }
  }

  pipeline.push_back(stage);
}


// Get productions of a decode declaration
//
// These correspond to extracted fields.
// We only record the names which get extracted
// and save the declaration elsewhere.
Field_env
Pipeline_checker::get_productions(Decode_decl const* d)
{
  Block_stmt const* body = as<Block_stmt>(d->body());

  assert(body);

  Field_env products;

  struct Find_products
  {
    Field_env& prod;
    Field_map& fld_map;

    void operator()(Empty_stmt const* s) { }
    void operator()(Block_stmt const* s) { }
    void operator()(Assign_stmt const* s) { }
    void operator()(Break_stmt const* s) { }
    void operator()(Continue_stmt const* s) { }
    void operator()(Expression_stmt const* s) { }
    void operator()(Return_stmt const* s) { throw Type_error({}, "return found in decoder body"); }
    void operator()(If_then_stmt const* s) { }
    void operator()(If_else_stmt const* s) { }
    void operator()(Match_stmt const* s) { }
    void operator()(Case_stmt const* s) { }
    void operator()(While_stmt const* s) { }
    void operator()(Decode_stmt const* s) { }
    void operator()(Goto_stmt const* s) { }
    void operator()(Action const* s) { }
    void operator()(Drop const* s) { }
    void operator()(Output const* s) { }
    void operator()(Set_field const* s) { }

    // the only productions (for now) come out of decl statements
    // and only if it is an extracts decl or rebind decl
    void operator()(Declaration_stmt const* s)
    {
      if (Extracts_decl const* ext = as<Extracts_decl>(s->declaration())) {
        prod.emplace(ext->name(), ext);
        fld_map.insert(ext);
      }
      else if (Rebind_decl const* reb = as<Rebind_decl>(s->declaration())) {
        // bind both the original name
        // and the aliased name
        prod.emplace(reb->name(), reb);
        prod.emplace(reb->original(), reb);

        fld_map.insert(reb->name());
        fld_map.insert(reb->original());
      }
    }
  };

  // scan through the decode decl body
  //    extract decls will add fields to the context
  //    header type will be added to the context
  for (auto stmt : body->statements()) {
    apply(stmt, Find_products{products, fld_map});
  }

  return products;
}


// Not sure we can discover if tables produce anything
Field_env
Pipeline_checker::get_productions(Table_decl const* d)
{
  return Field_env();
}


Sym_set
Pipeline_checker::get_requirements(Table_decl const* d)
{
  // Keep track of requirements
  // Requirements are specified by the declared
  // keys in the table.
  Sym_set requirements;
  for (auto subkey : d->keys()) {
    requirements.insert(subkey->name());
  }

  return requirements;
}


// Decoders don't explicitly require anything
Sym_set
Pipeline_checker::get_requirements(Decode_decl const* d)
{
  Sym_set requirements;

  return requirements;
}


// Branches can only occur within the context
// of flows
Stage_set
Pipeline_checker::find_branches(Table_decl const* d)
{
  Stage_set branches;

  struct Find_branches
  {
    Stage_set& br;
    Pipeline& p;

    // these cannot appear in flow bodies
    void operator()(Empty_stmt const* s) { }
    void operator()(Assign_stmt const* s) { }
    void operator()(Break_stmt const* s) { }
    void operator()(Continue_stmt const* s) { }
    void operator()(Expression_stmt const* s) { }
    void operator()(Declaration_stmt const* s) { }
    void operator()(Return_stmt const* s) { throw Type_error({}, "return found in flow body"); }
    void operator()(Block_stmt const* s) { }
    void operator()(If_then_stmt const* s) { }
    void operator()(If_else_stmt const* s) { }
    void operator()(Match_stmt const* s) { }
    void operator()(Case_stmt const* s) { }
    void operator()(While_stmt const* s) { }
    void operator()(Action const* s) { }
    void operator()(Drop const* s) { }
    void operator()(Output const* s) { }
    void operator()(Set_field const* s) { }

    // these can cause branches
    void operator()(Decode_stmt const* s)
    {
      Stage* b = p.find(s->decoder());
      assert(b);
      br.insert(b);
    }

    void operator()(Goto_stmt const* s)
    {
      Stage* b = p.find(s->table());
      assert(b);
      br.insert(b);
    }
  };

  for (auto f : d->body()) {
    // Flow_decl
    Flow_decl* flow = as<Flow_decl>(f);

    // either its a block stmt
    Block_stmt const* body = as<Block_stmt>(flow->instructions());
    if (body) {
      for (auto stmt : body->statements()) {
        apply(stmt, Find_branches{branches, pipeline});
      }
    }

    // or an identifier to a special action set
    // TODO: implement
  }

  return branches;
}


// Branches can occur within a number of places within a decoder
// decl
Stage_set
Pipeline_checker::find_branches(Decode_decl const* d)
{
  Stage_set branches;

  struct Find_branches
  {
    Stage_set& br;
    Pipeline& p;

    // these do not cause branches
    void operator()(Empty_stmt const* s) {  }
    void operator()(Assign_stmt const* s) {  }
    void operator()(Break_stmt const* s) {  }
    void operator()(Continue_stmt const* s) {  }
    void operator()(Expression_stmt const* s) {  }
    void operator()(Declaration_stmt const* s) {  }
    void operator()(Return_stmt const* s)
    {
      throw Type_error({}, "return found in decoder body");
    }

    void operator()(Action const* s) { }
    void operator()(Drop const* s) { }
    void operator()(Output const* s) { }
    void operator()(Set_field const* s) { }


    // these can cause branches
    void operator()(Block_stmt const* s)
    {
      for (auto stmt : s->statements()) {
        apply(stmt, *this);
      }
    }

    void operator()(If_then_stmt const* s)
    {
      apply(s->body(), *this);
    }

    void operator()(If_else_stmt const* s)
    {
      apply(s->true_branch(), *this);
    }

    void operator()(Match_stmt const* s)
    {
      for (auto c : s->cases()) {
        apply(c, *this);
      }
    }

    void operator()(Case_stmt const* s)
    {
      apply(s->stmt(), *this);
    }

    void operator()(While_stmt const* s)
    {
      apply(s->body(), *this);
    }

    void operator()(Decode_stmt const* s)
    {
      Stage* b = p.find(s->decoder());
      assert(b);
      br.insert(b);
    }

    void operator()(Goto_stmt const* s)
    {
      Stage* b = p.find(s->table());
      assert(b);
      br.insert(b);
    }
  };

  apply(d->body(), Find_branches{branches, pipeline});

  return branches;
}


// Go through all stages in the pipeline
// and discover the branches which it goes to.
void
Pipeline_checker::discover_branches()
{
  for (auto stage : pipeline) {
    if (Decode_decl const* decoder = as<Decode_decl>(stage->decl()))
      stage->branches_ = find_branches(decoder);
    else if (Table_decl const* table = as<Table_decl>(stage->decl()))
      stage->branches_ = find_branches(table);
    else
      throw std::runtime_error("Invalid decl found in pipeline.");
  }
}


bool
Pipeline_checker::check_pipeline()
{
  // first get the pipelines from the elaborator
  // FIXME: for now we only handle one pipeline
  Pipeline_decls pipeline_decls = elab.pipelines.front();

  for (Decl const* d : pipeline_decls) {

    if (Table_decl const* table = as<Table_decl>(d)) {
      register_stage(table);
    }
    else if (Decode_decl const* decode = as<Decode_decl>(d)) {
      register_stage(decode);
    }
    else
      throw std::runtime_error("Unknown pipeline stage.");
  }


  // discover all branches
  discover_branches();

  // check PATHS
  if (entry)
    dfs(entry);
  else
    throw Type_error({}, "No entry point in pipeline.");

  return false;
}



void
Pipeline_checker::print_header_mappings()
{
  std::cout << "======== Header-mapping =========\n";
  for (auto mapping : hdr_map) {
    std::cout << *mapping.first->name() << " : " << mapping.second << '\n';
  }
}


void
Pipeline_checker::print_field_mappings()
{
  std::cout << "======== Field-mapping =========\n";
  for (auto mapping : fld_map) {
    std::cout << *mapping.first << " : " << mapping.second << '\n';
  }
}



void
Pipeline_checker::print_stages()
{
  std::cout << "======== Stages =========\n";
  for (auto stage : pipeline) {
    print_stage(stage);
  }
  std::cout << "=================\n";
}


void
Pipeline_checker::print_stage(Stage const* s)
{
  std::cout << "\nStage: \n";
  std::cout << *s->decl()->name() << '\n';
  std::cout << "productions: \n";
  for (auto sym : s->productions()) {
    std::cout << *sym.first << " ";
  }
  std::cout << '\n';

  std::cout << "branches: \n";

  for (auto b : s->branches()) {
    std::cout << *b->decl()->name() << " ";
  }
  std::cout << '\n';

  std::cout << "reqs: \n";

  for (auto r : s->requirements()) {
    std::cout << *r << " ";
  }
  std::cout << '\n';
}

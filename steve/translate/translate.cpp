#include "translate.hpp"
#include "tostring.hpp"

#include "steve/net.hpp"
#include "steve/lower.hpp"

#include <iostream>

namespace steve
{

namespace
{

// maintain the location of a stmt
// within the sequence of stmts
std::unordered_map<Stmt const*, int> locations;

} // namespace

// Extract the pipeline and maintain the statement location
// for each pipeline decl.
void
Translator::extract_pipeline()
{
  int count = 0;

  for (auto stmt : program) {
    // If it is a declaration stmt declaring a pipeline stage
    if (Decl_stmt const* s = as<Decl_stmt>(stmt)) {

      // decode decl
      if (is<Decode_decl>(s->decl())) {
        register_stage(as<Decode_decl>(s->decl()));
        locations.insert({stmt, count});
      }

      // table decl
      if (is<Table_decl>(s->decl())) {
        register_stage(as<Table_decl>(s->decl()));
        locations.insert({stmt, count});
      }

      ++count;
    }
  }

  // check the pipeline
  check_pipeline();

  // now that stuffs been registered we can lower it
  Stmt_seq lowered;
  for (auto pair : locations) {
    int loc = pair.second;
    lower(pair.first, lowered);
    program.erase(program.begin() + loc);

    // FIXME: This makes a dangerous assumption that one decl stmt
    // gets lowered to exactly one other decl stmt
    program.insert(lowered.begin(), lowered.end(), program.begin() + loc);
  }

  for (auto stmt : program) {
    std::cout << tostring(translate(stmt));
  }
}

} // namespace steve
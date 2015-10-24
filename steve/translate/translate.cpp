#include "translate.hpp"
#include "tostring.hpp"

#include "steve/net.hpp"
#include "steve/lower.hpp"

#include <iostream>
#include <string>
#include <stdexcept>

namespace steve
{

namespace
{

// maintain the location of a stmt
// within the sequence of stmts
std::unordered_map<Stmt const*, int> locations_;

// maintains the name of the entrypoint
enum Entry_kind {
  match,
  decode,
};

std::pair<std::string, Entry_kind> entry_;

int max_extract = 4;

} // namespace

// Extract the pipeline and maintain the statement location
// for each pipeline decl.
//
// TODO: provide language feature for explicit declaration of first
// stage in the pipeline. Right now we assume the first declaration is
// the entry point into the pipeline.
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
        locations_.insert({stmt, count});
      }

      // table decl
      if (is<Table_decl>(s->decl())) {
        register_stage(as<Table_decl>(s->decl()));
        locations_.insert({stmt, count});
      }

      ++count;
    }
  }

  // check the pipeline
  if (check_pipeline()) {
    // get the start of the pipeline so
    // we know how to generate the entry point
    Decl const* start_decl = pipeline_get_start();
    if (is<Decode_decl>(start_decl))
      entry_ = std::make_pair(*start_decl->name(), Entry_kind::decode);
    else if (is<Table_decl>(start_decl))
      entry_ = std::make_pair(*start_decl->name(), Entry_kind::match);
  }
  else
    throw std::runtime_error("Bad pipeline.");
}


void
Translator::lower_pipeline()
{
  for (auto pair : locations_) {
    // now that stuffs been registered we can lower it
    Stmt_seq lowered;

    int loc = pair.second;
    lower(pair.first, lowered);

    program.erase(program.begin() + loc);

    // FIXME: This makes a dangerous assumption that one decl stmt
    // gets lowered to exactly one other decl stmt
    program.insert(program.begin() + loc, lowered.begin(), lowered.end());
  }
}


void
Translator::codegen()
{
  extract_pipeline();
  lower_pipeline();

  // inject the include statements
  code += "#include <iostream>\n"
          "#include \"lang/include.hpp\"\n"
          "using namespace fp;\n"
          "using App_cxt = Application_context<" + std::to_string(get_num_headers()) + ", "
                                                 + std::to_string(get_num_fields()) + ", " 
                                                 + std::to_string(max_extract) +
                                                 ">;\n";


  for (auto stmt : program) {
    code += tostring(translate(stmt));
  }

  std::string entry_code;
  switch (entry_.second) {
    // we have to dereference the _cxt_ because it is passed
    // via pointer but we want to pass it via reference
    // for the duration of the application runtime
    case Entry_kind::decode:
      entry_code += "__decode(*a, " + entry_.first + ");\n";
      break;
    case Entry_kind::match:
      entry_code += "__match(*a, " + entry_.first + ");\n";
      break;
  }

  // inject egress code
  code += "void egress(fp::Context* _cxt_)"
          "{\n"
          "   std::cout << _cxt_ << \'\\n\';\n"
          "   delete _cxt_;\n"
          "}\n";

  // inject the entry into the pipeline
  code += "Context* ingress(fp::Context* _cxt_)"
          "{\n"
          "   App_cxt* a = new App_cxt(*_cxt_);\n"
          "   delete _cxt_;\n"
          "   _cxt_ = a;\n"
          "   " + entry_code + 
          "   egress(_cxt_);\n"
          "}\n";

  std::cout << code;
}

} // namespace steve
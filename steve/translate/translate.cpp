#include "translate.hpp"
#include "tostring.hpp"

#include "steve/net.hpp"
#include "steve/lower.hpp"

#include <iostream>
#include <string>

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
  // flag to help determine entry point
  bool is_start = true;

  for (auto stmt : program) {
    // If it is a declaration stmt declaring a pipeline stage
    if (Decl_stmt const* s = as<Decl_stmt>(stmt)) {
      // decode decl
      if (is<Decode_decl>(s->decl())) {
        if (is_start) {
          entry_ = std::make_pair(*(s->decl()->name()), Entry_kind::decode);
          is_start = false;
        }

        register_stage(as<Decode_decl>(s->decl()));
        locations_.insert({stmt, count});
      }

      // table decl
      if (is<Table_decl>(s->decl())) {
        if (is_start) {
          entry_ = std::make_pair(*(s->decl()->name()), Entry_kind::match);
          is_start = false;
        }

        register_stage(as<Table_decl>(s->decl()));
        locations_.insert({stmt, count});
      }

      ++count;
    }
  }

  // check the pipeline
  check_pipeline();
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
          "#include \"builtin.hpp\"\n"
          "#include \"app_context.hpp\"\n"
          "#include \"include.hpp\"\n"
          "using namespace fp;\n"
          "using App_cxt = App_context<" + std::to_string(get_num_headers()) + ", "
                                         + std::to_string(get_num_fields()) + ">;\n";

  for (auto stmt : program) {
    code += tostring(translate(stmt));
  }

  std::string entry_code;
  switch (entry_.second) {
    case Entry_kind::decode:
      entry_code += "__decode(_cxt_, " + entry_.first + ");\n";
      break;
    case Entry_kind::match:
      entry_code += "__match(_cxt_, " + entry_.first + ");\n";
      break;
  }

  // inject egress code
  code += "void egress(App_cxt* _cxt_)"
          "{\n"
          "   std::cout << _cxt_ << \'\\n\';\n"
          "   delete _cxt_;\n"
          "}\n";

  // inject the entry into the pipeline
  code += "Context* ingress(App_cxt* _cxt_)"
          "{\n"
          "   App_cxt a = new App_cxt(_cxt_);\n"
          "   delete _cxt_;\n"
          "   _cxt_ = a;\n"
          "   " + entry_code + 
          "   egress(_cxt_);\n"
          "}\n";

  std::cout << code;
}

} // namespace steve
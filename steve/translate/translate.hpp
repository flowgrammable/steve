#ifndef STEVE_TRANSLATE_HPP
#define STEVE_TRANSLATE_HPP

#include "lingo/node.hpp"

#include "steve/prelude.hpp"
#include "steve/expr.hpp"
#include "steve/decl.hpp"
#include "steve/stmt.hpp"
#include "steve/type.hpp"
#include "steve/builtin.hpp"

#include "cxx/ast.hpp"
#include "cxx/decl.hpp"
#include "cxx/type.hpp"
#include "cxx/expr.hpp"
#include "cxx/stmt.hpp"
#include "cxx/name.hpp"
#include "cxx/string.hpp"

#include "tostring.hpp"
#include "translate-stmt.hpp"
#include "translate-expr.hpp"
#include "translate-decl.hpp"
#include "translate-type.hpp"


namespace steve
{

// The program translator converts a steve program into C++.
// A program in steve is define as a sequence of statements.
// A program goes through certain transformations before translation.
//
// 1. Program is parsed.
// 2. Semantic analysis (type check, name resolution, etc) is performed on
//      everything except pipeline declarations (decode and table decls). 
//      For decode decls, only the decode name and the name of the header it
//      decodes are checked. For table decls, only the table name and the fields
//      it extracts are checked. The checking of the bodies are defered.
//
// === Begin the translation phase === 
//
// 3. Pipeline decls are extracted from the program and registered into a pipeline. 
//
// 4. Perform semantic checks on the bodies of each pipeline phase. 
//      Regular semantic checks happen. 
//      Branches for each stage are discovered.
//      Requirements of each stage are discovered.
//      Extractions from each decoder are discovered.
//        - This causes a store of integer to field mappings to be created.
//        - The benefit is that we discard field names and replace them with a simpler representation.
//
// 5. Pipeline paths are checked.
//      All paths in the pipeline are checked for well-formedness.
//      This means that all fields required by a table are decoded before the table is reached.
//      Recursive repetition into previous decoders is not checked because the fields required by tables
//      are known to have already been discovered.
//
// 6. Lowering is done.
//      Phase 4 and 5 should guarantee that all transformations made in this phase are valid.
//      Lowered declarations are injected at the place of the non-lowered decl. The non-lowered decl is removed.
//
// 7. Translation into C++ takes place on each statement in order.

struct Translator
{
  // In order to translate the pipeline into C++ we need to know certain
  // things discovered during the compilation process
  // 1. All decoders, tables, their bodies, and their associated metadata
  // 2. The header environment which assigns an integer representation to header names
  // 3. The field environment which assigns an integer representation to field names
  Translator(Program& p)
    : program(p)
  { }

  // translate into c++
  void codegen();
  void write(String filename);

private:
  void extract_pipeline();
  void lower_pipeline();

  String code;
  Program& program;
};

} // namespace steve

#endif
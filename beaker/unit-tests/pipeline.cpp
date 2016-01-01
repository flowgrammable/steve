#include "beaker/prelude.hpp"
#include "beaker/lexer.hpp"
#include "beaker/parser.hpp"
#include "beaker/elaborator.hpp"
#include "beaker/pipeline.hpp"
#include "beaker/lower.hpp"
#include "beaker/generator.hpp"
#include "beaker/error.hpp"

#include <iostream>
#include <fstream>

#include <llvm/IR/Module.h>
#include <llvm/Support/raw_ostream.h>


int
main(int argc, char* argv[])
{
  init_colors();

  // Prepare the symbol table.
  Symbol_table syms;
  init_symbols(syms);

  // Prepare the input buffer.
  //
  // FIXME: Handle command line arguments.
  File src = argv[1];
  Input_buffer in = src;

  try {
    // Create the token stream over. This will be populated
    // by the lexer.
    Token_stream ts;

    // Build and run the lexer.
    Lexer lex(syms, in);
    if (!lex.lex(ts))
      return -1;

    // Build and run the parser. The location map
    // is used to save source locations, which are
    // used to diagnose elaboration errors.
    Location_map locs;
    Parser parse(syms, ts, locs);
    Module_decl  mod;  // The translation module
    Decl* m = parse.module(&mod);
    if (!parse)
      return -1;

    // Perform semantic analysis.
    //
    // TODO: Implement a parse-only phase.
    Elaborator elab(locs, syms);
    elab.elaborate(m);

    // Perform pipeline checks
    Pipeline_checker check(elab);
    check.check_pipeline();

    Lowerer lower(elab, check);
    Decl* lowered = lower.lower(m);
    //
    // check.print_header_mappings();
    // check.print_field_mappings();
    // check.print_stages();

    // Print all declaration

    // std::cout << *lowered;

    // Translate to LLVM.
    //
    // TODO: Support translation to other models?
    Generator gen;
    llvm::Module* gmod = gen(lowered);
    llvm::outs() << *gmod;
  }

  // Diagnose uncaught translation errors and exit
  // gracefully. All other uncaught exceptions are
  // ICEs and we want those to fail noisily. Note
  // that re-throwing does not re-establish the
  // origin of the error for the purpose of debugging.
  catch (Translation_error& err) {
    diagnose(err);
    return -1;
  }

  // FIXME: Do something with the module.
}

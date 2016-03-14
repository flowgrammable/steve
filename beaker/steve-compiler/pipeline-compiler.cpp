#include "beaker/prelude.hpp"
#include "beaker/lexer.hpp"
#include "beaker/parser.hpp"
#include "beaker/elaborator.hpp"
#include "beaker/pipeline.hpp"
#include "beaker/lower.hpp"
#include "beaker/generator.hpp"
#include "beaker/error.hpp"

#include "beaker/options.hpp"
#include "beaker/job.hpp"

#include <iostream>
#include <fstream>

// FIXME: It would be better if the generator hid all
// of these details from us.
#include <llvm/IR/Module.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/raw_ostream.h>

static void
usage(std::ostream& os, po::options_description& desc)
{
  os << "usage: beaker-compile [options] input-file...\n";
  os << desc << '\n';
}


enum Target
{
  program_tgt,
  module_tgt
};


// Records the configuration parsed from the
// command line arguments.
struct Config
{
  bool keep     = false;
  bool assemble = false;
  bool compile  = false;
  bool f_march  = false; // if march is set
  Target target = program_tgt;
  String march = "";
};


static bool parse(Path const&, Config const&);
static bool parse(Path_seq const&, Path const&, Config const&);

// static bool lower(Path const&, Path const&, Config const&);
// static bool assemble(Path const&, Path const&, Config const&);
// static bool executable(Path_seq const&, Path const&, Config const&);
// static bool module(Path_seq const&, Path const&, Config const&);
static Path make_libsteve(Path const&);
static bool link_libsteve(Path const&, Path const&, Path const&);
static bool clang_compile(Path_seq const&, Path const&, Config const&);

// Global resources.
Location_map locs; // Source code locations
Symbol_table syms; // The symbol table
Module_decl  mod;  // The translation module

int
main(int argc, char* argv[])
{
  init_colors();
  init_symbols(syms);

  po::options_description common_opts("Common options");
  common_opts.add_options()
    ("output,o",  po::value<String>(),      "Specify the output file.")
    ("input,i",   po::value<String_seq>(),  "Specify input files.")
    ("keep,k",    po::bool_switch(),        "Keep temporary files.")
    ("architecture,target", po::value<String>(), "Specify target triple to build for."
                                                  "Uses same -target option as clang.");

  po::positional_options_description positional_opts;
  positional_opts.add("input", -1);

  po::options_description all_opts;
  all_opts.add(common_opts);

  // Prepare the input buffer.
  //
  // FIXME: Handle command line arguments.
  // File src = argv[1];
  // Input_buffer in = src;

  // Default output file.
  Path output = "a.so";

  Config conf;
  po::variables_map vm;
  try {
    po::store(
      po::command_line_parser(argc, argv)
        .options(all_opts)
        .positional(positional_opts)
        .run(),
      vm);
    po::notify(vm);
  } catch(std::exception& err) {
    std::cerr << "error: " << err.what() << "\n\n";
    usage(std::cerr, all_opts);
    return -1;
  }

  // Validate the input files.
  if (!vm.count("input")) {
    std::cerr << "error: no input files\n\n";
    usage(std::cerr, all_opts);
    return -1;
  }

  Path_seq inputs;
  for (String const& s : vm["input"].as<String_seq>())
    inputs.push_back(s);

  if (vm.count("output"))
    output = vm["output"].as<String>();

  if (vm.count("keep"))
    conf.keep = true;

  if (vm.count("architecture")) {
    conf.march = vm["architecture"].as<String>();
    conf.f_march = true;
  }

  // Right now steve always compiles to modules.
  conf.target  = module_tgt;

  // Convert to IR file
  Path ir = to_ir_file(output);
  if (!parse(inputs, ir, conf))
    return -1;

  // Attempt to build steve-helper-lib using steve
  Path libsteve = make_libsteve(libsteve_loc());

  Path bc = to_bitcode_file(output);
  if (!link_libsteve(libsteve, ir, bc))
    return -1;

  if (!clang_compile({bc}, output, conf))
    return -1;

  // Path as = to_asm_file(output);
  // if (!lower(ir, as, conf))
  //   return -1;
  // if (conf.assemble)
  //   return 0;

  // Path obj = to_object_file(output);
  // if (!assemble(as, obj, conf))
  //   return -1;
  // if (conf.compile)
  //   return 0;

  // Generate the linked result.
  // if (conf.target == program_tgt)
  //   return executable({obj}, output, conf);
  // if (conf.target == module_tgt)
  //   return module({obj}, output, conf);

  // FIXME: Do something with the module.
  return 0;
}


// Lower LLVM IR/BC to native assembly.
bool
lower(Path const& in, Path const& out, Config const& conf)
{
  Job job(llvm_compiler(), {
    format("-o {}", out.string()),
    in.string()
  });
  return job.run();
}


// Translate an assembly program into an object file.
//
// FIXME: We should be using the native assembler and
// not a C compiler for this program. Note that we
// add the "-c" option as a result of this decision.
bool
assemble(Path const& in, Path const& out, Config const& conf)
{
  Job job(native_assembler(), {
    "-c",
    format("-o {}", out.string()),
    in.string()
  });
  return job.run();
}


// Link a sequence of object files into an executable program.
// Note that this uses the C compiler, so we implicitly link
// against the C runtime.
//
// TODO: Don't link against the C runtime!
bool
executable(Path_seq const& in, Path const& out, Config const& conf)
{
  // Build the argument list.
  String_seq args;
  args.push_back(format("-o {}", out.string()));
  for (Path const& p : in)
    args.push_back(p.string());

  // Build and run the job.
  Job job(native_linker(), args);
  return job.run();
}


// Link a sequence of object files into a shared
// library.
bool
module(Path_seq const& in, Path const& out, Config const& conf)
{
  // Build the argument list.
  String_seq args;
  args.push_back("-fPIC");
  args.push_back("-shared");
  args.push_back(format("-o {}", out.string()));
  for (Path const& p : in)
    args.push_back(p.string());

  // Build and run the job.
  Job job(native_linker(), args);
  return job.run();
}


// Make the ll file for libsteve
Path
make_libsteve(Path const& libloc)
{
  // Generate the complete path to the interface file.
  static char const* libsteve_file = "libsteve.cpp";
  Path src = libloc;
  src /= libsteve_file;

  Path ir = fs::temp_directory_path() / to_ir_file(libsteve_file);

  String_seq args;
  args.push_back("-emit-llvm");
  args.push_back("-femit-all-decls");
  args.push_back("-S");
  args.push_back("-std=c++11");
  args.push_back(src.string());
  args.push_back(format("-o {}", ir.string()));

  // Build and run the job.
  Job job(clang_compiler(), args);
  if (job.run())
    return ir;

  throw std::runtime_error("Failed to compile libsteve.");
}


// Link libsteve with regular ll file.
bool
link_libsteve(Path const& lib, Path const& ir, Path const& out)
{
  String_seq args;
  args.push_back(ir.string());
  args.push_back(lib.string());
  args.push_back(format("-o {}", out.string()));
  Job job(llvm_linker(), args);

  std::cout << llvm_linker() << " ";
  for (auto a : args)
    std::cout << a << " ";

  return job.run();
}


// Make a shared object from an ll file
bool
clang_compile(Path_seq const& in, Path const& out, Config const& conf)
{
  // Build the argument list.
  String_seq args;
  args.push_back("-fPIC");
  args.push_back("-shared");
  if (conf.f_march)
    args.push_back("-target " + conf.march);
  args.push_back(format("-o {}", out.string()));
  args.push_back("-O3"); // Complete optimization
  for (Path const& p : in)
    args.push_back(p.string());

  std::cout << clang_compiler() << " ";
  for (auto a : args)
    std::cout << a << " ";

  // Build and run the job.
  Job job(clang_compiler(), args);
  return job.run();
}


// Parse the input file into the module.
bool
parse(Path const& in, Config const& conf)
{
  try {
    // Read the input source.
    File src = in.c_str();
    Input_buffer buf = src;

    // Lex the input source.
    Token_stream ts;
    Location_map locs;
    Lexer lex(syms, buf);
    if (!lex.lex(ts))
      return false;

    // Parse the token stream.
    Parser parse(syms, ts, locs);
    if (!parse.module(&mod))
      return false;

    return true;
  }

  // Diagnose uncaught translation errors and exit
  // gracefully. All other uncaught exceptions are
  // ICEs and we want those to fail noisily. Note
  // that re-throwing does not re-establish the
  // origin of the error for the purpose of debugging.
  catch (Translation_error& err) {
    diagnose(err);
    return false;
  }
  catch (...)
  {
    return false;
  }
}


bool
parse(Path_seq const& in, Path const& out, Config const& conf)
{
  bool ok = true;
  for (Path const& p : in) {
    if (get_file_kind(p) == beaker_file)
      ok &= parse(p, conf);
    if (get_file_kind(p) == steve_file)
      ok &= parse(p, conf);
    else {
      // FIXME: LLVM IR/BC or assembly could (should?) be
      // lowered and passed through to the link phase. That
      // would allow a module to contain native assembly,
      // and used internally via foreign declarations.
      std::cerr << "error: unknown input file type\n";
      return false;
    }
  }
  if (!ok)
    return false;

  try {
    // Elaborate the parse result.static
    Elaborator elab(locs, syms);
    elab.elaborate(&mod);

    // Perform pipeline checks
    Pipeline_checker check(elab);
    check.check_pipeline();

    // Lower the syntax into basic beaker language stuff.
    Lowerer lowerer(elab, check);
    Decl* lowered = lowerer.lower(&mod);

    // Translate to LLVM.
    Generator gen;
    llvm::Module* ir = gen(lowered);

    // Write the output to an IR file, not the requested
    // output. That happens later.
    Path p = to_ir_file(out);

    // Write the result to the output file.
    std::error_code err;
    llvm::raw_fd_ostream ofs(p.string(), err, llvm::sys::fs::F_None);
    ofs << *ir;
  }
  // Diagnose uncaught translation errors and exit
  // gracefully. All other uncaught exceptions are
  // ICEs and we want those to fail noisily. Note
  // that re-throwing does not re-establish the
  // origin of the error for the purpose of debugging.
  catch (Translation_error& err) {
    diagnose(err);
    return false;
  }

  return true;
}

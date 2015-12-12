#ifndef BUILTIN_HPP
#define BUILTIN_HPP

#include "beaker/expr.hpp"
#include "beaker/stmt.hpp"
#include "beaker/decl.hpp"
#include "beaker/type.hpp"

// Define a set of global names for each builtin functions
// of flowpath functions
constexpr char const* __bind_header  = "fp_bind_header";
constexpr char const* __bind_field   = "fp_bind_field";
constexpr char const* __alias_bind   = "fp_alias_bind";
constexpr char const* __advance      = "fp_advance";
constexpr char const* __get_table    = "fp_get_table";
constexpr char const* __add_flow     = "fp_add_flow";
constexpr char const* __match        = "fp_goto_table";
constexpr char const* __load_field   = "fp_load_field";
constexpr char const* __get_port     = "fp_get_port";
constexpr char const* __gather       = "fp_gather";
constexpr char const* __output       = "fp_output2port";
constexpr char const* __drop         = "fp_drop";
constexpr char const* __context      = "__cxt__";
constexpr char const* __header       = "__header__";
constexpr char const* __table        = "__table__";
constexpr char const* __key          = "__key__";
constexpr char const* __drop_port    = "__drop";
constexpr char const* __flood_port   = "__flood";

// runtime interface functions
constexpr char const* __load         = "load";
constexpr char const* __process      = "process";
constexpr char const* __start        = "start";
constexpr char const* __stop         = "stop";
constexpr char const* __port_num     = "port_num";
constexpr char const* __unload       = "unload";


// -------------------------------------------------------------------------- //
//    Runtime calls

// Contains builtin expressions representing the
// flowpath south-bound interface
// i.e. functions which the runtime define and we can link against

// These functions will be linked externally from the C runtime

// Bind the location of an offset
// The runtime function for bind offset has the form
//
// void __bind_offset(Context*, id, offset, length);
//
// Extract declarations become a calls to
//  1 - bind_offset
//  2 - load
// The binding is established, and then the value
// is stored into a variable with the same name and type
// as the field within the extract declaration.
//
// This expression becomes a call to that function.
struct Bind_field : Call_expr
{
  Bind_field(Expr* fn, Expr_seq const& args)
    : Call_expr(fn, args)
  { }

  Bind_field(Expr* context, Expr* id, Expr* offset, Expr* length)
    : Call_expr(nullptr, {context, id, offset, length})
  { }
};


// Alias bind of a field
// i.e. extract f1 as f2
//
// This function is called when we want
// to extract a field and give it a name
// which is not its original name.
//
// This causes two binds to occur which
// point to the same byte offset within the
// packet.
//
// void __alias_bind(Context*, id1, id2, offset, length);
//
// This gets generated when rebind extractions are found.
struct Alias_bind : Call_expr
{
  Alias_bind(Expr* context, Expr* id1, Expr* id2, Expr* offset, Expr* length)
    : Call_expr(nullptr, {context, id1, id2, offset, length})
  { }
};


// Bind the location of a header
// The runtime function for this has the form
// The offset of the header is implicitly maintained
// by the current byte within the offset.
//
// void __bind_header(Context*, int id, int length);
//
// The values of entire headers are never immediately
// loaded into memory. This is just so we can keep
// track of the locations header which had been operated
// on.
//
// This becomes a call to that function.
struct Bind_header : Call_expr
{
  using Call_expr::Call_expr;

  Bind_header(Expr* fn, Expr* id, Expr* length)
    : Call_expr(fn, {id, length})
  { }

  Expr* first;
};


// Loads the value of a field into memory
struct Load_field : Call_expr
{
  Load_field(Expr* fn, Expr_seq const& args)
    : Call_expr(fn, args)
  { }
};


// Tell the dataplane to create a table
// The create_table function from the runtime has
// the form:
//
// void get_table(int id, int key_size, int flow_max, ...)
//
struct Create_table : Call_expr
{
  using Call_expr::Call_expr;

  void accept(Visitor& v) const { v.visit(this); }
  void accept(Mutator& v)       { v.visit(this); }

  Decl* table_;
};


// Remove a table
// Why do we need this per se?
struct Delete_table : Call_expr
{

};


struct Add_flow : Call_expr
{
  using Call_expr::Call_expr;
};


// Perform a gather operation on a list of
// fields.
//
// void gather(context*, int num_keys, ...)
struct Gather : Call_expr
{
  using Call_expr::Call_expr;
};


// Perform a lookup and execution within a table
//
// Make the assumption that the runtime does the
// gathering operation before dispatching to
// the table.
//
// void __match(Context*, Table*);
struct Match : Call_expr
{
  using Call_expr::Call_expr;
};


// Advance the current byte in the table
// Causes the current byte offset within the
// context to be incremented by n.
//
// void __advance(Context*, int n)
struct Advance : Call_expr
{
  Advance(Expr* fn, Expr_seq const& args)
    : Call_expr(fn, args)
  { }

  Advance(Expr* fn, Expr* context, Expr* n)
    : Call_expr(fn, {n})
  { }
};


struct Get_port : Call_expr
{
  Get_port(Expr* fn, Expr_seq const& args)
    : Call_expr(fn, args)
  { }

  void accept(Visitor& v) const { v.visit(this); }
  void accept(Mutator& v)       { v.visit(this); }

  // maintain the variable
  Decl* port_;
};


struct Drop_packet : Call_expr
{
  using Call_expr::Call_expr;
};


struct Output_packet : Call_expr
{
  using Call_expr::Call_expr;
};


// Build all builtin functions
struct Builtin
{
  using Function_map = std::unordered_map<std::string, Function_decl*>;
  using Port_map = std::unordered_map<std::string, Port_decl*>;

  Builtin(Symbol_table& syms)
    : syms(syms)
  {
    init_builtins();
  }

  Function_decl* get_builtin_function(std::string name);

  Function_map get_builtin_functions() const { return builtin_fn; }
  Port_map     get_builtin_ports() const { return builtin_ports; }

  Expr* call_bind_field(Expr_seq const& args);
  Expr* call_bind_header(Expr*, Expr*);
  Expr* call_alias_field();
  Expr* call_advance(Expr_seq const& args);
  Expr* call_create_table(Decl*, Expr_seq const& args);
  Expr* call_add_flow(Expr_seq const& args);
  Expr* call_match(Expr_seq const& args);
  Expr* call_load_field(Expr_seq const& args);
  Expr* call_get_port(Decl*, Expr_seq const& args);
  Expr* call_gather(Expr* cxt, Expr_seq const& var_args);
  Expr* call_drop(Expr* cxt);
  Expr* call_output(Expr* cxt, Expr* port);

  // exposed interface
  Function_decl* load(Stmt_seq const&);
  Function_decl* unload();
  Function_decl* start();
  Function_decl* stop();
  Function_decl* port_num();

  // construct instrinsic flow functions
  // from flow declarations
  Function_decl* flow_fn(Symbol const*, Stmt*);

private:
  void init_builtins();

  Function_decl* bind_header();
  Function_decl* bind_field();
  Function_decl* alias_bind();
  Function_decl* advance();
  Function_decl* get_table();
  Function_decl* add_flow();
  Function_decl* gather();
  Function_decl* match();
  Function_decl* load_field();
  Function_decl* get_port();
  Function_decl* drop();
  Function_decl* output();

  Port_decl* drop_port();
  Port_decl* flood_port();

  Symbol const* get_identifier(std::string);

  Symbol_table& syms;
  Function_map builtin_fn;
  Port_map builtin_ports;
};


#endif

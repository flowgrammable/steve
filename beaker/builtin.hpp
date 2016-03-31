#ifndef BUILTIN_HPP
#define BUILTIN_HPP

#include "beaker/expr.hpp"
#include "beaker/stmt.hpp"
#include "beaker/decl.hpp"
#include "beaker/type.hpp"

// Define a set of global names for each builtin functions
// of flowpath functions
constexpr char const* RT_bind_header     = "fp_bind_header";
constexpr char const* RT_bind_field      = "fp_bind_field";
constexpr char const* RT_alias_bind      = "fp_alias_bind";
constexpr char const* RT_read_field      = "fp_read_field";
constexpr char const* RT_advance         = "fp_advance_header";
constexpr char const* RT_get_table       = "fp_create_table";
constexpr char const* RT_add_init_flow   = "fp_add_init_flow";
constexpr char const* RT_add_new_flow    = "fp_add_new_flow";
constexpr char const* RT_rmv_flow        = "fp_del_flow";
constexpr char const* RT_add_miss        = "fp_add_miss";
constexpr char const* RT_rmv_miss        = "fp_del_miss";
constexpr char const* RT_match           = "fp_goto_table";
constexpr char const* RT_set_field       = "fp_set_field";
constexpr char const* RT_get_port        = "fp_get_port_by_name";
constexpr char const* RT_get_port_id     = "fp_get_port_by_id";
constexpr char const* RT_output          = "fp_output_port";
constexpr char const* RT_dataplane       = "fp_dataplane";
constexpr char const* RT_drop            = "fp_drop";
constexpr char const* RT_clear           = "fp_clear";
constexpr char const* RT_write_output    = "fp_write_output";
constexpr char const* RT_write_set       = "fp_write_set_field";
constexpr char const* RT_raise_event     = "fp_raise_event";
constexpr char const* RT_get_flow_egress = "fp_get_flow_egress";
constexpr char const* RT_get_inport      = "fp_get_packet_in_port";
constexpr char const* RT_get_inphysport  = "fp_get_packet_in_phys_port";
constexpr char const* RT_port_up         = "fp_port_id_is_up";
constexpr char const* RT_port_down       = "fp_port_id_is_down";
constexpr char const* RT_get_all_port    = "fp_get_all_port";
constexpr char const* RT_get_controller_port = "fp_get_controller_port";
constexpr char const* RT_get_reflow_port = "fp_get_reflow_port";
constexpr char const* RT_get_flood_port  = "fp_get_flood_port";
constexpr char const* RT_context         = "__cxt";
constexpr char const* RT_header          = "__header";
constexpr char const* RT_table           = "__table";
constexpr char const* RT_key             = "__key";
constexpr char const* RT_drop_port       = "__drop";
constexpr char const* RT_flood_port      = "__flood";
constexpr char const* RT_flow_self       = "__flow_self";
constexpr char const* RT_inport          = "__inport";
constexpr char const* RT_pktinport       = "__pktinport";
constexpr char const* RT_keyform         = "__KEYFORM_";

// runtime interface functions
constexpr char const* RT_load            = "load";
constexpr char const* RT_process         = "process";
constexpr char const* RT_start           = "start";
constexpr char const* RT_stop            = "stop";
constexpr char const* RT_port_num        = "ports";
constexpr char const* RT_unload          = "unload";
constexpr char const* RT_port_changed    = "port_changed";


// -------------------------------------------------------------------------- //
//    Runtime calls

// Contains builtin expressions representing the
// flowpath south-bound interface
// i.e. functions which the runtime define and we can link against

// These functions will be linked externally from the C runtime

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

  Expr* call_bind_field(Expr* cxt, Expr* id, Expr* offset, Expr* length);
  Expr* call_bind_header(Expr*, Expr*, Expr*);
  Expr* call_alias_bind(Expr*, Expr*, Expr*, Expr*, Expr*);
  Expr* call_read_field(Expr*, Expr*, Expr*);
  Expr* call_advance(Expr*, Expr*);
  Expr* call_create_table(Decl*, Expr*, Expr*, Expr*, Expr*, Expr*);
  Expr* call_add_init_flow(Expr*, Expr*, Expr*, Expr*, Expr*);
  Expr* call_add_new_flow(Expr*, Expr*, Expr*, Expr*, Expr*);
  Expr* call_remove_flow(Expr*, Expr*);
  Expr* call_remove_miss(Expr*);
  Expr* call_add_miss(Expr*, Expr*, Expr*, Expr*);
  Expr* call_match(Expr*, Expr*, Expr*, Expr_seq const& var_args);
  Expr* call_get_port(Decl*, Expr*, Expr*);
  Expr* call_get_port_by_id(Expr*, Expr*);
  Expr* call_get_in_port(Expr*);
  Expr* call_get_in_phys_port(Expr*);
  Expr* call_get_flow_egress(Expr*);
  Expr* call_get_all_port(Expr*);
  Expr* call_get_controller_port(Expr*);
  Expr* call_get_reflow_port(Expr*);
  Expr* call_get_flood_port(Expr*);
  Expr* call_port_id_up(Expr*, Expr*);
  Expr* call_port_id_down(Expr*, Expr*);
  Expr* call_drop(Expr* cxt);
  Expr* call_output(Expr* cxt, Expr* port);
  Expr* call_clear(Expr*);
  Expr* call_set_field(Expr* cxt, Expr* id, Expr* len, Expr* val);
  Expr* call_write_drop(Expr*);
  Expr* call_write_output(Expr* cxt, Expr* port);
  Expr* call_write_set_field(Expr* cxt, Expr* id, Expr* len, Expr* val);
  Expr* call_raise_event(Expr*, Expr*);

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
  Function_decl* read_field();
  Function_decl* advance();
  Function_decl* get_table();
  Function_decl* add_init_flow();
  Function_decl* add_new_flow();
  Function_decl* remove_flow();
  Function_decl* remove_miss();
  Function_decl* add_miss();
  Function_decl* match();
  Function_decl* get_port();
  Function_decl* get_port_by_id();
  Function_decl* get_in_port();
  Function_decl* get_in_phys_port();
  Function_decl* get_flow_egress();
  Function_decl* get_all_port();
  Function_decl* get_controller_port();
  Function_decl* get_reflow_port();
  Function_decl* get_flood_port();
  Function_decl* port_id_up();
  Function_decl* port_id_down();
  Function_decl* drop();
  Function_decl* output();
  Function_decl* clear();
  Function_decl* set_field();
  Function_decl* write_drop();
  Function_decl* write_output();
  Function_decl* write_set_field();
  Function_decl* raise_event();

  Symbol const* get_identifier(std::string);

  Symbol_table& syms;
  Function_map builtin_fn;
  Port_map builtin_ports;
};


#endif

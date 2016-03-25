#ifndef BUILTIN_HPP
#define BUILTIN_HPP

#include "beaker/expr.hpp"
#include "beaker/stmt.hpp"
#include "beaker/decl.hpp"
#include "beaker/type.hpp"

// Define a set of global names for each builtin functions
// of flowpath functions
constexpr char const* __bind_header     = "fp_bind_header";
constexpr char const* __bind_field      = "fp_bind_field";
constexpr char const* __alias_bind      = "fp_alias_bind";
constexpr char const* __read_field      = "fp_read_field";
constexpr char const* __advance         = "fp_advance_header";
constexpr char const* __get_table       = "fp_create_table";
constexpr char const* __add_init_flow   = "fp_add_init_flow";
constexpr char const* __add_new_flow    = "fp_add_new_flow";
constexpr char const* __rmv_flow        = "fp_del_flow";
constexpr char const* __add_miss        = "fp_add_miss";
constexpr char const* __rmv_miss        = "fp_del_miss";
constexpr char const* __match           = "fp_goto_table";
constexpr char const* __set_field       = "fp_set_field";
constexpr char const* __get_port        = "fp_get_port_by_name";
constexpr char const* __get_port_id     = "fp_get_port_by_id";
constexpr char const* __output          = "fp_output_port";
constexpr char const* __dataplane       = "fp_dataplane";
constexpr char const* __drop            = "fp_drop";
constexpr char const* __clear           = "fp_clear";
constexpr char const* __write_output    = "fp_write_output";
constexpr char const* __write_set       = "fp_write_set_field";
constexpr char const* __raise_event     = "fp_raise_event";
constexpr char const* __get_flow_egress = "fp_get_flow_egress";
constexpr char const* __get_inport      = "fp_get_packet_in_port";
constexpr char const* __get_inphysport  = "fp_get_packet_in_phys_port";
constexpr char const* __port_up         = "fp_port_id_is_up";
constexpr char const* __port_down       = "fp_port_id_is_down";
constexpr char const* __get_all_port    = "fp_get_all_port";
constexpr char const* __get_controller_port = "fp_get_controller_port";
constexpr char const* __get_reflow_port = "fp_get_reflow_port";
constexpr char const* __get_flood_port  = "fp_get_flood_port";
constexpr char const* __context         = "_cxt_";
constexpr char const* __header          = "_header_";
constexpr char const* __table           = "_table_";
constexpr char const* __key             = "_key_";
constexpr char const* __drop_port       = "_drop_";
constexpr char const* __flood_port      = "_flood_";
constexpr char const* __flow_self       = "__flow_self";
constexpr char const* __inport          = "__inport";
constexpr char const* __pktinport       = "__pktinport";
constexpr char const* __keyform         = "_KEYFORM_";

// runtime interface functions
constexpr char const* __load            = "load";
constexpr char const* __process         = "process";
constexpr char const* __start           = "start";
constexpr char const* __stop            = "stop";
constexpr char const* __port_num        = "ports";
constexpr char const* __unload          = "unload";
constexpr char const* __port_changed    = "port_changed";


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

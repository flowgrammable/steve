#include "beaker/builtin.hpp"
#include "beaker/builder.hpp"
#include "beaker/token.hpp"


// Helper function for constructing
// identifier symbols
Symbol const*
Builtin::get_identifier(std::string s)
{
  return syms.put<Identifier_sym>(s, identifier_tok);
}


//
// void RT_bind_header(int id, int length);
//
Function_decl*
Builtin::bind_header()
{
  Type const* void_type = get_void_type();
  Symbol const* fn_name = get_identifier(RT_bind_header);

  Decl_seq parms =
  {
    new Parameter_decl(get_identifier("cxt"), get_context_type()->ref()),
    new Parameter_decl(get_identifier("id"), get_integer_type()),
    // NOTE: headers might have variable length, we might not want to do this
    // new Parameter_decl(get_identifier("length"), get_integer_type()),
  };

  Type const* fn_type = get_function_type(parms, void_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, parms, block({}));

  fn->spec_ |= foreign_spec;
  return fn;
}


//
// void RT_bind_offset(Context*, id, offset, length);
//
Function_decl*
Builtin::bind_field()
{
  Type const* void_type = get_void_type();
  Symbol const* fn_name = get_identifier(RT_bind_field);

  Decl_seq parms =
  {
    new Parameter_decl(get_identifier("cxt"), get_context_type()->ref()),
    new Parameter_decl(get_identifier("id"), get_integer_type()),
    new Parameter_decl(get_identifier("offset"), get_integer_type()),
    new Parameter_decl(get_identifier("length"), get_integer_type()),
  };

  Type const* fn_type = get_function_type(parms, void_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, parms, block({}));

  fn->spec_ |= foreign_spec;
  return fn;
}


//
// Byte* RT_alias_bind(Context*, int org, int alias, int offset, int length);
//
Function_decl*
Builtin::alias_bind()
{
  Symbol const* fn_name = get_identifier(RT_alias_bind);

  Decl_seq parms
  {
    new Parameter_decl(get_identifier("cxt"), get_context_type()->ref()),
    new Parameter_decl(get_identifier("o"), get_integer_type()),
    new Parameter_decl(get_identifier("a"), get_integer_type()),
    new Parameter_decl(get_identifier("offset"), get_integer_type()),
    new Parameter_decl(get_identifier("length"), get_integer_type()),
  };

  Type const* fn_type = get_function_type(parms, get_void_type());

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, parms, block({}));

  fn->spec_ |= foreign_spec;
  return fn;
}


// Requests the the runtime returns a pointer to a specific field.
// The pointer is to the latest extracted field of that field kind.
//
//    void* read_field(Context*, int field)
Function_decl*
Builtin::read_field()
{
  Symbol const* fn_name = get_identifier(RT_read_field);

  Type const* ret_type = get_block_type(get_character_type());

  Decl_seq parms =
  {
    new Parameter_decl(get_identifier("cxt"), get_context_type()->ref()),
    new Parameter_decl(get_identifier("field"), get_integer_type()),
    new Parameter_decl(get_identifier("res"), get_character_type()->ref())
  };

  Type const* fn_type = get_function_type(parms, ret_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, parms, block({}));

  fn->spec_ |= foreign_spec;
  return fn;
}


//
// void RT_advance(Context*, int n)
//
Function_decl*
Builtin::advance()
{
  Type const* void_type = get_void_type();
  Symbol const* fn_name = get_identifier(RT_advance);

  Decl_seq parms =
  {
    new Parameter_decl(get_identifier("cxt"), get_context_type()->ref()),
    new Parameter_decl(get_identifier("length"), get_integer_type()),
  };

  Type const* fn_type = get_function_type(parms, void_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, parms, block({}));

  fn->spec_ |= foreign_spec;
  return fn;
}


// Requests a table from the runtime by providing some config details.
//
//    Table* get_table(Dataplane*, int id, int key_size, int tbl_size, int tbl_kind)
Function_decl*
Builtin::get_table()
{
  // Table types are entirely opaque during code generation
  // so what the actual table type is doesnt matter as long
  // as it is a table type.
  Type const* ret_type = get_opaque_type()->ref();
  Symbol const* fn_name = get_identifier(RT_get_table);

  Decl_seq parms =
  {
    new Parameter_decl(get_identifier("dp"), get_opaque_type()->ref()),
    new Parameter_decl(get_identifier("id"), get_integer_type()),
    new Parameter_decl(get_identifier("key_size"), get_integer_type()),
    new Parameter_decl(get_identifier("size"), get_integer_type()),
    new Parameter_decl(get_identifier("table_type"), get_integer_type())
  };

  Type const* fn_type = get_function_type(parms, ret_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, parms, block({}));

  fn->spec_ |= foreign_spec;
  return fn;
}


// Add an initial flow entry to the table.
//
//    void add_init_flow(Table*, Flow*, i8* key, int timeout, Port::ID egress)
Function_decl*
Builtin::add_init_flow()
{
  // Table types are entirely opaque during code generation
  // so what the actual table type is doesnt matter as long
  // as it is a table type.
  Type const* tbl_ref = get_opaque_type()->ref();
  Type const* cxt_ref = get_context_type()->ref();
  Type const* flw_ref = get_opaque_type()->ref();
  Type const* void_type = get_void_type();
  Type const* buffer_type = get_block_type(get_character_type());

  // Flows actually become free functions so they have function
  // type when lowered.
  Type_seq types {flw_ref, tbl_ref, cxt_ref};
  Type const* flow_fn_type = get_function_type(types, void_type);
  Type const* flow_ref = get_reference_type(flow_fn_type);

  Symbol const* fn_name = get_identifier(RT_add_init_flow);

  Decl_seq parms =
  {
    new Parameter_decl(get_identifier("table"), tbl_ref),
    new Parameter_decl(get_identifier("flow"), flow_ref),
    new Parameter_decl(get_identifier("key_buf"), buffer_type),
    new Parameter_decl(get_identifier("timeout"), get_integer_type()),
    new Parameter_decl(get_identifier("egr"), get_port_type()),
  };

  Type const* fn_type = get_function_type(parms, void_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, parms, block({}));

  fn->spec_ |= foreign_spec;
  return fn;
}


// Add a new flow entry to the table.
//
//    void add_new_flow(Table*, Flow*, i8* key, Context*)
Function_decl*
Builtin::add_new_flow()
{
  // Table types are entirely opaque during code generation
  // so what the actual table type is doesnt matter as long
  // as it is a table type.
  Type const* tbl_ref = get_opaque_type()->ref();
  Type const* cxt_ref = get_context_type()->ref();
  Type const* flw_ref = get_opaque_type()->ref();
  Type const* void_type = get_void_type();
  Type const* buffer_type = get_block_type(get_character_type());

  // Flows actually become free functions so they have function
  // type when lowered.
  Type_seq types {flw_ref, tbl_ref, cxt_ref};
  Type const* flow_fn_type = get_function_type(types, void_type);
  Type const* flow_ref = get_reference_type(flow_fn_type);

  Symbol const* fn_name = get_identifier(RT_add_new_flow);

  Decl_seq parms =
  {
    new Parameter_decl(get_identifier("table"), tbl_ref),
    new Parameter_decl(get_identifier("flow"), flow_ref),
    new Parameter_decl(get_identifier("key_buf"), buffer_type),
    new Parameter_decl(get_identifier("timeout"), get_integer_type()),
    new Parameter_decl(get_identifier("egr"), get_port_type()),
  };

  Type const* fn_type = get_function_type(parms, void_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, parms, block({}));

  fn->spec_ |= foreign_spec;
  return fn;
}


// Remove a flow entry with a given key from a given table.
//
//    void del_flow(Table*, void* key)
Function_decl*
Builtin::remove_flow()
{
  // Table types are entirely opaque during code generation
  // so what the actual table type is doesnt matter as long
  // as it is a table type.
  Type const* tbl_ref = get_opaque_type()->ref();
  Type const* void_type = get_void_type();
  Type const* buffer_type = get_block_type(get_character_type());

  Symbol const* fn_name = get_identifier(RT_rmv_flow);

  Decl_seq parms =
  {
    new Parameter_decl(get_identifier("table"), tbl_ref),
    new Parameter_decl(get_identifier("key_buf"), buffer_type)
  };

  Type const* fn_type = get_function_type(parms, void_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, parms, block({}));

  fn->spec_ |= foreign_spec;
  return fn;
}


// Add miss entry to the table.
//
//    void add_miss_case(Table*, Flow*)
Function_decl*
Builtin::add_miss()
{
  // Table types are entirely opaque during code generation
  // so what the actual table type is doesnt matter as long
  // as it is a table type.
  Type const* flow_ref = get_opaque_type()->ref();
  Type const* tbl_ref = get_opaque_type()->ref();
  Type const* cxt_ref = get_context_type()->ref();
  Type const* void_type = get_void_type();
  // Flows actually become free functions so they have function
  // type when lowered.
  Type_seq types {flow_ref, tbl_ref, cxt_ref};
  Type const* flow_fn_type = get_function_type(types, void_type);
  Type const* flow_fn_ref = get_reference_type(flow_fn_type);

  Symbol const* fn_name = get_identifier(RT_add_miss);

  Decl_seq parms =
  {
    new Parameter_decl(get_identifier("table"), tbl_ref),
    new Parameter_decl(get_identifier("flow"), flow_fn_ref),
    new Parameter_decl(get_identifier("timeout"), get_integer_type()),
    new Parameter_decl(get_identifier("egr"), get_port_type()),
  };

  Type const* fn_type = get_function_type(parms, void_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, parms, block({}));

  fn->spec_ |= foreign_spec;
  return fn;
}


// Remove a flow entry miss case from a table.
//
//    void del_miss(Table*)
Function_decl*
Builtin::remove_miss()
{
  // Table types are entirely opaque during code generation
  // so what the actual table type is doesnt matter as long
  // as it is a table type.
  Type const* tbl_ref = get_opaque_type()->ref();
  Type const* void_type = get_void_type();

  Symbol const* fn_name = get_identifier(RT_rmv_miss);

  Decl_seq parms =
  {
    new Parameter_decl(get_identifier("table"), tbl_ref)
  };

  Type const* fn_type = get_function_type(parms, void_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, parms, block({}));

  fn->spec_ |= foreign_spec;
  return fn;
}


// Match is used to goto a table and tell it to match the packet fields
// against flow entries and execute the flow. This has the form:
//
//    void goto_table(Context*, Table*, int fld_cnt, ...)
//
// The variadic arguments specify which fields are being matched upon.
Function_decl*
Builtin::match()
{
  // Table types are entirely opaque during code generation
  // so what the actual table type is doesnt matter as long
  // as it is a table type.
  Type const* ret_type = get_void_type();
  Type const* tbl_ref = get_opaque_type()->ref();
  Type const* cxt_ref = get_context_type()->ref();
  Symbol const* fn_name = get_identifier(RT_match);

  Decl_seq parms =
  {
    new Parameter_decl(get_identifier(RT_context), cxt_ref),
    new Parameter_decl(get_identifier(RT_table), tbl_ref),
    new Parameter_decl(get_identifier("n"), get_integer_type()) // number of fields
  };

  Type_seq parm_t = { cxt_ref, tbl_ref };

  // C Variadic Function
  Type const* fn_type = get_function_type(parm_t, ret_type, true);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, parms, block({}));

  fn->spec_ |= foreign_spec;
  return fn;
}


// TODO: Rename this to get_port_by_name
//
// This function call gets a port with a specific name from the runtime system.
//
//    Port::ID get_port(char*, char*);
//
// TODO: Add the configuration string to the function call. Write now the
// runtime doesn't support it so we're only going with the port name.
Function_decl*
Builtin::get_port()
{
  Symbol const* fn_name = get_identifier(RT_get_port);

  Type const* port_type = get_port_type();

  Decl_seq parms {
    new Parameter_decl(get_identifier("name"), get_block_type(get_character_type()))
  };

  Type const* fn_type = get_function_type(parms, port_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, {}, block({}));

  fn->spec_ |= foreign_spec;
  return fn;
}


// This function call makes a call back to the runtime with an ID to confirm
// that a port of that number actually exists. If it does, the returned ID will
// be equal to the id parameter. Otherwise, an error should be thrown by the
// runtime.
//
//    Port::ID get_port_by_id(Port::Id id)
Function_decl*
Builtin::get_port_by_id()
{
  Symbol const* fn_name = get_identifier(RT_get_port_id);

  Type const* port_type = get_port_type();

  Decl_seq parms {
    new Parameter_decl(get_identifier("dp"), get_opaque_type()->ref()),
    new Parameter_decl(get_identifier("id"), get_integer_type())
  };

  Type const* fn_type = get_function_type(parms, port_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, {}, block({}));

  fn->spec_ |= foreign_spec;
  return fn;
}


// This function call gets the in_port of a context.
//
//    Port::ID get_packet_in_port(Context*);
Function_decl*
Builtin::get_in_port()
{
  Symbol const* fn_name = get_identifier(RT_get_inport);

  Type const* port_type = get_port_type();
  Type const* cxt_ref = get_context_type()->ref();

  Decl_seq parms {
    new Parameter_decl(get_identifier(RT_context), cxt_ref)
  };

  Type const* fn_type = get_function_type(parms, port_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, {}, block({}));

  fn->spec_ |= foreign_spec;
  return fn;
}


// This function call gets the in_phys_port of a context.
//
//    Port::ID get_packet_in_phys_port(Context*);
Function_decl*
Builtin::get_in_phys_port()
{
  Symbol const* fn_name = get_identifier(RT_get_inphysport);

  Type const* port_type = get_port_type();
  Type const* cxt_ref = get_context_type()->ref();

  Decl_seq parms {
    new Parameter_decl(get_identifier(RT_context), cxt_ref)
  };

  Type const* fn_type = get_function_type(parms, port_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, {}, block({}));

  fn->spec_ |= foreign_spec;
  return fn;
}


// Get the reserved ALL port.
Function_decl*
Builtin::get_all_port()
{
  Symbol const* fn_name = get_identifier(RT_get_all_port);

  Type const* port_type = get_port_type();

  Decl_seq parms {
    new Parameter_decl(get_identifier("dp"), get_opaque_type()->ref()),
  };

  Type const* fn_type = get_function_type(parms, port_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, {}, block({}));

  fn->spec_ |= foreign_spec;
  return fn;
}


// Get the reserved CONTROLLER port.
Function_decl*
Builtin::get_controller_port()
{
  Symbol const* fn_name = get_identifier(RT_get_controller_port);

  Type const* port_type = get_port_type();

  Decl_seq parms {
    new Parameter_decl(get_identifier("dp"), get_opaque_type()->ref()),
  };

  Type const* fn_type = get_function_type(parms, port_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, {}, block({}));

  fn->spec_ |= foreign_spec;
  return fn;
}


// Get the reserved reflow port.
Function_decl*
Builtin::get_reflow_port()
{
  Symbol const* fn_name = get_identifier(RT_get_reflow_port);

  Type const* port_type = get_port_type();

  Decl_seq parms {
    new Parameter_decl(get_identifier("dp"), get_opaque_type()->ref()),
  };

  Type const* fn_type = get_function_type(parms, port_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, {}, block({}));

  fn->spec_ |= foreign_spec;
  return fn;
}


// Get the reserved flood port.
Function_decl*
Builtin::get_flood_port()
{
  Symbol const* fn_name = get_identifier(RT_get_flood_port);

  Type const* port_type = get_port_type();

  Decl_seq parms {
    new Parameter_decl(get_identifier("dp"), get_opaque_type()->ref()),
  };

  Type const* fn_type = get_function_type(parms, port_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, {}, block({}));

  fn->spec_ |= foreign_spec;
  return fn;
}


// Retrieves the inport value from a Flow structure.
//
//    void get_flow_egress(Flow*);
Function_decl*
Builtin::get_flow_egress()
{
  Symbol const* fn_name = get_identifier(RT_get_flow_egress);

  Type const* flow_ref = get_opaque_type()->ref();
  Type const* port_type = get_port_type();

  Decl_seq parms {
    new Parameter_decl(get_identifier(RT_flow_self), flow_ref)
  };

  Type const* fn_type = get_function_type(parms, port_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, {}, block({}));

  fn->spec_ |= foreign_spec;
  return fn;
}


// Calls to see if the port with the given ID is up.
//
//  bool port_id_up(int id)
Function_decl*
Builtin::port_id_up()
{
  Symbol const* fn_name = get_identifier(RT_port_up);

  Decl_seq parms {
    new Parameter_decl(get_identifier("dp"), get_opaque_type()->ref()),
    new Parameter_decl(get_identifier("id"), get_integer_type())
  };

  Type const* fn_type = get_function_type(parms, get_boolean_type());

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, {}, block({}));

  fn->spec_ |= foreign_spec;
  return fn;
}


// Calls to see if the port with the given ID is down.
//
//  bool port_id_down(int id)
Function_decl*
Builtin::port_id_down()
{
  Symbol const* fn_name = get_identifier(RT_port_down);

  Decl_seq parms {
    new Parameter_decl(get_identifier("dp"), get_opaque_type()->ref()),
    new Parameter_decl(get_identifier("id"), get_integer_type())
  };

  Type const* fn_type = get_function_type(parms, get_boolean_type());

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, {}, block({}));

  fn->spec_ |= foreign_spec;
  return fn;
}


// This call to the runtime instructs it to immediately drop the packet.
//
//    void drop(Context*)
Function_decl*
Builtin::drop()
{
  Symbol const* fn_name = get_identifier(RT_drop);

  Type const* void_type = get_void_type();

  Decl_seq parms {
    new Parameter_decl(get_identifier("cxt"), get_context_type()->ref())
  };

  Type const* fn_type = get_function_type(parms, void_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, {}, block({}));

  fn->spec_ |= foreign_spec;

  return fn;
}


// This instructs the runtime to send the packet out of the given port.
//
//    void output(Context*, Port*)
Function_decl*
Builtin::output()
{
  Symbol const* fn_name = get_identifier(RT_output);

  Type const* void_type = get_void_type();
  Type const* port_type = get_port_type();

  Decl_seq parms {
    new Parameter_decl(get_identifier("cxt"), get_context_type()->ref()),
    new Parameter_decl(get_identifier("port"), port_type)
  };

  Type const* fn_type = get_function_type(parms, void_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, {}, block({}));

  fn->spec_ |= foreign_spec;

  return fn;
}


// This instructs the runtime to clear the action list that has been
// written to the packet.
//
//    void clear(Context*);
Function_decl*
Builtin::clear()
{
  Symbol const* fn_name = get_identifier(RT_clear);

  Type const* void_type = get_void_type();

  Decl_seq parms {
    new Parameter_decl(get_identifier("cxt"), get_context_type()->ref())
  };

  Type const* fn_type = get_function_type(parms, void_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, {}, block({}));

  fn->spec_ |= foreign_spec;

  return fn;
}


// Requests that the runtime write over a certain field in the packet
// with the data provided to the function.
//
//    void set_field(Context*, int field, int len, void* val)
Function_decl*
Builtin::set_field()
{
  Symbol const* fn_name = get_identifier(RT_set_field);

  Type const* void_type = get_void_type();
  Type const* int_type = get_integer_type();
  Type const* cxt_ref = get_context_type()->ref();
  Type const* buffer = get_character_type()->ref();

  Decl_seq parms {
    new Parameter_decl(get_identifier("cxt"), cxt_ref),
    new Parameter_decl(get_identifier("field"), int_type),
    new Parameter_decl(get_identifier("len"), int_type),
    new Parameter_decl(get_identifier("val"), buffer)
  };

  Type const* fn_type = get_function_type(parms, void_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, {}, block({}));

  fn->spec_ |= foreign_spec;

  return fn;
}


// Write an output action to the context.
//
//      void write_output(Context*, Port*)
Function_decl*
Builtin::write_output()
{
  Symbol const* fn_name = get_identifier(RT_write_output);

  Type const* void_type = get_void_type();
  Type const* port_type = get_port_type();

  Decl_seq parms {
    new Parameter_decl(get_identifier("cxt"), get_context_type()->ref()),
    new Parameter_decl(get_identifier("port"), port_type)
  };

  Type const* fn_type = get_function_type(parms, void_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, {}, block({}));

  fn->spec_ |= foreign_spec;

  return fn;
}


// Write a set field action to the context.
//
//    void write_set_field(Context*, int field, int len, void* buf)
Function_decl*
Builtin::write_set_field()
{
  Symbol const* fn_name = get_identifier(RT_write_set);

  Type const* void_type = get_void_type();
  Type const* int_type = get_integer_type();
  Type const* cxt_ref = get_context_type()->ref();
  Type const* buffer = get_character_type()->ref();

  Decl_seq parms {
    new Parameter_decl(get_identifier("cxt"), cxt_ref),
    new Parameter_decl(get_identifier("field"), int_type),
    new Parameter_decl(get_identifier("len"), int_type),
    new Parameter_decl(get_identifier("val"), buffer)
  };

  Type const* fn_type = get_function_type(parms, void_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, {}, block({}));

  fn->spec_ |= foreign_spec;

  return fn;
}


// NOTE: The semantics of calling raise with the runtime should be
// that the implicit context being passed to the event handler is
// COPIED. This allows us to continue processing the packet, after having
// asynchronously passed it off to some event handler.
//
//    void raise_event(Context*, void (Context*)* event_handler);
Function_decl*
Builtin::raise_event()
{
  Symbol const* fn_name = get_identifier(RT_raise_event);

  Type const* void_type = get_void_type();
  Type const* event_type =
    get_function_type({get_context_type()->ref()}, void_type);

  Decl_seq parms {
    new Parameter_decl(get_identifier("cxt"), get_context_type()->ref()),
    new Parameter_decl(get_identifier("event_handle"), event_type->ref())
  };

  Type const* fn_type = get_function_type(parms, void_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, {}, block({}));

  fn->spec_ |= foreign_spec;

  return fn;
}


// Instantiate all the builtin functions required by the compiler
// from the runtime.
void
Builtin::init_builtins()
{
  builtin_fn =
  {
    {RT_bind_header, bind_header()},
    {RT_bind_field, bind_field()},
    {RT_alias_bind, alias_bind()},
    {RT_read_field, read_field()},
    {RT_advance, advance()},
    {RT_get_table, get_table()},
    {RT_add_init_flow, add_init_flow()},
    {RT_add_new_flow, add_new_flow()},
    {RT_rmv_flow, remove_flow()},
    {RT_rmv_miss, remove_miss()},
    {RT_add_miss, add_miss()},
    {RT_match, match()},
    // {RT_gather, gather()},
    // {RT_get_port, get_port()},
    {RT_get_port_id, get_port_by_id()},
    {RT_get_inport, get_in_port()},
    {RT_get_inphysport, get_in_phys_port()},
    {RT_get_all_port, get_all_port()},
    {RT_get_controller_port, get_controller_port()},
    {RT_get_reflow_port, get_reflow_port()},
    {RT_get_flow_egress, get_flow_egress()},
    {RT_get_flood_port, get_flood_port()},
    {RT_port_up, port_id_up()},
    {RT_port_down, port_id_down()},
    {RT_drop, drop()},
    {RT_output, output()},
    {RT_clear, clear()},
    {RT_set_field, set_field()},
    {RT_write_output, write_output()},
    {RT_write_set, write_set_field()},
    {RT_raise_event, raise_event()},
  };
}


// Constructs the load/config function which is called by the runtime.
Function_decl*
Builtin::load(Stmt_seq const& s)
{
  Type const* void_type = get_void_type();
  Symbol const* name = get_identifier(RT_load);

  Decl_seq parms;
  Type const* fn_type = get_function_type(parms, void_type);

  return new Function_decl(name, fn_type, parms, block(s));
}


Function_decl*
unload()
{
  throw std::runtime_error("unimplemented builtin");
}


Function_decl*
start()
{
  throw std::runtime_error("unimplemented builtin");
}


Function_decl*
stop()
{
  throw std::runtime_error("unimplemented builtin");
}


Function_decl*
port_num()
{
  throw std::runtime_error("unimplemented builtin");
}


Function_decl*
Builtin::flow_fn(Symbol const* name, Stmt* body)
{
  throw std::runtime_error("unimplemented builtin");
}


// Returns the builtin with the given name.
Function_decl*
Builtin::get_builtin_function(std::string name)
{
  return builtin_fn.find(name)->second;
}


Expr*
Builtin::call_bind_field(Expr* cxt, Expr* id, Expr* offset, Expr* length)
{
  Function_decl* fn = builtin_fn.find(RT_bind_field)->second;
  assert(fn);

  return new Call_expr(decl_id(fn), {cxt, id, offset, length});
}


Expr*
Builtin::call_bind_header(Expr* cxt, Expr* id, Expr* len)
{
  Function_decl* fn = builtin_fn.find(RT_bind_header)->second;
  assert(fn);

  // NOTE: we are current excluding len because the runtime
  // does not handle header length and its unsure if the length of a header
  // matters.

  return new Call_expr(decl_id(fn), {cxt, id});
}


Expr*
Builtin::call_alias_bind(Expr* cxt, Expr* id1, Expr* id2, Expr* off, Expr* len)
{
  Function_decl* fn = builtin_fn.find(RT_alias_bind)->second;
  assert(fn);

  // NOTE: we are current excluding len because the runtime
  // does not handle header length and its unsure if the length of a header
  // matters.

  return new Call_expr(decl_id(fn), {cxt, id1, id2, off, len});
}


Expr*
Builtin::call_read_field(Expr* cxt, Expr* id, Expr* ret)
{
  Function_decl* fn = builtin_fn.find(RT_read_field)->second;
  assert(fn);

  return new Call_expr(decl_id(fn), {cxt, id, ret});
}


Expr*
Builtin::call_create_table(Decl* d, Expr* dp, Expr* id, Expr* key_size, Expr* entry_size, Expr* kind)
{
  Function_decl* fn = builtin_fn.find(RT_get_table)->second;
  assert(fn);

  // Create_table* e = new Create_table(decl_id(fn), { dp, id, key_size, entry_size, kind});
  // e->table_ = d;

  return new Call_expr(decl_id(fn), { dp, id, key_size, entry_size, kind});
}


Expr*
Builtin::call_advance(Expr* cxt, Expr* length)
{
  Function_decl* fn = builtin_fn.find(RT_advance)->second;
  assert(fn);

  return new Call_expr(decl_id(fn), {cxt, length});
}


Expr*
Builtin::call_add_init_flow(Expr* table, Expr* flow, Expr* key, Expr* t_out, Expr* egress)
{
  Function_decl* fn = builtin_fn.find(RT_add_init_flow)->second;
  assert(fn);

  return new Call_expr(decl_id(fn), {table, flow, key, t_out, egress});
}


Expr*
Builtin::call_add_new_flow(Expr* table, Expr* flow, Expr* key, Expr* t_out, Expr* egress)
{
  Function_decl* fn = builtin_fn.find(RT_add_new_flow)->second;
  assert(fn);

  return new Call_expr(decl_id(fn), {table, flow, key, t_out, egress});
}


Expr*
Builtin::call_remove_flow(Expr* table, Expr* key)
{
  Function_decl* fn = builtin_fn.find(RT_rmv_flow)->second;
  assert(fn);

  return new Call_expr(decl_id(fn), {table, key});
}


Expr*
Builtin::call_add_miss(Expr* tbl, Expr* flow, Expr* t_out, Expr* egress)
{
  Function_decl* fn = builtin_fn.find(RT_add_miss)->second;
  assert(fn);

  return new Call_expr(decl_id(fn), {tbl, flow, t_out, egress});
}


Expr*
Builtin::call_remove_miss(Expr* table)
{
  Function_decl* fn = builtin_fn.find(RT_rmv_miss)->second;
  assert(fn);

  return new Call_expr(decl_id(fn), {table});
}


// FIXME: Currently the runtime doesnt support confirmation for both name
// and args, only name.
Expr*
Builtin::call_get_port(Decl* d, Expr* name, Expr* args)
{
  Function_decl* fn = builtin_fn.find(RT_get_port)->second;
  assert(fn);

  // Get_port* e = new Get_port(decl_id(fn), {name});
  // e->port_ = d;
  Expr* e = new Call_expr(decl_id(fn), {name});

  return e;
}


Expr*
Builtin::call_get_port_by_id(Expr* dp, Expr* id)
{
  Function_decl* fn = builtin_fn.find(RT_get_port_id)->second;
  assert(fn);

  Expr* e = new Call_expr(decl_id(fn), {dp, id});
  return e;
}


Expr*
Builtin::call_get_in_port(Expr* cxt)
{
  Function_decl* fn = builtin_fn.find(RT_get_inport)->second;
  assert(fn);

  return new Call_expr(decl_id(fn), {cxt});
}


Expr*
Builtin::call_get_in_phys_port(Expr* cxt)
{
  Function_decl* fn = builtin_fn.find(RT_get_inphysport)->second;
  assert(fn);

  return new Call_expr(decl_id(fn), {cxt});
}


Expr*
Builtin::call_get_all_port(Expr* dp)
{
  Function_decl* fn = builtin_fn.find(RT_get_all_port)->second;
  assert(fn);

  return new Call_expr(decl_id(fn), {dp});
}


Expr*
Builtin::call_get_controller_port(Expr* dp)
{
  Function_decl* fn = builtin_fn.find(RT_get_controller_port)->second;
  assert(fn);

  return new Call_expr(decl_id(fn), {dp});
}


Expr*
Builtin::call_get_reflow_port(Expr* dp)
{
  Function_decl* fn = builtin_fn.find(RT_get_reflow_port)->second;
  assert(fn);

  return new Call_expr(decl_id(fn), {dp});
}


Expr*
Builtin::call_get_flood_port(Expr* dp)
{
  Function_decl* fn = builtin_fn.find(RT_get_flood_port)->second;
  assert(fn);

  return new Call_expr(decl_id(fn), {dp});
}


Expr*
Builtin::call_get_flow_egress(Expr* flow)
{
  Function_decl* fn = builtin_fn.find(RT_get_flow_egress)->second;
  assert(fn);

  return new Call_expr(decl_id(fn), {flow});
}


Expr*
Builtin::call_port_id_up(Expr* dp, Expr* id)
{
  Function_decl* fn = builtin_fn.find(RT_port_up)->second;
  assert(fn);

  return new Call_expr(decl_id(fn), {dp, id});
}


Expr*
Builtin::call_port_id_down(Expr* dp, Expr* id)
{
  Function_decl* fn = builtin_fn.find(RT_port_down)->second;
  assert(fn);

  return new Call_expr(decl_id(fn), {dp, id});
}


Expr*
Builtin::call_match(Expr* cxt, Expr* tbl, Expr* n, Expr_seq const& var_args)
{
  Function_decl* fn = builtin_fn.find(RT_match)->second;
  assert(fn);

  Expr_seq args { cxt, tbl, n };
  args.insert(args.end(), var_args.begin(), var_args.end());

  return new Call_expr(decl_id(fn), args);
}


Expr*
Builtin::call_drop(Expr* cxt)
{
  Function_decl* fn = builtin_fn.find(RT_drop)->second;
  assert(fn);

  return new Call_expr(decl_id(fn), {cxt});
}


Expr*
Builtin::call_output(Expr* cxt, Expr* port)
{
  Function_decl* fn = builtin_fn.find(RT_output)->second;
  assert(fn);

  return new Call_expr(decl_id(fn), {cxt, port});
}


Expr*
Builtin::call_clear(Expr* cxt)
{
  Function_decl* fn = builtin_fn.find(RT_clear)->second;
  assert(fn);

  return new Call_expr(decl_id(fn), {cxt});
}


Expr*
Builtin::call_set_field(Expr* cxt, Expr* id, Expr* len, Expr* val)
{
  Function_decl* fn = builtin_fn.find(RT_set_field)->second;
  assert(fn);

  return new Call_expr(decl_id(fn), {cxt, id, len, val});
}


Expr*
Builtin::call_write_output(Expr* cxt, Expr* port)
{
  Function_decl* fn = builtin_fn.find(RT_write_output)->second;
  assert(fn);

  return new Call_expr(decl_id(fn), {cxt, port});
}


Expr*
Builtin::call_write_set_field(Expr* cxt, Expr* id, Expr* len, Expr* val)
{
  Function_decl* fn = builtin_fn.find(RT_write_set)->second;
  assert(fn);

  return new Call_expr(decl_id(fn), {cxt, id, len, val});
}


Expr*
Builtin::call_raise_event(Expr* cxt, Expr* event_fn)
{
  Function_decl* fn = builtin_fn.find(RT_raise_event)->second;
  assert(fn);

  return new Call_expr(decl_id(fn), {cxt, event_fn});
}

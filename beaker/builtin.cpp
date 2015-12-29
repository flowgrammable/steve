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
// void __bind_header(int id, int length);
//
Function_decl*
Builtin::bind_header()
{
  Type const* void_type = get_void_type();
  Symbol const* fn_name = get_identifier(__bind_header);

  Decl_seq parms =
  {
    new Parameter_decl(get_identifier("cxt"), get_reference_type(get_context_type())),
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
// Byte* __bind_offset(Context*, id, offset, length);
//
Function_decl*
Builtin::bind_field()
{
  Type const* buffer_type = get_block_type(get_character_type());
  Symbol const* fn_name = get_identifier(__bind_field);

  Decl_seq parms =
  {
    new Parameter_decl(get_identifier("cxt"), get_reference_type(get_context_type())),
    new Parameter_decl(get_identifier("id"), get_integer_type()),
    new Parameter_decl(get_identifier("offset"), get_integer_type()),
    new Parameter_decl(get_identifier("length"), get_integer_type()),
  };

  Type const* fn_type = get_function_type(parms, buffer_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, parms, block({}));

  fn->spec_ |= foreign_spec;
  return fn;
}


//
// Byte* __alias_bind(Context*, int id1, int id2, int offset, int length);
//
Function_decl*
Builtin::alias_bind()
{
  Type const* buffer_type = get_block_type(get_character_type());
  Symbol const* fn_name = get_identifier(__alias_bind);

  Decl_seq parms =
  {
    new Parameter_decl(get_identifier("cxt"), get_reference_type(get_context_type())),
    new Parameter_decl(get_identifier("id1"), get_integer_type()),
    new Parameter_decl(get_identifier("id2"), get_integer_type()),
    new Parameter_decl(get_identifier("offset"), get_integer_type()),
    new Parameter_decl(get_identifier("length"), get_integer_type()),
  };

  Type const* fn_type = get_function_type(parms, buffer_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, parms, block({}));

  fn->spec_ |= foreign_spec;
  return fn;
}


//
// void __advance(Context*, int n)
//
Function_decl*
Builtin::advance()
{
  Type const* void_type = get_void_type();
  Symbol const* fn_name = get_identifier(__advance);

  Decl_seq parms =
  {
    new Parameter_decl(get_identifier("cxt"), get_reference_type(get_context_type())),
    new Parameter_decl(get_identifier("length"), get_integer_type()),
  };

  Type const* fn_type = get_function_type(parms, void_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, parms, block({}));

  fn->spec_ |= foreign_spec;
  return fn;
}


Function_decl*
Builtin::get_table()
{
  // Table types are entirely opaque during code generation
  // so what the actual table type is doesnt matter as long
  // as it is a table type.
  Type const* ret_type = get_reference_type(get_opaque_table());
  Symbol const* fn_name = get_identifier(__get_table);

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


Function_decl*
Builtin::add_flow()
{
  // Table types are entirely opaque during code generation
  // so what the actual table type is doesnt matter as long
  // as it is a table type.
  Type const* tbl_ref = get_reference_type(get_table_type({}, {}));
  Type const* cxt_ref = get_reference_type(get_context_type());
  Type const* void_type = get_void_type();
  Type const* buffer_type = get_block_type(get_character_type());

  // Flows actually become free functions so they have function
  // type when lowered.
  Type_seq types {tbl_ref, cxt_ref};
  Type const* flow_fn_type = get_function_type(types, void_type);
  Type const* flow_ref = get_reference_type(flow_fn_type);

  Symbol const* fn_name = get_identifier(__add_flow);

  Decl_seq parms =
  {
    new Parameter_decl(get_identifier("table"), tbl_ref),
    new Parameter_decl(get_identifier("flow"), flow_ref),
    new Parameter_decl(get_identifier("key_buf"), buffer_type)
  };

  Type const* fn_type = get_function_type(parms, void_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, parms, block({}));

  fn->spec_ |= foreign_spec;
  return fn;
}


Function_decl*
Builtin::add_miss()
{
  // Table types are entirely opaque during code generation
  // so what the actual table type is doesnt matter as long
  // as it is a table type.
  Type const* tbl_ref = get_reference_type(get_table_type({}, {}));
  Type const* cxt_ref = get_reference_type(get_context_type());
  Type const* void_type = get_void_type();
  // Flows actually become free functions so they have function
  // type when lowered.
  Type_seq types {tbl_ref, cxt_ref};
  Type const* flow_fn_type = get_function_type(types, void_type);
  Type const* flow_ref = get_reference_type(flow_fn_type);

  Symbol const* fn_name = get_identifier(__add_miss);

  Decl_seq parms =
  {
    new Parameter_decl(get_identifier("table"), tbl_ref),
    new Parameter_decl(get_identifier("flow"), flow_ref),
  };

  Type const* fn_type = get_function_type(parms, void_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, parms, block({}));

  fn->spec_ |= foreign_spec;
  return fn;
}


// Gather keys
Function_decl*
Builtin::gather()
{
  Symbol const* fn_name = get_identifier(__gather);
  Type const* cxt_ref = get_context_type()->ref();
  Type const* int_type = get_integer_type();
  Type const* key_type = get_key_type()->ref();

  Decl_seq parms =
  {
    new Parameter_decl(get_identifier(__context), cxt_ref),
    new Parameter_decl(get_identifier("n"), int_type),
  };
  // variable argument function
  Type const* fn_type =
    get_function_type(Type_seq {cxt_ref, int_type}, key_type, true);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, parms, block({}));

  fn->spec_ |= foreign_spec;
  return fn;
}


Function_decl*
Builtin::match()
{
  // Table types are entirely opaque during code generation
  // so what the actual table type is doesnt matter as long
  // as it is a table type.
  Type const* ret_type = get_void_type();
  Type const* tbl_ref = get_table_type({}, {})->ref();
  Type const* cxt_ref = get_context_type()->ref();
  Symbol const* fn_name = get_identifier(__match);

  Decl_seq parms =
  {
    new Parameter_decl(get_identifier(__context), cxt_ref),
    new Parameter_decl(get_identifier(__table), tbl_ref),
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

Function_decl*
Builtin::get_port()
{
  Symbol const* fn_name = get_identifier(__get_port);

  Type const* port_type = get_reference_type(get_port_type());

  Decl_seq parms {
    new Parameter_decl(get_identifier("name"), get_block_type(get_character_type()))
  };

  Type const* fn_type = get_function_type(parms, port_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, {}, block({}));

  fn->spec_ |= foreign_spec;
  return fn;
}


Function_decl*
Builtin::drop()
{
  Symbol const* fn_name = get_identifier(__drop);

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


Function_decl*
Builtin::output()
{
  Symbol const* fn_name = get_identifier(__output);

  Type const* void_type = get_void_type();
  Type const* port_type = get_port_type()->ref();

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


Function_decl*
Builtin::set_field()
{
  Symbol const* fn_name = get_identifier(__set_field);

  Type const* void_type = get_void_type();
  Type const* int_type = get_integer_type();
  Type const* cxt_ref = get_context_type()->ref();
  Type const* buffer = get_block_type(get_character_type());

  Decl_seq parms {
    new Parameter_decl(get_identifier("cxt"), cxt_ref),
    new Parameter_decl(get_identifier("id"), int_type),
    new Parameter_decl(get_identifier("len"), int_type),
    new Parameter_decl(get_identifier("val"), buffer)
  };

  Type const* fn_type = get_function_type(parms, void_type);

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, {}, block({}));

  fn->spec_ |= foreign_spec;

  return fn;
}

void
Builtin::init_builtins()
{
  builtin_fn =
  {
    {__bind_header, bind_header()},
    {__bind_field, bind_field()},
    {__alias_bind, alias_bind()},
    {__advance, advance()},
    {__get_table, get_table()},
    {__add_flow, add_flow()},
    {__add_miss, add_miss()},
    {__match, match()},
    {__gather, gather()},
    {__get_port, get_port()},
    {__drop, drop()},
    {__output, output()},
    {__set_field, set_field()},
  };
}


Function_decl*
Builtin::load(Stmt_seq const& s)
{
  Type const* void_type = get_void_type();
  Symbol const* name = get_identifier(__load);

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



Function_decl*
Builtin::get_builtin_function(std::string name)
{
  return builtin_fn.find(name)->second;
}


Expr*
Builtin::call_bind_field(Expr_seq const& args)
{
  Function_decl* fn = builtin_fn.find(__bind_field)->second;
  assert(fn);

  return new Bind_field(decl_id(fn), args);
}


Expr*
Builtin::call_bind_header(Expr* cxt, Expr* id, Expr* len)
{
  Function_decl* fn = builtin_fn.find(__bind_header)->second;
  assert(fn);

  // NOTE: we are current excluding len because the runtime
  // does not handle header length and its unsure if the length of a header
  // matters.

  return new Bind_header(decl_id(fn), cxt, id);
}


Expr*
Builtin::call_alias_bind(Expr* cxt, Expr* id1, Expr* id2, Expr* off, Expr* len)
{
  Function_decl* fn = builtin_fn.find(__alias_bind)->second;
  assert(fn);

  // NOTE: we are current excluding len because the runtime
  // does not handle header length and its unsure if the length of a header
  // matters.

  return new Bind_header(decl_id(fn), {cxt, id1, id2, off, len});
}


Expr*
Builtin::call_create_table(Decl* d, Expr* dp, Expr* id, Expr* key_size, Expr* entry_size, Expr* kind)
{
  Function_decl* fn = builtin_fn.find(__get_table)->second;
  assert(fn);

  Create_table* e = new Create_table(decl_id(fn), { dp, id, key_size, entry_size, kind});
  e->table_ = d;

  return e;
}


Expr*
Builtin::call_advance(Expr_seq const& args)
{
  Function_decl* fn = builtin_fn.find(__advance)->second;
  assert(fn);

  return new Advance(decl_id(fn), args);
}


Expr*
Builtin::call_add_flow(Expr_seq const& args)
{
  Function_decl* fn = builtin_fn.find(__add_flow)->second;
  assert(fn);

  return new Add_flow(decl_id(fn), args);
}


Expr*
Builtin::call_add_miss(Expr* tbl, Expr* flow)
{
  Function_decl* fn = builtin_fn.find(__add_miss)->second;
  assert(fn);

  return new Add_miss(decl_id(fn), {tbl, flow});
}


Expr*
Builtin::call_get_port(Decl* d, Expr_seq const& args)
{
  Function_decl* fn = builtin_fn.find(__get_port)->second;
  assert(fn);

  Get_port* e = new Get_port(decl_id(fn), args);
  e->port_ = d;

  return e;
}


Expr*
Builtin::call_gather(Expr* cxt, Expr_seq const& var_args)
{
  Function_decl* fn = builtin_fn.find(__gather)->second;
  assert(fn);

  Expr* num_args = new Literal_expr(get_integer_type(), var_args.size());

  Expr_seq args;
  args.push_back(cxt);
  args.push_back(num_args);
  args.insert(args.end(), var_args.begin(), var_args.end());

  return new Gather(decl_id(fn), args);
}


Expr*
Builtin::call_match(Expr* cxt, Expr* tbl, Expr* n, Expr_seq const& var_args)
{
  Function_decl* fn = builtin_fn.find(__match)->second;
  assert(fn);

  Expr_seq args { cxt, tbl, n };
  args.insert(args.end(), var_args.begin(), var_args.end());

  return new Match(decl_id(fn), args);
}


Expr*
Builtin::call_drop(Expr* cxt)
{
  Function_decl* fn = builtin_fn.find(__drop)->second;
  assert(fn);

  return new Drop_packet(decl_id(fn), {cxt});
}


Expr*
Builtin::call_output(Expr* cxt, Expr* port)
{
  Function_decl* fn = builtin_fn.find(__output)->second;
  assert(fn);

  return new Output_packet(decl_id(fn), {cxt, port});
}


Expr*
Builtin::call_set_field(Expr* cxt, Expr* id, Expr* len, Expr* val)
{
  Function_decl* fn = builtin_fn.find(__set_field)->second;
  assert(fn);

  return new Call_expr(decl_id(fn), {cxt, id, len, val});
}

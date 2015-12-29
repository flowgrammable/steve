#include "beaker/type.hpp"
#include "beaker/expr.hpp"
#include "beaker/decl.hpp"
#include "beaker/actions.hpp"
#include "beaker/lower.hpp"
#include "beaker/error.hpp"
#include "beaker/mangle.hpp"
#include "beaker/gather.hpp"
#include "beaker/evaluator.hpp"

#include <iostream>

// Helper function for constructing
// identifier symbols
Symbol const*
Lowerer::get_identifier(std::string s)
{
  return elab.syms.put<Identifier_sym>(s, identifier_tok);
}


// -------------------------------------------------------------------------- //
// Application interface

Function_decl*
Lowerer::load_function()
{
  Type const* void_type = get_void_type();
  Decl_seq parms {  };

  Type const* fn_type = get_function_type(parms, void_type);
  Symbol const* fn_name = get_identifier(__load);

  Function_decl* load = new Function_decl(fn_name, fn_type,
                                          parms, block(load_body));

  load->spec_ |= foreign_spec;
  declare(load);

  return load;
}


// Process takes a context pointer
// and passes it to the first decoder specified
// in the pipeline.
Function_decl*
Lowerer::process_function()
{
  // Form the function
  Symbol const* fn_name = get_identifier(__process);
  Type const* void_type = get_void_type();
  Type const* cxt_ref = get_reference_type(get_context_type());
  Parameter_decl* cxt = new Parameter_decl(get_identifier(__context), cxt_ref);
  Type const* fn_type = get_function_type(Type_seq{cxt_ref}, void_type);

  Function_decl* process =
    new Function_decl(fn_name, fn_type, {cxt}, nullptr);
  declare(process);

  Scope_sentinel scope(*this, process);
  // declare the context parameter
  declare(cxt);

  // Form a call to the first function in a pipeline
  // form a call to the decoder
  assert(start_fn);
  Call_expr* call =
    new Call_expr(get_void_type(), id(start_fn), { id(cxt) });
  elab.elaborate(call);

  Stmt_seq process_body;
  process_body.push_back(new Expression_stmt(call));

  process->spec_ |= foreign_spec;

  process->body_ = block(process_body);

  return process;
}


Function_decl*
Lowerer::port_number_function()
{
  Symbol const* fn_name = get_identifier(__port_num);
  Decl_seq parms;
  Type const* fn_type = get_function_type(parms, get_integer_type());

  Expr* port_num = new Literal_expr(get_integer_type(), port_count);

  Stmt_seq body {
    new Return_stmt(port_num)
  };

  Function_decl* fn =
    new Function_decl(fn_name, fn_type, {}, block(body));

  fn->spec_ |= foreign_spec;

  return fn;
}


namespace
{

struct Lower_expr_fn
{
  Lowerer& lower;

  // catch all case
  // simply return the original
  // expression without lowering it
  template<typename T>
  Expr* operator()(T* e) const { return e; }

  Expr* operator()(Value_conv* e) { return lower.lower(e); }
  Expr* operator()(Promotion_conv* e) { return lower.lower(e); }
  Expr* operator()(Demotion_conv* e) { return lower.lower(e); }
  Expr* operator()(Sign_conv* e) { return lower.lower(e); }

  // Field access expr
  // becomes an id_expr whose declaration is
  // resolved against a variable created by lowering
  // the extracts decl
  Expr* operator()(Field_access_expr* e) const { return lower.lower(e); }
};


struct Lower_decl_fn
{
  Lowerer& lower;

  // catch all case
  // return the original declaration
  template<typename T>
  Decl* operator()(T* d) const { lower.declare(d); return d; }

  Decl* operator()(Module_decl* d) const { return lower.lower(d); }

  // network declarations
  Decl* operator()(Flow_decl* d) const { return lower.lower(d); }
};


struct Lower_stmt_fn
{
  Lowerer& lower;

  // catch all case
  template<typename T>
  Stmt_seq operator()(T* s) const { return { s }; }

  // TODO: consider how this works and if we allow this
  // Stmt_seq operator()(Assign_stmt* s) const { return lower.lower(s); }

  Stmt_seq operator()(Empty_stmt* s) const { return lower.lower(s); }
  Stmt_seq operator()(Block_stmt* s) const { return lower.lower(s); }
  Stmt_seq operator()(If_then_stmt* s) const { return lower.lower(s); }
  Stmt_seq operator()(If_else_stmt* s) const { return lower.lower(s); }
  Stmt_seq operator()(Match_stmt* s) const { return lower.lower(s); }
  Stmt_seq operator()(Case_stmt* s) const { return lower.lower(s); }
  Stmt_seq operator()(While_stmt* s) const { return lower.lower(s); }
  Stmt_seq operator()(Expression_stmt* s) const { return lower.lower(s); }
  Stmt_seq operator()(Declaration_stmt* s) const { return lower.lower(s); }
  Stmt_seq operator()(Decode_stmt* s) const { return lower.lower(s); }
  Stmt_seq operator()(Goto_stmt* s) const { return lower.lower(s); }

  Stmt_seq operator()(Action* s) const { return lower.lower(s); }
  Stmt_seq operator()(Drop* s) const { return lower.lower(s); }
  Stmt_seq operator()(Output* s) const { return lower.lower(s); }
  Stmt_seq operator()(Set_field* s) const { return lower.lower(s); }
};


struct Lower_global_decl
{
  Lowerer& l;

  // Catch all for non-lowered globals
  template<typename T>
  Decl* operator()(T* d) const { l.declare(d); return d; }

  Decl* operator()(Decode_decl* d) const { return l.lower_global_decl(d); }
  Decl* operator()(Table_decl* d) const { return l.lower_global_decl(d); }
  Decl* operator()(Port_decl* d) const { return l.lower_global_decl(d); }
};


struct Lower_global_def
{
  Lowerer& l;

  // Catch all for non-lowered globals
  template<typename T>
  Decl* operator()(T* d) const { return d; }

  Decl* operator()(Decode_decl* d) const { return l.lower_global_def(d); }
  Decl* operator()(Table_decl* d) const { return l.lower_global_def(d); }
  Decl* operator()(Port_decl* d) const { return l.lower_global_def(d); }
};

} // namespace





// ------------------------------------------------------------------------- //
//                    Lower Expressions


Expr*
Lowerer::lower(Expr* e)
{
  return apply(e, Lower_expr_fn{*this});
}


Expr*
Lowerer::lower(Value_conv* e)
{
  Expr* val = lower(e->source());
  e->first = val;
  return e;
}


Expr*
Lowerer::lower(Promotion_conv* e)
{
  Expr* val = lower(e->source());
  e->first = val;
  return e;
}


Expr*
Lowerer::lower(Demotion_conv* e)
{
  Expr* val = lower(e->source());
  e->first = val;
  return e;
}


Expr*
Lowerer::lower(Sign_conv* e)
{
  Expr* val = lower(e->source());
  e->first = val;
  return e;
}


Expr*
Lowerer::lower(Field_access_expr* e)
{
  // search for the mangled variable name
  Symbol const* name = get_identifier(mangle(e));

  Overload* ovl = unqualified_lookup(name);
  assert(ovl);
  Decl* var = ovl->back();
  assert(var);

  Decl_expr* ref = new Decl_expr(var->type(), var);

  return ref;
}


// ------------------------------------------------------------------------- //
//                    Lower Declarations

Decl*
Lowerer::lower_global_decl(Decl* d)
{
  Lower_global_decl fn{*this};

  return apply(d, fn);
}


// Declare a new function placeholder
// Lower the body and replace this declaratiion
// later. This is to ensure that this thing
// becomes a function declaration when looked up.
Decl*
Lowerer::lower_global_decl(Decode_decl* d)
{
  // declare an implicit context variable
  Type const* cxt_ref = get_reference_type(get_context_type());
  Parameter_decl* cxt = new Parameter_decl(get_identifier(__context), cxt_ref);

  // The type of all decoders is fn(Context&) -> void
  Function_decl* fn = new Function_decl(d->name(), d->type(), {cxt}, d->body());

  declare(fn);

  return fn;
}


// We replace all table types with an opaque
// table type because after the original type
// checking we no longer care about the shape of the
// table. The runtime abstracts all tables the same way.
Decl*
Lowerer::lower_global_decl(Table_decl* d)
{
  // emit a variable with the same name of table type
  // the table type doesn't really matter too much
  // because it becomes an opaque type during code generation
  //
  // this should be a table pointer not a table object
  Variable_decl* table = new Variable_decl(d->name(),
                                           get_reference_type(opaque_table),
                                           new Default_init(d->type()));

  // this variable should be initialized during the load function
  declare(table);

  return d;
}


Decl*
Lowerer::lower_global_decl(Port_decl* d)
{
  port_count++;

  // this should be a port pointer
  // not a port object
  Variable_decl* port = new Variable_decl(d->name(),
                                          get_reference_type(d->type()),
                                          new Default_init(d->type()));

  declare(port);
  return port;
}


Decl*
Lowerer::lower_global_def(Decl* d)
{
  Lower_global_def fn{*this};

  return apply(d, fn);
}


// FIXME: do a lookup of the Function
// and modify that instead of creating a brand
// new function.
Decl*
Lowerer::lower_global_def(Decode_decl* d)
{
  Overload* ovl = unqualified_lookup(d->name());
  assert(ovl);
  Function_decl* fn = as<Function_decl>(ovl->back());
  assert(fn);

  // enter a scope
  Scope_sentinel scope(*this, d);

  // declare all parameters again
  // NOTE: this declares the context parameter
  for (auto parm : fn->parameters()) {
    declare(parm);
  }

  // we declare an implict header variable so we can
  // lookup type information associated with the decoded header later
  // such as when calling advance()
  Parameter_decl* header = new Parameter_decl(get_identifier(__header), d->header());
  declare(header);

  // get the context varaible
  ovl = unqualified_lookup(get_identifier(__context));
  assert(ovl);
  Decl* cxt = ovl->back();
  assert(cxt);

  // Lower the body and change the definition of the function.
  Stmt* body = lower(d->body()).back();
  fn->body_ = body;
  fn->spec_ |= foreign_spec;

  // bind the header into the context with its id
  Layout_type const* ltype = as<Layout_type>(d->header());
  Layout_decl* ldecl = as<Layout_decl>(ltype->declaration());
  Expr* id = make_int(checker.get_header_mapping(ldecl));
  Expr* len = get_length(ltype);
  Expr* bind = builtin.call_bind_header(decl_id(cxt), id, len);

  // attach the bind header call to the body
  Block_stmt* block = as<Block_stmt>(body);
  block->first.insert(block->first.begin(), new Expression_stmt(bind));

  // register the starting decoder
  if (d->is_start())
    start_fn = fn;

  return fn;
}


Decl_seq
Lowerer::lower_table_flows(Table_decl* d)
{
  Decl_seq flow_fns;

  Type const* cxt_ref = get_reference_type(get_context_type());
  Type const* tbl_ref = get_reference_type(opaque_table);
  Type const* void_type = get_void_type();

  for (auto f : d->body()) {
    Flow_decl* flow = as<Flow_decl>(f);
    Symbol const* flow_name = f->name();

    Scope_sentinel scope(*this, flow);

    // declare an implicit context variable
    Parameter_decl* cxt = new Parameter_decl(get_identifier(__context), cxt_ref);
    Parameter_decl* tbl = new Parameter_decl(get_identifier(__table), tbl_ref);
    declare(cxt);
    declare(tbl);
    Decl_seq parms { tbl, cxt };

    Stmt* flow_body = lower(flow->instructions()).back();
    elab.elaborate(flow_body);

    // The type of all flows is fn(Context&) -> void
    Type const* type = get_function_type(parms, void_type);
    Function_decl* fn = new Function_decl(flow_name, type, parms, flow_body);
    fn->spec_ |= foreign_spec;
    flow_fns.push_back(fn);
  }

  return flow_fns;
}


Decl*
Lowerer::lower_miss_case(Table_decl* d)
{
  // Lower the miss case if there is one
  if (d->miss_case()) {
    Type const* cxt_ref = get_reference_type(get_context_type());
    Type const* tbl_ref = get_reference_type(opaque_table);
    Type const* void_type = get_void_type();

    Flow_decl* flow = as<Flow_decl>(d->miss_case());
    Symbol const* flow_name = flow->name();

    Scope_sentinel scope(*this, flow);

    // declare an implicit context variable
    Parameter_decl* cxt = new Parameter_decl(get_identifier(__context), cxt_ref);
    Parameter_decl* tbl = new Parameter_decl(get_identifier(__table), tbl_ref);
    declare(cxt);
    declare(tbl);
    Decl_seq parms { tbl, cxt };

    Stmt* flow_body = lower(flow->instructions()).back();
    elab.elaborate(flow_body);

    // The type of all flows is fn(Context&) -> void
    Type const* type = get_function_type(parms, void_type);
    Function_decl* fn = new Function_decl(flow_name, type, parms, flow_body);
    fn->spec_ |= foreign_spec;

    return fn;
  }

  // If no miss case exists.
  return nullptr;
}


void
Lowerer::add_flows(Decl* table, Decl_seq const& flow_fns, Decl* miss, Expr_seq const& keys)
{
  auto key_it = keys.begin();

  for (auto flow : flow_fns) {
    // create a call to add_flow() and pass the flow
    // and the current table into it as arguments
    //
    // FIXME: there's something wrong with the elaboration of
    // function pointers so we don't elaborate this for now.
    // However, it should be guaranteed to work.
    Type const* buffer_t = get_block_type(get_character_type());
    Expr* add_flow = builtin.call_add_flow({ decl_id(table),
                                             decl_id(flow),
                                             new Block_conv(buffer_t, *key_it) });
    // elab.elaborate(add_flow);
    load_body.push_back(new Expression_stmt(add_flow));

    ++key_it;
  }

  // Handle the miss case
  if (miss) {
    Expr* add_miss = builtin.call_add_miss(decl_id(table), decl_id(miss));
    load_body.push_back(new Expression_stmt(add_miss));
  }
}


// Converts the keys of flows into c string like
// literals.
Expr_seq
Lowerer::lower_flow_keys(Decl_seq const& flows)
{
  Expr_seq keys;

  for (auto f : flows) {
    Flow_decl* flow = as<Flow_decl>(f);
    Expr* g = gather(flow->keys());
    keys.push_back(g);
  }

  return keys;
}


// FIXME: We should be able to support starting with table
// declarations and matching on fields from context fields
// such as InPort, ArrivalTime, etc.
Decl*
Lowerer::lower_global_def(Table_decl* d)
{
  // We want to take every flow body within a table
  // and emit them as a function.
  //
  // Within the load() function, we want to form a call
  // to the runtime to add this table, then we want to form
  // calls to add every flow.
  // return the variable declaration of the table
  Overload* ovl = unqualified_lookup(d->name());
  assert(ovl);
  Decl* tbl = ovl->back();
  assert(tbl);

  Scope_sentinel scope(*this, d);

  // generate the call to get_table
  Expr* id_no = make_int(d->number());
  Expr* key_len = get_length(d->keys());
  // FIXME: actually have syntax for saying how many
  // flows are allowed in a table. Do this right!
  Expr* num_flows = make_int(1000);
  Expr* table_kind = make_int(d->kind());
  Expr* get_table = builtin.call_create_table(tbl, { id_no, key_len,
                                             num_flows, table_kind });

  // We do special generation for calls to create table
  // because regular assignment does not work with opaque types
  // since the load causes an object of that type to be made,
  // of course you can't have an object of that type because
  // it is opaque and you have no type info about it.
  elab.elaborate(get_table);
  load_body.push_back(new Expression_stmt(get_table));

  // lower the flows transforms them into a bunch of
  // free functions
  Decl_seq flows = lower_table_flows(d);
  Expr_seq keys  = lower_flow_keys(d->body());
  module_decls.insert(module_decls.end(), flows.begin(), flows.end());

  // deal with the flows
  for (auto flow : flows) {
    declare(flow);
  }

  // handle the miss case
  Decl* miss = lower_miss_case(d);
  if (miss) {
    declare(miss);
    module_decls.push_back(miss);
  }

  // add the flows to the load body
  add_flows(tbl, flows, miss, keys);

  return tbl;
}


Decl*
Lowerer::lower_global_def(Port_decl* d)
{
  // Find the port declaration
  Overload* ovl = unqualified_lookup(d->name());
  assert(ovl);
  Decl* var = ovl->back();
  assert(var);

  // Construct a call to get port
  Expr* get_port = builtin.call_get_port(var,
    { make_cstr(d->name()->spelling().c_str()) });

  elab.elaborate(get_port);
  load_body.push_back(new Expression_stmt(get_port));

  return var;
}


Decl*
Lowerer::lower(Decl* d)
{
  return apply(d, Lower_decl_fn{*this});
}


void
Lowerer::add_builtin_functions()
{
  // declare all builtins
  for (auto pair : builtin.get_builtin_functions()) {
    declare(pair.second);
    prelude.push_back(pair.second);
  }
}


void
Lowerer::add_prelude()
{
  // declare all builtin functions
  add_builtin_functions();
}


Decl*
Lowerer::lower(Module_decl* d)
{
  Scope_sentinel scope(*this, d);

  // add prelude functions
  add_prelude();

  // declare all globals
  Lower_global_decl decls{*this};
  for (Decl* decl : d->declarations()) {
    apply(decl, decls);
  }

  // lower all globals
  Lower_global_def defs{*this};
  for (Decl* decl : d->declarations()) {
    Decl* lowered = apply(decl, defs);
    // discard layout declarations
    if (is<Layout_decl>(lowered))
      continue;

    module_decls.push_back(lowered);
  }

  // inject the forward declarations at
  // the beginning of the file.
  module_decls.insert(module_decls.begin(),
                      prelude.begin(), prelude.end());

  // Application interface functions
  module_decls.push_back(load_function());
  module_decls.push_back(process_function());
  module_decls.push_back(port_number_function());

  return new Module_decl(d->name(), module_decls);
}


Decl*
Lowerer::lower(Flow_decl* d)
{
  lingo_unreachable();
}


// -------------------------------------------------------------------------- //
//                    Lowering Statements



Stmt_seq
Lowerer::lower(Stmt* s)
{
  return apply(s, Lower_stmt_fn{*this});
}


// The lowering of a block statement
// causes the generation of a new block
// whose body is a concatenation of all lowered
// statements within the original block.
Stmt_seq
Lowerer::lower(Block_stmt* s)
{
  Stmt_seq stmts;

  for (auto stmt : s->statements()) {
    Stmt_seq new_stmts = lower(stmt);
    stmts.insert(stmts.end(), new_stmts.begin(), new_stmts.end());
  }

  // TODO: possibly check that these are still the same
  // statements and if they are just return the same block.
  Block_stmt* new_block = new Block_stmt(stmts);

  return { new_block };
}


// The lowering of an if stmt
// causes the lowering of its condition,
// and its branch
Stmt_seq
Lowerer::lower(If_then_stmt* s)
{
  Expr* condition = lower(s->condition());

  // this should only ever produce 1 stmt
  // otherwise there is an internal inconsistency
  Stmt* body = lower(s->body()).back();

  // create a new if statement
  If_then_stmt* ifthen = new If_then_stmt(condition, body);

  return { ifthen };
}


Stmt_seq
Lowerer::lower(If_else_stmt* s)
{
  Expr* condition = lower(s->condition());

  Stmt* true_branch = lower(s->true_branch()).back();
  Stmt* false_branch = lower(s->false_branch()).back();

  // create a new if statement
  If_else_stmt* ifelse = new If_else_stmt(condition, true_branch, false_branch);

  return { ifelse };
}


Stmt_seq
Lowerer::lower(Match_stmt* s)
{
  // lower the condition and each case
  // stmt in turn
  Expr* condition = lower(s->condition());

  Stmt_seq cases;

  // these should all be case statements
  for (auto c : s->cases()) {
    // these should all produce exactly one stmt
    Stmt* stmt = lower(c).back();
    cases.push_back(stmt);
  }

  Match_stmt* match = new Match_stmt(condition, cases);

  return { match };
}


// A case stmt lowering causes a lowering
// of its body. The label should be a Literal
// value which does not need lowering.
Stmt_seq
Lowerer::lower(Case_stmt* s)
{
  Stmt_seq body = lower(s->stmt());
  Case_stmt* c = new Case_stmt(s->label(), block(body));

  return { c };
}


Stmt_seq
Lowerer::lower(While_stmt* s)
{
  Expr* condition  = lower(s->condition());

  Stmt* body = lower(s->body()).back();

  While_stmt* whil = new While_stmt(condition, body);

  return { whil };
}


Stmt_seq
Lowerer::lower(Expression_stmt* s)
{
  Expr* expr = lower(s->expression());

  Expression_stmt* expr_stmt = nullptr;

  if (expr != s->expression())
    expr_stmt = new Expression_stmt(expr);
  else
    expr_stmt = s;

  return { expr_stmt };
}


Stmt_seq
Lowerer::lower_extracts_decl(Extracts_decl* d)
{
  // get the context from the decoder functionl
  Overload* ovl = unqualified_lookup(get_identifier(__context));
  Decl* cxt = ovl->back();

  // get the id from the pipeline checker
  int mapping = checker.get_field_mapping(d->name());

  Field_name_expr* field = as<Field_name_expr>(d->field());
  assert(field);

  // get the offset into the layout of the field
  Expr* offset = get_offset(field);

  // get the length of the field
  Expr* length = get_length(field);

  // create the binding call
  Expr_seq args
  {
    id(cxt),
    make_int(mapping),
    offset,
    length
  };
  Expr* bind_field = builtin.call_bind_field(args);
  bind_field = elab.elaborate(bind_field);
  Expr* cast = new Reinterpret_cast(bind_field, field->type());

  // Mangle the name of the variable from the name of the
  // extracted field. Declare it as a new variable.
  Symbol const* field_name = get_identifier(mangle(d));
  Variable_decl* load_var = new Variable_decl(field_name,
                                              cast->type(),
                                              cast);

  declare(load_var);

  Stmt_seq stmts {
    new Declaration_stmt(load_var)
  };

  return stmts;
}


// We change a rebind decl into a call to the
// implicit function __double_bind_offset(cxt, true_env_offset, aliased_env_offset, offsetof, lengthof)
//
// bind field1 as field2
//
// The aliased env offset is the number it would receive if its name was field2
// The true_env offset is the number it would receive if its name was field1
Stmt_seq
Lowerer::lower_rebind_decl(Rebind_decl* d)
{
  // get the context from the decoder functionl
  Overload* ovl = unqualified_lookup(get_identifier(__context));
  Decl* cxt = ovl->back();

  // get the id from the pipeline checker
  int mapping1 = checker.get_field_mapping(d->name());
  int mapping2 = checker.get_field_mapping(d->original());

  Field_name_expr* field = as<Field_name_expr>(d->field());
  assert(field);

  // get the offset into the layout of the field
  Expr* offset = get_offset(field);

  // get the length of the field
  Expr* length = get_length(field);

  // create the binding call
  Expr* bind_field = builtin.call_alias_bind( id(cxt),
                                              make_int(mapping1),
                                              make_int(mapping2),
                                              offset,
                                              length);
  bind_field = elab.elaborate(bind_field);
  Expr* cast = new Reinterpret_cast(bind_field, field->type());

  // Mangle the name of the variable from the name of the
  // extracted field. Declare it as a new variable.
  Symbol const* field_name = get_identifier(mangle(d));
  Variable_decl* load_var = new Variable_decl(field_name,
                                              cast->type(),
                                              cast);

  declare(load_var);

  Stmt_seq stmts {
    new Declaration_stmt(load_var)
  };

  return stmts;
}


Stmt_seq
Lowerer::lower(Declaration_stmt* s)
{
  Stmt_seq stmts;

  // These are exceptions to the lowering
  // process as they are declarations which
  // lower into call expressions instead of
  // other declarations

  // NOTE: We have to check rebind decl first since it inherits from
  // extracts decl and thus the cast to extracts decl would still succeed.
  if (Rebind_decl* rebind = as<Rebind_decl>(s->declaration())) {
    Stmt_seq l = lower_rebind_decl(rebind);
    stmts.insert(stmts.end(), l.begin(), l.end());
    return stmts;
  }

  if (Extracts_decl* extract = as<Extracts_decl>(s->declaration())) {
    Stmt_seq l = lower_extracts_decl(extract);
    stmts.insert(stmts.end(), l.begin(), l.end());
    return stmts;
  }

  // Regular lowering process for decl stmts
  if (Decl* decl = lower(s->declaration())) {
    if (decl != s->declaration())
      stmts.push_back(new Declaration_stmt(decl));
    else
      stmts.push_back(s);
  }

  return stmts;
}


Stmt_seq
Lowerer::lower(Decode_stmt* s)
{
  Stmt_seq stmts;

  // get the decoder function
  Overload* ovl = unqualified_lookup(s->decoder()->name());
  assert(ovl);
  Decl* fn = ovl->back();
  assert(fn);

  // get the context variable which should Always
  // be within the scope of a decoder body
  ovl = unqualified_lookup(get_identifier(__context));
  assert(ovl);
  Decl* cxt = ovl->back();
  assert(cxt);

  // form an advance based on the length of the header
  ovl = unqualified_lookup(get_identifier(__header));
  if (ovl) {
    Decl* header = ovl->back();
    Expr* length = get_length(header->type());
    Expr* advance = builtin.call_advance({ id(cxt), length });
    elab.elaborate(advance);

    stmts.push_back(new Expression_stmt(advance));
  }


  // form a call to the decoder
  Call_expr* call =
    new Call_expr(get_void_type(), id(fn), { id(cxt) });

  elab.elaborate(call);

  // return the call
  stmts.push_back(new Expression_stmt(call));
  return stmts;
}


Stmt*
Lowerer::goto_advance(Decl const* decoder)
{
  // get the decoder function
  Overload* ovl = unqualified_lookup(decoder->name());
  assert(ovl);
  Decl* fn = ovl->back();
  assert(fn);

  // get the context variable which should Always
  // be within the scope of a decoder body
  ovl = unqualified_lookup(get_identifier(__context));
  assert(ovl);
  Decl* cxt = ovl->back();
  assert(cxt);

  // form an advance based on the length of the header
  ovl = unqualified_lookup(get_identifier(__header));
  if (ovl) {
    Decl* header = ovl->back();
    Expr* length = get_length(header->type());
    Expr* advance = builtin.call_advance({ id(cxt), length });
    elab.elaborate(advance);
    return new Expression_stmt(advance);
  }

  throw Type_error({}, "Header type not found when generating goto.");
}


// Stmt*
// Lowerer::goto_get_key(Decl const* table)
// {
//   Table_decl const* t = as<Table_decl>(table);
//   Expr_seq key_mappings;
//
//   for (auto subkey : t->keys()) {
//     int mapping = checker.get_field_mapping(subkey->name());
//     key_mappings.push_back(new Literal_expr(get_integer_type(), mapping));
//   }
//
//   // get the context variable which should Always
//   // be within the scope of a decoder body
//   Overload* ovl = unqualified_lookup(get_identifier(__context));
//   assert(ovl);
//   Decl* cxt = ovl->back();
//   assert(cxt);
//
//   // TODO: fully support variable arguments to functions so that
//   // we can actually elaborate this without it failing.
//   Expr* gather = builtin.call_gather(decl_id(cxt), key_mappings);
//   Variable_decl* key = new Variable_decl(get_identifier("key"),
//                                          get_reference_type(get_key_type()),
//                                          gather);
//
//   declare(key);
//   return new Declaration_stmt(key);
// }


// NOTE: It is the current expectation that when the runtime
// goes to match the context against the table that it implicitly goes to
// compose the key from the fields provided as arguments in this function.
Stmt*
Lowerer::goto_match(Goto_stmt* s)
{
  // get the table function
  Overload* ovl = unqualified_lookup(s->table()->name());
  assert(ovl);
  Decl* tbl = ovl->back();
  assert(tbl);

  // get the context variable which should Always
  // be within the scope of a decoder body
  ovl = unqualified_lookup(get_identifier(__context));
  assert(ovl);
  Decl* cxt = ovl->back();
  assert(cxt);

  // get the key variable
  // ovl = unqualified_lookup(get_identifier("key"));
  // assert(ovl);
  // Decl* key = ovl->back();
  // assert(key);

  // produce the set of fields needed by the table.
  Table_decl const* t = as<Table_decl>(s->table());
  assert(t);
  Expr_seq key_mappings;
  for (auto subkey : t->keys()) {
    int mapping = checker.get_field_mapping(subkey->name());
    key_mappings.push_back(new Literal_expr(get_integer_type(), mapping));
  }

  // number of fields
  Expr* n = make_int(key_mappings.size());

  // produce the call
  Expr* match = builtin.call_match(decl_id(cxt), decl_id(tbl), n, key_mappings);
  // NOTE: Avoid elaboration again since we don't fully support variable args.
  // elab.elaborate(match);

  return new Expression_stmt(match);
}


// A goto stmt actually translates into three statements.
// It adds a call to advance() if the goto occurs within the context
// of a decoder.
//
// It adds a call to gather_key() which has the runtime build the key pointer.
//
// It applys a call to match which takes a key and a table and attempts to find
// a match. NOTE: The runtime should be responsible for handling the resources
// required by the key (like any dynamic allocation).
Stmt_seq
Lowerer::lower(Goto_stmt* s)
{
  Stmt_seq stmts;
  // produce an advance if its in a decoder
  // otherwise no advance is necessary
  if (is<Decode_decl>(s->context())) {
    stmts.push_back(goto_advance(s->context()));
  }

  // produce the call to get the key
  // stmts.push_back(goto_get_key(s->table()));

  // produce the call to match
  // pass the table and the key
  stmts.push_back(goto_match(s));

  return stmts;
}


Stmt_seq
Lowerer::lower(Action* s)
{
  lingo_unreachable();
}


Stmt_seq
Lowerer::lower(Drop* s)
{
  // get the context variable which should Always
  // be within the scope of a decoder body
  Overload* ovl = unqualified_lookup(get_identifier(__context));
  assert(ovl);
  Decl* cxt = ovl->back();
  assert(cxt);

  // make a call to the drop function
  Expr* drop = builtin.call_drop(decl_id(cxt));
  elab.elaborate(drop);

  return { new Expression_stmt(drop) };
}


Stmt_seq
Lowerer::lower(Output* s)
{
  // get the context variable which should Always
  // be within the scope of a decoder body
  Overload* ovl = unqualified_lookup(get_identifier(__context));
  assert(ovl);
  Decl* cxt = ovl->back();
  assert(cxt);

  // acquire the drop port
  // TODO: we;re not relly using this right now since we assume
  // drop is an intrinsic
  Symbol const* port_name = as<Decl_expr>(s->port())->declaration()->name();
  ovl = unqualified_lookup(port_name);
  assert(ovl);
  Decl* port = ovl->back();
  assert(port);

  // make a call to the drop function
  Expr* drop = builtin.call_output(decl_id(cxt), decl_id(port));
  elab.elaborate(drop);

  return { new Expression_stmt(drop) };
}


Stmt_seq
Lowerer::lower(Set_field* s)
{
  // get the context varaible
  Overload* ovl = unqualified_lookup(get_identifier(__context));
  assert(ovl);
  Decl* cxt = ovl->back();
  assert(cxt);

  // Set field translates to a function call to
  // fp_set_field, passing in the context, field id, and value.
  Field_access_expr* e = as<Field_access_expr>(s->field());
  assert(e);

  Expr* id = make_int(checker.get_field_mapping(e->name()));

  // convert the integer value into a byte array and pass it as a block
  // first evaluate it
  Evaluator ev;
  Value v = ev.eval(s->value());
  // get the integer value back
  // and store it in a buffer
  std::stringstream ss;
  ss << v.get_integer().decimal_str();
  uint512_t buf = 0;
  ss >> buf;

  // convert to a byte array
  // get the precision of the value
  int prec = precision(s->value()->type());
  char* bytes = new char[prec / 8];
  char* k = reinterpret_cast<char*>(&buf);
  std::copy(k, k + (prec / 8), bytes);

  Array_value arr { bytes, (size_t) prec / 8 };
  Type const* z = get_integer_type();
  // create the array length literal
  Expr* n = new Literal_expr(z, arr.len + 1);
  // Create the array type.
  Type const* c = get_character_type();
  Type const* t = get_array_type(c, n);

  // create the array literal
  Expr* val = new Literal_expr(t, arr);

  // create the call
  Expr* set_field = builtin.call_set_field(decl_id(cxt),
                                           id,
                                           make_int(prec / 8),
                                           val);
  elab.elaborate(set_field);

  return { new Expression_stmt(set_field) };
}


// -------------------------------------------------------------------------- //
// Declaration of entities


// Determine if d can be overloaded with the existing
// elements in the set.
void
Lowerer::overload(Overload& ovl, Decl* curr)
{
  // Check to make sure that curr does not conflict with any
  // declarations in the current overload set.
  for (Decl* prev : ovl) {
    // If the two declarations have the same type, this
    // is not overloading. It is redefinition.
    if (prev->type() == curr->type()) {
      std::stringstream ss;
      ss << "redefinition of " << *curr->name() << '\n';
      throw Type_error({}, ss.str());
    }

    if (!can_overload(prev, curr)) {
      std::stringstream ss;
      ss << "cannot overload " << *curr->name() << '\n';
      throw Type_error({}, ss.str());
    }
  }

  ovl.push_back(curr);
}


// Create a declarative binding for d. This also checks
// that the we are not redefining a symbol in the current
// scope.
void
Lowerer::declare(Decl* d)
{
  Scope& scope = stack.current();

  // Set d's declaration context.
  d->cxt_ = stack.context();

  // If we've already seen the name, we should
  // determine if it can be overloaded.
  if (Scope::Binding* bind = scope.lookup(d->name()))
    return overload(bind->second, d);

  // Create a new overload set.
  Scope::Binding& bind = scope.bind(d->name(), {});
  Overload& ovl = bind.second;
  ovl.push_back(d);
}


// When opening the scope of a previously declared
// entity, simply push the declaration into its
// overload set.
void
Lowerer::redeclare(Decl* d)
{
  Scope& scope = stack.current();
  Overload* ovl;
  if (Scope::Binding* bind = scope.lookup(d->name()))
    ovl = &bind->second;
  else
    ovl = &scope.bind(d->name(), {}).second;
  ovl->push_back(d);
}


// Perform lookup of an unqualified identifier. This
// will search enclosing scopes for the innermost
// binding of the identifier.
Overload*
Lowerer::unqualified_lookup(Symbol const* sym)
{
  if (Scope::Binding* bind = stack.lookup(sym))
    return &bind->second;
  else
    return nullptr;
}


// Perform a qualified lookup of a name in the given
// scope. This searches only that scope for a binding
// for the identifier.
Overload*
Lowerer::qualified_lookup(Scope* s, Symbol const* sym)
{
  if (Scope::Binding* bind = s->lookup(sym))
    return &bind->second;
  else
    return nullptr;
}

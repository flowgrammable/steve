#include "beaker/type.hpp"
#include "beaker/expr.hpp"
#include "beaker/decl.hpp"
#include "beaker/actions.hpp"
#include "beaker/lower.hpp"
#include "beaker/error.hpp"
#include "beaker/mangle.hpp"
#include "beaker/gather.hpp"
#include "beaker/evaluator.hpp"
#include "beaker/convert.hpp"

#include <iostream>

// Helper function for constructing
// identifier symbols
Symbol const*
Lowerer::get_identifier(std::string s)
{
  return elab.syms.put<Identifier_sym>(s, identifier_tok);
}


namespace
{

struct Lower_expr_fn
{
  Lowerer& lower;

  // Catch all case.
  // Simply return the original expression without lowering it.
  template<typename T>
  Expr* operator()(T* e) const { return e; }

  // Port expr.
  Expr* operator()(Port_expr* e) const { return lower.lower(e); }

  // Unary expressions
  Expr* operator()(Neg_expr* e) const { return lower.lower_unary_expr(e); }
  Expr* operator()(Pos_expr* e) const { return lower.lower_unary_expr(e); }
  Expr* operator()(And_expr* e) const { return lower.lower_unary_expr(e); }
  Expr* operator()(Or_expr* e) const { return lower.lower_unary_expr(e); }
  Expr* operator()(Not_expr* e) const { return lower.lower_unary_expr(e); }

  // Binary Expressions
  Expr* operator()(Add_expr* e) const { return lower.lower_binary_expr(e); }
  Expr* operator()(Sub_expr* e) const { return lower.lower_binary_expr(e); }
  Expr* operator()(Mul_expr* e) const { return lower.lower_binary_expr(e); }
  Expr* operator()(Div_expr* e) const { return lower.lower_binary_expr(e); }
  Expr* operator()(Rem_expr* e) const { return lower.lower_binary_expr(e); }
  Expr* operator()(Lshift_expr* e) const { return lower.lower_binary_expr(e); }
  Expr* operator()(Rshift_expr* e) const { return lower.lower_binary_expr(e); }
  Expr* operator()(Bitwise_or_expr* e) const { return lower.lower_binary_expr(e); }
  Expr* operator()(Bitwise_and_expr* e) const { return lower.lower_binary_expr(e); }
  Expr* operator()(Xor_expr* e) const { return lower.lower_binary_expr(e); }
  Expr* operator()(Eq_expr* e) const { return lower.lower_binary_expr(e); }
  Expr* operator()(Ne_expr* e) const { return lower.lower_binary_expr(e); }
  Expr* operator()(Lt_expr* e) const { return lower.lower_binary_expr(e); }
  Expr* operator()(Gt_expr* e) const { return lower.lower_binary_expr(e); }
  Expr* operator()(Le_expr* e) const { return lower.lower_binary_expr(e); }
  Expr* operator()(Ge_expr* e) const { return lower.lower_binary_expr(e); }

  // Lower a call
  Expr* operator()(Call_expr* e) const { return lower.lower(e); }

  // We should lower initializers so you can write something like:
  //    var x : int = eth::type;
  Expr* operator()(Copy_init* e) const { return lower.lower_unary_expr(e); }
  Expr* operator()(Reference_init* e) const { return lower.lower_unary_expr(e); }

  // Value conversions.
  Expr* operator()(Value_conv* e) const { return lower.lower_unary_expr(e); }
  Expr* operator()(Promotion_conv* e) const { return lower.lower_unary_expr(e); }
  Expr* operator()(Demotion_conv* e) const { return lower.lower_unary_expr(e); }
  Expr* operator()(Sign_conv* e) const { return lower.lower_unary_expr(e); }

  // Field access expr becomes an id_expr whose declaration is
  // resolved against a variable created by lowering the extracts decl.
  Expr* operator()(Field_access_expr* e) const { return lower.lower(e); }

  // Inport and inphys port turn into calls to fetch those fields out of
  // the context.
  Expr* operator()(Inport_expr* e) const { return lower.lower(e); }
  Expr* operator()(Inphysport_expr* e) const { return lower.lower(e); }
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

  // Local Variables.
  Decl* operator()(Variable_decl* d) const { return lower.lower(d); }
};


struct Lower_stmt_fn
{
  Lowerer& lower;

  // catch all case
  template<typename T>
  Stmt_seq operator()(T* s) const { return { s }; }

  Stmt_seq operator()(Assign_stmt* s) const { return lower.lower(s); }
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
  Stmt_seq operator()(Output_egress* s) const { return lower.lower(s); }
  Stmt_seq operator()(Flood* s) const { return lower.lower(s); }
  Stmt_seq operator()(Clear* s) const { return lower.lower(s); }
  Stmt_seq operator()(Set_field* s) const { return lower.lower(s); }
  Stmt_seq operator()(Insert_flow* s) const { return lower.lower(s); }
  Stmt_seq operator()(Remove_flow* s) const { return lower.lower(s); }
  Stmt_seq operator()(Write_drop* s) const { return lower.lower(s); }
  Stmt_seq operator()(Write_output* s) const { return lower.lower(s); }
  Stmt_seq operator()(Write_flood* s) const { return lower.lower(s); }
  Stmt_seq operator()(Write_set_field* s) const { return lower.lower(s); }
  Stmt_seq operator()(Raise* s) const { return lower.lower(s); }
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
  Decl* operator()(Event_decl* d) const { return l.lower_global_decl(d); }
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
  Decl* operator()(Event_decl* d) const { return l.lower_global_def(d); }
};

} // namespace



// -------------------------------------------------------------------------- //
// Application interface

// This is the function called when the dataplane wants configuration information
// upon loading the application.
Function_decl*
Lowerer::load_function()
{
  Type const* void_type = get_void_type();
  auto p1 = new Parameter_decl(get_identifier("dp"), get_opaque_type()->ref());
  Decl_seq parms {
    p1
  };

  Type const* fn_type = get_function_type(parms, void_type);
  Symbol const* fn_name = get_identifier(__load);

  // The Load function should save a pointer to the dataplane that is loading it.
  // Construct a global variable of opaque dataplane type.
  Overload* ovl = unqualified_lookup(get_identifier(__dataplane));
  assert(ovl);
  Decl* dp = ovl->back();
  assert(dp);

  // In the load body, set the dp global variable to be equal to the pointer
  // passed in the parameter.
  //
  // The parameter should be directly stored into the global variable.
  Expr* set_dp = builtin.call_get_dataplane(p1, dp);
  load_body.insert(load_body.begin(), statement(set_dp));

  // Construct the load function with the accumulated load_body.
  Function_decl* load = new Function_decl(fn_name, fn_type,
                                          parms, block(load_body));

  load->spec_ |= extern_spec;
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
  process_body.push_back(statement(call));

  process->spec_ |= extern_spec;

  process->body_ = block(process_body);

  return process;
}


// Returns the amount of ports specifically asked for by the application.
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

  fn->spec_ |= extern_spec;

  return fn;
}


// Maintain a pointer to the dataplane that this application has been loaded
// by.
Variable_decl*
Lowerer::dataplane_pointer()
{
  static Variable_decl dp(get_identifier(__dataplane),
                          get_opaque_type()->ref(),
                          new Default_init(get_opaque_type()->ref()));
  declare(&dp);
  return &dp;
}


// ------------------------------------------------------------------------- //
//                    Lower Expressions


template <typename T>
Expr* Lowerer::lower_unary_expr(T* e)
{
  Expr* first = lower(e->first);
  e->first = first;
  return e;
}


template <typename T>
Expr*
Lowerer::lower_binary_expr(T* e)
{
  Expr* first = lower(e->first);
  assert(first);
  Expr* second = lower(e->second);
  assert(second);
  e->first = first;
  e->second = second;
  return e;
}


Expr*
Lowerer::lower(Expr* e)
{
  return apply(e, Lower_expr_fn{*this});
}


// Lowering a port expr returns the identifier to the
// global variable created for that port.
Expr*
Lowerer::lower(Port_expr* e)
{
  // Lookup the new port variable declaration.
  Overload* ovl = unqualified_lookup(e->name());
  assert(ovl);

  Decl* p = ovl->back();
  assert(is<Port_type>(p->type()->nonref()));

  e->decl = p;

  Expr* i = id(p);
  return elab.elaborate(i);
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
Lowerer::lower(Call_expr* e)
{
  Expr_seq args;
  // Lower all of the arguments.
  for (auto a1 : e->arguments()) {
    Expr* a = lower(a1);
    args.push_back(a);
  }

  e->second = args;
  return e;
}


// NOTE: Field access expressions always recover the value from the last
// extracted instance of a field. This is a valid operation in both decoders
// and tables and should not provoke unexpected behaviour.
//
// Within decoders, you can only access fields that have been extracted in that
// decoder, so this is a safe operation.
//
// Tables ALWAYS match on the most recently extracted fields. Any field access
// expr which occur within the flows, thus, by definition, refer to the most
// recently extracted values for those fields.
Expr*
Lowerer::lower(Field_access_expr* e)
{
  // create the mangled variable name
  Symbol const* name = get_identifier(mangle(e));

  // Look for the local variable created with the extracts declaration.
  // If it has a non-default initializer (i.e. its been set with the result)
  // of lowering a Field access expr already, then simply return it.
  //
  // Otherwise, if its a default initializer, replace the default initializer
  // with the call to fp_read_field(cxt, mapping).
  Overload* ovl = unqualified_lookup(name);
  assert(ovl);
  // This variable should be guaranteed to exist since the elaboration phase
  // prevents the use of field access expressions without extracts decls or key
  // decls.
  Variable_decl* var = as<Variable_decl>(ovl->back());
  assert(var);

  // If the variable has not been initialized with a call to read_field()
  // then replace its initializer.
  //
  // This is an optimization to prevent a call to read_field() every time
  // a field access expression is needed.
  //
  // Instead we just read from the local variable which should contain an
  // update value from that field.
  //
  // Set_field() and Copy_field() are expected to update that local variable as
  // well, so any changes to that field in the context cause updates to the local
  // variable instead of creating a new call to read_field() from the runtime.
  // This should reduce the number of crosses between the runtime barrier.

  if (is<Default_init>(var->init())) {
    // This should always be valid since flows and decoders have an implicit
    // context parameter.
    ovl = unqualified_lookup(get_identifier(__context));
    assert(ovl);
    Decl* cxt = ovl->back();
    assert(cxt);

    // get the integer mapping for the field
    int mapping = checker.get_field_mapping(e->name());

    // cast the variable which will hold the result into a i8*
    Expr* cast = new Void_cast(decl_id(var));

    // produce the call
    Expr* read_field = builtin.call_read_field(decl_id(cxt), make_int(mapping), cast);

    // Reinterpret the bits of the return back into the appropriate type.
    cast = new Reinterpret_cast(read_field, e->type()->nonref());

    var->init_ = cast;
  }

  // If the variable has already been initialized with a call to read field
  // then just return an identifier to the variable.
  return decl_id(var);
}


// Lowering an inport passes the context to a runtime and requests back
// the inport id.
Expr*
Lowerer::lower(Inport_expr* e)
{
  Overload* ovl = unqualified_lookup(get_identifier(__context));
  assert(ovl);
  Decl* cxt = ovl->back();
  assert(cxt);

  // Make a call to get_in_port
  Expr* port = builtin.call_get_in_port(id(cxt));
  elab.elaborate(port);

  return port;
}


// Lowering an inphysport passes the context to a runtime and requests back
// the inphysport id.
Expr*
Lowerer::lower(Inphysport_expr* e)
{
  Overload* ovl = unqualified_lookup(get_identifier(__context));
  assert(ovl);
  Decl* cxt = ovl->back();
  assert(cxt);

  // Make a call to get_in_port
  Expr* port = builtin.call_get_in_phys_port(id(cxt));
  elab.elaborate(port);

  return port;
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


// Every table needs its own key forming function
// in order to support adding and removing flow entries
// during runtime using non-static values.
//
// For example add {x, y, z} -> {...} into t1
// can only work if there is a function to compose non-static x, y, and z
// into a single key which can be passed to the runtime.
//
// TODO: Refactor into parm and body components.
void
Lowerer::produce_key_function(Table_decl* d)
{
  auto table_type = as<Table_type>(d->type());


  // Produce a name for the key function.
  // Combination of "__KEYFORM_" followed by the table name.
  static std::string kf = __keyform;
  std::string n = kf + d->name()->spelling();
  Symbol const* fn_name = get_identifier(n);

  // The precision of the return type.
  int ret_p = 0;

  // The parameters.
  Decl_seq parms;

  for (auto f : table_type->field_names()) {
    // Create the parameter.
    // The parameters have the same respective types as the keys.
    parms.push_back(new Parameter_decl(f->name(), f->type()));

    // Add to the precision of the return type.
    ret_p += precision(f->type());
  }

  // The return type is an integer with precision equal to the sum of all
  // precisions of the field types.
  Type const* ret_type = get_integer_type(ret_p, unsigned_int, native_order);

  // Produce the function type.
  Type const* fn_type = get_function_type(parms, ret_type);

  // Produce the function body.
  Stmt_seq body;
  // Maintain a count of temporary variables.
  int vc = 0;
  // Maintain the precision of the prior parameter.
  int pprec = 0;
  // Create a variable to hold the return value.
  Variable_decl* retv =
    new Variable_decl(get_identifier("retv"), ret_type, new Default_init(ret_type));
  body.push_back(statement(retv));

  // Create the instructions necessary to compose the key.
  for (auto p : parms) {
    // First we must create a variable with the precision of the
    // return type.
    //
    // The name we give it is an internal name.
    Variable_decl* v = temp_var(elab.syms, ret_type, new Default_init(ret_type));
    body.push_back(statement(v));

    // Bitwise-And the variable with the parameter.
    Expr* bor = new Bitwise_or_expr(id(v), id(p));
    // Assign the result to the variable.
    Assign_stmt* assign = new Assign_stmt(id(v), bor);
    body.push_back(assign);

    // Shift by the precision of the prior and then bitwise-and it with the
    // return value.
    //
    // FIXME: Only shift if the number of bits shifted is greater than 0
    Expr* lshift = new Lshift_expr(id(v), make_int(pprec));
    // Bitwise-and with result.
    Expr* or_retv = new Bitwise_or_expr(id(retv), lshift);
    // Assign to the retv
    assign = new Assign_stmt(id(retv), or_retv);
    body.push_back(assign);

    // Set the prior precision to the sum of the current parameter's precision
    // and the prior.
    pprec += precision(p->type());

    // Update temp variable counter.
    ++vc;
  }

  // Create the return statement.
  Stmt* ret = new Return_stmt(id(retv));
  body.push_back(ret);

  // Create the function.
  Function_decl* fn =
    new Function_decl(fn_name, fn_type, parms, block(body));

  // Add the function to the list of key forming functions.
  key_functions.push_back(fn);
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

  // This variable should be initialized during the load function
  declare(table);

  // Produce a static key forming function for every table.
  produce_key_function(d);

  return d;
}


Decl*
Lowerer::lower_global_decl(Port_decl* d)
{
  port_count++;

  // this should be a port pointer
  // not a port object
  Variable_decl* port = new Variable_decl(d->name(),
                                          d->type(),
                                          new Default_init(d->type()));

  declare(port);
  return port;
}


// Event declarations get lowered into functions as well.
// These get passed to the runtime with the context
// whenever a raise action is used.
Decl*
Lowerer::lower_global_decl(Event_decl* d)
{
  // declare an implicit context variable
  Type const* cxt_ref = get_context_type()->ref();
  Parameter_decl* cxt = new Parameter_decl(get_identifier(__context), cxt_ref);

  // The type of all events is fn(Context&) -> void
  Function_decl* fn = new Function_decl(d->name(), d->type(), {cxt}, d->body());

  declare(fn);

  return fn;
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
  fn->spec_ |= extern_spec;

  // bind the header into the context with its id
  Layout_type const* ltype = as<Layout_type>(d->header());
  Layout_decl* ldecl = as<Layout_decl>(ltype->declaration());
  Expr* id = make_int(checker.get_header_mapping(ldecl));
  Expr* len = get_length(ltype);
  Expr* bind = builtin.call_bind_header(decl_id(cxt), id, len);

  // attach the bind header call to the body
  Block_stmt* block = as<Block_stmt>(body);
  block->first.insert(block->first.begin(), statement(bind));

  // register the starting decoder
  if (d->is_start())
    start_fn = fn;

  return fn;
}



// Lowering the body of a flow handles any special transformations needed
// for a flow to become a function.
//
// This currently includes allocated local variables so key values may be
// accessed inside the scope of the flow function.
Stmt*
Lowerer::lower_flow_body(Table_decl* d, Stmt* s)
{
  Stmt_seq body;
  // Allocate variables corresponding to every key so that their value
  // can be recovered in the flow function.
  for (auto decl : d->keys()) {
    Symbol const* name = get_identifier(mangle(decl));
    Variable_decl* load_var =
      new Variable_decl(name, decl->type(), new Default_init(decl->type()));

    declare(load_var);

    body.push_back(statement(load_var));
  }

  // Allocate variables corresponding to every requirement so that their
  // value can be recovered in the flow function.
  for (auto r : d->requirements()) {
    Field_name_expr* fld = as<Field_name_expr>(r);
    assert(fld);
    Symbol const* name = get_identifier(mangle(fld));

    if (!unqualified_lookup(name)) {
      Variable_decl* load_var =
        new Variable_decl(name, fld->type(), new Default_init(fld->type()));
      declare(load_var);
      body.push_back(statement(load_var));
    }
  }

  // Insert the allocated variables to the beginning of the body.
  Stmt* l = lower(s).back();
  Block_stmt* flow_body = as<Block_stmt>(l);
  assert(flow_body);
  body.insert(body.end(), flow_body->statements().begin(), flow_body->statements().end());
  l = block(body);

  return l;
}


// Lower a flow within a table and construct the necessary flow function
// required by the runtime system.
Function_decl*
Lowerer::lower_init_flow(Table_decl* t, Flow_decl* flow)
{
  Type const* cxt_ref = get_context_type()->ref();
  Type const* tbl_ref = opaque_table->ref();
  Type const* flow_ref = get_opaque_type()->ref();
  Type const* void_type = get_void_type();

  // Create parameters common to all flow functions.
  //
  // Flow functions take an implicit 'this' parameter to their flow data.
  // Flow functions take a context to process.
  // Flow functions take a reference to their containing table.
  Parameter_decl* flw = new Parameter_decl(get_identifier(__flow_self), flow_ref);
  Parameter_decl* cxt = new Parameter_decl(get_identifier(__context), cxt_ref);
  Parameter_decl* tbl = new Parameter_decl(get_identifier(__table), tbl_ref);
  Decl_seq parms { flw, tbl, cxt };

  // The type of all flows is fn(Table&, Context&) -> void
  Type const* type = get_function_type(parms, void_type);

  Symbol const* flow_name = flow->name();

  // Enter flow function scope.
  Scope_sentinel scope(*this, flow);

  // declare an implicit flow, context and table variable
  declare(flw);
  declare(cxt);
  declare(tbl);

  // Contruct the body from the instructions.
  // Trust that the lowering process correctly elaborates the body so
  // its not necessary to do so again.
  //
  // Each flow body should allocate space for every local variable (related to keys).
  // Handle any additional modifications to the flow body.
  Stmt* flow_body = lower_flow_body(t, flow->instructions());

  // Produce the flow function.
  Function_decl* fn = new Function_decl(flow_name, type, parms, flow_body);

  // Make sure it has external linkage.
  fn->spec_ |= extern_spec;

  return fn;
}


Decl*
Lowerer::lower_miss_case(Table_decl* d)
{
  // Lower the miss case if there is one
  if (d->miss_case()) {
    Type const* cxt_ref = get_context_type()->ref();
    Type const* tbl_ref = opaque_table->ref();
    Type const* flow_ref = get_opaque_type()->ref();
    Type const* void_type = get_void_type();

    // declare an implicit context variable
    Parameter_decl* flw = new Parameter_decl(get_identifier(__flow_self), flow_ref);
    Parameter_decl* cxt = new Parameter_decl(get_identifier(__context), cxt_ref);
    Parameter_decl* tbl = new Parameter_decl(get_identifier(__table), tbl_ref);
    Decl_seq parms { flw, tbl, cxt };

    // The type of all flows is fn(Context&) -> void
    Type const* type = get_function_type(parms, void_type);

    Flow_decl* flow = as<Flow_decl>(d->miss_case());
    Symbol const* flow_name = flow->name();

    Scope_sentinel scope(*this, flow);
    declare(flw);
    declare(cxt);
    declare(tbl);

    // Trust that the lowering process correctly elaborates all the statements
    // so we don't have to elaborate again.
    Stmt* flow_body = lower_flow_body(d, flow->instructions());

    Function_decl* fn = new Function_decl(flow_name, type, parms, flow_body);
    fn->spec_ |= extern_spec;

    return fn;
  }

  // If no miss case exists.
  return nullptr;
}


Flow_properties
Lowerer::lower_flow_properties(Flow_decl* f)
{
  auto p = f->properties();

  // Lower the expressions comprising each property.
  // If that property was not set, set it to the default
  // vaulue associated with that property.

  // Handle the timeout property.
  // The default value for timeout is 0.
  // NOTE: We should make the runtime timeout flows at 1 so we can
  // reserve 0 for the "never timeout" value.
  if (!p.timeout)
    p.timeout = zero();
  else {
    p.timeout = elab.elaborate(lower(p.timeout));
    p.timeout = convert_to_value(p.timeout);
  }

  // Handle the egress property.
  // The default port id for egress is 0 which is a non-existant port
  // but it should be impossible to call output egress without setting the
  // egress property to a valid port, so this shouldn't matter.
  if (!p.egress)
    p.egress = zero();
  else {
    p.egress = elab.elaborate(lower(p.egress));
    p.egress = convert_to_value(p.egress);
  }

  // Update the flow properties.
  f->prop_ = p;

  return p;
}


// 'table' is a global variable declaration which retains the pointer to the
// table received via the runtime.
//
// 'flow_fns' are a sequence of lowered flows (aka regular functions of
// type: (Flow*, Table*, Context*)->void ).
//
// 'miss' is a pointer to the lowered miss function.
//
// 'keys' are the block literals statically created to be passed as keys
// to the runtime. Right now these are character arrays but they should be
// changed to something else.
void
Lowerer::add_init_flows(Table_decl* table)
{
  // return the variable declaration of the table
  Overload* ovl = unqualified_lookup(table->name());
  assert(ovl);
  Decl* tblptr = ovl->back();
  assert(tblptr);

  // Find the appropriate key forming function.
  std::string fn_name = __keyform + table->name()->spelling();
  ovl = unqualified_lookup(get_identifier(fn_name));
  assert(ovl);
  Decl* key_fn = ovl->back();
  assert(key_fn);

  Decl_seq const& flows = table->body();

  for (auto f : flows) {
    Flow_decl* flow = as<Flow_decl>(f);

    Function_decl* flow_fn = lower_init_flow(table, flow);
    declare(flow_fn);
    module_decls.push_back(flow_fn);

    // Form a call to construct the key during runtime.
    Expr_seq keys;
    // Lower all keys first.
    for (auto e : flow->keys()) {
      keys.push_back(lower(e));
    }
    Expr* call = new Call_expr(id(key_fn), keys);
    elab.elaborate(call);
    Variable_decl* temp = temp_var(elab.syms, call->type(), call);
    // Void cast the result of forming the key.
    Expr* vcast = new Void_cast(decl_id(temp));

    // Produce the properties parameters.
    Flow_properties prop = lower_flow_properties(flow);

    // Make a call to fp_add_flow.
    // NOTE: that function pointers don't actually work so this skips
    // re-elaboration.
    Expr* add_flow =
      builtin.call_add_init_flow(decl_id(tblptr), decl_id(flow_fn), vcast,
                                 prop.timeout, prop.egress);

    // elab.elaborate(add_flow);
    load_body.push_back(statement(temp));
    load_body.push_back(statement(add_flow));
  }

  // Handle the miss case
  Decl* miss = lower_miss_case(table);
  if (miss) {
    declare(miss);
    module_decls.push_back(miss);
    // Produce the properties parameters.
    Flow_properties prop =
      lower_flow_properties(as<Flow_decl>(table->miss_case()));

    Expr* add_miss =
      builtin.call_add_miss(decl_id(tblptr), decl_id(miss),
                            prop.timeout, prop.egress);

    load_body.push_back(statement(add_miss));
  }
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
  Decl* tblptr = ovl->back();
  assert(tblptr);

  ovl = unqualified_lookup(get_identifier(__dataplane));
  assert(ovl);
  Expr* dp = decl_id(ovl->back());
  assert(ovl->back());

  // We need the global variable storing the dataplane pointer which is
  // set when the config() function is called.

  Scope_sentinel scope(*this, d);

  // generate the call to get_table
  Expr* id_no = make_int(d->number());
  Expr* key_len = get_length(d->keys());
  // FIXME: actually have syntax for saying how many
  // flows are allowed in a table. Do this right!
  Expr* num_flows = make_int(1000);
  Expr* table_kind = make_int(d->kind());
  Expr* get_table = builtin.call_create_table(tblptr, dp, id_no, key_len,
                                             num_flows, table_kind );

  // We do special generation for calls to create table
  // because regular assignment does not work with opaque types
  // since the load causes an object of that type to be made,
  // of course you can't have an object of that type because
  // it is opaque and you have no type info about it.
  elab.elaborate(get_table);
  load_body.push_back(statement(get_table));

  // Add the rest of init flows to the table.
  add_init_flows(d);

  return tblptr;
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
    make_cstr(d->name()->spelling().c_str()), d->address());

  // Construct the assigment.
  Assign_stmt* a = new Assign_stmt(id(var), get_port);
  elab.elaborate(a);

  load_body.push_back(a);

  return var;
}


Decl*
Lowerer::lower_global_def(Event_decl* d)
{
  // Lookup the new function.
  Overload* ovl = unqualified_lookup(d->name());
  assert(ovl);
  Function_decl* fn = as<Function_decl>(ovl->back());
  assert(fn);

  // enter a scope
  Scope_sentinel scope(*this, d);

  // The new body for the function.
  Block_stmt* body = as<Block_stmt>(d->body());

  // Allocate variables corresponding to every field required so that their value
  // can be recovered in the flow function.
  for (auto f : d->requirements()) {
    Field_name_expr* fld = as<Field_name_expr>(f);
    assert(fld);
    Symbol const* name = get_identifier(mangle(fld));
    Variable_decl* load_var =
      new Variable_decl(name, fld->type(), new Default_init(fld->type()));

    body->first.insert(body->statements().begin(), statement(load_var));
  }

  // declare all parameters again
  // NOTE: this declares the context parameter
  for (auto parm : fn->parameters()) {
    declare(parm);
  }

  // get the context varaible
  ovl = unqualified_lookup(get_identifier(__context));
  assert(ovl);
  Decl* cxt = ovl->back();
  assert(cxt);

  // Lower the body and change the definition of the function.
  Stmt* b = lower(d->body()).back();

  fn->body_ = b;
  fn->spec_ |= extern_spec;

  return fn;
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
Lowerer::add_builtin_variables()
{
  prelude.push_back(dataplane_pointer());
}


void
Lowerer::add_prelude()
{
  // declare all builtin functions
  add_builtin_functions();
  add_builtin_variables();
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

  // Declare all key forming functions formed when
  // lowering the declarations of tables.
  for (auto fn : key_functions)
  {
    elab.elaborate_decl(fn);
    elab.elaborate_def(fn);
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

  // inject the forward declarations of runtime functions at
  // the beginning of the file.
  module_decls.insert(module_decls.begin(),
                      prelude.begin(), prelude.end());

  // Inject the key forming functions.
  module_decls.insert(module_decls.begin(),
                      key_functions.begin(), key_functions.end());

  // Application interface functions
  module_decls.push_back(load_function());
  module_decls.push_back(process_function());
  module_decls.push_back(port_number_function());

  return new Module_decl(d->name(), module_decls);
}


// All lowering of flows is done alongside the lowering of their
// containing tables.
Decl*
Lowerer::lower(Flow_decl* d)
{
  lingo_unreachable();
}


Decl*
Lowerer::lower(Variable_decl* d)
{
  declare(d);
  Expr* init = lower(d->init());
  d->init_ = init;
  return d;
}


// -------------------------------------------------------------------------- //
//                    Lowering Statements



Stmt_seq
Lowerer::lower(Stmt* s)
{
  return apply(s, Lower_stmt_fn{*this});
}


// Lowering the lhs lets you assign field-access-expr to existing variables.
Stmt_seq
Lowerer::lower(Assign_stmt* s)
{
  s->second = lower(s->value());
  assert(s->second);
  return { s };
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
  Stmt*    miss = nullptr;

  // these should all be case statements
  for (auto c : s->cases()) {
    // these should all produce exactly one stmt
    Stmt* stmt = lower(c).back();
    cases.push_back(stmt);
  }

  if (s->has_miss())
    miss = lower(s->miss()).back();

  Match_stmt* match = new Match_stmt(condition, cases, miss);

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
    expr_stmt = statement(expr);
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

  // emit a local variable
  Symbol const* name = get_identifier(mangle(d));
  Variable_decl* load_var = new Variable_decl(name,
                                              d->type(),
                                              new Default_init(d->type()));
  declare(load_var);

  return
  {
    statement(bind_field),
    statement(load_var)
  };
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
  // NOTE: The original mapping is the binding it WOULD HAVE been given
  // if this were a regular extract.
  int alias = checker.get_field_mapping(d->name());
  int original = checker.get_field_mapping(d->original());

  Field_name_expr* field = as<Field_name_expr>(d->field());
  assert(field);

  // get the offset into the layout of the field
  Expr* offset = get_offset(field);

  // get the length of the field
  Expr* length = get_length(field);

  // create the binding call
  Expr* bind_field = builtin.call_alias_bind( id(cxt),
                                              make_int(original),
                                              make_int(alias),
                                              offset,
                                              length);
  bind_field = elab.elaborate(bind_field);

  // Mangle the name of the variable from the name of the
  // extracted field. Declare it as a new variable.
  Symbol const* field_name = get_identifier(mangle(d));
  Variable_decl* load_var = new Variable_decl(field_name,
                                              d->type(),
                                              new Default_init(d->type()));

  declare(load_var);

  Stmt_seq stmts {
    statement(bind_field),
    statement(load_var)
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
      stmts.push_back(statement(decl));
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

  // Form an advance based on the length of the header.
  //
  // NOTE: This will only occur if within the context of a decode
  // declaration because this implicit header variable used to recover
  // the header information only gets declared within decoder declarations.
  ovl = unqualified_lookup(get_identifier(__header));
  if (ovl) {
    Decl* header = ovl->back();
    Expr* length = get_length(header->type());
    Expr* advance = builtin.call_advance({ id(cxt), length });
    elab.elaborate(advance);

    stmts.push_back(statement(advance));
  }


  // form a call to the decoder
  Call_expr* call =
    new Call_expr(get_void_type(), id(fn), { id(cxt) });

  elab.elaborate(call);

  // return the call
  stmts.push_back(statement(call));

  // Decodes should cause implicit returns. Once control of the packet
  // is transfered to a decode stage, its impossible to guarantee that any
  // statements occuring after it in the function are safe.
  stmts.push_back(return_void());

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
    return statement(advance);
  }

  throw Type_error({}, "Header type not found when generating goto.");
}


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

  return statement(match);
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

  // Gotos should cause a return. We don't know what
  // can happen to a packet after its been dispatched to
  // another function so any statements that occur after a goto
  // could cause undefined behavior.
  stmts.push_back(return_void());

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

  // Drops should cause an implicit return void. After a drop, any statements
  // after can not be guaranteed to be safe since the context has likely been
  // deleted by then.
  return
  {
    statement(drop),
    return_void()
  };
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

  // Acquire the port.
  Expr* port = lower(s->port());
  // make a call to the output function
  Expr* output = builtin.call_output(decl_id(cxt), port);
  elab.elaborate(output);

  // Outputs should cause an implicit return void for the same reason as drops.
  // No safety guarantees exist after a packet has been outputted.

  return
  {
    statement(output),
    return_void()
  };
}


Stmt_seq
Lowerer::lower(Output_egress* s)
{
  // get the context variable which should Always
  // be within the scope of a decoder body
  Overload* ovl = unqualified_lookup(get_identifier(__context));
  assert(ovl);
  Decl* cxt = ovl->back();
  assert(cxt);

  // Acquire the port.
  // Make a call to the flow to get its inport field and resolve it into
  // a Port*.
  ovl = unqualified_lookup(get_identifier(__flow_self));
  assert(ovl);
  Decl* self = ovl->back();
  assert(self);

  Expr* egress = builtin.call_get_flow_egress(decl_id(self));

  // make a call to the output function
  Expr* output = builtin.call_output(decl_id(cxt), egress);
  elab.elaborate(output);

  // Outputs should cause an implicit return void for the same reason as drops.
  // No safety guarantees exist after a packet has been outputted.
  return
  {
    statement(output),
    return_void()
  };
}


Stmt_seq
Lowerer::lower(Flood* s)
{
  // get the context variable which should Always
  // be within the scope of a decoder body
  Overload* ovl = unqualified_lookup(get_identifier(__context));
  assert(ovl);
  Decl* cxt = ovl->back();
  assert(cxt);

  // make a call to the drop function
  Expr* flood = builtin.call_flood(decl_id(cxt));
  elab.elaborate(flood);

  // Drops should cause an implicit return void. After a drop, any statements
  // after can not be guaranteed to be safe since the context has likely been
  // deleted by then.
  return
  {
    statement(flood),
    return_void()
  };
}


Stmt_seq
Lowerer::lower(Clear* s)
{
  // get the context variable which should Always
  // be within the scope of a decoder body
  Overload* ovl = unqualified_lookup(get_identifier(__context));
  assert(ovl);
  Decl* cxt = ovl->back();
  assert(cxt);

  // make a call to the clear function
  Expr* clear = builtin.call_clear(decl_id(cxt));
  elab.elaborate(clear);

  return
  {
    statement(clear),
  };
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

  // Lower the value first to ensure it can be evaluated.
  s->value_ = lower(s->value_);

  // Store the value into the local variable used to save values for extracted
  // fields.
  //
  // NOTE: Set field should update the local variable that can be accessed
  // using field access expressions.
  ovl = unqualified_lookup(get_identifier(mangle(e)));
  assert(ovl);
  Decl* fld_var = ovl->back();
  Assign_stmt* assign = new Assign_stmt(decl_id(fld_var), s->value());


  // Convert the value into a byte array and pass it as an i8*.
  int prec = precision(s->value()->type());
  auto val = expr_to_void_block(decl_id(fld_var));

  // Create the call, passing in the value as an i8* to the runtime.
  Expr* set_field = builtin.call_set_field(decl_id(cxt),
                                           id,
                                           make_int(prec / 8),
                                           val);
  elab.elaborate(set_field);

  return {
    assign,
    statement(set_field)
  };
}



Decl*
Lowerer::construct_added_flow(Table_decl* table, Flow_decl* flow)
{
  Type const* cxt_ref = get_context_type()->ref();
  Type const* tbl_ref = opaque_table->ref();
  Type const* flw_ref = get_opaque_type()->ref();
  Type const* void_type = get_void_type();

  // Create parameters common to all
  Parameter_decl* flw = new Parameter_decl(get_identifier(__flow_self), flw_ref);
  Parameter_decl* cxt = new Parameter_decl(get_identifier(__context), cxt_ref);
  Parameter_decl* tbl = new Parameter_decl(get_identifier(__table), tbl_ref);
  Decl_seq parms { flw, tbl, cxt };

  // The type of all flows is fn(Table&, Context&) -> void
  Type const* type = get_function_type(parms, void_type);

  Symbol const* flow_name = flow->name();

  // Enter flow function scope.
  Scope_sentinel scope(*this, flow);

  // declare an implicit context and table variable
  declare(flw);
  declare(cxt);
  declare(tbl);

  // Contruct the body from the instructions.
  // Trust that the lowering process correctly elaborates the body so
  // its not necessary to do so again.
  //
  // Each flow body should allocate space for every local variable.
  // Handle any additional modifications to the flow body.
  Stmt* flow_body = lower_flow_body(table, flow->instructions());

  // Produce the flow function.
  Function_decl* fn = new Function_decl(flow_name, type, parms, flow_body);

  // Make sure it has external linkage.
  fn->spec_ |= extern_spec;

  // Add the flow function to the module.
  module_decls.push_back(fn);

  return fn;
}


Stmt_seq
Lowerer::lower(Insert_flow* s)
{
  Table_decl* table = as<Table_decl>(s->table());
  assert(table);

  // Form a call to the appropriate key forming function.
  std::string fn_name = __keyform + table->name()->spelling();
  Overload* ovl = unqualified_lookup(get_identifier(fn_name));
  assert(ovl);
  Decl* key_fn = ovl->back();
  assert(key_fn);

  ovl = unqualified_lookup(table->name());
  assert(ovl);
  Decl* tblptr = ovl->back();
  assert(tblptr);

  ovl = unqualified_lookup(get_identifier(__context));
  assert(ovl);
  Decl* cxt = ovl->back();
  assert(cxt);

  // Get the key values needed for the flow.
  Flow_decl* flow = as<Flow_decl>(s->flow());
  assert(flow);

  // Form a call.
  Expr_seq keys;
  // Lower all keys first.
  for (auto e : flow->keys()) {
    keys.push_back(lower(e));
  }
  Expr* call = new Call_expr(id(key_fn), keys);
  elab.elaborate(call);
  Variable_decl* temp = temp_var(elab.syms, call->type(), call);

  // Void cast the result
  Expr* vcast = new Void_cast(decl_id(temp));

  // Construct the flow function and add it into the module.
  Decl* flow_fn = construct_added_flow(table, flow);

  // Make a call to fp_add_flow
  Expr* add_flow =
    builtin.call_add_new_flow(decl_id(tblptr), decl_id(flow_fn), vcast, decl_id(cxt));

  return {
    statement(temp),
    statement(add_flow),
  };
}


Stmt_seq
Lowerer::lower(Remove_flow* s)
{
  Table_decl* table = as<Table_decl>(s->table());
  assert(table);

  // To remove a flow, we must compose the key first.
  // Form a call to the appropriate key forming function.
  std::string fn_name = __keyform + table->name()->spelling();
  Overload* ovl = unqualified_lookup(get_identifier(fn_name));
  assert(ovl);
  Decl* key_fn = ovl->back();
  assert(key_fn);

  ovl = unqualified_lookup(table->name());
  assert(ovl);
  Decl* tblptr = ovl->back();
  assert(tblptr);

  // Form a call.
  Expr_seq keys;
  // Lower all keys first.
  for (auto e : s->keys()) {
    keys.push_back(lower(e));
  }
  Expr* call = new Call_expr(id(key_fn), keys);
  elab.elaborate(call);
  Variable_decl* temp = temp_var(elab.syms, call->type(), call);

  // Void cast the result
  Expr* vcast = new Void_cast(decl_id(temp));

  // Make a call to fp_del_flow.
  Expr* rmv_flow = builtin.call_remove_flow(decl_id(tblptr), vcast);

  return {
    statement(temp),
    statement(rmv_flow),
  };
}


Stmt_seq
Lowerer::lower(Write_drop* w)
{
  // get the context variable which should Always
  // be within the scope of a decoder body
  Overload* ovl = unqualified_lookup(get_identifier(__context));
  assert(ovl);
  Decl* cxt = ovl->back();
  assert(cxt);

  // make a call to the drop function
  Expr* write = builtin.call_write_drop(decl_id(cxt));
  elab.elaborate(write);

  return
  {
    statement(write)
  };
}


// FIXME: Writing an output for later has some questionable semantics.
// Upon applying the output, all actions afterward should not be executed
// (since the outputing of a packet causes its context to be deleted and no
// longer valid). This is easier to enforce in immediate action rather than
// written actions which is currently not enforced in.
Stmt_seq
Lowerer::lower(Write_output* w)
{
  Output* s = w->output();
  assert(s);

  // get the context variable which should Always
  // be within the scope of a decoder body
  Overload* ovl = unqualified_lookup(get_identifier(__context));
  assert(ovl);
  Decl* cxt = ovl->back();
  assert(cxt);

  // Acquire the port.
  Symbol const* port_name = as<Decl_expr>(s->port())->declaration()->name();
  ovl = unqualified_lookup(port_name);
  assert(ovl);
  Decl* port = ovl->back();
  assert(port);

  // make a call to the drop function
  Expr* output = builtin.call_write_output(decl_id(cxt), id(port));
  elab.elaborate(output);

  return
  {
    statement(output),
  };
}


// Raise passes a task to a hypothetical asynchronous thread in the runtime
// system with a context.
//
// NOTE: The semantics of calling raise with the runtime should be
// that the implicit context being passed to the event handler is
// COPIED. This allows us to continue processing the packet, after having
// asynchronously passed it off to some event handler.
//
// FIXME: This isn't quite right yet. We avoid elaborating the call to raise
// event because we do not currently support passing around function pointer.
// Therefore the behavior is faked to generate the correct code.
Stmt_seq
Lowerer::lower(Raise* s)
{
  // Lookup the context.
  Overload* ovl = unqualified_lookup(get_identifier(__context));
  assert(ovl);
  Decl* cxt = ovl->back();
  assert(cxt);

  // Lookup the event function.
  ovl = unqualified_lookup(s->event()->name());
  assert(ovl);
  Decl* event = ovl->back();
  assert(event);

  // Make a call to fp_raise_event(Context*, Event*)
  Expr* raise_event = builtin.call_raise_event(decl_id(cxt), decl_id(event));

  return
  {
    statement(raise_event)
  };
}


Stmt_seq
Lowerer::lower(Write_flood* w)
{
  // get the context variable which should Always
  // be within the scope of a decoder body
  Overload* ovl = unqualified_lookup(get_identifier(__context));
  assert(ovl);
  Decl* cxt = ovl->back();
  assert(cxt);

  // make a call to the drop function
  Expr* write = builtin.call_write_flood(decl_id(cxt));
  elab.elaborate(write);

  return
  {
    statement(write)
  };
}


Stmt_seq
Lowerer::lower(Write_set_field* w)
{
  Set_field* s = w->set_field();
  assert(s);

  // get the context varaible
  Overload* ovl = unqualified_lookup(get_identifier(__context));
  assert(ovl);
  Decl* cxt = ovl->back();
  assert(cxt);

  // Write Set field translates to a function call to
  // fp_write_set_field, passing in the context, field id, and value.
  Field_access_expr* e = as<Field_access_expr>(s->field());
  assert(e);

  Expr* id = make_int(checker.get_field_mapping(e->name()));

  // Lower the value first to ensure it can be evaluated.
  s->value_ = lower(s->value_);

  // Initialize a temp variable with the value used to set the field.
  Variable_decl* var = temp_var(elab.syms, s->value()->type(), s->value());
  declare(var);

  // Convert the value into a byte array and pass it as an i8*.
  int prec = precision(s->value()->type());
  auto val = expr_to_void_block(decl_id(var));

  // Create the call, passing in the value as an i8* to the runtime.
  Expr* write =
    builtin.call_write_set_field(decl_id(cxt), id, make_int(prec / 8), val);
  elab.elaborate(write);

  return {
    statement(var),
    statement(write)
  };
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

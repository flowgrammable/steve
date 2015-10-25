#include "steve/lower.hpp"
#include "steve/builtin.hpp"
#include "steve/lookup.hpp"
#include "steve/net.hpp"
#include "steve/offset.hpp"
#include "steve/length.hpp"
#include "steve/convert.hpp"


namespace steve
{

namespace
{

String _cxt_ = "_cxt_";
String _header_ = "_header_";

// empty block
Stmt*
make_empty_block()
{
  Stmt_seq s;
  return make_block_stmt(s);
}


// ----------------------------------------------------------------- //
//                    Lower exprs


// FIXME: there should be two calls generated here
// Need to add expr for reinterpreting members of cxt as correct header type
// before making the call to the decoder
Expr const*
lower_do_decode(Do_expr const* e)
{
  auto decode = builtin_function(__decode);

  if (Overload const* c = lookup("_cxt_")) {
    if (Overload const* h = lookup("_header_")) {
      // make call to the decode dispatcher
      Expr_seq cargs {
        id(c->front()), // context
        id(lookup_decl(as<Id_expr>(e->target())->name())), // decode function pointer
        // advance the context byte by this number before decoding
        lower(make_lengthof_expr(id(h->front()))), 
      };

      return make_call_expr(id(decode), cargs);
    }
  }

  lingo_unreachable("Unable to lower do decode.");

  return nullptr;
}


// TODO: Implement
// Figure out how we make calls to tables since ideally
// tables should be lowered to produce callable functions
// and functions which configure the dataplane
Expr const*
lower_do_table(Do_expr const* e)
{
  auto match = get_match_fn(e->target()->type());

  if (!match) {
    error(Location::none, "No match function found for '{}'.", e->target());
    return nullptr;
  }

  if (Overload const* c = lookup("_cxt_")) {
    if (Overload const* h = lookup("_header_")) {

      Expr_seq args {
        id(c->front()), 
        e->target(),
        lower(make_lengthof_expr(id(h->front())))
      };

      // make a call to the next table
      return make_call_expr(id(match), args);
    }
  }

  lingo_unreachable("Unable to lower do decode.");

  return e;
}


// ------------------------------------------------------------ //
//             Lower Declarations


// We convert an extracts decl into implicit function
// calls to __bind_offset(cxt, n, offsetof(field))
// where n is a unique number refering to the order
// in which that extracted field is found when walking
// the program.
Stmt_seq
lower_extracts_decl(Extracts_decl const* d)
{
  Stmt_seq stmts;
  auto bind_offset = builtin_function(__bind_offset);

  // this should be guarenteed earlier in type checking
  Field_expr const* f = as<Field_expr>(d->field());

  // Create the calls
  if (Overload const* oc = lookup(get_identifier(_cxt_))) {
    if (Overload const* oh = lookup(get_identifier(_header_))) {
      Expr_seq args {
        id(oc->front()),
        make_value_expr(get_int_type(), lookup_field_binding(f->name())),
        lower(make_offsetof_expr(id(oh->front()), f->field()->decl())),
        lower(make_lengthof_expr(id(f->field()->decl())))
      };

      // make call
      Call_expr* call = make_call_expr(id(bind_offset), args);
      stmts.push_back(make_expr_stmt(call));
    }
  }

  return stmts;
}

// We change a rebind decl into a call to the
// implicit function __double_bind_offset(cxt, true_env_offset, aliased_env_offset, offset, offsetof, lengthof)
//
// bind field1 as field2
// 
// The aliased env offset is the number it would receive if its name was field2
// The true_env offset is the number it would receive if its name was field1
// Stmt_seq
// lower_rebind_decl(Rebind_decl const* d)
// {
//   Stmt_seq stmts;
//   auto bind_offset = builtin_function(__bind_offset);

//   // this should be guarenteed earlier in type checking
//   Field_expr const* f = as<Field_expr>(d->field());

//   // Create the calls
//   if (Overload const* oc = lookup(get_identifier(_cxt_))) {
//     if (Overload const* oh = lookup(get_identifier(_header_))) {
//       Expr_seq args {
//         id(oc->front()),
//         make_value_expr(get_int_type(), lookup_field_binding(f->name())),
//         lower(make_offsetof_expr(id(oh->front()), f->field()->decl())),
//         lower(make_lengthof_expr(id(f->field()->decl())))
//       };

//       // make call
//       Call_expr* call = make_call_expr(id(bind_offset), args);
//       stmts.push_back(make_expr_stmt(call));
//     }
//   }

//   return stmts;
// }


// --------------------------------------------------------------- //
//              Lowering functions


struct Expr_lower
{
  Expr const* operator()(Id_expr const* e) 
  {
    return e; 
  }

  Expr const* operator()(Constant_expr const* e) 
  {
    return e; 
  }

  Expr const* operator()(Lookup_expr const* e) 
  {
    return e; 
  }

  Expr const* operator()(Default_expr const* e) 
  {
    return e; 
  }

  Expr const* operator()(Init_expr const* e) 
  {
    return e; 
  }

  Expr const* operator()(Value_expr const* e) 
  {
    return e; 
  }

  Expr const* operator()(Unary_expr const* e) 
  {
    return e; 
  }

  Expr const* operator()(Binary_expr const* e) 
  {
    return e; 
  }

  Expr const* operator()(Call_expr const* e) 
  {
    return e; 
  }

  Expr const* operator()(Tuple_expr const* e) 
  {
    return e; 
  }

  Expr const* operator()(Index_expr const* e) 
  {
    return e; 
  }

  Expr const* operator()(Member_expr const* e) 
  {
    return e; 
  }

  Expr const* operator()(Field_expr const* e) 
  {
    return e; 
  }

  Expr const* operator()(Convert_expr const* e) 
  {
    return e; 
  }

  // We need to be able to resolve lengthof expressions into
  // function calls.
  // 1. A lengthof expr resolved into a function call iff there exists a length(T t)->int in scope
  // 2. A lengthof expr causes a function call to be synthesized iff no length(T t)->int is declared
  //     within scope. Then the lengthof expr is resolved into a function call.
  Expr const* operator()(Lengthof_expr const* e) 
  {
    Lengthof_expr const* len = e;

    Overload const* ovl = lookup("lengthof");
    Function_decl const* len_fn = nullptr;

    if (ovl) {
      for (auto decl : *ovl) {
        lingo_assert(is<Function_decl>(decl));
        Function_decl const* fn = as<Function_decl>(decl);

        // check that there is exactly one parameter and get its type
        if (fn->parms().size() == 1)
          if (fn->parms().at(0)->type() == len->arg()->type()) {
            len_fn = fn;
            break;
          }
      }

      if (len_fn)
        return make_call_expr(id(len_fn), {len->arg()});
    }

    // otherwise if there are no lengthof fn then return an expr calculating length
    return get_length(len->arg()->type());
  }

  Expr const* operator()(Offsetof_expr const* e) 
  {
    Offsetof_expr const* off = e;

    // confirm this has record type
    if (is<Record_type>(off->object()->type())) {
      // get the record declaration from the record type
      Record_decl const* rd = as<Record_type>(off->object()->type())->decl();

      return get_offset(rd, off->member());
    }

    // It might have reference type
    if (Reference_type const* ref = as<Reference_type>(off->object()->type())) {
      if (is<Record_type>(ref->type())) {
        // get the record declaration from the record type
        Record_decl const* rd = as<Record_type>(ref->type())->decl();

        return get_offset(rd, off->member());
      }
    }

    lingo_unreachable("Broken offset lowering.");

    return nullptr;
  }

  Expr const* operator()(Headerof_expr const* e) 
  {
    return e; 
  }

  Expr const* operator()(Do_expr const* e) 
  {
    switch (e->do_what()) {
      case decode: 
        return lower_do_decode(e);
      case table:
        return lower_do_table(e);
    }

    return e; 
  }

  Expr const* operator()(Insert_expr const* e) 
  {
    return e; 
  }

  Expr const* operator()(Delete_expr const* e) 
  {
    return e; 
  }

  Expr const* operator()(Field_idx_expr const* e) 
  {
    return e; 
  }

  Expr const* operator()(Header_idx_expr const* e) 
  {
    return e; 
  }

  // builtins
  Expr const* operator()(Header_cast_expr const* e) 
  {
    return e; 
  }
};


struct Decl_lower
{
  Decl const* operator()(Variable_decl const* d) 
  {
    if (d->init())
      if (Expr const* e = lower(d->init()))
        if (e != d->init())
          return make_variable_decl(d->name(), d->type(), e);

    return d; 
  }

  Decl const* operator()(Constant_decl const* d) 
  {
    return d; 
  }

  Decl const* operator()(Function_decl const* d) 
  {
    if (d->body())
      return make_function_decl(d->name(), d->parms(), d->ret_type(), block(lower(d->body()))); 

    return d;
  }

  Decl const* operator()(Parameter_decl const* d) 
  {
    return d; 
  }

  Decl const* operator()(Record_decl const* d) 
  {
    return d; 
  }

  Decl const* operator()(Member_decl const* d) 
  {
    return d; 
  }

  Decl const* operator()(Variant_decl const* d) 
  {
    return d; 
  }

  Decl const* operator()(Enum_decl const* d) 
  {
    return d; 
  }

  Decl const* operator()(Forward_decl const* d) 
  {
    return d; 
  }

  // Convert a decode decl into just another function
  // declaration.
  // 
  // decode d1(eth) 
  // {
  //   extracts eth.src;
  //   extracts eth.dst;
  //   extracts eth.type;

  //   match(eth.type) {
  //     case 0x800: do decode d2;
  //   }
  // }
  // =>
  // def d1(cxt : CXT&)->void
  // {
  //   T& _header_ = header_cast();
  //   __bind_header(cxt, #);
  //   __bind_offset(cxt, 0, offsetof(eth, eth.src), lengthof(eth.src));
  //   __bind_offset(cxt, 1, offsetof(eth, eth.dst), lengthof(eth.dst));
  //   __bind_offset(cxt, 2, offsetof(eth, eth.type), lengthof(eth.type));
  //   match(_header_.type)
  //   {
  //     case 0x800: 
  //     { 
  //       __decode(cxt, d2, lengthof(_header_));
  //     )
  //   }
  // }
  //
  // first line of function all ways binds the header

  Decl const* operator()(Decode_decl const* d) 
  {
    // Find the bind header functions
    auto bind_header = builtin_function(__bind_header);
    // FIXME: header_cast expr implicitly has type ref(d->header)
    auto header_cast = make_header_cast(d->header());

    // Enter the block scope to confirm that 
    // all declarations made from here are valid
    Local_scope local;

    Block_stmt const* body = nullptr;
    if (is<Block_stmt>(d->body()))
      body = as<Block_stmt>(d->body());
    else {
      error(d->location(), "Decode declaration '{}' has invalid body.", d);
    }

    // FIXME: a bit of a hack but it works
    // going to declare a parameter named header for the explicit and only purpose
    // of determining what type the immediate decode handles. This lets me carry the type
    // across lower() calls using scoping.
    // it is no longer being used as a parameter for the decode function
    //
    // Technically this entire line is not type checked because the type check would fail
    // since header_cast neither has the correct return type nor a return at all, but 
    // this works.
    Variable_decl const* header_var = make_variable_decl(get_identifier(_header_), 
                                                         get_reference_type(d->header()), header_cast);

    Parameter_decl const* cxt = make_parameter_decl(get_identifier(_cxt_), get_reference_type(get_context_type()));  

    declare(cxt->name(), cxt);
    declare(header_var->name(), header_var);

    Decl_seq parms =
    {
      cxt,
    };

    // stmts for the new decode function
    Stmt_seq new_stmts;

    // the first line is always a call to header_cast()
    new_stmts.push_back(make_decl_stmt(header_var));

    Expr_seq args {
      id(cxt), 
      make_value_expr(get_int_type(), lookup_header_binding(as<Record_type>(d->header())->decl()->name())),
      lower(make_lengthof_expr(id(header_var)))
    };

    new_stmts.push_back(make_expr_stmt(make_call_expr(id(bind_header), args)));

    // lower the body after injecting all of the extra stmts
    Stmt_seq lowered = lower(body);
    new_stmts.insert(new_stmts.end(), lowered.begin(), lowered.end());

    // construct a new function declaration
    // FIXME: replace the body
    Function_decl* fn = make_function_decl(d->name(), parms, get_void_type(), block(new_stmts));
    fn->set_foreign();

    return fn; 
  }

  Decl const* operator()(Table_decl const* d) 
  {
    // FIXME: This is ugly but we definitely do
    // not want to emit a new table declaration,
    // we just want to modify the existing table's
    // body with flows that have lowered bodies.
    Table_decl* t = const_cast<Table_decl*>(d);

    Decl_seq new_body;

    for (auto flow : t->body()) {
      new_body.push_back(lower(flow));
    }

    t->set_body(new_body);

    return d; 
  }

  Decl const* operator()(Flow_decl const* d) 
  {
    Stmt_seq l = lower(d->instructions());

    // FIXME: this is ugly but we don't really have a choice
    // We don't want to create a brand new flow declaration
    // since naming is done automatically on flows and we
    // would simply end up with a flow with a different name.
    //
    // We just want to modify the existing declaration
    // with lowered stmts
    Flow_decl* flow = const_cast<Flow_decl*>(d);
    flow->set_instructions(block(l));

    return d; 
  }

  Decl const* operator()(Extracts_decl const* d) 
  {
    return d; 
  }

  Decl const* operator()(Rebind_decl const* d) 
  {
    return d; 
  }

};


struct Stmt_lower
{
  Stmt_seq stmts;

  Stmt_seq operator()(Empty_stmt const* s) 
  {
    stmts.push_back(s);
    return stmts;
  }

  Stmt_seq operator()(Expr_stmt const* s) 
  {
    if (Expr const* e = lower(s->expr())) {
      if (e != s->expr()) 
        stmts.push_back(make_expr_stmt(lower(s->expr())));
      else
        stmts.push_back(s);
    }

    return stmts;
  }

  Stmt_seq operator()(Decl_stmt const* s) 
  {
    // These are exceptions to the lowering
    // process as they are declarations which
    // lower into call expressions instead of
    // other declarations

    if (Extracts_decl const* extract = as<Extracts_decl>(s->decl())) {
      Stmt_seq l = lower_extracts_decl(extract);
      stmts.insert(stmts.end(), l.begin(), l.end());
      return stmts;
    }

    if (is<Rebind_decl>(s->decl())) {
      // TODO: implement me
    }

    if (Decl const* decl = lower(s->decl())) {
      if (decl != s->decl())
        stmts.push_back(make_decl_stmt(decl));
      else
        stmts.push_back(s);
    }

    return stmts;
  }

  // FIXME: if none of the stmts go unchanged
  // there's no real reason to make a new block stmt
  // 
  // Instead of inserting a new block stmt we just return all
  // stmts that have been lowered. The caller is responsible for
  // forming the block.
  Stmt_seq operator()(Block_stmt const* s) 
  {
    for (auto stmt : *s) {
      Stmt_seq l = lower(stmt);
      stmts.insert(stmts.end(), l.begin(), l.end());
    } 

    return stmts;
  }

  // Lower the expression being returned
  Stmt_seq operator()(Return_stmt const* s) 
  {
    if (Expr const* e = lower(s->result())) {
      if (e != s->result()) 
        stmts.push_back(make_return_stmt(lower(s->result())));
      else
        stmts.push_back(s);
    }

    return stmts;
  }

  Stmt_seq operator()(Match_stmt const* s) 
  {
    Stmt_seq new_stmts;
    for (auto c : s->cases()) {
      Stmt_seq l = lower(c);

      new_stmts.insert(new_stmts.end(), l.begin(), l.end());
    }

    stmts.push_back(make_match_stmt(lower(s->cond()), new_stmts));

    return stmts;
  }

  Stmt_seq operator()(Case_stmt const* s) 
  {
    Stmt_seq new_stmts = lower(s->stmt());
    Block_stmt const* b = make_block_stmt(new_stmts);
    stmts.push_back(make_case_stmt(s->label(), b));

    return stmts;
  }

  Stmt_seq operator()(Instruct_stmt const* s) 
  {
    stmts.push_back(s);
    return stmts;
  }
};


} // namespace


Expr const* 
lower(Expr const* e)
{
  Expr_lower expr_lwr;
  return apply(e, expr_lwr);
}


Decl const* 
lower(Decl const* d)
{
  Decl_lower decl_lwr;
  return apply(d, decl_lwr);
}


Stmt_seq
lower(Stmt const* s)
{
  Stmt_lower stmt_lwr;
  return apply(s, stmt_lwr);

  // if (is<Expr_stmt>(s))
  //   lower(as<Expr_stmt>(s), stmts);
  // else if (is<Decl_stmt>(s)) 
  //   lower(as<Decl_stmt>(s), stmts);
  // else if (is<Match_stmt>(s))
  //   lower(as<Match_stmt>(s), stmts);
  // else if (is<Case_stmt>(s))
  //   lower(as<Case_stmt>(s), stmts);
  // else
  //   stmts.push_back(s);

  // // scan the stmts and push any declarations onto scope
  // // FIXME: this is actually unnecessary for now i think
  // // for (auto s : stmts) {
  // //   if (Decl_stmt const* d = as<Decl_stmt>(s)) {
  // //     rewrite_declare(d->decl()->name(), d->decl());
  // //   }
  // // }

  // return stmts;
}

} // namespace steve


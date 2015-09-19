#include "steve/lower.hpp"
#include "steve/builtin.hpp"
#include "steve/lookup.hpp"
#include "steve/net.hpp"
#include "steve/offset.hpp"
#include "steve/length.hpp"



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


// ------------------------------------------------------------ //
//             Lengthof and Offset of Expr

// We need to be able to resolve lengthof expressions into
// function calls.
// 1. A lengthof expr resolved into a function call iff there exists a length(T t)->int in scope
// 2. A lengthof expr causes a function call to be synthesized iff no length(T t)->int is declared
//     within scope. Then the lengthof expr is resolved into a function call.
Expr const*
lower_lengthof(Expr const* e)
{
  lingo_assert(is<Lengthof_expr>(e));
  Lengthof_expr const* len = as<Lengthof_expr>(e);

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


// We need to be able to resolve offsetof expressions into values
// or function calls which determine the offsetof a given field.
Expr const*
lower_offset(Expr const* e)
{
  lingo_assert(is<Offsetof_expr>(e));
  Offsetof_expr const* off = as<Offsetof_expr>(e);
  // confirm this has record type
  lingo_assert(is<Record_type>(off->object()->type()));

  // get the record declaration from the record type
  Record_decl const* rd = as<Record_type>(off->object()->type())->decl();

  return get_offset(rd, off->member());
}


// FIXME: there should be two calls generated here
// Need to add expr for reinterpreting members of cxt as correct header type
// before making the call to the decoder
void
lower_do_decode(Do_expr const* e, Stmt_seq& stmts)
{
  auto advance = builtin_function(__advance);
  auto decode = builtin_function(__decode);

  if (Overload const* c = lookup("_cxt_")) {
    if (Overload const* h = lookup("_header_")) {
      // makes the call expr to __advance
      Expr_seq args {
        id(c->front()),
        lower_lengthof(make_lengthof_expr(id(h->front())))
      };
      stmts.push_back(make_expr_stmt(make_call_expr(id(advance), args)));

      // make call to the decode dispatcher
      Expr_seq cargs {
        id(c->front()), // context
        id(lookup_decl(as<Id_expr>(e->target())->name())), // decode function pointer
      };

      stmts.push_back(make_expr_stmt(make_call_expr(id(decode), cargs)));
    }
  }
}


// TODO: Implement
// Figure out how we make calls to tables since ideally
// tables should be lowered to produce callable functions
// and functions which configure the dataplane
void
lower_do_table(Do_expr const* e, Stmt_seq& stmts)
{
  auto advance = builtin_function(__advance);
  auto match = get_match_fn(e->target()->type());

  if (!match) {
    error(Location::none, "No match function found for '{}'.", e->target());
    return;
  }

  if (Overload const* c = lookup("_cxt_")) {
    if (Overload const* h = lookup("_header_")) {
      // makes the call expr to __advance
      Expr_seq args {
        id(c->front()),
        lower_lengthof(make_lengthof_expr(id(h->front())))
      };
      stmts.push_back(make_expr_stmt(make_call_expr(id(advance), args)));

      // make a call to the next table
      stmts.push_back(make_expr_stmt(make_call_expr(id(match), {id(c->front()), e->target()})));
    }
  }
}


void
lower_do_expr(Do_expr const* e, Stmt_seq& stmts)
{
  switch (e->do_what()) {
    case decode: 
      lower_do_decode(e, stmts);
      break;
    case table:
      lower_do_table(e, stmts);
      break;
  }
}


Expr const*
lower_header_lookup(Header_idx_expr const* e)
{
  lingo_assert(is<Id_expr>(e->header()));
  Id_expr const* hdr = as<Id_expr>(e->header());

  lingo_assert(is<Record_decl>(hdr->decl()));
  Record_decl const* rd = as<Record_decl>(hdr->decl());

  auto lookup_fn = builtin_function(__lookup_hdr);

  if (auto cxt = lookup_decl(get_identifier(_cxt_))) {
    Expr_seq args {
      id(cxt),
      make_value_expr(get_int_type(), lookup_header_binding(rd->name())),
    };
    return make_call_expr(id(lookup_fn), args);
  }
  else
    error("Unable to find context '_cxt_' within scope.");

  return nullptr;
}


Expr const*
lower_field_lookup(Field_idx_expr const* e)
{
  lingo_assert(is<Field_expr>(e->field()));
  Field_expr const* fld = as<Field_expr>(e->field());

  auto lookup_fn = builtin_function(__lookup_fld);

  if (auto cxt = lookup_decl(get_identifier(_cxt_))) {
    Expr_seq args {
      id(cxt),
      make_value_expr(get_int_type(), lookup_field_binding(fld->name())),
    };
    
    return make_call_expr(id(lookup_fn), args);
  }
  else
    error("Unable to find context '_cxt_' within scope.");

  return nullptr;
}


// We don't handle do exprs here because those can only occur
// in specific context
//
// TODO: refactor into visitor pattern
Expr const*
lower(Expr const* e)
{
  // TODO: do the rest of the expressions
  if (Header_idx_expr const* h = as<Header_idx_expr>(e))
    return lower_header_lookup(h);
  if (Field_idx_expr const* f = as<Field_idx_expr>(e))
    return lower_field_lookup(f);

  return e;
}


// ------------------------------------------------------------ //
//             Lower Declarations

// Convert a decode decl into just another function
// declaration.
// 
// decode d1(eth) 
// {
//   extracts eth.src;
//   extracts eth.dst;
//   extracts eth.type;

//   match(eth.type) {
//     case 0x800: do decode d2(ipv4);
//   }
// }
// =>
// def d1(cxt : CXT&, _header_ : eth&)->void
// {
//   __bind_header(cxt, #);
//   __bind_offset(cxt, 0, offsetof(cxt, eth.src));
//   __bind_offset(cxt, 1, offsetof(cxt, eth.dst));
//   __bind_offset(cxt, 2, offsetof(cxt, eth.type));
//   match(_header_.type)
//   {
//     case 0x800: 
//     { 
//       __advance(cxt, lengthof(_header_); 
//       d2(cxt, (ipv4)cxt.packet[x:y]);
//     )
//   }
// }
//
// first line of function all ways binds the header
// convert
void
lower_decode_decl(Decode_decl const* d, Stmt_seq& stmts)
{
  // Find the bind header functions
  auto bind_header = builtin_function(__bind_header);
  auto header_cast = builtin_function(__header_cast);

  Local_scope local;

  Block_stmt const* body = nullptr;
  if (is<Block_stmt>(d->body()))
    body = as<Block_stmt>(d->body());
  else {
    error(d->location(), "Decode declaration '{}' has invalid body.", d);
  }

  Parameter_decl const* cxt = make_parameter_decl(get_identifier(_cxt_), get_reference_type(get_context_type()));
  // FIXME: a bit of a hack but it works
  // going to declare a parameter named header for the explicit and only purpose
  // of determining what type the immediate decode handles. This lets me carry the type
  // across lower() calls using scoping.
  // it is no longer being used as a parameter for the decode function
  Variable_decl const* header = make_variable_decl(get_identifier(_header_), d->header());

  declare(cxt->name(), cxt);
  declare(header->name(), header);

  Decl_seq parms =
  {
    cxt,
  };

  // stmts for the new decode function
  Stmt_seq new_stmts;

  // the first line is always a call to header_cast()
  new_stmts.push_back(make_expr_stmt(make_call_expr(id(header_cast), {})));

  Expr_seq args {
    id(cxt), 
    make_value_expr(get_int_type(), lookup_header_binding(as<Record_type>(d->header())->decl()->name()))
  };
  new_stmts.push_back(make_expr_stmt(make_call_expr(id(bind_header), args)));

  // for each stmt, attempt to lower it and at it to the new body
  for(Stmt const* s : *body)
  {
    lower(s, new_stmts);
  }

  Block_stmt* new_body = make_block_stmt(new_stmts);

  // construct a new function declaration
  // FIXME: replace the body
  Function_decl const* fn = make_function_decl(d->name(), parms, get_void_type(), new_body);

  stmts.push_back(make_decl_stmt(fn));
}


// We convert an extracts decl into implicit function
// calls to __bind_offset(cxt, n, offsetof(field))
// where n is a unique number refering to the order
// in which that extracted field is found when walking
// the program.
void
lower_extracts_decl(Extracts_decl const* d, Stmt_seq& stmts)
{
  if (auto bind_offset = builtin_function(__bind_offset)) {
    Field_expr const* f = as<Field_expr>(d->field());

    if (Overload const* oc = lookup(get_identifier(_cxt_))) {
      if (Overload const* oh = lookup(get_identifier(_header_))) {
        Expr_seq args {
          id(oc->front()),
          make_value_expr(get_int_type(), lookup_field_binding(f->name())),
          lower_offset(make_offsetof_expr(id(oh->front()), f->field()->decl()))
        };

        // make call
        Call_expr* call = make_call_expr(id(bind_offset), args);
        stmts.push_back(make_expr_stmt(call));
      }
    }
  }
}


void
lower(Expr_stmt const* s, Stmt_seq& stmts)
{
  if (is<Do_expr>(s->expr()))
    lower_do_expr(cast<Do_expr>(s->expr()), stmts);
  else
    stmts.push_back(s);
}


void
lower(Decl_stmt const* s, Stmt_seq& stmts)
{
  if (is<Decode_decl>(s->decl()))
    lower_decode_decl(cast<Decode_decl>(s->decl()), stmts);
  else if (is<Extracts_decl>(s->decl()))
    lower_extracts_decl(cast<Extracts_decl>(s->decl()), stmts);
  else
    stmts.push_back(s);
}


void
lower(Match_stmt const* s, Stmt_seq& stmts)
{
  Stmt_seq new_stmts;
  for (auto c : s->cases()) {
    lower(c, new_stmts);
  }

  stmts.push_back(make_match_stmt(lower(s->cond()), new_stmts));
}


void 
lower(Case_stmt const* s, Stmt_seq& stmts)
{
  Stmt_seq new_stmts;
  // if there is a block stmt instead of a single stmt
  if (is<Block_stmt>(s->stmt()))
    // lower each stmt in the block in turn
    for (auto stmt : *as<Block_stmt>(s->stmt()))
      lower(stmt, new_stmts);
  // otherwise its a single stmt and lower as normal
  else
    lower(s->stmt(), new_stmts);

  Block_stmt const* b = make_block_stmt(new_stmts);
  stmts.push_back(make_case_stmt(s->label(), b)); 
}


} // namespace

Stmt_seq
lower(Stmt const* s, Stmt_seq& stmts)
{
  if (is<Expr_stmt>(s))
    lower(as<Expr_stmt>(s), stmts);
  else if (is<Decl_stmt>(s)) 
    lower(as<Decl_stmt>(s), stmts);
  else if (is<Match_stmt>(s))
    lower(as<Match_stmt>(s), stmts);
  else if (is<Case_stmt>(s))
    lower(as<Case_stmt>(s), stmts);
  else
    stmts.push_back(s);

  // scan the stmts and push any declarations onto scope
  for (auto s : stmts) {
    if (Decl_stmt const* d = as<Decl_stmt>(s)) {
      rewrite_declare(d->decl()->name(), d->decl());
    }
  }

  return stmts;
}

} // namespace steve


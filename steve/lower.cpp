#include "steve/lower.hpp"
#include "steve/builtin.hpp"
#include "steve/lookup.hpp"
#include "steve/net.hpp"

// ----------------------------------------------------------------- //
//                    Lower decls

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


// ------------------------------------------------------------ //
//             Lower Expressions

// FIXME: there should be two calls generated here
// Need to add expr for reinterpreting members of cxt as correct header type
// before making the call to the decoder
void
lower_do_decode(Do_expr const* e, Stmt_seq& stmts)
{
  auto advance = builtin_function(__advance);

  if (Overload const* c = lookup("_cxt_")) {
    if (Overload const* h = lookup("_header_")) {
      // makes the call expr to __advance
      Expr_seq args {
        id(c->front()),
        make_lengthof_expr(id(h->front()))
      };
      stmts.push_back(make_expr_stmt(make_call_expr(id(advance), args)));

      // makes the call expr to __decode
      // auto decode = make_decode_fn();
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
  Function_decl const* bind_header = builtin_function(__bind_header);

  Local_scope local;

  lingo_assert(is<Block_stmt>(d->body()));
  Block_stmt const* body = as<Block_stmt>(d->body());

  String const* n = d->name();

  Parameter_decl const* cxt = make_parameter_decl(get_identifier(_cxt_), get_reference_type(get_context_type()));

  declare(cxt->name(), cxt);

  Decl_seq parms =
  {
    cxt,
  };

  Stmt_seq new_stmts;
  Expr_seq args {
    id(cxt), 
    make_value_expr(get_int_type(), lookup_header_binding(as<Record_type>(d->header())->decl()->name()))
  };
  new_stmts.push_back(make_expr_stmt(make_call_expr(id(bind_header), args)));

  // for each stmt, attempt to lower it
  for(Stmt const* s : *body)
  {
    lower(s, new_stmts);
  }

  Block_stmt* new_body = make_block_stmt(new_stmts);

  // construct a new function declaration
  // FIXME: replace the body
  Function_decl const* fn = make_function_decl(n, parms, get_void_type(), new_body);

  stmts.push_back(make_decl_stmt(fn));

  declare(n, fn);
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
    lingo_assert(is<Field_expr>(d->field()));
    Field_expr const* f = as<Field_expr>(d->field());

    if (Overload const* oc = lookup(get_identifier(_cxt_))) {
      Expr_seq args {
        id(oc->front()),
        make_value_expr(get_int_type(), lookup_field_binding(f->name())),
        make_offsetof_expr(f->record(), f->field()->decl())
      };

      // make call
      Call_expr* call = make_call_expr(id(bind_offset), args);
      stmts.push_back(make_expr_stmt(call));
    }
  }
}


void
lower(Expr_stmt const* s, Stmt_seq& stmts)
{
  switch (s->expr()->kind()) {
    case do_expr:
      lower_do_expr(cast<Do_expr>(s->expr()), stmts);
      break;
    default:
      stmts.push_back(s);
      break;
  }
}


void
lower(Decl_stmt const* s, Stmt_seq& stmts)
{
  switch(s->decl()->kind()) {
    case decode_decl:
      lower_decode_decl(cast<Decode_decl>(s->decl()), stmts);
      break;
    case extracts_decl:
      lower_extracts_decl(cast<Extracts_decl>(s->decl()), stmts);
      break;
    default:
      stmts.push_back(s);
      break;
  }
}


void
lower(Match_stmt const* s, Stmt_seq& stmts)
{
  Stmt_seq new_stmts;
  for (auto c : s->cases()) {
    lower(c, new_stmts);
  }

  stmts.push_back(make_match_stmt(s->cond(), new_stmts));
}


void 
lower(Case_stmt const* s, Stmt_seq& stmts)
{
  Stmt_seq new_stmts;
  lower(s->stmt(), new_stmts);

  Block_stmt const* b = make_block_stmt(new_stmts);
  stmts.push_back(make_case_stmt(s->label(), b)); 
}


} // namespace

Stmt_seq
lower(Stmt const* s, Stmt_seq& stmts)
{
  switch (s->kind())
  {
    case expr_stmt: 
      lower(as<Expr_stmt>(s), stmts);
      break;
    case decl_stmt: 
      lower(as<Decl_stmt>(s), stmts);
      break;
    case match_stmt:
      lower(as<Match_stmt>(s), stmts);
      break;
    case case_stmt:
      lower(as<Case_stmt>(s), stmts);
      break;
    default:
      stmts.push_back(s);
      break;
  }

  return stmts;
}

} // namespace steve


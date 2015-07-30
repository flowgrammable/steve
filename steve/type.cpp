// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "steve/type.hpp"
#include "steve/expr.hpp"
#include "steve/decl.hpp"
#include "steve/stmt.hpp"
#include "steve/relation.hpp"
#include "steve/convert.hpp"
#include "steve/evaluate.hpp"

#include "lingo/memory.hpp"


namespace steve
{

// Returns a textual representation of the node's name.
char const*
get_type_name(Type_kind k)
{
  switch (k) {
    case kind_type: return "kind_type";
    case void_type: return "void_type";
    case boolean_type: return "boolean_type";
    case integer_type: return "integer_type";
    case constant_type: return "constant_type";
    case reference_type: return "reference_type";
    case function_type: return "function_type";
    case array_type: return "array_type";
    case tuple_type: return "tuple_type";
    case record_type: return "record_type";
    case variant_type: return "variant_type";
    case enum_type: return "enum_type";
    case match_type: return "match_type";
    case if_type: return "if_type";
    case seq_type: return "seq_type";
    case buffer_type: return "buffer_type";
    case until_type: return "until_type";
    case table_type: return "table_type";
    case flow_type: return "flow_type";
  }
  lingo_unreachable("unhandled type kind ({})", (int)k);
}


// -------------------------------------------------------------------------- //
//                             Type accessors

// Global types.
namespace
{

// Compares type values.
struct Type_less
{
  bool operator()(Type const& a, Type const& b) const
  {
    return less(&a, &b);
  }
};


Kind_type kind_;
Void_type void_;
Boolean_type bool_;

Unique_factory<Integer_type, Type_less> int_;
Unique_factory<Constant_type, Type_less> constant_;
Unique_factory<Reference_type, Type_less> reference_;
Unique_factory<Function_type, Type_less> function_;
Unique_factory<Array_type, Type_less> array_;
Unique_factory<Tuple_type, Type_less> tuple_;
Unique_factory<Record_type, Type_less> record_;
Unique_factory<Variant_type, Type_less> variant_;
Unique_factory<Enum_type, Type_less> enum_;
Unique_factory<Match_type, Type_less> mactch_;
Unique_factory<If_type, Type_less> if_;
Unique_factory<Seq_type, Type_less> seq_;
Unique_factory<Buffer_type, Type_less> buffer_;
Unique_factory<Until_type, Type_less> until_;


} // namespace


Kind_type const*
get_kind_type()
{
  return &kind_;
}


Void_type const*
get_void_type()
{
  return &void_;
}


Boolean_type const*
get_boolean_type()
{
  return &bool_;
}


Integer_type const*
get_integer_type(int p, Integer_sign s, Integer_order o)
{
  return int_.make(p, s, o);
}


Constant_type const*
get_constant_type(Type const* t)
{
  if (!is_object_type(t)) {
    error("'{}' is not an object type");
    return nullptr;
  }

  // const const T == const T
  if (Constant_type const* t1 = as<Constant_type>(t))
    return t1;

  return constant_.make(t);
}


Reference_type const*
get_reference_type(Type const* t)
{
  if (!is_object_type(t)) {
    error("cannot form a reference to '{}'");
    return nullptr;
  }

  // ref ref T == ref T
  if (Reference_type const* t1 = as<Reference_type>(t))
    return t1;
  
  return reference_.make(t);
}


Function_type const*
get_function_type(Type_seq const& a, Type const* r)
{
  return function_.make(a, r);
}


Array_type const*
get_array_type(Type const* t, Integer const& n)
{
  return array_.make(t, n);
}


Array_type const*
get_array_type(Type const* t, Expr const* e)
{
  if (!is_integer_expr(e)) {
    error (e->location(), "'{}' is not an integer expression");
    return nullptr;
  }

  Value v = evaluate(e);
  if (!v) {
    error (e->location(), "'{}' is not a constant expression");
    return nullptr;
  }
  return get_array_type(t, v.get_integer());
}


Tuple_type const*
get_tuple_type(Type_seq const& t)
{
  return tuple_.make(t);
}


// For every record type, there is a unique tuple whose
// components have the same type as the members of the
// record. This function returns that tuple type.
Tuple_type const*
get_tuple_type(Record_type const* t)
{
  Decl_seq const& ds = t->decl()->members();
  Type_seq ts;
  ts.reserve(ds.size());
  for (Decl const* d : ds)
    ts.push_back(d->type());
  return get_tuple_type(ts);
}


Record_type const*
get_record_type(Decl const* d)
{
  return record_.make(d);
}


Variant_type const*
get_variant_type(Decl const* d)
{
  return variant_.make(d);
}


Enum_type const*
get_enum_type(Decl const* d)
{
  return enum_.make(d);
}


// Returns a new match term.
Match_term const*
make_match_term(Expr const* e, Type const* t)
{
  return gc().make<Match_term>(e, t);
}


Match_type const*
get_match_type(Expr const* e, Match_seq const& m)
{
  return new Match_type(e, m);
}


If_type const*
get_if_type(Expr const* e, Type const* t)
{
  return new If_type(e, t);
}


Seq_type const*
get_seq_type(Type const* t, Expr const* e)
{
  return new Seq_type(t, e);
}


Buffer_type const*
get_buffer_type(Type const* t, Expr const* e)
{
  return new Buffer_type(t, e);
}


Until_type const*
get_until_type(Expr const* e, Type const* t)
{
  return new Until_type(e, t);
}


// -------------------------------------------------------------------------- //
//                             Type checking
//
// The following functions are used to verify that the operands of
// to an expression satsify the static (i.e., typing) requirements
// of that expression. For example, division of boolean values is
// not permitted.

// The type of a tuple expression is a tuple type
// comprised of the type of each element in the
// expression.
Type const*
type_tuple_expr(Expr_seq const& es)
{
  Type_seq ts;
  ts.reserve(es.size());
  for (Expr const* e : es)
    ts.push_back(e->type());
  return get_tuple_type(ts);
}


// -------------------------------------------------------------------------- //
//                       Typing rules for member expressions


namespace
{

Type const*
type_record_member_access(Location loc, Record_type const* t, std::size_t n)
{
  Record_decl const* rec = t->decl();
  Decl_seq const& mem = rec->members();
  if (n > mem.size()) {
    error(loc, "member index '{}' out of bounds", n);
    return nullptr;
  }
  return mem[n]->type();
}


Type const*
type_tuple_member_access(Location loc, Tuple_type const* t, std::size_t n)
{
  Type_seq const& ts = t->types();
  if (n > ts.size()) {
    error(loc, "tuple index '{}' out of bounds", n);
    return nullptr;
  }
  return ts[n];
}


} // namespace


Type const*
type_index_expr(Expr const* e, Expr const* n)
{
  // Make sure that we have an integer constant.
  Value v = evaluate_integer_constant(n);
  if (!v)
    return nullptr;
  
  // Check that the integer value is non-negative.
  //
  // TODO: If we have signed integer expressions, we should
  // be a bit more nuanced.
  //
  // TODO: Be aware of integer overflow (it's unlikely, but
  // it could happen).
  int index = v.get_integer().gets();
  if (index < 0) {
    error(n->location(), "negative member index '{}'", index);
    return nullptr;
  }


  Type const* t0 = e->type();
  Location loc = e->location();

  // For record types...
  if (Record_type const* rec = as<Record_type>(t0))
    return type_record_member_access(loc, rec, index);

  // For tuple types...
  if (Tuple_type const* tup = as<Tuple_type>(t0))
    return type_tuple_member_access(loc, tup, index);

  // Anything else?
  error(e->location(), "expression does not have composite type; "
                       "it has type '{}'", t0);
  return nullptr;
}


Type const*
type_member_expr(Expr const* e, Expr const* s)
{
  if (!is<Record_type>(e->type())) {
    error(e->location(), "'{}' does not have record type", e);
    return nullptr;
  }
  Record_decl const* rec = cast<Record_type>(e->type())->decl();

  // The selector must be an id-expression.
  if (!is<Id_expr>(s)) {
    error(s->location(), "invalid member selector '{}'", s);
    return nullptr;
  }
  Decl const* mem = cast<Id_expr>(s)->decl();

  // The declaration had better be a member. Otherwise the program
  // is internally inconsistent: lookup of a member name returned a
  // non-member.
  lingo_assert(is<Member_decl>(mem));
  lingo_assert(has_member(rec, cast<Member_decl>(mem)));

  return mem->type();
}

// -------------------------------------------------------------------------- //
//                      Statement Checking 


// Order case statements by their labels.
//
// TODO: If we allow ranges in case statements, then we have to
// do a lot more work to determine overlap. For example, we could
// have a case 2 and a case 0..10. That should be an error.
struct Case_less
{
  bool operator()(Stmt const* a, Stmt const* b)
  {
    Case_stmt const* c1 = cast<Case_stmt>(a);
    Case_stmt const* c2 = cast<Case_stmt>(b);
    return less(c1->label(), c2->label());
  }
};


// Check that the expression used is a member to the type that 
// is being decoded.
bool
check_match_stmt(Expr const* e, Stmt_seq const& sq)
{
  Type const* t = e->type();
  bool ok = true;

  std::set<Stmt const*, Case_less> cases(sq.begin(), sq.end());

  // TODO: Report each duplicate entry. This can be done by
  // inserting each element in turn.
  if (sq.size() > cases.size())
    error(Location::none, "duplicate match cases found");

  // Check that the type of each case label has the type
  // of the condition.
  for (Stmt const* s : sq) {
    lingo_assert(is<Case_stmt>(s));
    Case_stmt const* c = cast<Case_stmt>(s);
    Expr const* lab = c->label();
    if (lab->type() != t) {
      error(Location::none, "'{}' (of type '{}') does not have the "
                            "same type as the condition '{}'", 
                            lab, lab->type(), e, t);
      ok = false;
    }
  }

  return ok;
}

// -------------------------------------------------------------------------- //
//                            Declaration checking

// TODO: Factor initialization into a separate module.

namespace
{

bool
check_aggregate_init(Record_type const* t, Tuple_expr const* e)
{
  Type const* t0 = get_tuple_type(t);
  Type const* t1 = e->type();
  if (t0 != t1) {
    error(e->location(),
          "'{}' cannot be initialized from a tuple of type '{}", t, t1);
    return false;
  }
  return true;
}


bool
check_direct_init(Type const* t, Expr const* e)
{
  if (t != e->type()) {
    error(e->location(), 
          "initializer does not have type '{}'; "
          "it has type '{}'", t, e->type());
    return false;
  }
  return true;
}


} // namespace


// Check that the initializer is valid for the given type. 
// When the type of the iniitalized variable is a record type
// and the initializer is a tuple, aggregate initialization
// is used. Otherwise, direct initialization is used.
//
// TODO: If we support conversions, then the return value
// of this operation will be the 
bool
check_initializer(Type const* t, Expr const* e)
{
  if (Record_type const* rec = as<Record_type>(t))
    if (Tuple_expr const* tup = as<Tuple_expr>(e))
      return check_aggregate_init(rec, tup);
  return check_direct_init(t, e);
}


// -------------------------------------------------------------------------- //
//                            Return type checking

namespace
{


Type const* check_return_type(Stmt const*, Type const*);


// Check that any return statements in this block have the
// same type as `t`. Returns the last seen return type in
// block, or nullptr if no such returns exist.
Type const*
check_return_type(Block_stmt const* s, Type const* t)
{
  Type const* t0 = nullptr;

  for (Stmt const* s0 : *s) {
    // Check the nested statement. If we got a non-null
    // response then the statement was either a return
    // or a compound statement containing a return. Note
    // that the return could have been an error.
    //
    // In general, save the last such result. However,
    // if we had previously gotten an error, don't update
    // the most recent return value.
    if (Type const* t1 = check_return_type(s0, t))
      if (!is_error_node(t0))
        t0 = t1;
  }

  return t0;
}


// The semantics are similar to a block statement. Look through 
// all statementsand determine the return type for each one.
Type const*
check_return_type(Match_stmt const* s, Type const* t)
{
  Type const* t0 = nullptr;

  for (Stmt const* s0 : s->cases()) {
    if (Type const* t1 = check_return_type(s0, t))
      if (!is_error_node(t0))
        t0 = t1;
  }

  return t0;
}


// Check the return type for the statement of the of
// case label.
Type const*
check_return_type(Case_stmt const* s, Type const* t)
{
  return check_return_type(s->stmt(), t);
}


// Check that the type of the result type is the same
// as `t`.
//
// TODO: Weaken to allow conversions.
Type const*
check_return_type(Return_stmt const* s, Type const* t)
{
  Expr const* e = s->result();
  if (e->type() != t) {
    if (t == get_void_type()) {
      error(e->location(), "returning a value from a 'void' function");
      return make_error_node<Type>();
    }

    // Otherwise, peform conversion. Note that we have
    // to update the expression of the return statement
    // with the converted operand.
    //
    // NOTE: We could allow the `void` issue above to
    // fail in conversion (since values don't convert to
    // void), but the diagnostic above would be more
    // appropriate.
    //
    // TODO: This is kind of gross (but not entirely without
    // precedent -- we retroactively adjust the type of
    // enumerators). But it would be more elegant if the
    // creation of the return statement was done in a
    // context where the return type was available. But
    // we would need to define what that was.

    Expr const* c = convert(e, t);
    if (!c)
      return make_error_node<Type>();
    
    // TODO: Yuck.
    Return_stmt* s1 = const_cast<Return_stmt*>(s);
    s1->first = c;
    return t;
  }
  return t;
}


// Search for returns of the given statement and ensure
// that they have type `t`.
//
// TODO: We could also, at this point, ensure that each path 
// returns a value. Or we could do that later...
Type const*
check_return_type(Stmt const* s, Type const* t)
{
  lingo_assert(is_valid_node(s));
  switch (s->kind()) {
    case block_stmt:
      return check_return_type(cast<Block_stmt>(s), t);

    case return_stmt: 
      return check_return_type(cast<Return_stmt>(s), t);

    case match_stmt:
      return check_return_type(cast<Match_stmt>(s), t);

    case case_stmt:
      return check_return_type(cast<Case_stmt>(s), t);

    case empty_stmt:
    case expr_stmt:
    case decl_stmt:
    case do_stmt:
    case instruct_stmt:
      // These do not indicate return types.
      return nullptr;
  }
  lingo_unreachable("unhandled statement '{}'", s->node_name());
}


} // namesapce


// Check that the return statements in `s` match the function
// return type `t`.
bool
check_function_decl(Type const* t, Stmt const* s)
{
  // Check for/find a return type.
  Type const* r = check_return_type(s, t);
  if (is_error_node(r))
    return false;

  // If no return type was found, then the return type
  // of the function must be void.
  //
  // FIXME: Source location? Also, a more appropriate error
  // would be something like, "not all paths return a value"
  // or something like that.
  if (!r && t != get_void_type()) {
    error(Location::none, "no return statement in non-void function");
    return false;
  }

  return true;
}


} // namespace steve

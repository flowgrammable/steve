// Copyright (c) 2015 Andrew Sutton
// All rights reserved


#include "beaker/elaborator.hpp"
#include "beaker/type.hpp"
#include "beaker/expr.hpp"
#include "beaker/decl.hpp"
#include "beaker/stmt.hpp"
#include "beaker/convert.hpp"
#include "beaker/evaluator.hpp"
#include "beaker/error.hpp"
#include "beaker/builtin.hpp"
#include "beaker/actions.hpp"

#include <algorithm>
#include <iostream>
#include <set>


// -------------------------------------------------------------------------- //
// Declaration of entities


// Determine if d can be overloaded with the existing
// elements in the set.
void
Elaborator::overload(Overload& ovl, Decl* curr)
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
Elaborator::declare(Decl* d)
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
Elaborator::redeclare(Decl* d)
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
Elaborator::unqualified_lookup(Symbol const* sym)
{
  if (Scope::Binding* bind = stack.lookup(sym))
    return &bind->second;
  else
    return nullptr;
}



// Perform a qualified lookup of a name in the given scope.
// This searches only that scope for a binding for the identifier.
// If the scope is that of a record, the name may be a member of
// a base class.
Overload*
Elaborator::qualified_lookup(Scope* s, Symbol const* sym)
{
  if (Record_decl* d = as<Record_decl>(s->decl))
    return member_lookup(d, sym);

  if (Scope::Binding* bind = s->lookup(sym))
    return &bind->second;

  return nullptr;
}



Overload*
Elaborator::member_lookup(Record_decl* d, Symbol const* sym)
{
  do {
    if (Scope::Binding* bind = d->scope()->lookup(sym))
      return &bind->second;
    d = d->base()->declaration();
  } while (d);
  return nullptr;
}


// -------------------------------------------------------------------------- //
// Elaboration of types


inline bool
requires_definition(Type const* t)
{
  // A type T[n] requires a definition iff T requires
  // a definition.
  if (Array_type const* a = as<Array_type>(t))
    return requires_definition(a->type());

  // A user-defined type T requires a definition iff it
  // is not a reference or block type.
  if (is<Record_type>(t))
    return true;
  return false;
}


// Elaborate a type. If the type is requried to be a complete
// type then recursively elaborate it.
Type const*
Elaborator::elaborate_type(Type const* t)
{
  Type const* t1 = elaborate(t);
  if (requires_definition(t1))
    t1 = elaborate_def(t1);
  return t1;
}


Type const*
Elaborator::elaborate_def(Type const* t)
{
  if (Record_type const* r = as<Record_type>(t)) {
    elaborate_def(r->declaration());
    return t;
  }
  lingo_unreachable();
}



Type const*
Elaborator::elaborate(Type const* t)
{
  struct Fn
  {
    Elaborator& elab;

    Type const* operator()(Id_type const* t) { return elab.elaborate(t); }
    Type const* operator()(Boolean_type const* t) { return elab.elaborate(t); }
    Type const* operator()(Character_type const* t) { return elab.elaborate(t); }
    Type const* operator()(Integer_type const* t) { return elab.elaborate(t); }
    Type const* operator()(Function_type const* t) { return elab.elaborate(t); }
    Type const* operator()(Block_type const* t) { return elab.elaborate(t); }
    Type const* operator()(Array_type const* t) { return elab.elaborate(t); }
    Type const* operator()(Reference_type const* t) { return elab.elaborate(t); }
    Type const* operator()(Record_type const* t) { return elab.elaborate(t); }
    Type const* operator()(Void_type const* t) { return elab.elaborate(t); }

    Type const* operator()(Layout_type const* t) { return elab.elaborate(t); }
    Type const* operator()(Context_type const* t) { return elab.elaborate(t); }
    Type const* operator()(Table_type const* t) { return elab.elaborate(t); }
    Type const* operator()(Flow_type const* t) { return elab.elaborate(t); }
    Type const* operator()(Port_type const* t) { return elab.elaborate(t); }
    Type const* operator()(Key_type const* t) { return elab.elaborate(t); }
  };
  return apply(t, Fn{*this});
}


// The elaboration of an identifer as a type performs
// unqualified name lookup. The declaration associated
// with the name shall be a user-defined type or an
// alias.
//
// TODO: Support type aliases.
Type const*
Elaborator::elaborate(Id_type const* t)
{
  // Perform unqualified lookup.
  Overload* ovl = unqualified_lookup(t->symbol());
  if (!ovl) {
    String msg = format("no matching declaration for '{}'", *t);
    throw Lookup_error(locate(t), msg);
  }

  // We can't currently overload types, so this could
  // only mean that we found a funtion overload set.
  if (ovl->size() > 1) {
    String msg = format("'{}' does not name a type", *t);
    throw Lookup_error(locate(t), msg);
  }

  // Determine if the name is a type declaration.
  Decl* d = ovl->front();
  if (Record_decl* r = as<Record_decl>(d))
    return get_record_type(r);

  if (Layout_decl* l = as<Layout_decl>(d))
    return get_layout_type(l);

  String msg = format("'{}' does not name a type", *t);
  throw Lookup_error(locate(t), msg);
}


Type const*
Elaborator::elaborate(Boolean_type const* t)
{
  return t;
}


Type const*
Elaborator::elaborate(Character_type const* t)
{
  return t;
}


Type const*
Elaborator::elaborate(Integer_type const* t)
{
  return t;
}


// Elaborate each type in the function type.
Type const*
Elaborator::elaborate(Function_type const* t)
{
  Type_seq ts;
  ts.reserve(t->parameter_types().size());
  for (Type const* t1 : t->parameter_types())
    ts.push_back(elaborate(t1));
  Type const* r = elaborate(t->return_type());
  return get_function_type(ts, r);
}


Type const*
Elaborator::elaborate(Array_type const* t)
{
  Type const* t1 = elaborate(t->type());
  Expr* e = elaborate(t->extent());
  Expr* n = reduce(e);
  if (!n)
    throw Type_error({}, "non-constant array extent");
  return get_array_type(t1, n);
}

Type const*
Elaborator::elaborate(Block_type const* t)
{
  Type const* t1 = elaborate(t->type());
  return get_block_type(t1);
}


Type const*
Elaborator::elaborate(Reference_type const* t)
{
  Type const* t1 = elaborate(t->type());
  return get_reference_type(t1);
}


// No further elaboration is needed.
Type const*
Elaborator::elaborate(Record_type const* t)
{
  return t;
}


Type const*
Elaborator::elaborate(Void_type const* t)
{
  return t;
}


// No further elaboration is needed.
Type const*
Elaborator::elaborate(Layout_type const* t)
{
  return t;
}


Type const*
Elaborator::elaborate(Context_type const* t)
{
  return t;
}

// no further elaboration required
Type const*
Elaborator::elaborate(Table_type const* t)
{
  return t;
}

// no further elaboration required
Type const*
Elaborator::elaborate(Flow_type const* t)
{
  return t;
}


// No further elaboration required
Type const*
Elaborator::elaborate(Port_type const* t)
{
  return t;
}


// Nothing should have key type.
// This is an opaque type for use with the run time.
Type const*
Elaborator::elaborate(Key_type const* t)
{
  lingo_unreachable();
}


// -------------------------------------------------------------------------- //
// Elaboration of expressions

// Returns the type of an expression. This also annotates
// the expression by saving the computed type as part of
// the expression.
Expr*
Elaborator::elaborate(Expr* e)
{
  struct Fn
  {
    Elaborator& elab;

    Expr* operator()(Literal_expr* e) const { return elab.elaborate(e); }
    Expr* operator()(Id_expr* e) const { return elab.elaborate(e); }
    Expr* operator()(Decl_expr* e) const { return elab.elaborate(e); }
    Expr* operator()(Add_expr* e) const { return elab.elaborate(e); }
    Expr* operator()(Sub_expr* e) const { return elab.elaborate(e); }
    Expr* operator()(Mul_expr* e) const { return elab.elaborate(e); }
    Expr* operator()(Div_expr* e) const { return elab.elaborate(e); }
    Expr* operator()(Rem_expr* e) const { return elab.elaborate(e); }
    Expr* operator()(Neg_expr* e) const { return elab.elaborate(e); }
    Expr* operator()(Pos_expr* e) const { return elab.elaborate(e); }
    Expr* operator()(Eq_expr* e) const { return elab.elaborate(e); }
    Expr* operator()(Ne_expr* e) const { return elab.elaborate(e); }
    Expr* operator()(Lt_expr* e) const { return elab.elaborate(e); }
    Expr* operator()(Gt_expr* e) const { return elab.elaborate(e); }
    Expr* operator()(Le_expr* e) const { return elab.elaborate(e); }
    Expr* operator()(Ge_expr* e) const { return elab.elaborate(e); }
    Expr* operator()(And_expr* e) const { return elab.elaborate(e); }
    Expr* operator()(Or_expr* e) const { return elab.elaborate(e); }
    Expr* operator()(Not_expr* e) const { return elab.elaborate(e); }
    Expr* operator()(Call_expr* e) const { return elab.elaborate(e); }
    Expr* operator()(Dot_expr* e) const { return elab.elaborate(e); }
    Expr* operator()(Field_expr* e) const { return elab.elaborate(e); }
    Expr* operator()(Method_expr* e) const { return elab.elaborate(e); }
    Expr* operator()(Index_expr* e) const { return elab.elaborate(e); }
    Expr* operator()(Value_conv* e) const { return elab.elaborate(e); }
    Expr* operator()(Block_conv* e) const { return elab.elaborate(e); }
    Expr* operator()(Promotion_conv* e) const { return elab.elaborate(e); }
    Expr* operator()(Demotion_conv* e) const { return elab.elaborate(e); }
    Expr* operator()(Default_init* e) const { return elab.elaborate(e); }
    Expr* operator()(Copy_init* e) const { return elab.elaborate(e); }
    Expr* operator()(Reference_init* e) const { return elab.elaborate(e); }
    Expr* operator()(Reinterpret_cast* e) const { return elab.elaborate(e); }
    Expr* operator()(Field_name_expr* e) const { return elab.elaborate(e); }
    Expr* operator()(Field_access_expr* e) const { return elab.elaborate(e); }
    Expr* operator()(Get_port* e) const { return elab.elaborate(e); }
    Expr* operator()(Create_table* e) const { return elab.elaborate(e); }
  };

  return apply(e, Fn{*this});
}


// Literal expressions are fully elaborated at the point
// of construction.
Expr*
Elaborator::elaborate(Literal_expr* e)
{
  return e;
}


// The elaboration of an identifier requires performs
// unqualified name lookup. The associated declaration
// shall not declare a type.
//
// If lookup associates a single declaration D, with
// declared type T, with the name, then the type of
// the expression is determined as follows:
//
//  - if D is an object, the  type of the expression
//    is T&;
//  - otherwise, then the type is T.
//
// Lookup may associate a set of declarations (an
// overload set). A single declaration is selected
// by overload resolution (see call expressions).
//
// TODO: Allow overload sets of templates?
Expr*
Elaborator::elaborate(Id_expr* e)
{
  Location loc = locate(e);

  // Lookup the declaration for the identifier.
  Overload* ovl = unqualified_lookup(e->symbol());
  if (!ovl) {
    std::stringstream ss;
    ss << "no matching declaration for '" << *e->symbol() << '\'';
    throw Lookup_error(locs.get(e), ss.str());
  }

  // We can't resolve an overload without context,
  // so return the resolved overload set.
  if (ovl->size() > 1) {
    Expr* ret = new Overload_expr(ovl);
    locate(ret, loc);
    return ret;
  }

  // Get the declaration named by the symbol.
  Decl* d = ovl->front();

  // An identifier always refers to an object, so
  // these expressions have reference type.
  Type const* t = d->type();
  if (is_object(d))
    t = t->ref();

  // Return a new expression.
  Expr* ret = new Decl_expr(t, d);
  locate(ret, loc);

  return ret;
}


// This deoes not require elaboration.
Expr*
Elaborator::elaborate(Decl_expr* e)
{
  return e;
}


namespace
{

// Used to require the conversion of a reference to a
// value. Essentially, this unwraps the reference if
// needed.
Expr*
require_value(Elaborator& elab, Expr* e)
{
  e = elab.elaborate(e);
  e = convert_to_value(e);
  return e;
}


// Used to require the conversion of an expression
// to a given type. This returns nullptr if the convesion
// fails.
Expr*
require_converted(Elaborator& elab, Expr* e, Type const* t)
{
  e = elab.elaborate(e);
  e = convert(e, t);
  return e;
}


// The operands of a binary arithmetic expression are
// converted to rvalues. The converted operands shall have
// type int. The result of an arithmetic expression is an
// rvalue with type int.
template<typename T>
Expr*
check_binary_arithmetic_expr(Elaborator& elab, T* e)
{
  Type const* z = get_integer_type();
  Expr* c1 = require_converted(elab, e->first, z);
  Expr* c2 = require_converted(elab, e->second, z);
  if (!c1)
    throw Type_error({}, "left operand cannot be converted to 'int'");
  if (!c2)
    throw Type_error({}, "right operand cannot be converted to 'int'");

  // Rebuild the expression with the
  // converted operands.
  e->type_ = z;
  e->first = c1;
  e->second = c2;
  return e;
}


// The operands of a unary arithmetic expression are
// converted to rvalues. The converted operands shall
// have type int. The result of an arithmetic expression
// is an rvalue of type int.
template<typename T>
Expr*
check_unary_arithmetic_expr(Elaborator& elab, T* e)
{
  // Apply conversions
  Type const* z = get_integer_type();
  Expr* c = require_converted(elab, e->first, z);
  if (!c)
    throw Type_error({}, "operand cannot be converted to 'int'");

  // Rebuild the expression with the converted operands.
  e->type_ = z;
  e->first = c;
  return e;
}


// Check all flows within a table initializer
// to confirm that the keys given are of the
// correct type.
//
// FIXME: confirm that all flows have unique keys
bool
check_table_initializer(Elaborator& elab, Table_decl* d)
{
  assert(is<Table_type>(d->type()));

  Table_type const* table_type = as<Table_type>(d->type());

  Type_seq const& field_types = table_type->field_types();

  // key track of the flow in the initializer
  int flow_cnt = 0;

  for (auto f : d->body()) {
    assert(is<Flow_decl>(f));

    ++flow_cnt;
    Flow_decl* flow = as<Flow_decl>(f);
    Expr_seq const& key = flow->keys();

    // check for equally size keys
    if (field_types.size() != key.size()) {
      std::stringstream ss;
      ss << "Flow " << *f << " does not have the same number of keys as"
         << "table: " << *d->name();
      throw Type_error({}, ss.str());

      return false;
    }

    // check that each subkey type can be converted
    // to the type specified by the table
    auto table_subtype = field_types.begin();
    auto subkey = key.begin();

    Expr_seq new_key;
    for(;table_subtype != field_types.end() && subkey != key.end(); ++table_subtype, ++subkey)
    {
      Expr* e = require_converted(elab, *subkey, *table_subtype);
      if (e)
        new_key.push_back(e);
      else {
        std::stringstream ss;
        ss << "Failed type conversion in flow #" << flow_cnt << " subkey: " << **subkey;
        throw Type_error({}, ss.str());
      }
    }

    flow->keys_ = new_key;
  }

  return true;
}


} // namespace


Expr*
Elaborator::elaborate(Add_expr* e)
{
  return check_binary_arithmetic_expr(*this, e);
}


Expr*
Elaborator::elaborate(Sub_expr* e)
{
  return check_binary_arithmetic_expr(*this, e);
}


Expr*
Elaborator::elaborate(Mul_expr* e)
{
  return check_binary_arithmetic_expr(*this, e);
}


Expr*
Elaborator::elaborate(Div_expr* e)
{
  return check_binary_arithmetic_expr(*this, e);
}


Expr*
Elaborator::elaborate(Rem_expr* e)
{
  return check_binary_arithmetic_expr(*this, e);
}


//
Expr*
Elaborator::elaborate(Neg_expr* e)
{
  return check_unary_arithmetic_expr(*this, e);
}


Expr*
Elaborator::elaborate(Pos_expr* e)
{
  return check_unary_arithmetic_expr(*this, e);
}


namespace
{

// The operands of an equality expression are converted
// to rvalues. The operands shall have the same type. The
// result of an equality expression is an rvalue of type
// bool.
//
// TODO: Update equality comparison for new types.
Expr*
check_equality_expr(Elaborator& elab, Binary_expr* e)
{
  // Apply conversions.
  Type const* b = get_boolean_type();
  Expr* e1 = require_value(elab, e->first);
  Expr* e2 = require_value(elab, e->second);

  // Check types.
  if (e1->type() != e2->type())
    throw Type_error({}, "operands have different types");

  e->type_ = b;
  e->first = e1;
  e->second = e2;
  return e;
}

} // naespace


Expr*
Elaborator::elaborate(Eq_expr* e)
{
  return check_equality_expr(*this, e);
}


Expr*
Elaborator::elaborate(Ne_expr* e)
{
  return check_equality_expr(*this, e);
}



namespace
{

// The operands of an ordering expression are converted
// to rvalues. The operands shall have type int. The
// result of an equality expression is an rvalue of type
// bool.
//
// TODO: Update the ordering operands for new types.
Expr*
check_ordering_expr(Elaborator& elab, Binary_expr* e)
{
  // Apply conversions.
  Type const* z = get_integer_type();
  Type const* b = get_boolean_type();
  Expr* c1 = require_converted(elab, e->first, z);
  Expr* c2 = require_converted(elab, e->second, z);
  if (!c1)
    throw Type_error({}, "left operand cannot be converted to 'int'");
  if (!c2)
    throw Type_error({}, "right operand cannot be converted to 'int'");

  // Rebuild the expression with the converted
  // operands.
  e->type_ = b;
  e->first = c1;
  e->second = c2;
  return e;
}


} // naespace


Expr*
Elaborator::elaborate(Lt_expr* e)
{
  return check_ordering_expr(*this, e);
}


Expr*
Elaborator::elaborate(Gt_expr* e)
{
  return check_ordering_expr(*this, e);
}


Expr*
Elaborator::elaborate(Le_expr* e)
{
  return check_ordering_expr(*this, e);
}


Expr*
Elaborator::elaborate(Ge_expr* e)
{
  return check_ordering_expr(*this, e);
}


namespace
{


// TODO: Document me!
Expr*
check_binary_logical_expr(Elaborator& elab, Binary_expr* e)
{
  // Apply conversions.
  Type const* b = get_boolean_type();
  Expr* c1 = require_converted(elab, e->first, b);
  Expr* c2 = require_converted(elab, e->second, b);
  if (!c1)
    throw Type_error({}, "left operand cannot be converted to 'bool'");
  if (!c2)
    throw Type_error({}, "right operand cannot be converted to 'bool'");

  // Rebuild the expression with the converted
  // operands.
  e->type_ = b;
  e->first = c1;
  e->second = c2;
  return e;
}


// TODO: Document me!
Expr*
check_unary_logical_expr(Elaborator& elab, Unary_expr* e)
{
  Type const* b = get_boolean_type();
  Expr* c = require_converted(elab, e->first, b);
  if (!c)
    throw Type_error({}, "operand cannot be converted to 'bool'");

  // Rebuild the expression with the converted
  // operand.
  e->type_ = b;
  e->first = c;
  return e;
}

} // namespace


Expr*
Elaborator::elaborate(And_expr* e)
{
  return check_binary_logical_expr(*this, e);
}


Expr*
Elaborator::elaborate(Or_expr* e)
{
  return check_binary_logical_expr(*this, e);
}


Expr*
Elaborator::elaborate(Not_expr* e)
{
  return check_unary_logical_expr(*this, e);
}


// Diagnose failures of argument conversion for
// function calls.
void
Elaborator::on_call_error(Expr_seq const& conv,
                          Expr_seq const& args,
                          Type_seq const& parms)
{
  if (args.size() < parms.size())
    throw Type_error({}, "too few arguments");
  if (parms.size() < args.size())
    throw Type_error({}, "too many arguments");

  for (std::size_t i = 0; i < parms.size(); ++i) {
    Expr const* c = conv[i];
    if (!c) {
      Expr const* a = args[i];
      Type const* p = parms[i];
      String s = format(
        "type mismatch in argument {} (expected {} but got {})\n",
        i + 1,
        *a->type(),
        *p);

      // FIXME: Don't fail on the first error.
      throw Type_error({}, s);
    }
  }
}


namespace
{

// Returns a dot-expr if e is of the form x.ovl.
// Otherwise, returns nullptr.
inline Dot_expr*
as_method_overload(Dot_expr* e)
{
  if (is<Overload_expr>(e->member()))
    return e;
  return nullptr;
}


inline Dot_expr*
as_method_overload(Expr* e)
{
  if (Dot_expr* dot = as<Dot_expr>(e))
    return as_method_overload(dot);
  return nullptr;
}


// Returns a dot-expr if e is of the form x.m or
// x.ovl. Otherwise, returns nullptr.
inline Dot_expr*
as_method(Expr* e)
{
  if (Dot_expr* dot = as<Dot_expr>(e)) {
    // x.y refers to a method.
    if (Method_expr* m = as<Method_expr>(dot))
      return m;

    // x.y refers to a field.
    if (is<Field_expr>(dot))
      return nullptr;

    // By elimination of cases, it must be a
    // method overload.
    lingo_assert(as_method_overload(dot));
    return dot;
  }
  return nullptr;
}


} // namespace


Expr*
Elaborator::call(Function_decl* d, Expr_seq const& args)
{
  Function_type const* t = d->type();

  // Perform argument conversion.
  Type_seq const& parms = t->parameter_types();
  Expr_seq conv = convert(args, parms);
  if (std::any_of(conv.begin(), conv.end(), [](Expr const* p) { return !p; }))
    return nullptr;

  // Update the expression with the return type
  // of the named function.
  Expr* ref = new Decl_expr(t, d);
  return new Call_expr(t->return_type(), ref, args);
}


Expr*
Elaborator::resolve(Overload_expr* ovl, Expr_seq const& args)
{
  // Build a set of call expressions to the
  // declarations in the overload set.
  Expr_seq cands;
  Overload& decls = ovl->declarations();
  cands.reserve(decls.size());
  for (Decl* d : decls) {
    if (Expr* e = call(cast<Function_decl>(d), args))
      cands.push_back(e);
  }

  // FIXME: If the call is to a method, then write
  // out the method format for the call. Same as below.
  if (cands.empty()) {
    Location loc = locate(ovl);
    String msg = format("{}: no matching function for '{}'", loc, *ovl->name());
    std::cerr << msg << '\n';
    std::cerr << loc << ": candidates are:\n";
    for (Decl* d : decls) {
      std::cerr << format("{}: {}\n", locate(d), *d);
    }
    throw Type_error(locate(ovl), msg);
  }

  // TODO: Select the best candidate.
  if (cands.size() > 1) {
    String msg = format("call to function '{}' is ambiguous", *ovl->name());
  }

  return cands.front();
}



// Resolve a function call. The target of a function
// may be one of the following:
//
//    - a function f(args...)
//    - a function overload set ovl(args...)
//    - a method x.m(args...)
//    - a method overload set x.ovl(args...)
//
// In the case where the target is a method or
// member overload set of the form x.y(args...)
// the containing object x is added to the front
// of the argument list, and the funtion target
// is simply the method or overlaod set. That is,
// the following transformation is made:
//
//    x.y(args...) ~> y(x.args...)
//
// Let y be the new function target.
//
// If the function target is an overload set, select
// a function by overload resolution.
//
// TODO: If we support function objects by way of
// overloading the call operator, then the target
// could be an object or field of class type with
// one or more member call operators.
//
// TODO: Would it be better to differentiate
// function and method call and have those dealt
// with separately on the back end(s)?
//
// TODO: Support the lookup of member funtions using
// free-function notation:
//
//    f(x, args...) ~> x.f(args...)
//
// Applying this transformation might just entail
// the creation of a fake expression and its elaboration
// to resolve a method or overload set.
Expr*
Elaborator::elaborate(Call_expr* e)
{
  // Apply lvalue to rvalue conversion and ensure that
  // the target (ultimately) has function type.
  Expr* f = require_value(*this, e->target());
  if (!is_callable(f))
    throw Type_error({}, "object is not callable");

  // Elaborate the arguments (in place) prior to
  // conversion. Do it now so we don't re-elaborate
  // arguments during overload resolution.
  //
  // Apply lvalue conversion on all arguments
  Expr_seq& args = e->arguments();
  for (Expr*& a : args)
    a = elaborate(a);

  // If the target is of the form x.m or x.ovl, insert x
  // into the argument list and update the function target.
  if (Dot_expr* dot = as_method(f)) {
      // Build the "this" argument.
      Expr* self = dot->container();
      args.insert(args.begin(), self);

      // Adjust the function target.
      f = dot->member();
  }

  // Handle the case where f is an overload set.
  if (Overload_expr* ovl = as<Overload_expr>(f)) {
    return resolve(ovl, args);
  } else {
    // If it's not an overload set, it has function type.
    Function_type const* t = cast<Function_type>(f->type());

    // Perform argument conversion.
    Type_seq const& parms = t->parameter_types();
    Expr_seq conv = convert(args, parms);
    if (std::any_of(conv.begin(), conv.end(), [](Expr const* p) { return !p; }))
      on_call_error(conv, args, parms);

    // Update the expression with the return type
    // of the named function.
    e->type_ = t->return_type();
    e->first = f;
    e->second = conv;
  }

  // Guarantee that f is an expression that refers
  // to a declaration.
  lingo_assert(is<Decl_expr>(f) &&
               is<Function_decl>(cast<Decl_expr>(f)->declaration()));

  // Update the call expression before returning.
  return e;
}


namespace
{

// Search the base classes for the given field.
//
// TODO: Support multiple base classes.
void
get_path(Record_decl* r, Field_decl* f, Field_path& p)
{
  // Search the record for the given fields.
  Decl_seq const& fs = r->fields();
  auto iter = std::find(fs.begin(), fs.end(), f);
  if (iter != fs.end()) {
    // Compute the offset adjustment for this member.
    // A virtual table reference counts as a subobject, and
    // so does a base class sub-object.
    int a = 0;
    if (r->vref())
      ++a;
    if (r->base())
      ++a;
    p.push_back(std::distance(fs.begin(), iter) + a);
    return;
  }

  // Recursively search the base class.
  if (r->base()) {
    p.push_back(0);
    get_path(r->base()->declaration(), f, p);
  }
}


// Construct a sequence of indexes through the record and
// up to the given field. The resulting path shall be
// a non-empty sequence of indexes.
Field_path
get_path(Record_decl* r, Field_decl* f)
{
  Field_path p;
  get_path(r, f, p);
  lingo_assert(!p.empty());
  return p;
}


} // namespace


// TODO: Document the semantics of member access.
Expr*
Elaborator::elaborate(Dot_expr* e)
{
  Expr* e1 = elaborate(e->container());
  if (!is<Reference_type>(e1->type())) {
    std::stringstream ss;
    ss << "cannot access a member of a non-object";
    throw Type_error({}, ss.str());
  }

  // Get the non-reference type of the outer object
  // so we can perform qualified lookup.
  //
  // TODO: If we support modules, we would need to allow
  // for different kinds of scopes here.
  Record_type const* t1 = as<Record_type>(e1->type()->nonref());
  if (!t1) {
    std::stringstream ss;
    ss << "object does not have record type";
    throw Type_error({}, ss.str());
  }
  Scope* s = t1->declaration()->scope();

  // We expect the member to be an unresolved id expression.
  // If it isn't, there's not much we can do with it.
  //
  // TODO: Maybe allow a literal value in this position
  // to support tuple access?
  //
  //    t.0 -- get the first tuple element?
  Expr* e2 = e->member();
  if (!is<Id_expr>(e2)) {
    String msg = format("invalid member '{}'", *e2);
    throw Type_error(locate(e2), msg);
  }
  Id_expr* id = cast<Id_expr>(e2);

  // Perform qualified lookup on the member.
  Overload* ovl = qualified_lookup(s, id->symbol());
  if (!ovl) {
    String msg = format("no member matching '{}'", *id);
    throw Lookup_error(locate(id), msg);
  }

  // If we get a single declaration, return a corresponding
  // expression.
  if (ovl->size() == 1) {
    Decl*d = ovl->front();
    e2 = new Decl_expr(d->type(), d);
    if (Field_decl* f = as<Field_decl>(d)) {
      Type const* t2 = e2->type()->ref();
      Field_path p = get_path(t1->declaration(), f);
      return new Field_expr(t2, e1, e2, f, p);
    }
    if (Method_decl* m = as<Method_decl>(d)) {
      return new Method_expr(e1, e2, m);
    }
  }

  // Otherwise, if the name resolves to a set of declarations,
  // then the declaration is still unresolved. Update the
  // expression with the overload set and defer until we find
  // a function call.
  else {
    e->first = e1;
    e->second = new Overload_expr(ovl);
    return e;
  }

  // Otherwise, this is an error.
  std::stringstream ss;
  ss << "invalid member reference";
  throw Type_error({}, ss.str());
}


Expr*
Elaborator::elaborate(Field_expr* e)
{
  return e;
}


Expr*
Elaborator::elaborate(Method_expr* e)
{
  return e;
}


// In the expression e1[e2], e1 shall be an object of
// array type T[N] (for some N) or block type T[]. The
// expression e2 shall be an integer value. The result
// type of the expressions is ref T.
//
// Note that e1 is not converted to a value, and in fact
// *must* be a reference to an object. Converting to a
// value will prevent me from creating element pointers
// in code gen, because we need the base pointer from
// which to compute offsets.
Expr*
Elaborator::elaborate(Index_expr* e)
{
  Expr* e1 = elaborate(e->first);
  if (!is<Reference_type>(e1->type())) {
    std::stringstream ss;
    ss << "cannot index into a value";
    throw Type_error({}, ss.str());
  }

  // Get the non-reference type of the array.
  //
  // FIXME: Does this require a value transformation?
  // We don't (yet?) have array literals, so I generally
  // expect that this *must* be a reference to an array.
  //
  // TODO: Allow block type.
  Array_type const* t = as<Array_type>(e1->type()->nonref());
  if (!t) {
    std::stringstream ss;
    ss << "object does not have array type";
    throw Type_error({}, ss.str());
  }

  // The index shall be an integer value.
  Expr* e2 = require_converted(*this, e->second, get_integer_type());

  // The result type shall be ref T.
  e->type_ = get_reference_type(t->type());
  e->first = e1;
  e->second = e2;

  return e;
}


// NOTE: Conversions are created after their source
// expressions  have been elaborated. No action is
// required.

Expr*
Elaborator::elaborate(Value_conv* e)
{
  return e;
}


Expr*
Elaborator::elaborate(Block_conv* e)
{
  return e;
}


Expr*
Elaborator::elaborate(Promotion_conv* e)
{
  return e;
}


Expr*
Elaborator::elaborate(Demotion_conv* e)
{
  return e;
}


// TODO: I probably need to elaborate the type.
Expr*
Elaborator::elaborate(Default_init* e)
{
  e->type_ = elaborate(e->type_);
  return e;
}


Expr*
Elaborator::elaborate(Copy_init* e)
{
  // Elaborate the type.
  e->type_ = elaborate(e->type_);

  // If copying into a reference, we're actually
  // performing reference initialization. Create
  // a new node and elaborate it.
  if (is<Reference_type>(e->type())) {
    Reference_init* init = new Reference_init(e->type(), e->value());
    return elaborate(init);
  }

  // Otherwise, this actually a copy.
  //
  // TOOD: This should perform a lookup to find a
  // function that implements copies. It could be
  // bitwise copy, a memberwise copy, or a copy
  // constructor.

  // Convert the value to the resulting type.
  Expr* c = require_converted(*this, e->first, e->type_);
  e->first = elaborate(e->first);
  if (!c) {
    std::stringstream ss;
    ss << "type mismatch in copy initializer (expected "
       << *e->type() << " but got " << *e->value()->type() << ')';
    throw Type_error({}, ss.str());
  }
  e->first = c;

  return e;
}


// Note that this is only ever called from the
// elaborator for copy initialization. The type must
// already be elaborated.
Expr*
Elaborator::elaborate(Reference_init* e)
{
  Expr* obj = elaborate(e->object());

  // A reference can only be bound to an object.
  if (!is<Reference_type>(obj->type())) {
    throw Type_error({}, "binding reference to temporary");
  }

  // TODO: Allow t2 to be derived from t1.
  //
  //    struct B { };
  //    struct D : B { };
  //
  //    var obj : D;
  //    var ref : B& = obj;
  //
  // TODO: Allow t2 to be less cv qualified than t1.
  // That would allow bindings to constants:
  //
  //    var T x;
  //    var T const& c = x;
  Type const* t1 = e->type();
  Type const* t2 = obj->type();
  if (t1->nonref() != t2->nonref()) {
    std::stringstream ss;
    ss << "binding reference to an object of a different type"
       << "(expected " << *t1 << " but got " << *t2 << ')';
    throw Type_error({}, ss.str());
  }

  // Update the expression.
  e->first = obj;

  return e;
}


// Reinterpret casts can only be performed on objects of
// reference or block type. They can be cast to either
// scalar or pointer type.
Expr*
Elaborator::elaborate(Reinterpret_cast* e)
{
  Expr* target = e->expression();
  if (is<Reference_type>(target->type()) || is<Block_type>(target->type())) {
    std::stringstream ss;
    ss << *e << " is not of ref or block type.";
    throw Type_error({}, ss.str());
  }

  return e;
}


// Names a field within a layout to be extracted
Expr*
Elaborator::elaborate(Field_name_expr* e)
{
  // maintain every declaration that the field
  // name expr refers to
  Decl_seq decls;
  Expr_seq ids = e->identifiers();

  // confirm that each identifier is a member of the prior element
  // second should always be an element of first, unless first is the
  // last element of the list of identifiers
  if (ids.size() <= 1) {
    throw Type_error({}, "Invalid field name expr with only one valid field.");
  }

  auto first = ids.begin();
  auto second = first + 1;

  Id_expr* id1 = as<Id_expr>(*first);

  // previous
  Layout_decl* prev = nullptr;

  if (id1) {
    Decl* d = stack.lookup(id1->symbol())->second.front();
    if (Layout_decl* lay = as<Layout_decl>(d)) {
      prev = lay;
    }
  }
  else {
    std::stringstream ss;
    ss << "Invalid layout identifier: " << *id1;
    throw Type_error({}, ss.str());
  }

  decls.push_back(prev);

  // the first one is always an identifier to a layout decl
  while(second != ids.end()) {
    if (!prev) {
      std::stringstream ss;
      ss << "Invalid layout identifier: " << *id1;
      throw Type_error({}, ss.str());
    }

    id1 = as<Id_expr>(*first);

    if (!id1) {
      std::stringstream ss;
      ss << "Invalid layout identifier: " << *id1;
      throw Type_error({}, ss.str());
    }

    Id_expr* id2 = as<Id_expr>(*second);

    if (!id2) {
      std::stringstream ss;
      ss << "Invalid layout identifier: " << *id2;
      throw Type_error({}, ss.str());
    }

    // if we can find the field
    // then set prev equal to the new field
    if (Field_decl* f = find_field(prev, id2->symbol())) {
      // NOTE: if this ever fails theres probably a reference type
      // wrapping this thing
      if (Layout_type const* lt = as<Layout_type>(f->type())) {
        prev = lt->declaration();
      }
      else {
        prev = nullptr;
      }
      decls.push_back(f);
    }
    else {
      std::stringstream ss;
      ss << "Field " << *id2 << " is not a member of " << *id1;
      throw Type_error({}, ss.str());
    }

    // move the iterators
    ++first;
    ++second;
  }


  e->decls_ = decls;

  // the type is the type of the final declaration
  Type const* t = decls.back()->type();
  if (!t) {
    std::stringstream ss;
    ss << "Field expression" << *e << " of unknown type.";
    throw Type_error({}, ss.str());
  }
  e->type_ = t;

  return e;
}


// Field access expressions differ from Field
// name expressions in that they require an extraction
// before being used whereas field name expression
// are used within extracts declarations to refer to a specifiv
// field.
Expr*
Elaborator::elaborate(Field_access_expr* e)
{
  auto binding = stack.lookup(e->name());

  if (!binding) {
    std::stringstream ss;
    ss << *e << " used but not extracted.";
    throw Type_error({}, ss.str());
  }

  // maintain every declaration that the field
  // name expr refers to
  Decl_seq decls;
  Expr_seq ids = e->identifiers();

  // confirm that each identifier is a member of the prior element
  // second should always be an element of first, unless first is the
  // last element of the list of identifiers
  if (ids.size() <= 1) {
    throw Type_error({}, "Invalid field name expr with only one valid field.");
  }

  auto first = ids.begin();
  auto second = first + 1;

  Id_expr* id1 = as<Id_expr>(*first);

  // previous
  Layout_decl* prev = nullptr;

  if (id1) {
    Decl* d = stack.lookup(id1->symbol())->second.front();
    if (Layout_decl* lay = as<Layout_decl>(d)) {
      prev = lay;
    }
  }
  else {
    std::stringstream ss;
    ss << "Invalid layout identifier: " << *id1;
    throw Type_error({}, ss.str());
  }

  decls.push_back(prev);

  // the first one is always an identifier to a layout decl
  while(second != ids.end()) {
    if (!prev) {
      std::stringstream ss;
      ss << "Invalid layout identifier: " << *id1;
      throw Type_error({}, ss.str());
    }

    id1 = as<Id_expr>(*first);

    if (!id1) {
      std::stringstream ss;
      ss << "Invalid layout identifier: " << *id1;
      throw Type_error({}, ss.str());
    }

    Id_expr* id2 = as<Id_expr>(*second);

    if (!id2) {
      std::stringstream ss;
      ss << "Invalid layout identifier: " << *id2;
      throw Type_error({}, ss.str());
    }

    // if we can find the field
    // then set prev equal to the new field
    if (Field_decl* f = find_field(prev, id2->symbol())) {
      // NOTE: if this ever fails theres probably a reference type
      // wrapping this thing
      if (Layout_type const* lt = as<Layout_type>(f->type())) {
        prev = lt->declaration();
      }
      else {
        prev = nullptr;
      }

      decls.push_back(f);
    }
    else {
      std::stringstream ss;
      ss << "Field " << *id2 << " is not a member of " << *id1;
      throw Type_error({}, ss.str());
    }

    // move the iterators
    ++first;
    ++second;
  }


  e->decls_ = decls;

  // the type is the type of the final declaration
  Type const* t = decls.back()->type();
  if (!t) {
    std::stringstream ss;
    ss << "Field expression" << *e << " of unknown type.";
    throw Type_error({}, ss.str());
  }

  e->type_ = get_reference_type(t);

  return e;
}



// -------------------------------------------------------------------------- //
// Elaboration of builtins

Expr*
Elaborator::elaborate(Get_port* e)
{
  // elaborate it as a call expr
  Call_expr* call = as<Call_expr>(e);
  return elaborate(call);
}


Expr*
Elaborator::elaborate(Create_table* e)
{
  // elaborate it as a call expr
  Call_expr* call = as<Call_expr>(e);
  return elaborate(call);
}


// -------------------------------------------------------------------------- //
// Elaboration of declarations

// Elaborate a declaration. This returns true if
// elaboration succeeds and false otherwise.
Decl*
Elaborator::elaborate(Decl* d)
{
  struct Fn
  {
    Elaborator& elab;
    Decl* operator()(Variable_decl* d) const { return elab.elaborate(d); }
    Decl* operator()(Function_decl* d) const { return elab.elaborate(d); }
    Decl* operator()(Parameter_decl* d) const { return elab.elaborate(d); }
    Decl* operator()(Record_decl* d) const { return elab.elaborate(d); }
    Decl* operator()(Field_decl* d) const { return elab.elaborate(d); }
    Decl* operator()(Method_decl* d) const { return elab.elaborate(d); }
    Decl* operator()(Module_decl* d) const { return elab.elaborate(d); }

    // network declarations
    Decl* operator()(Layout_decl* d) const { return elab.elaborate(d); }
    Decl* operator()(Decode_decl* d) const { return elab.elaborate(d); }
    Decl* operator()(Table_decl* d) const { return elab.elaborate(d); }
    Decl* operator()(Key_decl* d) const { return elab.elaborate(d); }
    Decl* operator()(Flow_decl* d) const { return elab.elaborate(d); }
    Decl* operator()(Port_decl* d) const { return elab.elaborate(d); }
    Decl* operator()(Extracts_decl* d) const { return elab.elaborate(d); }
    Decl* operator()(Rebind_decl* d) const { return elab.elaborate(d); }
  };

  return apply(d, Fn{*this});
}


// The type of the initializer shall match the declared type
// of the variable.
//
// The variable is declared prior to the elaboration of its
// initializer.
Decl*
Elaborator::elaborate(Variable_decl* d)
{
  d->type_ = elaborate_type(d->type_);

  // Declare the variable.
  declare(d);

  // Elaborate the initializer. Note that the initializers
  // type must be the same as that of the declaration.
  d->init_ = elaborate(d->init());

  // Annotate the initializer with the declared
  // object.
  //
  // TODO: This will probably be an expression in
  // the future.
  cast<Init>(d->init())->decl_ = d;

  return d;
}


// The types of return expressions shall match the declared
// return type of the function.
Decl*
Elaborator::elaborate(Function_decl* d)
{
  throw Type_error(locate(d), "function declaration in block scope");
}


// Elaborate a parameter declaration. This simply declares
// the parameter in the current scope.
Decl*
Elaborator::elaborate(Parameter_decl* d)
{
  d->type_ = elaborate_type(d->type_);
  declare(d);
  return d;
}


// FIXME: Allow records in block scope?
Decl*
Elaborator::elaborate(Record_decl* d)
{
  throw Type_error(locate(d), "record declaration in block scope");
}


// There is no single pass elaborator for fields.
Decl*
Elaborator::elaborate(Field_decl* d)
{
  lingo_unreachable();
}


// There is no single pass elaborator for methods.
Decl*
Elaborator::elaborate(Method_decl* d)
{
  lingo_unreachable();
}


// Elaborate the module. Modules use a two phase
// lookup mechanism.
Decl*
Elaborator::elaborate(Module_decl* m)
{
  Scope_sentinel scope(*this, m);

  // enter a pipeline block
  pipelines.new_pipeline(m);

  for (Decl*& d : m->decls_)
    d = elaborate_decl(d);
  for (Decl*& d : m->decls_)
    d = elaborate_def(d);
  return m;
}



// ------------------------------------------------------------ //
//          Network specific declarations


Decl*
Elaborator::elaborate(Layout_decl* d)
{
  throw Type_error(locate(d), "layout declaration in block scope");
}


// Insert the implicit this parameter and adjust the
// type of the declaration.
Decl*
Elaborator::elaborate(Decode_decl* d)
{
  throw Type_error(locate(d), "decode declaration in block scope");
}


Decl*
Elaborator::elaborate(Table_decl* d)
{
  throw Type_error(locate(d), "table declaration in block scope");
}


// Elaborating a key decl checks whether
// or not the keys name valid field within
// layouts
Decl*
Elaborator::elaborate(Key_decl* d)
{
  // declare(d);

  // confirm this occurs within the
  // context of a table
  if (!is<Table_decl>(stack.context())) {
    std::stringstream ss;
    ss << "Key appearing outside the context of a table declaration: " << *d;
    throw Type_error({}, ss.str());
  }


  // maintain every declaration that the field
  // name expr refers to
  Decl_seq decls;
  Expr_seq ids = d->identifiers();

  // confirm that each identifier is a member of the prior element
  // second should always be an element of first, unless first is the
  // last element of the list of identifiers
  if (ids.size() <= 1) {
    throw Type_error({}, "Invalid key with only one valid field.");
  }

  auto first = ids.begin();
  auto second = first + 1;

  Id_expr* id1 = as<Id_expr>(*first);

  // previous
  Layout_decl* prev = nullptr;

  if (id1) {
    Decl* d = stack.lookup(id1->symbol())->second.front();
    if (Layout_decl* lay = as<Layout_decl>(d)) {
      prev = lay;
    }
  }
  else {
    std::stringstream ss;
    ss << "Invalid layout identifier: " << *id1;
    throw Type_error({}, ss.str());
  }

  decls.push_back(prev);

  // the first one is always an identifier to a layout decl
  while(second != ids.end()) {
    if (!prev) {
      std::stringstream ss;
      ss << "Invalid layout identifier: " << *id1;
      throw Type_error({}, ss.str());
    }

    id1 = as<Id_expr>(*first);

    if (!id1) {
      std::stringstream ss;
      ss << "Invalid layout identifier: " << *id1;
      throw Type_error({}, ss.str());
    }

    Id_expr* id2 = as<Id_expr>(*second);

    if (!id2) {
      std::stringstream ss;
      ss << "Invalid layout identifier: " << *id2;
      throw Type_error({}, ss.str());
    }

    // if we can find the field
    // then set prev equal to the new field
    if (Field_decl* f = find_field(prev, id2->symbol())) {
      // this precludes the very first id from becoming the prev twice
      // since only fields can have reference type and the first is always
      // an identifier to a layout
      //
      // FIXME: there's something not quite correct here
      // What happens when we get a record type which can't belong here?
      if (Reference_type const* ref = as<Reference_type>(f->type())) {
        if (Layout_type const* lt = as<Layout_type>(ref->nonref())) {
          prev = lt->declaration();
        }
        // Does this correctly handle it with the check
        // at the beginning of the loop?
        else
          prev = nullptr;
      }
      decls.push_back(f);
    }
    else {
      std::stringstream ss;
      ss << "Field " << *id2 << " is not a member of " << *id1;
      throw Type_error({}, ss.str());
    }

    // move the iterators
    ++first;
    ++second;
  }


  d->decls_ = decls;

  // the type is the type of the final declaration
  Type const* t = decls.back()->type();
  if (!t) {
    std::stringstream ss;
    ss << "Field expression" << *d << " of unknown type.";
    throw Type_error({}, ss.str());
  }
  d->type_ = t;

  return d;
}


Decl*
Elaborator::elaborate(Flow_decl* d)
{
  Scope_sentinel scope(*this, d);

  Type_seq types;
  for (auto expr : d->keys()) {
    Expr* key = elaborate(expr);
    types.push_back(key->type());
  }

  d->type_ = get_flow_type(types);
  d->instructions_ = elaborate(d->instructions());

  return d;
}


Decl*
Elaborator::elaborate(Port_decl* d)
{
  declare(d);

  return d;
}


Decl*
Elaborator::elaborate(Extracts_decl* d)
{
  Decode_decl* decoder = as<Decode_decl>(stack.context());
  // guarantee this stmt occurs
  // within the context of a decoder function or a flow function
  if (!decoder) {
    std::stringstream ss;
    ss << *d
       << " found outside of the context of a decoder."
       << "Context is: " << *stack.context()->name();

    throw Type_error({}, ss.str());
  }

  // This should be a guarentee from decoder elaboration
  Layout_type const* header_type = as<Layout_type>(decoder->header());
  assert(header_type);

  Field_name_expr* fld = as<Field_name_expr>(d->field());

  if (!fld) {
    std::stringstream ss;
    ss << "Invalid field name: " << *d->field() << " in extracts decl: " << *d;
    throw Type_error({}, ss.str());
  }

  // declare the extraction with the name
  // of the field to be extracted
  d->name_ = fld->name();
  declare(d);

  Expr* e1 = elaborate(d->field());

  // confirm that the first declaration is
  // the same layout decl that the decoder
  // handles
  if ((fld = as<Field_name_expr>(e1))) {
    if (fld->declarations().front() != header_type->declaration()) {
      std::stringstream ss;
      ss << "Cannot extract from: " << *fld->declarations().front()->name()
         << " in extracts decl: " << *d
         << ". Decoder " << *decoder->name() << " decodes layout: " << *header_type;
      throw Type_error({}, ss.str());
    }
  }
  else {
    std::stringstream ss;
    ss << "Invalid field name: " << *d->field() << " in extracts decl: " << *d;
    throw Type_error({}, ss.str());
  }

  d->field_ = e1;
  d->type_ = e1->type();

  return d;
}


Decl*
Elaborator::elaborate(Rebind_decl* d)
{
  Decode_decl* decoder = as<Decode_decl>(stack.context());
  // guarantee this stmt occurs
  // within the context of a decoder function or a flow function
  if (!decoder) {
    std::stringstream ss;
    ss << *d
       << " found outside of the context of a decoder."
       << "Context is: " << *stack.context()->name();

    throw Type_error({}, ss.str());
  }

  // Elaborate the first expression
  Expr* e1 = elaborate(d->field());
  Field_name_expr* origin = as<Field_name_expr>(e1);
  if (!origin) {
    std::stringstream ss;
    ss << "Invalid field name: " << *d->field() << " in rebind decl: " << *d;
    throw Type_error({}, ss.str());
  }
  d->field_ = e1;

  // The second field name just provides a named
  // We don't care about any semantics related to it so we do
  // NOT elaborate the second field.
  Field_name_expr* alias = as<Field_name_expr>(d->alias());
  // the name of a rebind declaration is the name of its alias
  d->name_ = alias->name();
  // save its original name as well
  d->original_ = origin->name();

  // declare the rebind
  declare(d);

  d->type_ = e1->type();

  return d;
}



// -------------------------------------------------------------------------- //
// Elaboration of declarations (but not definitions)

namespace
{

// Defined here because of the member template.
struct Elab_decl_fn
{
  Elaborator& elab;

  template<typename T>
  [[noreturn]] Decl* operator()(T*) const { lingo_unreachable(); }

  // NOTE: Add overloads in order to support nested
  // declarations. Note that supporting nested types
  // would require its full elaboration.
  Decl* operator()(Variable_decl* d) const { return elab.elaborate_decl(d); }
  Decl* operator()(Function_decl* d) const { return elab.elaborate_decl(d); }
  Decl* operator()(Parameter_decl* d) const { return elab.elaborate_decl(d); }
  Decl* operator()(Record_decl* d) const { return elab.elaborate_decl(d); }
  Decl* operator()(Field_decl* d) const { return elab.elaborate_decl(d); }
  Decl* operator()(Method_decl* d) const { return elab.elaborate_decl(d); }
  Decl* operator()(Module_decl* d) const { return elab.elaborate_decl(d); }

  Decl* operator()(Layout_decl* d) const { return elab.elaborate_decl(d); }
  Decl* operator()(Port_decl* d) const { return elab.elaborate_decl(d); }
  Decl* operator()(Decode_decl* d) const { return elab.elaborate_decl(d); }
  Decl* operator()(Table_decl* d) const { return elab.elaborate_decl(d); }
};


} // namespace

Decl*
Elaborator::elaborate_decl(Decl* d)
{
  return apply(d, Elab_decl_fn{*this});
}


Decl*
Elaborator::elaborate_decl(Variable_decl* d)
{
  d->type_ = elaborate_type(d->type_);
  declare(d);
  return d;
}


Decl*
Elaborator::elaborate_decl(Function_decl* d)
{
  d->type_ = elaborate_type(d->type_);
  declare(d);

  // Remember if we've seen a function named main().
  //
  // FIXME: This seems dumb. Is there a better way
  // of handling the discovery and elaboration of
  // main?
  if (d->name() == syms.get("main")) {
    main = d;

    // Ensure that main has foreign linkage.
    d->spec_ |= foreign_spec;

    // TODO: Check that main conforms to the
    // expected return type and arguments.
  }

  return d;
}


Decl*
Elaborator::elaborate_decl(Parameter_decl* d)
{
  lingo_unreachable();
}


Decl*
Elaborator::elaborate_decl(Field_decl* d)
{
  d->type_ = elaborate_type(d->type_);
  declare(d);
  return d;
}


Decl*
Elaborator::elaborate_decl(Record_decl* d)
{
  declare(d);
  return d;
}


Decl*
Elaborator::elaborate_decl(Method_decl* d)
{
  Record_decl* rec = stack.record();

  // Propagate virtual/abstract specifiers to the class.
  if (d->is_virtual())
    rec->spec_ |= virtual_spec;
  if (d->is_abstract())
    rec->spec_ |= abstract_spec;

  // Generate the type of the implicit this parameter.
  //
  // TODO: Handle constant references.
  Type const* type = get_reference_type(get_record_type(rec));

  // Re-build the function type.
  //
  // TODO: Factor this out as an operation on a method.
  Function_type const* ft = cast<Function_type>(elaborate(d->type()));
  Type_seq pt = ft->parameter_types();
  pt.insert(pt.begin(), type);
  Type const* rt = ft->return_type();
  Type const* mt = get_function_type(pt, rt);
  d->type_ = mt;

  // Actually build the implicit this parameter and add it
  // to the front of the list of parameters.
  Symbol const* name = syms.get("this");
  Parameter_decl* self = new Parameter_decl(name, type);
  d->parms_.insert(d->parms_.begin(), self);

  // Note that we don't need to elaborate or declare
  // the funciton parameters because they're only visible
  // within the function body (see the def elaborator for
  // function definitions).

  // Now declare the method.
  declare(d);

  // If the method is virtual add it to the record'sd
  // virtual table and update its index.
  //
  // FIXME: If the function is an overrider, then replace its
  // current definition in the virtual table.
  //
  // TODO: Factor this out as an operation on a record.
  if (d->is_polymorphic()) {
    if (!rec->vtbl_)
      rec->vtbl_ = new Decl_seq();
    rec->vtbl_->push_back(d);

    // FIXME: Set the vtable index for the method.
  }

  return d;
}


Decl*
Elaborator::elaborate_decl(Layout_decl* d)
{
  declare(d);
  return d;
}


Decl*
Elaborator::elaborate_decl(Port_decl* d)
{
  declare(d);
  return d;
}


Decl*
Elaborator::elaborate_decl(Decode_decl* d)
{
  assert(d->name());

  pipelines.insert(d);

  declare(d);

  return d;
}


Decl*
Elaborator::elaborate_decl(Table_decl* d)
{
  pipelines.insert(d);
  declare(d);

  // Tentatively declare that every field
  // needed by the table has been extracted.
  // This is checked later in the pipeline
  // checking phase where all paths leading into
  // this table are analyzed.
  //
  // This allows the elaboration of the key fields
  // to pass without error.
  Scope_sentinel scope(*this, d);

  // maintain the field decl for each field
  // and the type for each field
  Decl_seq field_decls;
  Type_seq types;

  for (auto subkey : d->keys()) {
    if (Key_decl* field = as<Key_decl>(subkey)) {
      elaborate(field);
      declare(field);

      // construct the table type
      Decl* field_decl = field->declarations().back();

      assert(field_decl);
      assert(field_decl->type());

      // save the field decl
      field_decls.push_back(field_decl);
      // save the type of the field decl
      types.push_back(field_decl->type());
    }
  }

  // elaborate the individual flows
  for (auto flow : d->body()) {
    elaborate(flow);
  }

  Type const* type = get_table_type(field_decls, types);

  d->type_ = type;
  return d;
}


// Since modules aren't nested, we should never get here.
Decl*
Elaborator::elaborate_decl(Module_decl* d)
{
  lingo_unreachable();
}


// -------------------------------------------------------------------------- //
// Elaboration of definitions

namespace
{

// Defined here because of the member template.
struct Elab_def_fn
{
  Elaborator& elab;
  template<typename T>
  [[noreturn]] Decl* operator()(T* d) const { lingo_unreachable(); }

  Decl* operator()(Variable_decl* d) const { return elab.elaborate_def(d); }
  Decl* operator()(Function_decl* d) const { return elab.elaborate_def(d); }
  Decl* operator()(Parameter_decl* d) const { return elab.elaborate_def(d); }
  Decl* operator()(Record_decl* d) const { return elab.elaborate_def(d); }
  Decl* operator()(Field_decl* d) const { return elab.elaborate_def(d); }
  Decl* operator()(Method_decl* d) const { return elab.elaborate_def(d); }
  Decl* operator()(Layout_decl* d) const { return elab.elaborate_def(d); }
  Decl* operator()(Port_decl* d) const { return elab.elaborate_def(d); }
  Decl* operator()(Decode_decl* d) const { return elab.elaborate_def(d); }
  Decl* operator()(Table_decl* d) const { return elab.elaborate_def(d); }
  Decl* operator()(Module_decl* d) const { return elab.elaborate_def(d); }
};


} // namespace


Decl*
Elaborator::elaborate_def(Decl* d)
{
  return apply(d, Elab_def_fn{*this});
}


Decl*
Elaborator::elaborate_def(Variable_decl* d)
{
  // Elaborate the initializer.
  d->init_ = elaborate(d->init());

  // Annotate the initializer with the declared
  // object.
  //
  // FIXME: This needs to be rethought.
  cast<Init>(d->init())->decl_ = d;
  return d;
}


Decl*
Elaborator::elaborate_def(Function_decl* d)
{
  // Enter the function scope and declare all of
  // the parameters (by way of elaboration).
  //
  // Note that this modifies the original parameters.
  Scope_sentinel scope(*this, d);
  for (Decl*& p : d->parms_)
    p = elaborate(p);

  // Check the body of the function, if present.
  if (d->body())
    d->body_ = elaborate(d->body());

  // TODO: Are we actually checking returns match
  // the return type?

  // TODO: Build a control flow graph and ensure that
  // every branch returns a value.

  return d;
}


Decl*
Elaborator::elaborate_def(Parameter_decl* d)
{
  lingo_unreachable();
}


// Returns true if we are currently defining the declaration d.
// That is te case when the declaraiton appears in the decl
// stack.
bool
Elaborator::is_defining(Decl const* d) const
{
  return count(defining.begin(), defining.end(), d);
}


// FIXME: If the type of a member variable requires the
// definition of a user-defined type, then we need to
// recursively elaborate that. However, we need to be
// careful that we don't generate cycles.
Decl*
Elaborator::elaborate_def(Record_decl* d)
{
  // If the declaration has already been declared,
  // then don't re-elaborate it.
  if (defined.count(d))
    return d;

  // Prevent recursive type definitions.
  if (is_defining(d)) {
    std::cerr << format("cyclic definition of '{}'\n", *d->name());
    for (auto iter = defining.rbegin(); iter != defining.rend(); ++iter) {
      if (*iter == d)
        break;
      std::cerr << format("  referenced in the definition of '{}'\n", *(*iter)->name());
    }
    throw Type_error(locate(d), format("cyclic definition of '{}'", *d->name()));
  }
  Defining_sentinel def(*this, d);

  // Elaborate base class.
  if (d->base_)
    d->base_ = elaborate(d->base_);

  // Propagate the virtual table if supported.
  Record_decl const* b = d->base_declaration();
  if (b)
    if (Decl_seq const* vt = b->vtable())
      d->vtbl_ = new Decl_seq(*vt);

  // Elaborate member declarations, fields first.
  //
  // TODO: What are the lookup rules for default
  // member initializers. If we do this:
  //
  //    struct S {
  //      x : int = 1;
  //      y : int = x + 2; // Seems resonable.
  //
  //      a : int = b - 1; // OK?
  //      b : int = 0;
  //      // Making this okay could impose an alternative
  //      // initialization order.
  //
  //      g : int = f();   // OK?
  //      def f() -> int { ... }
  //      // What if f() refers to an uninitialized fiedl?
  //    }
  Scope_sentinel scope(*this, d->scope());
  for (Decl*& f : d->fields_)
    f = elaborate_decl(f);
  for (Decl*& m : d->members_)
    m = elaborate_decl(m);

  // Elaborate member definitions. See comments
  // above about handling member defintions.
  for (Decl*& m : d->members_)
    m = elaborate_def(m);


  // If the base class is polymorphic, then so
  // is the derived class.
  if (b) {
    // Propagate specifiers.
    if (b->is_virtual())
      d->spec_ |= virtual_spec;
    if (b->is_abstract())
      d->spec_ |= abstract_spec;
  }

  // Determine if we need a vtable reference. This is the case
  // when:
  //    - there is no base class or
  //    - the base is not polymorphic
  //
  // TODO: We may need to perform this transformation
  // before elaborating any fields. It depends on whether
  // or not we allow a member's type to refer to member
  // variables (a la decltype).
  //
  // TODO: For multiple base classes, we probably want
  // multiple vtable references (one for each base).
  if (d->is_polymorphic()) {
    if (!b || !b->is_polymorphic()) {
      Symbol const* n = syms.get("vref");
      Type const* p = get_reference_type(get_character_type());
      d->vref_ = new Field_decl(n, p);
    }
  }

  defined.insert(d);
  return d;
}


Decl*
Elaborator::elaborate_def(Layout_decl* d)
{
  // Push the stack onto scope.
  Scope_sentinel scope(*this, d);

  for (Decl*& f : d->fields_) {
    f = elaborate_decl(f);
  }
  return d;
}


Decl*
Elaborator::elaborate_def(Port_decl* d)
{
  return d;
}


// Nothing to do here now...
Decl*
Elaborator::elaborate_def(Field_decl* d)
{
  return d;
}


Decl*
Elaborator::elaborate_def(Decode_decl* d)
{
  Scope_sentinel scope(*this, d);

  if (d->header())
    d->header_ = elaborate(d->header());

  // Enter a scope since a decode body is
  // basically a special function body
  if (d->body())
    d->body_ = elaborate(d->body());

  return d;
}


// Elaborate the method as a function. Note that we pre-declare
// the implicit "this" parameter during the first pass.
Decl*
Elaborator::elaborate_def(Method_decl* d)
{
  elaborate_def(cast<Function_decl>(d));
  return d;
}


Decl*
Elaborator::elaborate_def(Table_decl* d)
{
  // check initializing flows for type equivalence
  if (!check_table_initializer(*this, d)) {
    std::stringstream ss;
    ss << "Invalid entry in table: " << *d->name();
    throw Type_error({}, ss.str());
  }

  return d;
}


Decl*
Elaborator::elaborate_def(Module_decl* d)
{
  // We should never get here.
  lingo_unreachable();
}


// -------------------------------------------------------------------------- //
// Elaboration of statements

// Elaborate a statement. This returns true if elaboration
// succeeds and false otherwise.
Stmt*
Elaborator::elaborate(Stmt* s)
{
  struct Fn
  {
    Elaborator& elab;

    Stmt* operator()(Empty_stmt* d) const { return elab.elaborate(d); }
    Stmt* operator()(Block_stmt* d) const { return elab.elaborate(d); }
    Stmt* operator()(Assign_stmt* d) const { return elab.elaborate(d); }
    Stmt* operator()(Return_stmt* d) const { return elab.elaborate(d); }
    Stmt* operator()(If_then_stmt* d) const { return elab.elaborate(d); }
    Stmt* operator()(If_else_stmt* d) const { return elab.elaborate(d); }
    Stmt* operator()(Match_stmt* d) const { return elab.elaborate(d); };
    Stmt* operator()(Case_stmt* d) const { return elab.elaborate(d); };
    Stmt* operator()(While_stmt* d) const { return elab.elaborate(d); }
    Stmt* operator()(Break_stmt* d) const { return elab.elaborate(d); }
    Stmt* operator()(Continue_stmt* d) const { return elab.elaborate(d); }
    Stmt* operator()(Expression_stmt* d) const { return elab.elaborate(d); }
    Stmt* operator()(Declaration_stmt* d) const { return elab.elaborate(d); }
    Stmt* operator()(Decode_stmt* d) const { return elab.elaborate(d); }
    Stmt* operator()(Goto_stmt* d) const { return elab.elaborate(d); }

    Stmt* operator()(Action* d) const { return elab.elaborate(d); }
    Stmt* operator()(Drop* d) const { return elab.elaborate(d); }
    Stmt* operator()(Output* d) const { return elab.elaborate(d); }
    Stmt* operator()(Set_field* d) const { return elab.elaborate(d); }
  };

  Stmt* stmt = apply(s, Fn{*this});
  // attach the context to the statement
  stmt->context_ = stack.context();
  return stmt;
}


Stmt*
Elaborator::elaborate(Empty_stmt* s)
{
  return s;
}


Stmt*
Elaborator::elaborate(Block_stmt* s)
{
  Scope_sentinel scope = *this;
  for (Stmt*& s1 : s->first) {
    s1 = elaborate(s1);
  }
  return s;
}


// In an assignment expression, the left operand shall
// refer to a mutable object. The types of the left and
// right operands shall match.
//
// TODO: If we have const types, then we'd have to add this
// checking.
Stmt*
Elaborator::elaborate(Assign_stmt* s)
{
  // FIXME: Write a better predicate?
  Expr* lhs = elaborate(s->object());
  if (!is<Reference_type>(lhs->type()))
    throw Type_error({}, "assignment to rvalue");

  // Apply rvalue conversion to the value and update the
  // expression.
  Expr* rhs = require_value(*this, s->second);

  // The types shall match after conversion. Compare t1 using the non-reference
  // type of the object.
  Type const* t1 = lhs->type()->nonref();
  rhs = convert(rhs, t1);
  // perform conversion
  if (!rhs) {
    throw Type_error({}, "assignment to an object of a different type");
  }

  s->first = lhs;
  s->second = rhs;
  return s;
}


// The type of the returned expression shall match the declared
// return type of the enclosing function.
//
// TODO: Implement me.
Stmt*
Elaborator::elaborate(Return_stmt* s)
{
  Function_decl* fn = stack.function();
  Type const* t = fn->return_type();

  // Check that the return type matches the returned value.
  Expr* e = elaborate(s->value());
  Expr* c = convert(e, t);
  if (!c) {
    std::stringstream ss;
    ss << "return type mismatch (expected "
       << *t << " but got " << *s->value()->type() << ")";
    throw std::runtime_error(ss.str());
  }

  s->first = c;
  return s;
}


// The condition must must be a boolean expression.
Stmt*
Elaborator::elaborate(If_then_stmt* s)
{
  Expr* c = require_converted(*this, s->first, get_boolean_type());
  if (!c)
    throw Type_error({}, "if condition does not have type 'bool'");
  Stmt* b = elaborate(s->body());

  s->first = c;
  s->second = b;
  return s;
}


// The condition must must be a boolean expression.
Stmt*
Elaborator::elaborate(If_else_stmt* s)
{
  Expr* c = require_converted(*this, s->first, get_boolean_type());
  if (!c)
    throw Type_error({}, "if condition does not have type 'bool'");
  Stmt* t = elaborate(s->true_branch());
  Stmt* f = elaborate(s->false_branch());

  s->first = c;
  s->second = t;
  s->third = f;
  return s;
}


Stmt*
Elaborator::elaborate(Match_stmt* s)
{
  Expr* cond = require_converted(*this, s->condition_, get_integer_type());

  if (!cond) {
    std::stringstream ss;
    ss << "Could not convert " << *s->condition_ << " to integer type.";
    throw Type_error({}, ss.str());
  }

  s->condition_ = cond;

  // TODO: check for same integer type
  // between condition and cases?

  // maintain all values found in every case
  std::unordered_set<Integer_value> vals;

  for (Stmt*& s1 : s->cases_) {
    Stmt* c = elaborate(s1);
    s1->context_ = stack.context();
    // there cannot be non-case statements inside
    // of a match stmt body
    if (Case_stmt* case_ = as<Case_stmt>(c)) {
      // the case label should be guarenteed to be an integer
      // by elaboration of the case stmt
      if (!vals.insert(case_->label()->value().get_integer()).second) {
        std::stringstream ss;
        ss << "Duplicate label value " << *case_->label()
           << " found in case statement " << *case_;
        throw Type_error({}, ss.str());
      }
    }
    else {
      std::stringstream ss;
      ss << "Non-case stmt " << *case_ << " found in match statement.";
      throw Type_error({}, ss.str());
    }
  }

  return s;
}


// FIXME: make sure case stmts can only appear
// in the context of match
Stmt*
Elaborator::elaborate(Case_stmt* s)
{
  Expr* label = require_converted(*this, s->label_, get_integer_type());

  if (!is<Literal_expr>(label)) {
    std::stringstream ss;
    ss << "Non-literal value " << *label << " found in case statement.";
    throw Type_error({}, ss.str());
  }

  if (!is<Integer_type>(label->type())) {
    std::stringstream ss;
    ss << "Non-integer value " << *label << " found in case statement.";
    throw Type_error({}, ss.str());
  }

  Stmt* stmt = elaborate(s->stmt_);

  s->label_ = label;
  s->stmt_ = stmt;

  return s;
}



Stmt*
Elaborator::elaborate(While_stmt* s)
{
  Expr* c = require_converted(*this, s->first, get_boolean_type());
  if (!c)
    throw Type_error({}, "loop condition does not have type 'bool'");
  Stmt* b = elaborate(s->body());

  s->first = c;
  s->second = b;
  return s;
}


Stmt*
Elaborator::elaborate(Break_stmt* s)
{
  // TODO: Verify that a break occurs within an
  // appropriate context.
  return s;
}


Stmt*
Elaborator::elaborate(Continue_stmt* s)
{
  // TODO: Verify that a continue occurs within an
  // appropriate context.
  return s;
}


Stmt*
Elaborator::elaborate(Expression_stmt* s)
{
  s->first = elaborate(s->expression());
  return s;
}


Stmt*
Elaborator::elaborate(Declaration_stmt* s)
{
  s->first = elaborate(s->declaration());
  return s;
}


Stmt*
Elaborator::elaborate(Decode_stmt* s)
{

  // guarantee this stmt occurs
  // within the context of a decoder function or a flow function
  if (!is<Decode_decl>(stack.context()) && !is<Flow_decl>(stack.context())) {
    std::stringstream ss;
    ss << "decode statement " << *s
       << " found outside of the context of a decoder or flow.";

    throw Type_error({}, ss.str());
  }

  Expr* target = elaborate(s->decoder_identifier());
  Decl_expr* target_id = as<Decl_expr>(target);

  if (!target_id) {
    std::stringstream ss;
    ss << "invalid decoder identifier provided in decode statement: " << *s;

    throw Type_error({}, ss.str());
  }

  if (!is<Decode_decl>(target_id->declaration())) {
    std::stringstream ss;
    ss << "invalid decoder " << *target_id
       << " provided in decode statement: " << *s;

    throw Type_error({}, ss.str());
  }

  s->decoder_identifier_ = target_id;
  s->decoder_ = target_id->declaration();

  return s;
}


// TODO: guarantee this stmt occurs
// within the context of a decoder function
Stmt*
Elaborator::elaborate(Goto_stmt* s)
{
  // guarantee this stmt occurs
  // within the context of a decoder function
  if (!is<Decode_decl>(stack.context()) && !is<Flow_decl>(stack.context())) {
    std::stringstream ss;
    ss << "decode statement " << *s
       << " found outside of the context of a decoder.";

    throw Type_error({}, ss.str());
  }

  Expr* tbl = elaborate(s->table_identifier_);

  if (Decl_expr* id = as<Decl_expr>(tbl)) {
    s->table_identifier_ = id;
    s->table_ = id->declaration();
  }
  else {
    std::stringstream ss;
    ss << "invalid table identifier: " << *s->table_identifier();
    throw Type_error({}, ss.str());
  }

  return s;
}


Stmt*
Elaborator::elaborate(Action* s)
{
  // This should never happen
  lingo_unreachable();
}


Stmt*
Elaborator::elaborate(Drop* s)
{
  // No further elaboration required
  return s;
}


Stmt*
Elaborator::elaborate(Output* s)
{
  // elaborate the port identififier and confirm
  // that it has port type
  Expr* port = elaborate(s->port_);

  if (!is<Port_type>(port->type()->nonref())) {
    std::stringstream ss;
    ss << "Invalid port identifier " << *port;
    throw Type_error({}, ss.str());
  }

  // this is necessary as the id expr will almost
  // certainly get rewritten with a decl expr
  s->port_ = port;

  return s;
}


Stmt*
Elaborator::elaborate(Set_field* s)
{
  if (!is<Flow_decl>(stack.context())
      && !is<Decode_decl>(stack.context()))
  {
    std::stringstream ss;
    ss << "Set field occuring outside the context of "
          "a decoder or flow declaration.";
    throw Type_error({}, ss.str());
  }

  Expr* field = elaborate(s->field_);
  Expr* val = elaborate(s->value_);

  assert(field->type());
  assert(val);
  Expr* conv = convert(val, field->type());

  s->value_ = conv;
  s->field_ = field;

  return s;
}

// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "steve/evaluate.hpp"
#include "steve/expr.hpp"
#include "steve/type.hpp"
#include "steve/decl.hpp"
#include "steve/stmt.hpp"
#include "steve/print.hpp"

#include <forward_list>
#include <unordered_map>


namespace steve
{

namespace
{


// The object store associates values with declarations.
//
// Note that unlike the lexical bindings, we don't have 
// multiple bindings for declarations. Each declaration
// is bound to a unique integer value.
struct Store : std::unordered_map<Decl const*, Value>
{
  void push(Decl const*, Value const&);
  void pop(Decl const*);
};


// The call tack is a stack of frames. 
struct Stack : std::forward_list<Frame*>
{
  Frame&       top()       { return *front(); }
  Frame const& top() const { return *front(); }
};


// Bind the given declaration to its value.
void
Store::push(Decl const* d, Value const& v)
{
  lingo_assert(count(d) == 0);
  insert({d, v});
}


// Unbind the declaratio from its value. Since variables
// are uniquely bound, this will also remove the value
// from memory.
void
Store::pop(Decl const* d)
{
  erase(d);
}


// The program data and stack.
Store data_;
Stack stack_;

} // namespace


Frame::Frame()
{
  stack_.push_front(this);
}


// When a stack frame is destroyed, remove all of its 
// bindings.
Frame::~Frame()
{
  for (Decl const* d : *this)
    data_.pop(d);
  stack_.pop_front();
}


// In the current frame, bind the declaration to its
// integer value.
void
Frame::bind(Decl const* d, Value const& v)
{
  data_.push(d, v);
  push_back(d);
}


// Returns the integer object saved for this
// declaration.
Value const&
Frame::entry(Decl const* d) const
{
  lingo_assert(data_.count(d));
  return data_.find(d)->second;
}


// Returns the current stack frame.
Frame&
active_frame()
{
  lingo_assert(!stack_.empty());
  return stack_.top();
}


// Initialize the memory for the declaration `d` with
// the given value.
void
store(Decl const* d, Value const& v)
{
  active_frame().bind(d, v);
}


// Returns the stored value in the current frame.
Value const&
load(Decl const* d)
{
  return active_frame().entry(d);
}


namespace
{


// -------------------------------------------------------------------------- //
//                    Evaluation of arithmetic expressions
//
// TODO: Arithmetic expressions have different evaluations
// when their operand types have non-integer representation.
//
// This needs a description of the underlying machine in
// order to clarify what sets of operations are actually
// supported for each expression. For example, we can
// add 2 ints and return an int. We can add 2 floats and
// return a float. We cannot add an int and a float. The
// conversion system would be required to convert the
// arguments to guarantee similar types.


inline Value
eval_numeric_add(Binary_expr const* e) 
{
  Value left = evaluate(e->left());
  Value right = evaluate(e->right());
  return left.get_integer() + right.get_integer();
}


inline Value
eval_numeric_sub(Binary_expr const* e)
{
  Value left = evaluate(e->left());
  Value right = evaluate(e->right());
  return left.get_integer() - right.get_integer();
}


inline Value
eval_numeric_mul(Binary_expr const* e)
{
  Value left = evaluate(e->left());
  Value right = evaluate(e->right());
  return left.get_integer() * right.get_integer();
}


inline Value
eval_numeric_div(Binary_expr const* e)
{
  Value left = evaluate(e->left());
  Value right = evaluate(e->right());
  return left.get_integer() / right.get_integer();
}


inline Value
eval_numeric_mod(Binary_expr const* e)
{
  Value left = evaluate(e->left());
  Value right = evaluate(e->right());
  return left.get_integer() % right.get_integer();
}


inline Value
eval_numeric_neg(Unary_expr const* e)
{
  Value arg = evaluate(e->arg());
  return -arg.get_integer();
}


inline Value
eval_numeric_pos(Unary_expr const* e)
{
  Value arg = evaluate(e->arg());
  return +arg.get_integer();
}


// -------------------------------------------------------------------------- //
//                    Evaluation of bitwise expressions


inline Value
eval_bitwise_and(Binary_expr const* e) 
{
  Value left = evaluate(e->left());
  Value right = evaluate(e->right());
  return left.get_integer() & right.get_integer();
}


inline Value
eval_bitwise_or(Binary_expr const* e)
{
  Value left = evaluate(e->left());
  Value right = evaluate(e->right());
  return left.get_integer() | right.get_integer();
}


inline Value
eval_bitwise_xor(Binary_expr const* e)
{
  Value left = evaluate(e->left());
  Value right = evaluate(e->right());
  return left.get_integer() ^ right.get_integer();
}


inline Value
eval_bitwise_not(Unary_expr const* e)
{
  Value arg = evaluate(e->arg());
  return ~arg.get_integer();
}


// TODO: Validate that we aren't shifting beyond the precision
// of the left operand.
inline Value
eval_bitwise_lsh(Binary_expr const* e)
{
  Value left = evaluate(e->left());
  Value right = evaluate(e->right());
  return left.get_integer() << right.get_integer();
}


// TODO: Verify that we aren't shifting beyond the precision
// of the right operand.
inline Value
eval_bitwise_rsh(Binary_expr const* e)
{
  Value left = evaluate(e->left());
  Value right = evaluate(e->right());
  return left.get_integer() >> right.get_integer();
}


// -------------------------------------------------------------------------- //
//                    Evaluation of relational expressions
//
// Tuples and records have a default lexicographical ordering.

inline Value
eval_relational_eq(Binary_expr const* e) 
{
  Value left = evaluate(e->left());
  Value right = evaluate(e->right());
  return Value(left == right);
}


inline Value
eval_relational_ne(Binary_expr const* e) 
{
  Value left = evaluate(e->left());
  Value right = evaluate(e->right());
  return Value(left != right);
}


inline Value
eval_relational_lt(Binary_expr const* e) 
{
  Value left = evaluate(e->left());
  Value right = evaluate(e->right());
  return Value(left < right);
}


inline Value
eval_relational_gt(Binary_expr const* e) 
{
  Value left = evaluate(e->left());
  Value right = evaluate(e->right());
  return Value(left > right);
}


inline Value
eval_relational_le(Binary_expr const* e) 
{
  Value left = evaluate(e->left());
  Value right = evaluate(e->right());
  return Value(left <= right);
}


inline Value
eval_relational_ge(Binary_expr const* e) 
{
  Value left = evaluate(e->left());
  Value right = evaluate(e->right());
  return Value(left >= right);
}


// -------------------------------------------------------------------------- //
//                    Evaluation of logical expressions


// A logical-and expression is `true` when both the left and
// right operands are `true`, and `false` otherwise. If the left 
// operand is `false`, the right operand is not evaluated, and 
// the expression is `false`.
inline Value
eval_logical_and(Binary_expr const* e) 
{
  Value left = evaluate(e->left());
  if (!left.get_boolean())
    return left;
  else
    return evaluate(e->right());
}


// A logical-or expression is `true` when either the left, right
// or both operands are `true`, and `false` otherwise. If the left 
// operand is `true`, the right operand is not evaluated, and 
// the expression is `true`.
inline Value
eval_logical_or(Binary_expr const* e) 
{
  Value left = evaluate(e->left());
  if (left.get_boolean())
    return left;
  else
    return evaluate(e->right());
}


// A logical-not expression is `true` when the operand is
// `false`, and `false` otherwise.
inline Value
eval_logical_not(Unary_expr const* e) 
{
  Value arg = evaluate(e->arg());
  return Value(!arg.get_boolean());
}


// -------------------------------------------------------------------------- //
//                 Evaluation of unary and binary operators
//
// Delegate to an evaluator corresponding to the
// expression's operator.



// Expressions evaluate to integers.
struct Eval_fn
{
  template<typename T>
  Value operator()(T const* t) { return evaluate(t); }
};


// Evaluate and discard the value.
struct Discard_fn
{
  template<typename T>
  void operator()(T const* t) { return evaluate(t); }
};

} // namespace


// Compute the integer evaluation of the expression.
Value
evaluate(Expr const* e)
{
  Eval_fn fn;
  return apply(e, fn);
}


// -------------------------------------------------------------------------- //
//                        Evaluation of identifers


// The value of an identifier is that stored for its 
// referenced declaration.
//
// NOTE: The program is internally inconsistent if this
// lookup fails.
inline Value
evaluate(Id_expr const* e)
{
  return load(e->decl());
}


// -------------------------------------------------------------------------- //
//                        Evaluation of literals


// The value of a literal is the spelled value. The
// value of a computed constant expression is that value.
inline Value
evaluate(Value_expr const* e)
{
  return e->value();
}


// -------------------------------------------------------------------------- //
//                       Unary and binary expressions


Value
evaluate(Unary_expr const* e)
{
  switch (e->op()) {
  case num_neg_op: return eval_numeric_neg(e);
  case num_pos_op: return eval_numeric_pos(e);
  case bit_not_op: return eval_bitwise_not(e);
  case log_not_op: return eval_logical_not(e);
  default:
    lingo_unreachable("invalid unary operator ({})", (int)e->op());
  }
}


Value
evaluate(Binary_expr const* e)
{
  switch (e->op()) {
  case num_add_op: return eval_numeric_add(e);
  case num_sub_op: return eval_numeric_sub(e);
  case num_mul_op: return eval_numeric_mul(e);
  case num_div_op: return eval_numeric_div(e);
  case num_mod_op: return eval_numeric_mod(e);
  case bit_and_op: return eval_bitwise_and(e);
  case bit_or_op: return eval_bitwise_or(e);
  case bit_xor_op: return eval_bitwise_xor(e);
  case bit_lsh_op: return eval_bitwise_lsh(e);
  case bit_rsh_op: return eval_bitwise_rsh(e);
  case rel_eq_op: return eval_relational_eq(e);
  case rel_ne_op: return eval_relational_ne(e);
  case rel_lt_op: return eval_relational_lt(e);
  case rel_gt_op: return eval_relational_gt(e);
  case rel_le_op: return eval_relational_le(e);
  case rel_ge_op: return eval_relational_ge(e);
  case log_and_op: return eval_logical_and(e);
  case log_or_op: return eval_logical_or(e);
  default:
    lingo_unreachable("invalid binary operator ({})", (int)e->op());
  }
}


// -------------------------------------------------------------------------- //
//                     Evaluation of function calls


// TODO: When do we evaluate function calls? Only when we're
// evaluating a constant expression. Hypothetically, we can
// evaluate "all the way down" to the OS. However, calls to
// externally defined functions (system calls!) cannot be
// constexpr evaluated.
inline Value
evaluate(Call_expr const* e)
{
  lingo_unreachable("not implemented");
}


// -------------------------------------------------------------------------- //
//                  Evaluation of tuples and member access


// The value of a tuple is the composite value of its
// expressions.
//
// TODO: Use std::transform on the inner loop.
inline Value
evaluate(Tuple_expr const* e)
{
  Expr_seq const& es = e->exprs();
  int n = e->exprs().size();
  Composite_value v(n);
  for (int i = 0; i < n; ++i)
    v.elems[i] = evaluate(es[i]);
  return v;
}


// Evaluate an index expression.
inline Value
evaluate(Index_expr const* e)
{
  // Evaluate the object.
  Value o = evaluate(e->object());
  if (!o || o.kind() != composite_value)
    return {};
  Composite_value comp = o.get_composite();

  // Evaluate the index. This should be a constant value.
  Value n = evaluate(e->index());
  int index = n.get_integer().gets();

  return comp.elems[index];
}


// Evaluate a member expression by resolving the member name.
//
// TODO: We really shouldn't 
inline Value
evaluate(Member_expr const* e)
{
  return evaluate(make_index_expr(e));
}


// FIXME: IDK why the compiler is forcing me to
// have this here. Do we evaluate lvalue references
// all the time causing this to happen?
inline Value
evaluate(Header_cast_expr const* e)
{
  lingo_unreachable("not implemented");
}


// -------------------------------------------------------------------------- //
//                        Evaluation of conversions

namespace
{

// Promote a boolean value to an integer.
Value
promote_bool(Convert_expr const* e)
{
  Value v =  evaluate(e->arg());
  // Adjust non-zero values to 1.
  Integer n = v.get_integer();
  if (n != 0)
    n = 1;
  return n;
}


// Promoting an enum does not require any transformations.
Value
promote_enum(Convert_expr const* e)
{
  return evaluate(e->arg());
}


// Convert an expression to bool.
Value
convert_to_bool(Convert_expr const* e)
{
  Expr const* e1 = e->arg();

  // For integers, we can just return the evaluated expression
  // and simply use its truth value for values.
  if (is_integer_expr(e1))
    return evaluate(e1);

  // There must be other implicit conversions of this sort.
  lingo_unreachable();
}


// Convert to an integer of a different type.
//
// FIXME: Our underlying integer represntation is not particularly 
// good conversions. We need to reason much more carefully about
// precision and byte order. For now, assume that convesions
// actually happen. As an example of where they don't, consider
// the conversion of -1 to uint. We can't just take the absolute
// value; we actually need to invert a set of bits.
Value
convert_to_int(Convert_expr const* e)
{
  return evaluate(e->arg());
}


// Convert a record to a tuple.
//
// This is a conceptual conversion because a tuple and a record
// are layout compatible.
Value
convert_to_record(Convert_expr const* e)
{
  return evaluate(e->arg());
}


// Transform the byte order of an integer expression.
//
// FIXME: This doesn't work with the current integer
// representation.
Value
xform_int(Convert_expr const* e)
{
  return evaluate(e->arg());
}


} // namespace



inline Value
evaluate(Convert_expr const* e)
{
  switch (e->conv()) {
    case boolean_prom: return promote_bool(e);
    case enumeration_prom: return promote_enum(e);
    case boolean_conv: return convert_to_bool(e);
    case integer_conv: return convert_to_int(e);
    case record_conv: return convert_to_record(e);
    case integer_xform: return xform_int(e);
  }
  lingo_unreachable();
}



// -------------------------------------------------------------------------- //
//                        Evaluation of declarations


// Evluate the declaration. Note that declarations do not
// result yield values.
void
evaluate(Decl const* d)
{
  Discard_fn fn;
  return apply(d, fn);
}


// Evaluate the declaration, storing a value for that
// declaration.
//
// TODO: We shoud only ever evaluate local variables (possibly
// other local declarations), because only those produce
// dynamic bindings.
void
evaluate(Variable_decl const* d)
{
  store(d, evaluate(d->init()));
}


// -------------------------------------------------------------------------- //
//                        Evaluation of statements


// Evaluate the statement. Note that statements do not
// yield values.
void
evaluate(Stmt const* s)
{
  Discard_fn fn;
  return apply(s, fn);
}


// Evalutae the statement's expression and discard the value.
void
evaluate(Expr_stmt const* s)
{
  evaluate(s->expr());
}


// Evaluate the declaration.
void
evaluate(Decl_stmt const* s)
{
  evaluate(s->decl());
}


// All blocks are evaluated in the same stack frame.
// Note that the lexical bindings have guaranteed that
// each variable (even if they have the same name),
// will be mapped to a different address.
void
evaluate(Block_stmt const* s)
{
  for (Stmt const* s0 : *s)
    evaluate(s0);
}


// -------------------------------------------------------------------------- //
//                         Specialized evaluation


// Evaluate `e` as an integer constant expression. If `e` is not
// an integer expression or does not compute a value, emit
// a diagnostic and return an error value.
//
// On successful completion, we guarantee that `result.is_integer()`
// is `true`.
Value
evaluate_integer_constant(Expr const* e)
{
  if (!is_integer_expr(e)) {
    error(e->location(), "'{}' is not an integer expression", e);
    return Value::error;
  }

  Value v = evaluate(e);
  if (!v) {
    error(e->location(), "'{}' is not a constant expression", e);
    return Value::error;
  }
  return v;
}


// -------------------------------------------------------------------------- //
//                           Reduction

// Fully reduce the expression `e`.
Expr const*
reduce(Expr const* e)
{
  return make_value_expr(e->type(), evaluate(e));
}


} // namespace steve

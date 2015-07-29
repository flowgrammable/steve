// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#ifndef STEVE_EVALUATE_HPP
#define STEVE_EVALUATE_HPP

#include "steve/prelude.hpp"
#include "steve/value.hpp"


namespace steve
{

using namespace lingo;

struct Expr;
struct Decl;
struct Stmt;


// A (stack) frame is a sequence of declartions that is
// active during the evaluation of a function.
struct Frame : std::vector<Decl const*>
{
  ~Frame();

  void         bind(Decl const*, Value const&);
  Value const& entry(Decl const*) const;
};


// ---------------------------------------------------------------------------//
//                            Stack management

// Frame management.
Frame& current_frame();
void activate_frame();
void deactivate_frame();


// -------------------------------------------------------------------------- //
//                               Evaluation

Value evaluate(Expr const*);
Value evaluate(Id_expr const*);
Value evaluate(Value_expr const*);
Value evaluate(Unary_expr const*);
Value evaluate(Binary_expr const*);
Value evaluate(Call_expr const*);
Value evaluate(Tuple_expr const*);
Value evaluate(Index_expr const*);
Value evaluate(Member_expr const*);
Value evaluate(Convert_expr const*);

void evaluate(Decl const*);
void evaluate(Variable_decl const*);

void evaluate(Stmt const*);
void evaluate(Expr_stmt const*);
void evaluate(Decl_stmt const*);
void evaluate(Block_stmt const*);

Value evaluate_integer_constant(Expr const* e);


Expr const* reduce(Expr const*);


// ---------------------------------------------------------------------------//
//                            Dynamic bindings

void         store(Decl const*, Integer const&);
Value const& access(Decl const*);


// ---------------------------------------------------------------------------//
//                                Tools

// The frame guard establishes a new stack frame at
// the point of construction. The frame is popped when
// it goes out of scope.
struct Frame_guard
{
  Frame_guard()
  {
    activate_frame();
  }

  ~Frame_guard()
  {
    deactivate_frame();
  }
};


} // namespace steve

#endif

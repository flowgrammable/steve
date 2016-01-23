// Copyright (c) 2015 Andrew Sutton
// All rights reserved

#ifndef BEAKER_STMT_HPP
#define BEAKER_STMT_HPP

#include "prelude.hpp"

// The base class of all statements in the language.
struct Stmt
{
  struct Visitor;
  struct Mutator;

  virtual ~Stmt() { }

  virtual void accept(Visitor&) const = 0;
  virtual void accept(Mutator&) = 0;

  Decl* context() const { return context_; }

  Decl* context_;
};


// The read-only declaration visitor.
struct Stmt::Visitor
{
  virtual void visit(Empty_stmt const*) = 0;
  virtual void visit(Block_stmt const*) = 0;
  virtual void visit(Assign_stmt const*) = 0;
  virtual void visit(Return_stmt const*) = 0;
  virtual void visit(Return_void_stmt const*) = 0;
  virtual void visit(If_then_stmt const*) = 0;
  virtual void visit(If_else_stmt const*) = 0;
  virtual void visit(Match_stmt const*) = 0;
  virtual void visit(Case_stmt const*) = 0;
  virtual void visit(While_stmt const*) = 0;
  virtual void visit(Break_stmt const*) = 0;
  virtual void visit(Continue_stmt const*) = 0;
  virtual void visit(Expression_stmt const*) = 0;
  virtual void visit(Declaration_stmt const*) = 0;
  virtual void visit(Decode_stmt const*) = 0;
  virtual void visit(Goto_stmt const*) = 0;

  virtual void visit(Action const*) = 0;
  virtual void visit(Drop const*) = 0;
  virtual void visit(Output const*) = 0;
  virtual void visit(Flood const*) = 0;
  virtual void visit(Clear const*) = 0;
  virtual void visit(Set_field const*) = 0;
  virtual void visit(Insert_flow const*) = 0;
  virtual void visit(Remove_flow const*) = 0;
  virtual void visit(Write_drop const*) = 0;
  virtual void visit(Write_output const*) = 0;
  virtual void visit(Write_flood const*) = 0;
  virtual void visit(Write_set_field const*) = 0;
};


// The read/write declaration visitor.
struct Stmt::Mutator
{
  virtual void visit(Empty_stmt*) = 0;
  virtual void visit(Block_stmt*) = 0;
  virtual void visit(Assign_stmt*) = 0;
  virtual void visit(Return_stmt*) = 0;
  virtual void visit(Return_void_stmt*) = 0;
  virtual void visit(If_then_stmt*) = 0;
  virtual void visit(If_else_stmt*) = 0;
  virtual void visit(Match_stmt*) = 0;
  virtual void visit(Case_stmt*) = 0;
  virtual void visit(While_stmt*) = 0;
  virtual void visit(Break_stmt*) = 0;
  virtual void visit(Continue_stmt*) = 0;
  virtual void visit(Expression_stmt*) = 0;
  virtual void visit(Declaration_stmt*) = 0;
  virtual void visit(Decode_stmt*) = 0;
  virtual void visit(Goto_stmt*) = 0;

  virtual void visit(Action*) = 0;
  virtual void visit(Drop*) = 0;
  virtual void visit(Output*) = 0;
  virtual void visit(Flood*) = 0;
  virtual void visit(Clear*) = 0;
  virtual void visit(Set_field*) = 0;
  virtual void visit(Insert_flow*) = 0;
  virtual void visit(Remove_flow*) = 0;
  virtual void visit(Write_drop*) = 0;
  virtual void visit(Write_output*) = 0;
  virtual void visit(Write_flood*) = 0;
  virtual void visit(Write_set_field*) = 0;
};



// The empty statement.
struct Empty_stmt : Stmt
{
  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }
};


// A block statement.
struct Block_stmt : Stmt
{
  Block_stmt(Stmt_seq const& s)
    : first(s)
  { }

  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }

  Stmt_seq const& statements() const { return first; }

  Stmt_seq first;
};


// An assignment statement of the form:
//
//    e1 = e2
struct Assign_stmt : Stmt
{
  Assign_stmt(Expr* e1, Expr* e2)
    : first(e1), second(e2)
  { }

  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }

  Expr* object() const { return first; }
  Expr* value() const  { return second; }

  Expr* first;
  Expr* second;
};


// A return statement.
struct Return_stmt : Stmt
{
  Return_stmt(Expr* e)
    : first(e)
  { }

  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }

  Expr* value() const { return first; }

  Expr* first;
};


// An explicit return 'void' statement.
//
// NOTE: This node is currently not supported or
// exposed as surface level syntax but can be generated internally by the
// compiler. This translates to an immediate return from the function and
// can only occur in functions that return void.
struct Return_void_stmt : Stmt
{
  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }
};


// A statement of the form:
//
//    if (e) s
struct If_then_stmt : Stmt
{
  If_then_stmt(Expr* e, Stmt* s)
    : first(e), second(s)
  { }

  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }

  Expr* condition() const { return first; }
  Stmt* body() const { return second; }

  Expr* first;
  Stmt* second;
};


// A statement of the form:
//
//    if (e) s1 else s2
struct If_else_stmt : Stmt
{
  If_else_stmt(Expr* e, Stmt* s1, Stmt* s2)
    : first(e), second(s1), third(s2)
  { }

  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }

  Expr* condition() const    { return first; }
  Stmt* true_branch() const  { return second; }
  Stmt* false_branch() const { return third; }

  Expr* first;
  Stmt* second;
  Stmt* third;
};


// A statement of the form:
//
//    while (e) s
struct While_stmt : Stmt
{
  While_stmt(Expr* e, Stmt* s)
    : first(e), second(s)
  { }

  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }

  Expr* condition() const { return first; }
  Stmt* body() const      { return second; }

  Expr* first;
  Stmt* second;
};


// A break statement.
struct Break_stmt : Stmt
{
  using Stmt::Stmt;

  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }
};


// A break statement.
struct Continue_stmt : Stmt
{
  using Stmt::Stmt;

  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }
};


// An expression statement.
struct Expression_stmt : Stmt
{
  Expression_stmt(Expr* e)
    : first(e)
  { }

  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }

  Expr* expression() const { return first; }

  Expr* first;
};


// A declaration statement.
struct Declaration_stmt : Stmt
{
  Declaration_stmt(Decl* d)
    : first(d)
  { }

  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }

  Decl* declaration() const { return first; }

  Decl* first;
};


// A match statement defines a decision condition and a set
// of possible results based on that condition.
//
// By default the miss case is the empty stmt
// but it can be explicitly set
struct Match_stmt : Stmt
{
  Match_stmt(Expr* d, Stmt_seq& b)
    : condition_(d), cases_(b), miss_(nullptr)
  { }

  Match_stmt(Expr* d, Stmt_seq& b, Stmt* m)
    : condition_(d), cases_(b), miss_(m)
  { }

  Expr* condition() const     { return condition_; }
  Stmt_seq const& cases() const    { return cases_; }
  Stmt* miss() const { return miss_; }

  bool has_miss() const { return miss_ ? true : false; }

  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }

  Expr* condition_;
  Stmt_seq    cases_;
  Stmt* miss_; // the miss case
};


// A case statement.
struct Case_stmt : Stmt
{
  Case_stmt(Expr* e, Stmt* s)
    : label_(e), stmt_(s)
  { }

  Expr* label() const { return label_; }
  Stmt* stmt() const  { return stmt_; }

  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }

  Expr* label_;
  Stmt* stmt_;
};



// Call to the next decoder and pass it the context
struct Decode_stmt : Stmt
{
  Decode_stmt(Expr* e)
    : decoder_identifier_(e), decoder_(nullptr)
  { }

  Expr* decoder_identifier() const { return decoder_identifier_; }
  Decl const* decoder() const { return decoder_; }

  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }

  Expr* decoder_identifier_;
  Decl const* decoder_;
};



struct Goto_stmt : Stmt
{
  Goto_stmt(Expr* e)
    : table_identifier_(e), table_(nullptr)
  { }

  Expr* table_identifier() const { return table_identifier_; }
  Decl const* table() const { return table_; }

  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }

  Expr* table_identifier_;
  Decl const* table_;
};



// -------------------------------------------------------------------------- //
// Generic visitors

template<typename F, typename T>
struct Generic_stmt_visitor : Stmt::Visitor, lingo::Generic_visitor<F, T>
{
  Generic_stmt_visitor(F fn)
    : lingo::Generic_visitor<F, T>(fn)
  { }

  void visit(Empty_stmt const* d) { this->invoke(d); };
  void visit(Block_stmt const* d) { this->invoke(d); };
  void visit(Assign_stmt const* d) { this->invoke(d); };
  void visit(Return_stmt const* d) { this->invoke(d); };
  void visit(Return_void_stmt const* d) { this->invoke(d); };
  void visit(If_then_stmt const* d) { this->invoke(d); };
  void visit(If_else_stmt const* d) { this->invoke(d); };
  void visit(Match_stmt const* d) { this->invoke(d); };
  void visit(Case_stmt const* d) { this->invoke(d); };
  void visit(While_stmt const* d) { this->invoke(d); };
  void visit(Break_stmt const* d) { this->invoke(d); };
  void visit(Continue_stmt const* d) { this->invoke(d); };
  void visit(Expression_stmt const* d) { this->invoke(d); };
  void visit(Declaration_stmt const* d) { this->invoke(d); };
  void visit(Decode_stmt const* d) { this->invoke(d); };
  void visit(Goto_stmt const* d) { this->invoke(d); };
  void visit(Action const* d) { this->invoke(d); };
  void visit(Drop const* d) { this->invoke(d); };
  void visit(Output const* d) { this->invoke(d); };
  void visit(Flood const* d) { this->invoke(d); };
  void visit(Clear const* d) { this->invoke(d); };
  void visit(Set_field const* d) { this->invoke(d); };
  void visit(Insert_flow const* d) { this->invoke(d); };
  void visit(Remove_flow const* d) { this->invoke(d); };
  void visit(Write_drop const* d) { this->invoke(d); };
  void visit(Write_output const* d) { this->invoke(d); };
  void visit(Write_flood const* d) { this->invoke(d); };
  void visit(Write_set_field const* d) { this->invoke(d); };
};


template<typename F, typename T = typename std::result_of<F(Empty_stmt const*)>::type>
inline T
apply(Stmt const* s, F fn)
{
  Generic_stmt_visitor<F, T> v(fn);
  return lingo::accept(s, v);
}


// -------------------------------------------------------------------------- //
// Generic mutator


template<typename F, typename T>
struct Generic_stmt_mutator : Stmt::Mutator, lingo::Generic_mutator<F, T>
{
  Generic_stmt_mutator(F fn)
    : lingo::Generic_mutator<F, T>(fn)
  { }

  void visit(Empty_stmt* d) { this->invoke(d); };
  void visit(Block_stmt* d) { this->invoke(d); };
  void visit(Assign_stmt* d) { this->invoke(d); };
  void visit(Return_stmt* d) { this->invoke(d); };
  void visit(Return_void_stmt* d) { this->invoke(d); };
  void visit(If_then_stmt* d) { this->invoke(d); };
  void visit(If_else_stmt* d) { this->invoke(d); };
  void visit(Match_stmt* d) { this->invoke(d); };
  void visit(Case_stmt* d) { this->invoke(d); };
  void visit(While_stmt* d) { this->invoke(d); };
  void visit(Break_stmt* d) { this->invoke(d); };
  void visit(Continue_stmt* d) { this->invoke(d); };
  void visit(Expression_stmt* d) { this->invoke(d); };
  void visit(Declaration_stmt* d) { this->invoke(d); };
  void visit(Decode_stmt* d) { this->invoke(d); };
  void visit(Goto_stmt* d) { this->invoke(d); };
  void visit(Action* d) { this->invoke(d); };
  void visit(Drop* d) { this->invoke(d); };
  void visit(Output* d) { this->invoke(d); };
  void visit(Flood* d) { this->invoke(d); };
  void visit(Clear* d) { this->invoke(d); };
  void visit(Set_field* d) { this->invoke(d); };
  void visit(Insert_flow* d) { this->invoke(d); };
  void visit(Remove_flow* d) { this->invoke(d); };
  void visit(Write_drop* d) { this->invoke(d); };
  void visit(Write_output* d) { this->invoke(d); };
  void visit(Write_flood* d) { this->invoke(d); };
  void visit(Write_set_field* d) { this->invoke(d); };
};


template<typename F, typename T = typename std::result_of<F(Empty_stmt*)>::type>
inline T
apply(Stmt* s, F fn)
{
  Generic_stmt_mutator<F, T> m(fn);
  return lingo::accept(s, m);
}


#endif

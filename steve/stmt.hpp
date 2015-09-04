// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#ifndef STEVE_STMT_HPP
#define STEVE_STMT_HPP

// The statement module defines the notions of statements
// in the language. A statement embodies some kind of
// computation or declaration.

#include "steve/prelude.hpp"

#include "lingo/node.hpp"

namespace steve
{

struct Stmt_visitor;

// -------------------------------------------------------------------------- //
//                            Statements kinds


struct Stmt_visitor
{
  virtual void visit(Empty_stmt const*) { }
  virtual void visit(Expr_stmt const*) { }
  virtual void visit(Decl_stmt const*) { }
  virtual void visit(Block_stmt const*) { }
  virtual void visit(Return_stmt const*) { }
  virtual void visit(Match_stmt const*) { }
  virtual void visit(Case_stmt const*) { }
  virtual void visit(Instruct_stmt const*) { }
};


// -------------------------------------------------------------------------- //
//                                Statements

struct Type;
struct Expr;
struct Decl;


// The Stmt class is the base class of all statements in
// the language. A statement contains a declaration, an
// expression, or some other form of control.
struct Stmt
{
  virtual ~Stmt()
  { }

  String node_name() const;

  // Accept a statement visitor.
  virtual void accept(Stmt_visitor&) const = 0;
};


// The empty statement invokes no commands.
struct Empty_stmt : Stmt
{
  Empty_stmt(Location loc)
    : loc_(loc)
  { }

  Location location() const { return loc_; }

  void accept(Stmt_visitor& v) const { v.visit(this); }

  Location loc_;
};


// An expression statement executes its expression
// and discards the result. The runtime environment
// may save the result in a log file (or terminal).
struct Expr_stmt : Stmt
{
  Expr_stmt(Expr const* e)
    : first(e)
  { }

  Expr const* expr() const { return first; }

  void accept(Stmt_visitor& v) const { v.visit(this); }

  Expr const* first;
};


// A declaration statement contains a delaration.
struct Decl_stmt : Stmt
{
  Decl_stmt(Decl const* d)
    : first(d)
  { }

  Decl const* decl() const { return first; }

  void accept(Stmt_visitor& v) const { v.visit(this); }

  Decl const* first;
};


// A block statement is a sequence of statements.
// This is primarily here to embody the notion
// of a program. Note that blocks can be nested
// and they define separate lexical scopes.
//
// Note that in the current language the entire 
// program is a single block statement.
struct Block_stmt : Stmt, Stmt_seq
{
  // TODO: Support move semantics for the statement sequence.
  Block_stmt(Location start, Location end, Stmt_seq const& s)
    : Stmt_seq(s), start_(start), end_(end)
  { }

  Location start_location() const { return start_; }
  Location end_location()   const { return end_; }

  void accept(Stmt_visitor& v) const { v.visit(this); }

  Location start_;
  Location end_;
};


// A return statement returns a value from a function.
//
// TODO: How do we represent a return statement without
// an operand? Return a synthetic void value?
struct Return_stmt : Stmt
{
  Return_stmt(Location loc, Expr const* e)
    : loc_(loc), first(e)
  { }

  Location    location() const { return loc_; }
  Expr const* result() const { return first; }

  void accept(Stmt_visitor& v) const { v.visit(this); }

  Location    loc_;
  Expr const* first;
};


// A case statement.
struct Case_stmt : Stmt   
{
  Case_stmt(Location loc, Expr const* e, Stmt const* s)
    : loc_(loc), first(e), second(s)
  { }

  Expr const* label() const { return first; }
  Stmt const* stmt() const  { return second; }

  void accept(Stmt_visitor& v) const { v.visit(this); }

  Location    loc_;
  Expr const* first;
  Stmt const* second;
};


// A match statement defines a decision condition and a set 
// of possible results based on that condition.
struct Match_stmt : Stmt
{
  Match_stmt(Location loc, Expr const* d, Stmt_seq const& b)
    : loc_(loc), first(d), second(b)
  { }

  Location        location() const { return loc_; }
  Expr     const* cond() const     { return first; }
  Stmt_seq const& cases() const    { return second; }

  void accept(Stmt_visitor& v) const { v.visit(this); }

  Location    loc_;
  Expr const* first;
  Stmt_seq    second;
};


enum Instruct_kind
{
  meter_ins,
  apply_ins,
  clear_ins,
  write_ins,
  meta_ins,
  goto_ins
};


// FIXME: Re-design this this.
struct Instruct_stmt : Stmt
{
  Instruct_stmt(Location loc, Instruct_kind k, Stmt_seq const& args)
    : instr_(k), first(args)
  { }

  Stmt_seq const& args() const { return first; }
  Instruct_kind   instr() const { return instr_; }

  void accept(Stmt_visitor& v) const { v.visit(this); }

  Instruct_kind instr_;
  Stmt_seq const first;
};


// -------------------------------------------------------------------------- //
//                           Concepts and dispatch

// True when T is models the Statement concept. 
//
// Note that we assume that a Statement is already known 
// to be Node, so we skip the explicit check.
template<typename T>
constexpr bool
is_stmt()
{
  return std::is_base_of<Stmt, T>::value;
}


// -------------------------------------------------------------------------- //
//                            Generic visitor

// A parameterized visitor that dispatches to a function object.
template<typename F, typename T>
struct Generic_stmt_visitor : Stmt_visitor, Generic_visitor<F, T>
{
  Generic_stmt_visitor(F f)
    : Generic_visitor<F, T>(f)
  { }

  void visit(Empty_stmt const* s) { this->invoke(s); }
  void visit(Expr_stmt const* s) { this->invoke(s); }
  void visit(Decl_stmt const* s) { this->invoke(s); }
  void visit(Block_stmt const* s) { this->invoke(s); }
  void visit(Return_stmt const* s) { this->invoke(s); }
  void visit(Match_stmt const* s) { this->invoke(s); }
  void visit(Case_stmt const* s) { this->invoke(s); }
  void visit(Instruct_stmt const* s) { this->invoke(s); }
};


// Apply the function f to the statement s.
template<typename F, typename T = typename std::result_of<F(Empty_stmt*)>::type>
inline T
apply(Stmt const* s, F fn)
{
  Generic_stmt_visitor<F, T> v(fn);
  return accept(s, v);
}


// -------------------------------------------------------------------------- //
//                            Statement builders

Empty_stmt*  make_empty_stmt(Location);
Expr_stmt*   make_expr_stmt(Expr const*);
Decl_stmt*   make_decl_stmt(Decl const*);
Block_stmt*  make_block_stmt(Location, Location, Stmt_seq const&);
Return_stmt* make_return_stmt(Location, Expr const*);
Match_stmt*  make_match_stmt(Location, Expr const*, Stmt_seq const&);
Case_stmt*   make_case_stmt(Location, Expr const*, Stmt const*);


inline Empty_stmt*
make_empty_stmt()
{
  return make_empty_stmt(Location::none);
}


inline Block_stmt*
make_block_stmt(Stmt_seq const& seq)
{
  return make_block_stmt(Location::none, Location::none, seq);
}


inline Return_stmt*
make_return_stmt(Expr const* e)
{
  return make_return_stmt(Location::none, e);
}


inline Case_stmt*
make_case_stmt(Expr const* e, Stmt const* s)
{
  return make_case_stmt(Location::none, e, s);
}


inline Match_stmt*
make_match_stmt(Expr const* e, Stmt_seq const& s)
{
  return make_match_stmt(Location::none, e, s);
}


// -------------------------------------------------------------------------- //
//                                 Facilities

// Garbage collection
void mark(Stmt const*);

// Pretty printing
void print(Printer&, Stmt const*);
void debug(Printer&, Stmt const*);

std::ostream& operator<<(std::ostream&, Stmt const*);


} // namespace steve

#endif

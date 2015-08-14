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


// -------------------------------------------------------------------------- //
//                            Statements kinds

// Different kinds of statement in the core language.
enum Stmt_kind
{
  empty_stmt,     // the empty statment (;)
  expr_stmt,      // e;
  decl_stmt,      // a declaration
  block_stmt,     // a sequence of statements
  return_stmt,    // return e;
  match_stmt,     // match { }
  case_stmt,      // <const_value> : stmt_seq;
  instruct_stmt,  // one of the 6 open flow instructions
};


char const* get_stmt_name(Stmt_kind);


// Adapt the generic node-kinding template to this node type.
template<Stmt_kind K>
using Stmt_impl = lingo::Kind_base<Stmt_kind, K>;


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
  Stmt(Stmt_kind k)
    : kind_(k)
  { }

  virtual ~Stmt()
  { }

  char const*   node_name() const { return get_stmt_name(kind_); }
  Stmt_kind     kind() const      { return kind_; }

  Stmt_kind     kind_;
};


// The empty statement invokes no commands.
struct Empty_stmt : Stmt, Stmt_impl<empty_stmt>
{
  Empty_stmt(Location loc)
    : Stmt(node_kind), loc_(loc)
  { }

  Location loc_;
};


// An expression statement executes its expression
// and discards the result. The runtime environment
// may save the result in a log file (or terminal).
struct Expr_stmt : Stmt, Stmt_impl<expr_stmt>
{
  Expr_stmt(Expr const* e)
    : Stmt(node_kind), first(e)
  { }

  Expr const* expr() const { return first; }

  Expr const* first;
};


// A declaration statement contains a delaration.
struct Decl_stmt : Stmt, Stmt_impl<decl_stmt>
{
  Decl_stmt(Decl const* d)
    : Stmt(node_kind), first(d)
  { }

  Decl const* decl() const { return first; }

  Decl const* first;
};


// A block statement is a sequence of statements.
// This is primarily here to embody the notion
// of a program. Note that blocks can be nested
// and they define separate lexical scopes.
//
// Note that in the current language the entire 
// program is a single block statement.
struct Block_stmt : Stmt, Stmt_impl<block_stmt>, Stmt_seq
{
  // TODO: Support move semantics for the statement sequence.
  Block_stmt(Location start, Location end, Stmt_seq const& s)
    : Stmt(node_kind), Stmt_seq(s), start_(start), end_(end)
  { }

  Location start_location() const { return start_; }
  Location end_location()   const { return end_; }

  Location start_;
  Location end_;
};


// A return statement returns a value from a function.
//
// TODO: How do we represent a return statement without
// an operand? Return a synthetic void value?
struct Return_stmt : Stmt, Stmt_impl<return_stmt>
{
  Return_stmt(Location loc, Expr const* e)
    : Stmt(node_kind), loc_(loc), first(e)
  { }

  Location    location() const { return loc_; }
  Expr const* result() const { return first; }

  Location    loc_;
  Expr const* first;
};


// A case statement.
struct Case_stmt : Stmt, Stmt_impl<case_stmt>      
{
  Case_stmt(Location loc, Expr const* e, Stmt const* s)
    : Stmt(node_kind), loc_(loc), first(e), second(s)
  { }

  Expr const* label() const { return first; }
  Stmt const* stmt() const  { return second; }

  Location    loc_;
  Expr const* first;
  Stmt const* second;
};


// A match statement defines a decision condition and a set 
// of possible results based on that condition.
struct Match_stmt : Stmt, Stmt_impl<match_stmt>
{
  Match_stmt(Location loc, Expr const* d, Stmt_seq const& b)
    : Stmt(node_kind), loc_(loc), first(d), second(b)
  { }

  Location        location() const { return loc_; }
  Expr     const* cond() const     { return first; }
  Stmt_seq const& cases() const    { return second; }

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
struct Instruct_stmt : Stmt, Stmt_impl<instruct_stmt>
{
  Instruct_stmt(Location loc, Instruct_kind k, Stmt_seq const& args)
    : Stmt(node_kind), instr_(k), first(args)
  { }

  Stmt_seq const& args() const { return first; }
  Instruct_kind   instr() const { return instr_; }

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


// Apply the function to the statement `s`.
template<typename T, typename F>
auto
apply(T const* s, F fn)
  -> typename std::enable_if<is_stmt<T>(), decltype(fn((Expr_stmt*)0))>::type
{
  lingo_alert(is_valid_node(s), "invalid statement");
  switch (s->kind()) {
  case empty_stmt: return fn(cast<Empty_stmt>(s));
  case expr_stmt: return fn(cast<Expr_stmt>(s));
  case decl_stmt: return fn(cast<Decl_stmt>(s));
  case block_stmt: return fn(cast<Block_stmt>(s));
  case return_stmt: return fn(cast<Return_stmt>(s));
  case match_stmt: return fn(cast<Match_stmt>(s));
  case case_stmt: return fn(cast<Case_stmt>(s));
  case instruct_stmt: return fn(cast<Instruct_stmt>(s));
  }
  lingo_unreachable("unhandled statement '{}'", s->node_name());
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

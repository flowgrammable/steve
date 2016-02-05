#ifndef ACTIONS_HPP
#define ACTIONS_HPP

#include "beaker/expr.hpp"
#include "beaker/type.hpp"
#include "beaker/stmt.hpp"


// ------------------------------------------------ //
//      Required Actions


struct Action : Stmt
{
  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }
};


struct Drop : Action
{
  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }
};


struct Flood : Action
{
  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }
};


// Output the packet to a given
// port.
struct Output : Action
{
  Output(Expr* e)
    : port_(e)
  { }

  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }

  Expr* port() const { return port_; }

  Expr* port_;
};


// Output inport is special because it can only occur within the context
// of a flow. When we say output inport, we mean that inport of the Context
// used when installing the flow.
//
// The inport is implicitly resolved at runtime when executing this action
// by requesting that a flow provide the inport.
struct Output_inport : Output
{
  Output_inport()
    : Output(nullptr)
  { }

  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }
};


// Clear the set of actions stored within the packet.
struct Clear : Action
{
  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }
};


struct Set_field : Action
{
  Set_field(Expr* f, Expr* v)
    : field_(f), value_(v)
  { }

  Expr* field() const { return field_; }
  Expr* value() const { return value_; }

  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }

  Expr* field_;
  Expr* value_;
};


struct Copy_field : Action
{
  Copy_field(Expr* f, Expr* v)
    : field_(f), target_(v)
  { }

  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }

  Expr* field_;
  Expr* target_;
};


struct Add_field : Action
{
};


struct Del_field : Action
{
};


struct Get_field : Action
{
};


// Add a flow entry to a table.
struct Insert_flow : Action
{
  Insert_flow(Decl* f, Expr* t)
    : flow_(f), table_id_(t)
  { }

  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }

  Decl* flow()  const { return flow_; }
  Decl* table() const;
  Expr* table_identifier() const { return table_id_; }

  Decl* flow_;
  Expr* table_id_;
};


inline Decl*
Insert_flow::table() const
{
  assert(is<Decl_expr>(table_id_));
  return as<Decl_expr>(table_id_)->declaration();
}


// Remove a flow entry from a table.
struct Remove_flow : Action
{
  Remove_flow(Expr_seq const& k, Expr* t)
    : keys_(k), table_id_(t)
  { }

  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }

  Expr_seq const& keys()  const { return keys_; }
  Decl*           table() const;
  Expr*           table_identifier() const { return table_id_; }

  Expr_seq keys_;
  Expr* table_id_;
};


inline Decl*
Remove_flow::table() const
{
  assert(is<Decl_expr>(table_id_));
  return as<Decl_expr>(table_id_)->declaration();
}


// Raise an event.
struct Raise : Action
{
  Raise(Expr* e)
    : event_id_(e)
  { }

  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }

  Expr* event_identifier() const { return event_id_; }
  Decl* event()            const { return event_; }

  Expr* event_id_;
  Decl* event_;
};


// Goto a group table
struct Group : Action
{
};


// Write a drop for later.
struct Write_drop : Action
{
  Write_drop(Stmt* a)
    : first(a)
  { }

  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }

  Drop* drop() const { return cast<Drop>(first); }

  Stmt* first;
};


// Write an output to port acttion
// to the context
struct Write_output : Action
{
  Write_output(Stmt* a)
    : first(a)
  { }

  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }

  Output* output() const { return cast<Output>(first); }

  Stmt* first;
};


// Write a flood action to context.
struct Write_flood : Action
{
  Write_flood(Stmt* a)
    : first(a)
  { }

  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }

  Flood* flood() const { return cast<Flood>(first); }

  Stmt* first;
};


// Write set field
struct Write_set_field : Action
{
  Write_set_field(Stmt* a)
  : first(a)
{ }

  void accept(Visitor& v) const { return v.visit(this); }
  void accept(Mutator& v)       { return v.visit(this); }

  Set_field* set_field() const { return cast<Set_field>(first); }

  Stmt* first;
};


// Write add field
struct Write_add_field : Action
{
};


// Write rmv field
struct Write_del_field : Action
{
};


struct Write_copy_field : Action
{
};


struct Write_group : Action
{
};


// Returns true iff the statement is a pipeline terminator action.
// Terminators are:
//    decode-stmts
//    goto-stmt
//    drop-stmt
//    flood-stmt
//    output-stmt
inline bool
is_terminator(Stmt* s)
{
  return is<Decode_stmt>(s)
      || is<Goto_stmt>(s)
      || is<Drop>(s)
      || is<Flood>(s)
      || is<Output>(s);
      // FIXME: Is raise a terminating action? I don't think it is.
      // Raise should cause a copy of the context to be passed to an
      // asynchronous event handler and allow the continuation of processing
      // on the current packet.
      // || is<Raise>(s);
}


// Returns true iff at least 1 statement in a statement
// sequence contains a terminator.
inline bool
has_terminator_action(Stmt_seq const& body)
{
  for (auto s : body) {
    if (is_terminator(s))
      return true;
  }

  return false;
}


// Returns true iff more than 1 statement in a statement sequence
// is a terminator.
inline bool
has_multiple_terminators(Stmt_seq const& body)
{
  int c = 0;
  for (auto s : body) {
    if (is_terminator(s))
      c++;
  }

  return (c > 1) ? true : false;
}


// Returns true iff a statement is an action.
inline bool
is_action(Stmt* s)
{
  // FIXME: Get rid of this once Decode_stmt and Goto_stmt are made actions.
  return is<Action>(s)
      || is<Decode_stmt>(s)
      || is<Goto_stmt>(s);
      // FIXME: Remove this, currently for debugging purposes only.
      // || is<Stmt>(s);
}


// Returns true iff an action occurs within the context of a
// decoder, flow, or event.
inline bool
is_valid_action_context(Stmt* s)
{
  return is<Decode_decl>(s->context())
      || is<Flow_decl>(s->context())
      || is<Event_decl>(s->context());
}


#endif

// Copyright (c) 2015 Andrew Sutton
// All rights reserved

#ifndef BEAKER_PARSER_HPP
#define BEAKER_PARSER_HPP

#include <beaker/prelude.hpp>
#include <beaker/decl.hpp>
#include <beaker/specifier.hpp>
#include <beaker/token.hpp>


class Input_buffer;


// The parser performs syntactic analysis, transforming
// a token stream into an AST.
class Parser
{
public:
  Parser(Symbol_table&, Token_stream&);
  Parser(Symbol_table&, Token_stream&, Location_map&);

  // Expression parsers
  Expr* primary_expr();
  Expr* call_expr();
  Expr* postfix_expr();
  Expr* unary_expr();
  Expr* multiplicative_expr();
  Expr* additive_expr();
  Expr* bitshift_expr();
  Expr* ordering_expr();
  Expr* equality_expr();
  Expr* bitwise_and_expr();
  Expr* bitwise_xor_expr();
  Expr* bitwise_or_expr();
  Expr* logical_and_expr();
  Expr* logical_or_expr();
  Expr* field_name_expr();
  Expr* field_access_expr();
  Expr* expr();

  // Postfix expr
  Expr* dot_expr(Expr*);
  Expr* call_expr(Expr*);

  // Type parsers
  Type const* integer_type();
  Type const* unsigned_integer_type();
  Type const* primary_type();
  Type const* postfix_type();
  Type const* type();

  // Declaration parsers
  Decl* decl();
  Decl* variable_decl(Specifier);
  Decl* function_decl(Specifier);
  Decl* parameter_decl();
  Decl* record_decl(Specifier);
  Decl* field_decl(Specifier);
  Decl* method_decl(Specifier);
  Specifier specifier_seq();

  // network specific
  Decl* layout_decl();
  Decl* decode_decl();
  Decl* exact_table_decl();
  Decl* key_decl();
  Decl* inport_key_decl();
  Decl* inphysport_key_decl();
  Decl* flow_decl();
  Decl* port_decl();
  Decl* extract_decl();
  Decl* rebind_decl();
  Decl* event_decl();

  // Statement parsers
  Stmt* stmt();
  Stmt* empty_stmt();
  Stmt* block_stmt();
  Stmt* return_stmt();
  Stmt* if_stmt();
  Stmt* while_stmt();
  Stmt* break_stmt();
  Stmt* continue_stmt();
  Stmt* declaration_stmt();
  Stmt* expression_stmt();
  Stmt* match_stmt();
  Stmt* case_stmt();
  Stmt* miss_case_stmt();
  Stmt* decode_stmt();
  Stmt* goto_stmt();
  Stmt* drop_stmt();
  Stmt* flood_stmt();
  Stmt* clear_stmt();
  Stmt* output_stmt();
  Stmt* set_stmt();
  Stmt* copy_stmt();
  Stmt* write_stmt();
  Stmt* add_flow_stmt();
  Stmt* rmv_flow_stmt();
  Stmt* raise_stmt();

  // Top-level.
  Decl* module(Module_decl*);

  // Helpers
  Expr_seq parse_colon_seperated(Token tok);
  Symbol const* get_qualified_name(Expr_seq const&);
  Stmt_seq flow_properties();

  // Parse state
  bool ok() const { return errs_ == 0; }

  explicit operator bool() const { return ok(); }

private:
  // Actions
  Type const* on_id_type(Token);
  Type const* on_reference_type(Type const*);
  Type const* on_array_type(Type const*, Expr*);
  Type const* on_block_type(Type const*);
  Type const* on_function_type(Type_seq const&, Type const*);

  Expr* on_id(Token);
  Expr* on_bool(Token);
  Expr* on_int(Token);
  Expr* on_uint(Token);
  Expr* on_hex(Token);
  Expr* on_binary(Token);
  Expr* on_char(Token);
  Expr* on_str(Token);
  Expr* on_add(Expr*, Expr*);
  Expr* on_sub(Expr*, Expr*);
  Expr* on_mul(Expr*, Expr*);
  Expr* on_div(Expr*, Expr*);
  Expr* on_rem(Expr*, Expr*);
  Expr* on_lshift(Expr*, Expr*);
  Expr* on_rshift(Expr*, Expr*);
  Expr* on_bitwise_and(Expr*, Expr*);
  Expr* on_bitwise_or(Expr*, Expr*);
  Expr* on_xor(Expr*, Expr*);
  Expr* on_neg(Expr*);
  Expr* on_pos(Expr*);
  Expr* on_eq(Expr*, Expr*);
  Expr* on_ne(Expr*, Expr*);
  Expr* on_lt(Expr*, Expr*);
  Expr* on_gt(Expr*, Expr*);
  Expr* on_le(Expr*, Expr*);
  Expr* on_ge(Expr*, Expr*);
  Expr* on_and(Expr*, Expr*);
  Expr* on_or(Expr*, Expr*);
  Expr* on_not(Expr*);
  Expr* on_call(Expr*, Expr_seq const&);
  Expr* on_index(Expr*, Expr*);
  Expr* on_dot(Expr*, Expr*);
  Expr* on_field_name(Expr_seq const&);
  Expr* on_field_access(Expr_seq const&);
  Expr* on_inport(Token);
  Expr* on_inphysport(Token);
  Expr* on_all_port(Token);
  Expr* on_controller_port(Token);
  Expr* on_reflow_port(Token);

  Decl* on_variable(Specifier, Token, Type const*);
  Decl* on_variable(Specifier, Token, Type const*, Expr*);
  Decl* on_parameter(Specifier, Type const*);
  Decl* on_parameter(Specifier, Token, Type const*);
  Decl* on_function(Specifier, Token, Decl_seq const&, Type const*);
  Decl* on_function(Specifier, Token, Decl_seq const&, Type const*, Stmt*);
  Decl* on_record(Specifier, Token, Decl_seq const&, Decl_seq const&, Type const*);
  Decl* on_field(Specifier, Token, Type const*);
  Decl* on_method(Specifier, Token, Decl_seq const&, Type const*, Stmt*);
  Decl* on_module(Module_decl*, Decl_seq const&);

  Decl* on_layout(Token, Decl_seq const&);
  Decl* on_decoder(Token, Type const*, Stmt*, bool);
  Decl* on_extract(Expr*);
  Decl* on_rebind(Expr*, Expr*);
  Decl* on_exact_table(Token, Decl_seq&, Expr_seq&, Decl_seq&, Decl*);
  Decl* on_key(Expr*);
  Decl* on_inport_key(Token);
  Decl* on_inphysport_key(Token);
  Decl* on_flow(Expr_seq const&, Stmt*, Stmt_seq const&);
  Decl* on_flow_miss(Stmt*, Stmt_seq const&);
  Decl* on_port(Token, Expr*);
  Decl* on_event(Token, Expr_seq const&, Stmt*);


  // FIXME: Remove _stmt from handlers.
  Stmt* on_empty();
  Stmt* on_block(Stmt_seq const&);
  Stmt* on_assign(Expr*, Expr*);
  Stmt* on_return(Expr*);
  Stmt* on_if_then(Expr*, Stmt*);
  Stmt* on_if_else(Expr*, Stmt*, Stmt*);
  Stmt* on_while(Expr*, Stmt*);
  Stmt* on_break();
  Stmt* on_continue();
  Stmt* on_expression(Expr*);
  Stmt* on_declaration(Decl*);

  Stmt* on_case(Expr*, Stmt*);
  Stmt* on_match(Expr*, Stmt_seq&, Stmt*);
  Stmt* on_decode(Expr*, Expr*);
  Stmt* on_goto(Expr*, Expr*);
  Stmt* on_drop();
  Stmt* on_flood();
  Stmt* on_clear();
  Stmt* on_output(Expr*);
  Stmt* on_output_egress();
  Stmt* on_set(Expr*, Expr*);
  Stmt* on_copy(Expr*, Expr*);
  Stmt* on_write(Stmt*);
  Stmt* on_add_flow(Decl*, Expr*);
  Stmt* on_rmv_flow(Expr_seq const&, Expr*);
  Stmt* on_raise(Expr*);

  // Parsing support
  Token_kind lookahead() const;
  Token_kind lookahead(int) const;
  Token      match(Token_kind);
  Token      match_if(Token_kind);
  Token      require(Token_kind);
  Token      accept();
  void       consume_until(Token_kind);
  void       consume_thru(Token_kind);

  // Error handling. These functions throw
  // exceptions. They never return.
  [[noreturn]] void error(char const*);
  [[noreturn]] void error(String const&);

  // Location management
  void locate(void*, Location);
  Location locate(void*);

  template<typename T, typename... Args>
  T* init(Location, Args&&...);

private:
  Symbol_table& syms_;
  Token_stream& ts_;
  Location_map* locs_;

  Specifier spec_;  // Current specifeirs

  int errs_;        // Error count

  // Parse flags
  Token_kind term_; // Statement termination token.
};


inline
Parser::Parser(Symbol_table& s, Token_stream& t)
  : syms_(s), ts_(t), locs_(nullptr), errs_(0), term_()
{ }


inline
Parser::Parser(Symbol_table& s, Token_stream& t, Location_map& l)
  : syms_(s), ts_(t), locs_(&l), errs_(0), term_()
{ }


// Returns the first token of lookahead.
inline Token_kind
Parser::lookahead() const
{
  return Token_kind(ts_.peek().kind());
}


// Returns the nth token of lookahead.
inline Token_kind
Parser::lookahead(int n) const
{
  return Token_kind(ts_.peek(n).kind());
}


// Save the location of the declaratio.
inline void
Parser::locate(void* p, Location l)
{
  locs_->emplace(p, l);
}


inline Location
Parser::locate(void* p)
{
  auto iter = locs_->find(p);
  if (iter != locs_->end())
    return iter->second;
  else
    return {};
}


// A helper function to create nodes and record their
// source location.
//
// TODO: Put this in the .cpp file? It is private.
template<typename T, typename... Args>
inline T*
Parser::init(Location loc, Args&&... args)
{
  T* t = new T(std::forward<Args>(args)...);
  locs_->emplace(t, loc);
  return t;
}


#endif

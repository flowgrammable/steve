// Copyright (c) 2015 Andrew Sutton
// All rights reserved


#include "beaker/generator.hpp"
#include "beaker/type.hpp"
#include "beaker/expr.hpp"
#include "beaker/stmt.hpp"
#include "beaker/decl.hpp"
#include "beaker/mangle.hpp"
#include "beaker/evaluator.hpp"
#include "beaker/builtin.hpp"

#include "llvm/IR/Type.h"
#include "llvm/IR/GlobalVariable.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Module.h"
#include <llvm/Support/raw_ostream.h>

#include <iostream>


// -------------------------------------------------------------------------- //
// Mapping of names

// Synthesize a name using the linkage model for
// the declaration's language. Currently, there
// are two linkage models:
//
//    - C
//    - Beaker
//
// NOTE: Currently, these are the same. However, these
// differ be as Beaker evolves.
String
Generator::get_name(Decl const* d)
{
  if (d->is_foreign())
    return d->name()->spelling();
  else if (d->is_extern())
    return d->name()->spelling();
  else
    return mangle(d);
}


// -------------------------------------------------------------------------- //
// Mapping of types
//
// The type generator transforms a beaker type into
// its correspondiong LLVM type.


llvm::Type*
Generator::get_type(Type const* t)
{
  struct Fn
  {
    Generator& g;
    llvm::Type* operator()(Id_type const* t) const { return g.get_type(t); }
    llvm::Type* operator()(Boolean_type const* t) const { return g.get_type(t); }
    llvm::Type* operator()(Character_type const* t) const { return g.get_type(t); }
    llvm::Type* operator()(Integer_type const* t) const { return g.get_type(t); }
    llvm::Type* operator()(Function_type const* t) const { return g.get_type(t); }
    llvm::Type* operator()(Array_type const* t) const { return g.get_type(t); }
    llvm::Type* operator()(Block_type const* t) const { return g.get_type(t); }
    llvm::Type* operator()(Reference_type const* t) const { return g.get_type(t); }
    llvm::Type* operator()(Record_type const* t) const { return g.get_type(t); }
    llvm::Type* operator()(Void_type const* t) { return g.get_type(t); }
    llvm::Type* operator()(Context_type const* t) { return g.get_type(t); }
    llvm::Type* operator()(Opaque_type const* t) { return g.get_type(t); }

    // network specific types
    llvm::Type* operator()(Layout_type const* t) const { return g.get_type(t); }
    llvm::Type* operator()(Table_type const* t) const { return g.get_type(t); }
    llvm::Type* operator()(Flow_type const* t) const { return g.get_type(t); }
    llvm::Type* operator()(Port_type const* t) const { return g.get_type(t); }
    llvm::Type* operator()(Key_type const* t) const { return g.get_type(t); }
  };
  return apply(t, Fn{*this});
}


// The program is unsound if we ever reach this
// function. Id-types are replaced with their
// referenced declarations during elaboration.
llvm::Type*
Generator::get_type(Id_type const* t)
{
  std::stringstream ss;
  ss << "unresolved id-type '" << *t->symbol() << '\'';
  throw std::runtime_error(ss.str());
}


// Return the 1 bit integer type.
llvm::Type*
Generator::get_type(Boolean_type const*)
{
  return build.getInt1Ty();
}


// Return the 8 bit integer type.
llvm::Type*
Generator::get_type(Character_type const*)
{
  return build.getInt8Ty();
}


// Return the 32 bit integer type.
llvm::Type*
Generator::get_type(Integer_type const* t)
{
  return build.getIntNTy(t->precision());
}


// Return a function type.
llvm::Type*
Generator::get_type(Function_type const* t)
{
  std::vector<llvm::Type*> ts;
  ts.reserve(t->parameter_types().size());
  for (Type const* t1 : t->parameter_types())
    ts.push_back(get_type(t1));
  llvm::Type* r = get_type(t->return_type());
  return llvm::FunctionType::get(r, ts, t->var_args());
}


// Return an array type.
llvm::Type*
Generator::get_type(Array_type const* t)
{
  llvm::Type* t1 = get_type(t->type());
  Value v = evaluate(t->extent());
  return llvm::ArrayType::get(t1, v.get_integer());
}


// A chunk is just a pointer to an object
// of the underlying type.
llvm::Type*
Generator::get_type(Block_type const* t)
{
  llvm::Type* t1 = get_type(t->type());
  return llvm::PointerType::getUnqual(t1);
}


// Translate reference types into pointer types in the
// generic address space.
//
// TODO: Actually do this?
llvm::Type*
Generator::get_type(Reference_type const* t)
{
  llvm::Type* t1 = get_type(t->type());
  return llvm::PointerType::getUnqual(t1);
}


// Return the structure type corresponding to the
// declaration of t. If, for some reason, we encounter
// the type before its declaration, just emit the
// definition now.
llvm::Type*
Generator::get_type(Record_type const* t)
{
  auto const* bind = types.lookup(t->declaration());
  if (!bind) {
    // Note that we have to do a 2nd lookup because
    // we don't return anything from generating
    // declarations.
    gen(t->declaration());
    bind = types.lookup(t->declaration());
  }
  return bind->second;
}


llvm::Type*
Generator::get_type(Void_type const* t)
{
  return build.getVoidTy();
}


llvm::Type*
Generator::get_type(Opaque_type const* t)
{
  static llvm::Type* opaque_type = llvm::StructType::create(cxt, "Opaque");
  return opaque_type;
}


// We should never get here
llvm::Type*
Generator::get_type(Layout_type const* t)
{
  throw std::runtime_error("cannot generate layout type");
  return nullptr;
}


// TODO: create an opaque type
// %Context = type opaque
llvm::Type*
Generator::get_type(Context_type const* t)
{
  static llvm::Type* context_type = llvm::StructType::create(cxt, "Context");
  return context_type;
}


// Generate a table type (?)
// Is this strictly necessary?
// I think tables are only for use in semantic checking
// and just become requests once we move to the runtime
llvm::Type*
Generator::get_type(Table_type const*)
{
  static llvm::Type* table_type = llvm::StructType::create(cxt, "Table");
  return table_type;
}


llvm::Type*
Generator::get_type(Flow_type const*)
{
  throw std::runtime_error("cannot generate flow type");
  return nullptr;
}


// Produces and opaque type
llvm::Type*
Generator::get_type(Port_type const* t)
{
  static llvm::Type* port_type = llvm::StructType::create(cxt, "Port");
  return port_type;
}


// Produces and opaque type
llvm::Type*
Generator::get_type(Key_type const* t)
{
  static llvm::Type* key_type = llvm::StructType::create(cxt, "Key");
  return key_type;
}


// -------------------------------------------------------------------------- //
// Code generation for expressions
//
// An expression is transformed into a sequence instructions whose
// intermediate results are saved in registers.

llvm::Value*
Generator::gen(Expr const* e)
{
  struct Fn
  {
    Generator& g;
    llvm::Value* operator()(Literal_expr const* e) const { return g.gen(e); }
    llvm::Value* operator()(Id_expr const* e) const { return g.gen(e); }
    llvm::Value* operator()(Decl_expr const* e) const { return g.gen(e); }
    llvm::Value* operator()(Add_expr const* e) const { return g.gen(e); }
    llvm::Value* operator()(Sub_expr const* e) const { return g.gen(e); }
    llvm::Value* operator()(Mul_expr const* e) const { return g.gen(e); }
    llvm::Value* operator()(Div_expr const* e) const { return g.gen(e); }
    llvm::Value* operator()(Rem_expr const* e) const { return g.gen(e); }
    llvm::Value* operator()(Lshift_expr const* e) const { return g.gen(e); }
    llvm::Value* operator()(Rshift_expr const* e) const { return g.gen(e); }
    llvm::Value* operator()(Bitwise_and_expr const* e) const { return g.gen(e); }
    llvm::Value* operator()(Bitwise_or_expr const* e) const { return g.gen(e); }
    llvm::Value* operator()(Xor_expr const* e) const { return g.gen(e); }
    llvm::Value* operator()(Neg_expr const* e) const { return g.gen(e); }
    llvm::Value* operator()(Pos_expr const* e) const { return g.gen(e); }
    llvm::Value* operator()(Eq_expr const* e) const { return g.gen(e); }
    llvm::Value* operator()(Ne_expr const* e) const { return g.gen(e); }
    llvm::Value* operator()(Lt_expr const* e) const { return g.gen(e); }
    llvm::Value* operator()(Gt_expr const* e) const { return g.gen(e); }
    llvm::Value* operator()(Le_expr const* e) const { return g.gen(e); }
    llvm::Value* operator()(Ge_expr const* e) const { return g.gen(e); }
    llvm::Value* operator()(And_expr const* e) const { return g.gen(e); }
    llvm::Value* operator()(Or_expr const* e) const { return g.gen(e); }
    llvm::Value* operator()(Not_expr const* e) const { return g.gen(e); }
    llvm::Value* operator()(Call_expr const* e) const { return g.gen(e); }
    llvm::Value* operator()(Dot_expr const* e) const { return g.gen(e); }
    llvm::Value* operator()(Field_expr const* e) const { return g.gen(e); }
    llvm::Value* operator()(Method_expr const* e) const { return g.gen(e); }
    llvm::Value* operator()(Index_expr const* e) const { return g.gen(e); }
    llvm::Value* operator()(Value_conv const* e) const { return g.gen(e); }
    llvm::Value* operator()(Block_conv const* e) const { return g.gen(e); }
    llvm::Value* operator()(Promotion_conv const* e) const { return g.gen(e); }
    llvm::Value* operator()(Demotion_conv const* e) const { return g.gen(e); }
    llvm::Value* operator()(Sign_conv const* e) const { return g.gen(e); }
    llvm::Value* operator()(Default_init const* e) const { return g.gen(e); }
    llvm::Value* operator()(Copy_init const* e) const { return g.gen(e); }
    llvm::Value* operator()(Reference_init const* e) const { return g.gen(e); }
    llvm::Value* operator()(Reinterpret_cast const* e) const { return g.gen(e); }
    llvm::Value* operator()(Void_cast const* e) const { return g.gen(e); }
    llvm::Value* operator()(Field_name_expr const* e) const { return g.gen(e); }
    llvm::Value* operator()(Field_access_expr const* e) const { lingo_unreachable(); }
    llvm::Value* operator()(Get_port const* e) const { return g.gen(e); }
    llvm::Value* operator()(Create_table const* e) const { return g.gen(e); }
    llvm::Value* operator()(Get_dataplane const* e) const { return g.gen(e); }
  };

  return apply(e, Fn{*this});
}


// Return the value corresponding to a literal expression.
llvm::Value*
Generator::gen(Literal_expr const* e)
{
  // TODO: Write better type queries.
  //
  // TODO: Write a better interface for values.
  Value v = evaluate(e);
  Type const* t = e->type();
  if (t == get_boolean_type())
    return build.getInt1(v.get_integer());
  if (t == get_character_type())
    return build.getInt8(v.get_integer());
  if (Integer_type const* itype = as<Integer_type>(t)) {
    // Construct an APInt from the integer
    Integer_value val = v.get_integer();
    llvm::APInt integer(itype->precision(),
                        val.decimal_str(),
                        10);
    llvm::Value* v = build.getInt(integer);
    return v;
  }

  // FIXME: How should we generate array literals? Are
  // these global constants or are they local alloca
  // objects. Does it depend on context?

  // A string literal produces a new global string constant.
  // and returns a pointer to an array of N characters.
  if (is_string(t)) {
    Array_value a = v.get_array();
    String s = a.get_string();

    // FIXME: This does not unify equivalent strings.
    // Maybe we needt maintain a mapping in order to
    // avoid redunancies.
    auto iter = strings.find(s);
    if (iter == strings.end()) {
      llvm::Value* v = build.CreateGlobalString(s);
      iter = strings.emplace(s, v).first;
    }
    return iter->second;
  }

  else
    throw std::runtime_error("cannot generate function literal");
}


llvm::Value*
Generator::gen(Id_expr const* e)
{
  lingo_unreachable();
}


// Returns the value associated with the declaration.
llvm::Value*
Generator::gen(Decl_expr const* e)
{
  auto const* bind = stack.lookup(e->declaration());
  llvm::Value* result = bind->second;

  // Fetch the value from a reference declaration.
  Decl const* decl = bind->first;

  if (is_reference(decl))
    return build.CreateLoad(result);

  return result;
}


llvm::Value*
Generator::gen(Add_expr const* e)
{
  llvm::Value* l = gen(e->left());
  llvm::Value* r = gen(e->right());
  return build.CreateAdd(l, r);
}


llvm::Value*
Generator::gen(Sub_expr const* e)
{
  llvm::Value* l = gen(e->left());
  llvm::Value* r = gen(e->right());
  return build.CreateSub(l, r);
}


llvm::Value*
Generator::gen(Mul_expr const* e)
{
  llvm::Value* l = gen(e->left());
  llvm::Value* r = gen(e->right());
  return build.CreateMul(l, r);
}


llvm::Value*
Generator::gen(Div_expr const* e)
{
  llvm::Value* l = gen(e->left());
  llvm::Value* r = gen(e->right());
  return build.CreateSDiv(l, r);
}


// FIXME: decide on unsigned or signed remainder
// based on types of expressions
llvm::Value*
Generator::gen(Rem_expr const* e)
{
  llvm::Value* l = gen(e->left());
  llvm::Value* r = gen(e->right());
  return build.CreateURem(l, r);
}


llvm::Value*
Generator::gen(Lshift_expr const* e)
{
  llvm::Value* l = gen(e->left());
  llvm::Value* r = gen(e->right());
  return build.CreateShl(l, r);
}

llvm::Value*
Generator::gen(Rshift_expr const* e)
{
  llvm::Value* l = gen(e->left());
  llvm::Value* r = gen(e->right());
  return build.CreateLShr(l, r);
}


llvm::Value*
Generator::gen(Bitwise_and_expr const* e)
{
  llvm::Value* l = gen(e->left());
  llvm::Value* r = gen(e->right());
  return build.CreateAnd(l, r);
}


llvm::Value*
Generator::gen(Bitwise_or_expr const* e)
{
  llvm::Value* l = gen(e->left());
  llvm::Value* r = gen(e->right());
  return build.CreateOr(l, r);
}


llvm::Value*
Generator::gen(Xor_expr const* e)
{
  llvm::Value* l = gen(e->left());
  llvm::Value* r = gen(e->right());
  return build.CreateXor(l, r);
}


llvm::Value*
Generator::gen(Neg_expr const* e)
{
  llvm::Value* zero = build.getInt32(0);
  llvm::Value* val = gen(e->operand());
  return build.CreateSub(zero, val);
}


llvm::Value*
Generator::gen(Pos_expr const* e)
{
  return gen(e->operand());
}


llvm::Value*
Generator::gen(Eq_expr const* e)
{
  llvm::Value* l = gen(e->left());
  llvm::Value* r = gen(e->right());
  return build.CreateICmpEQ(l, r);
}


llvm::Value*
Generator::gen(Ne_expr const* e)
{
  llvm::Value* l = gen(e->left());
  llvm::Value* r = gen(e->right());
  return build.CreateICmpNE(l, r);
}


llvm::Value*
Generator::gen(Lt_expr const* e)
{
  llvm::Value* l = gen(e->left());
  llvm::Value* r = gen(e->right());
  return build.CreateICmpSLT(l, r);
}


llvm::Value*
Generator::gen(Gt_expr const* e)
{
  llvm::Value* l = gen(e->left());
  llvm::Value* r = gen(e->right());
  return build.CreateICmpSGT(l, r);
}


llvm::Value*
Generator::gen(Le_expr const* e)
{
  llvm::Value* l = gen(e->left());
  llvm::Value* r = gen(e->right());
  return build.CreateICmpSLE(l, r);
}


llvm::Value*
Generator::gen(Ge_expr const* e)
{
  llvm::Value* l = gen(e->left());
  llvm::Value* r = gen(e->right());
  return build.CreateICmpSGE(l, r);
}


llvm::Value*
Generator::gen(And_expr const* e)
{
  llvm::BasicBlock* head_block = build.GetInsertBlock();
  llvm::BasicBlock* tail_block = llvm::BasicBlock::Create(cxt, "", fn, head_block->getNextNode());
  llvm::BasicBlock* then_block = llvm::BasicBlock::Create(cxt, "", fn, tail_block);

  // Generate code for the left operand.
  llvm::Value* left = gen(e->left());
  build.CreateCondBr(left, then_block, tail_block);
  build.SetInsertPoint(then_block);

  // Generate code for the right operand.
  llvm::Value* right = gen(e->right());
  build.CreateBr(tail_block);
  build.SetInsertPoint(tail_block);

  llvm::PHINode* phi_inst = build.CreatePHI(build.getInt1Ty(), 2);
  phi_inst->addIncoming(build.getFalse(), head_block);
  phi_inst->addIncoming(right, then_block);
  return phi_inst;
}


llvm::Value*
Generator::gen(Or_expr const* e)
{
  llvm::BasicBlock* head_block = build.GetInsertBlock();
  llvm::BasicBlock* tail_block = llvm::BasicBlock::Create(cxt, "", fn, head_block->getNextNode());
  llvm::BasicBlock* then_block = llvm::BasicBlock::Create(cxt, "", fn, tail_block);

  // Generate code for the left operand.
  llvm::Value* left = gen(e->left());
  build.CreateCondBr(left, tail_block, then_block);
  build.SetInsertPoint(then_block);

  // Generate code for the right operand.
  llvm::Value* right = gen(e->right());
  build.CreateBr(tail_block);
  build.SetInsertPoint(tail_block);

  llvm::PHINode* phi_inst = build.CreatePHI(build.getInt1Ty(), 2);
  phi_inst->addIncoming(build.getTrue(), head_block);
  phi_inst->addIncoming(right, then_block);
  return phi_inst;
}


// Logical not is a simple XOR with the value true
// 1 xor 1 = 0
// 0 xor 1 = 1
llvm::Value*
Generator::gen(Not_expr const* e)
{
  llvm::Value* one = build.getTrue();
  llvm::Value* operand = gen(e->operand());
  return build.CreateXor(one, operand);
}


// Note that method calls have been explicitly
// rewritten to free function calls.
llvm::Value*
Generator::gen(Call_expr const* e)
{
  llvm::Value* fn = gen(e->target());
  std::vector<llvm::Value*> args;
  for (Expr const* a : e->arguments())
    args.push_back(gen(a));
  return build.CreateCall(fn, args);
}


// NOTE: The IR builder will automatically compact
// nested member expressions into a single GEP
// instruction. We don't have to do anything more
// complex than this.
llvm::Value*
Generator::gen(Dot_expr const* e)
{
  lingo_unreachable();
}


llvm::Value*
Generator::gen(Field_expr const* e)
{
  llvm::Value* obj = gen(e->container());

  // Build the GEP index array.
  Field_path const& p = e->path();
  std::vector<llvm::Value*> args(p.size() + 1);
  args[0] = build.getInt32(0);
  std::transform(p.begin(), p.end(), ++args.begin(), [&](int n) {
    return build.getInt32(n);
  });

  return build.CreateGEP(obj, args);
}


// Just generate the base object. This will be used
// as the argument for the method call.
llvm::Value*
Generator::gen(Method_expr const* e)
{
  return gen(e->container());
}


llvm::Value*
Generator::gen(Index_expr const* e)
{
  llvm::Value* arr = gen(e->array());
  llvm::Value* ix = gen(e->index());
  std::vector<llvm::Value*> args {
    build.getInt32(0), // 0th element from base
    ix                 // requested index
  };
  return build.CreateGEP(arr, args);
}


llvm::Value*
Generator::gen(Value_conv const* e)
{
  llvm::Value* v = gen(e->source());
  return build.CreateLoad(v);
}


llvm::Value*
Generator::gen(Block_conv const* e)
{
  // Generate the array value.
  llvm::Value* a = gen(e->source());

  // Decay the array pointer to an array into
  // a pointer to the first object. This effectively
  // returns a pointer to the first object in the
  // array.
  llvm::Value *zero = build.getInt32(0);
  llvm::Value *args[] = { zero, zero };
  return build.CreateInBoundsGEP(a, args);
}


llvm::Value*
Generator::gen(Promotion_conv const* e)
{
  llvm::Type* t = get_type(e->target());
  llvm::Value* v = gen(e->source());
  return build.CreateZExt(v, t);
}


// NOTE: For integer literals, llvm's IR builder optimizes
// out this instruction.
llvm::Value*
Generator::gen(Demotion_conv const* e)
{
  llvm::Type* t = get_type(e->target());
  llvm::Value* v = gen(e->source());
  return build.CreateTrunc(v, t);
}


// NOTE: LLVM doesn't distinguish between signed and unsigned integers.
// Only operations care about the sign.
//
// TODO: Do we need to do anything else with this?
llvm::Value*
Generator::gen(Sign_conv const* e)
{
  Integer_type const* int_t = as<Integer_type>(e->target());
  llvm::Type* t = get_type(e->target());
  llvm::Value* v = gen(e->source());
  return build.CreateIntCast(v, t, int_t->is_signed());
}


// TODO: Return the value or store it?
llvm::Value*
Generator::gen(Default_init const* e)
{
  Type const* t = e->type();
  llvm::Type* type = get_type(t);

  // Scalar types should get a 0 value in the
  // appropriate type.
  if (is_scalar(t))
    return llvm::ConstantInt::get(type, 0);

  // Aggregate types are zero initialized.
  //
  // NOTE: This isn't actually correct. Aggregate types
  // should be memberwise default initialized.
  if (is_aggregate(t))
    return llvm::ConstantAggregateZero::get(type);

  throw std::runtime_error("unhahndled default initializer");
}


// TODO: Return the value or store it?
llvm::Value*
Generator::gen(Copy_init const* e)
{
  return gen(e->value());
}


llvm::Value*
Generator::gen(Field_name_expr const* e)
{
  throw std::runtime_error("not implemented");
}


llvm::Value*
Generator::gen(Reference_init const* e)
{
  return gen(e->object());
}


// Reinterpret cast
llvm::Value*
Generator::gen(Reinterpret_cast const* e)
{
  // do a bitcast from expression type to pointer to cast type
  // and put it in a variable
  llvm::Value* val = gen(e->expression());
  llvm::Type* t = get_type(get_reference_type(e->cast_type()));
  llvm::Value* bc = build.CreateBitCast(val, t);
  // load from that variable into a variable of cast type
  return build.CreateLoad(bc);
}


// Void cast causes an value to be bitcast into i8*.
llvm::Value*
Generator::gen(Void_cast const* e)
{
  llvm::Value* val = gen(e->expression());
  // Create a bit cast from whatever to i8*.
  llvm::Type* t = get_type(get_character_type()->ref());
  return build.CreateBitCast(val, t);
}


llvm::Value*
Generator::gen(Get_port const* e)
{
  // generate the call
  llvm::Value* fn = gen(e->target());
  std::vector<llvm::Value*> args;
  for (Expr const* a : e->arguments()) {
    auto arg = gen(a);
    args.push_back(arg);
  }
  llvm::Value* res = build.CreateCall(fn, args);

  // generate the store of the result directly into
  // the global variable
  assert(e->port_);
  auto const* bind = stack.lookup(e->port_);
  llvm::Value* port = bind->second;

  return build.CreateStore(res, port);
}


llvm::Value*
Generator::gen(Create_table const* e)
{
  // generate the call
  llvm::Value* fn = gen(e->target());
  std::vector<llvm::Value*> args;
  for (Expr const* a : e->arguments())
    args.push_back(gen(a));
  llvm::Value* res = build.CreateCall(fn, args);

  assert(e->table_);
  auto const* bind = stack.lookup(e->table_);
  llvm::Value* table = bind->second;

  return build.CreateStore(res, table);
}


llvm::Value*
Generator::gen(Get_dataplane const* e)
{
  assert(e->dataplane());
  auto const* bind = stack.lookup(e->dataplane());
  assert(bind);
  // We have to load the pointer from the parameter variable.
  // There's no way around this.
  llvm::Value* dataplane = build.CreateLoad(bind->second);
  assert(dataplane);

  assert(e->target());
  bind = stack.lookup(e->target());
  assert(bind);
  llvm::Value* target = bind->second;
  assert(target);

  return build.CreateStore(dataplane, target);
}

// -------------------------------------------------------------------------- //
// Code generation for statements
//
// The statement generator is responsible for
// the generation of statements at block scope.

void
Generator::gen(Stmt const* s)
{
  struct Fn
  {
    Generator& g;
    void operator()(Empty_stmt const* s) { g.gen(s); }
    void operator()(Block_stmt const* s) { g.gen(s); }
    void operator()(Assign_stmt const* s) { g.gen(s); }
    void operator()(Return_stmt const* s) { g.gen(s); }
    void operator()(Return_void_stmt const* s) { g.gen(s); }
    void operator()(If_then_stmt const* s) { g.gen(s); }
    void operator()(If_else_stmt const* s) { g.gen(s); }
    void operator()(Match_stmt const* s) { g.gen(s); }
    void operator()(Case_stmt const* s) { g.gen(s); }
    void operator()(While_stmt const* s) { g.gen(s); }
    void operator()(Break_stmt const* s) { g.gen(s); }
    void operator()(Continue_stmt const* s) { g.gen(s); }
    void operator()(Expression_stmt const* s) { g.gen(s); }
    void operator()(Declaration_stmt const* s) { g.gen(s); }
    void operator()(Decode_stmt const* s) { g.gen(s); }
    void operator()(Goto_stmt const* s) { g.gen(s); }

    void operator()(Action const* s) { lingo_unreachable(); }
    void operator()(Drop const* s) { lingo_unreachable(); }
    void operator()(Output const* s) { lingo_unreachable(); }
    void operator()(Flood const* s) { lingo_unreachable(); }
    void operator()(Clear const* s) { lingo_unreachable(); }
    void operator()(Set_field const* s) { lingo_unreachable(); }
    void operator()(Insert_flow const* s) { lingo_unreachable(); }
    void operator()(Remove_flow const* s) { lingo_unreachable(); }
    void operator()(Write_drop const* s) { lingo_unreachable(); }
    void operator()(Write_output const* s) { lingo_unreachable(); }
    void operator()(Write_flood const* s) { lingo_unreachable(); }
    void operator()(Write_set_field const* s) { lingo_unreachable(); }
  };
  apply(s, Fn{*this});
}


void
Generator::gen(Empty_stmt const* s)
{
  // Do nothing.
}


// Generate code for a sequence of statements.
// Note that this does not correspond to a basic
// block since we don't need any terminators
// in the following program.
//
//    {
//      { ; }
//    }
//
// We only need new blocks for specific control
// flow concepts.
void
Generator::gen(Block_stmt const* s)
{
  for (Stmt const* s1 : s->statements())
    gen(s1);
}


void
Generator::gen(Assign_stmt const* s)
{
  llvm::Value* lhs = gen(s->object());
  llvm::Value* rhs = gen(s->value());
  build.CreateStore(rhs, lhs);
}


void
Generator::gen(Return_stmt const* s)
{
  llvm::BasicBlock* curr = build.GetInsertBlock();
  // Only create a branch if the current block has no terminator.
  if (!curr->getTerminator()) {
    llvm::Value* v = gen(s->value());
    build.CreateStore(v, ret);
    build.CreateBr(exit);
  }
}


// The exit block will have the ret void statement made
// if the function returns void so we shouldn't have to deal
// with that here. We should only need to branch to exit block.
void
Generator::gen(Return_void_stmt const* s)
{
  llvm::BasicBlock* curr = build.GetInsertBlock();

  // Only create a branch if the current block has no terminator.
  if (!curr->getTerminator()) {
    build.CreateBr(exit);
    return;
  }
}


void
Generator::gen(If_then_stmt const* s)
{
  llvm::Value* cond = gen(s->condition());

  llvm::BasicBlock* then = llvm::BasicBlock::Create(cxt, "if.then", fn);
  llvm::BasicBlock* done = llvm::BasicBlock::Create(cxt, "if.done", fn);
  build.CreateCondBr(cond, then, done);

  // Emit the 'then' block
  build.SetInsertPoint(then);
  gen(s->body());
  then = build.GetInsertBlock();
  if (!then->getTerminator())
    build.CreateBr(done);

  // Emit the merge point.
  build.SetInsertPoint(done);
}


void
Generator::gen(If_else_stmt const* s)
{
  llvm::Value* cond = gen(s->condition());

  llvm::BasicBlock* then = llvm::BasicBlock::Create(cxt, "if.then", fn);
  llvm::BasicBlock* other = llvm::BasicBlock::Create(cxt, "if.else", fn);
  llvm::BasicBlock* done = llvm::BasicBlock::Create(cxt, "if.done", fn);
  build.CreateCondBr(cond, then, other);

  // Emit the then block.
  build.SetInsertPoint(then);
  gen(s->true_branch());
  then = build.GetInsertBlock();
  if (!then->getTerminator())
    build.CreateBr(done);

  // Emit the else block.
  build.SetInsertPoint(other);
  gen(s->false_branch());
  other = build.GetInsertBlock();
  if (!other->getTerminator())
    build.CreateBr(done);

  // Emit the done block.
  build.SetInsertPoint(done);
}


void
Generator::gen(While_stmt const* s)
{
  // Save the current loop information, to be restored
  // on scope exit.
  Loop_sentinel loop(*this);

  // Create the new loop blocks.
  top = llvm::BasicBlock::Create(cxt, "while.top", fn);
  bottom = llvm::BasicBlock::Create(cxt, "while.bottom", fn);
  llvm::BasicBlock* body = llvm::BasicBlock::Create(cxt, "while.body", fn, bottom);
  build.CreateBr(top);

  // Emit the condition test.
  build.SetInsertPoint(top);
  llvm::Value* cond = gen(s->condition());
  build.CreateCondBr(cond, body, bottom);

  // Emit the loop body.
  build.SetInsertPoint(body);
  gen(s->body());
  body = build.GetInsertBlock();
  if (!body->getTerminator())
    build.CreateBr(top);

  // Emit the bottom block.
  build.SetInsertPoint(bottom);
}


// Branch to the bottom of the current loop.
void
Generator::gen(Break_stmt const* s)
{
  build.CreateBr(bottom);
}


// Branch to the top of the current loop.
void
Generator::gen(Continue_stmt const* s)
{
  build.CreateBr(top);
}


void
Generator::gen(Expression_stmt const* s)
{
  gen(s->expression());
}


void
Generator::gen(Declaration_stmt const* s)
{
  gen(s->declaration());
}


void
Generator::gen(Decode_stmt const* s)
{
  throw std::runtime_error("not implemented");
}


void
Generator::gen(Goto_stmt const* s)
{
  throw std::runtime_error("not implemented");
}


void
Generator::gen(Match_stmt const* s)
{
  // create the value you want to switch on
  llvm::Value* cond = gen(s->condition());

  // Block for each case
  std::vector<llvm::BasicBlock> cases;
  // block to merge back into
  llvm::BasicBlock* done = llvm::BasicBlock::Create(cxt, "switch.done", fn);
  llvm::SwitchInst* switch_ = build.CreateSwitch(cond, done);

  for (auto stmt : s->cases()) {
    assert(is<Case_stmt>(stmt));
    Case_stmt* c = as<Case_stmt>(stmt);

    llvm::BasicBlock* c1 = llvm::BasicBlock::Create(cxt, "switch.c", fn);
    build.SetInsertPoint(c1);
    gen(c->stmt());
    // if the case has no terminator then make a branch to switch.done
    if (!c1->getTerminator())
      build.CreateBr(done);

    llvm::Value* label = gen(c->label());
    assert(is<llvm::ConstantInt>(label));
    switch_->addCase(as<llvm::ConstantInt>(label), c1);
  }

  // generate the merging block
  build.SetInsertPoint(done);

  // handle the default case
  if (s->has_miss()) {
    gen(s->miss());
  }
}


void
Generator::gen(Case_stmt const* s)
{
  lingo_unreachable();
}


// -------------------------------------------------------------------------- //
// Code generation for declarations
//
// TODO: We can't generate all of the code for a module
// in a single pass. We probably need to break this up
// into a number of smaller declaration generators. For
// example, generators that:
//
//    - produce declarations
//    - produce global initializers
//    - produce global destructors
//    - other stuff
//
// In, it might not be worthwhile to have a number
// of sub-generators that refer to the top-level
// generator.

void
Generator::gen(Decl const* d)
{
  struct Fn
  {
    Generator& g;
    void operator()(Variable_decl const* d) { return g.gen(d); }
    void operator()(Function_decl const* d) { return g.gen(d); }
    void operator()(Parameter_decl const* d) { return g.gen(d); }
    void operator()(Record_decl const* d) { return g.gen(d); }
    void operator()(Field_decl const* d) { return g.gen(d); }
    void operator()(Method_decl const* d) { return g.gen(d); }
    void operator()(Module_decl const* d) { return g.gen(d); }

    void operator()(Layout_decl const* d) { return g.gen(d); }
    void operator()(Decode_decl const* d) { return g.gen(d); }
    void operator()(Table_decl const* d) { return g.gen(d); }
    void operator()(Key_decl const* d) { return g.gen(d); }
    void operator()(Flow_decl const* d) { return g.gen(d); }
    void operator()(Port_decl const* d) { return g.gen(d); }
    void operator()(Extracts_decl const* d) { return g.gen(d); }
    void operator()(Rebind_decl const* d) { return g.gen(d); }
  };
  return apply(d, Fn{*this});
}


void
Generator::gen_local(Variable_decl const* d)
{
  // Create the alloca instruction at the beginning of
  // the function. Not at the point where we get it.
  llvm::BasicBlock& b = fn->getEntryBlock();
  llvm::IRBuilder<> tmp(&b, b.begin());
  llvm::Type* type = get_type(d->type());
  String name = d->name()->spelling();
  llvm::Value* ptr = tmp.CreateAlloca(type, nullptr, name);

  // Save the decl binding.
  stack.top().bind(d, ptr);

  // Generate the initializer.
  llvm::Value* init = gen(d->init());

  // Store the result in the object.
  build.CreateStore(init, ptr);
}


void
Generator::gen_global(Variable_decl const* d)
{
  String      name = get_name(d);
  llvm::Type* type = get_type(d->type());

  // Try to generate a constant initializer.
  //
  // FIXME: If the initializer can be reduced to a value,
  // then generate that constant. If not, we need dynamic
  // initialization of global variables.
  llvm::Constant* init = nullptr;
  if (!d->is_foreign())
    init = llvm::Constant::getNullValue(type);


  // Note that the aggregate 0 only applies to aggregate
  // types. We can't apply it to initializers for scalars.

  // Build the global variable, automatically adding
  // it to the module.
  llvm::GlobalVariable* var = new llvm::GlobalVariable(
    *mod,                                  // owning module
    type,                                  // type
    false,                                 // is constant
    llvm::GlobalVariable::ExternalLinkage, // linkage,
    init,                                  // initializer
    name                                   // name
  );

  // Create a rebinding for the new variable.
  // NOTE: The first pass of global name declarations
  // should already guarantee this binding existed.
  stack.top().rebind(d, var);
}


// Generate code for a variable declaration. Note that
// code generation depends heavily on context. Globals
// and locals are very different.
//
// TODO: If we add class/record types, then we also
// need to handle member variables as well. Maybe.
void
Generator::gen(Variable_decl const* d)
{
  if (is_global_variable(d))
    return gen_global(d);
  else
    return gen_local(d);
}


void
Generator::gen(Function_decl const* d)
{
  // If it was a declaration only it should
  // have been captured by the first pass and no further
  // generation is necessary.
  if (d->is_foreign())
    return;

  // If the function has external linkage, do not mangle the name.
  String name;
  if (d->is_extern())
    name = d->name()->spelling();
  else
    name = get_name(d);


  llvm::Type* type = get_type(d->type());

  // Build the function.
  llvm::FunctionType* ftype = llvm::cast<llvm::FunctionType>(type);
  fn = llvm::Function::Create(
    ftype,                           // function type
    llvm::Function::ExternalLinkage, // linkage
    name,                            // name
    mod);                            // owning module

  // Create a new binding for the variable.
  // If it already exists rebind it.
  if (stack.lookup(d))
    stack.top().rebind(d, fn);
  else
    stack.top().bind(d, fn);

  // If the declaration is not defined, then don't
  // do any of this stuff...
  if (!d->body())
    return;

  // Establish a new binding environment for declarations
  // related to this function.
  Symbol_sentinel scope(*this);

  // Build the argument list. Note that
  {
    auto ai = fn->arg_begin();
    auto pi = d->parameters().begin();
    while (ai != fn->arg_end()) {
      Decl const* p = *pi;
      llvm::Argument* a = &*ai;
      a->setName(p->name()->spelling());

      // Create an initial name binding for the function
      // parameter. Note that we're going to overwrite
      // this when we create locals for each parameter.
      stack.top().bind(p, a);

      ++ai;
      ++pi;
    }
  }

  // Build the entry and exit blocks for the function.
  entry = llvm::BasicBlock::Create(cxt, "entry", fn);
  exit = llvm::BasicBlock::Create(cxt, "exit");
  build.SetInsertPoint(entry);

  // Build the return value. If its a function type don't do this.
  if (!fn->getReturnType()->isVoidTy())
    ret = build.CreateAlloca(fn->getReturnType());

  // Generate a local variable for each of the variables.
  for (Decl const* p : d->parameters())
    gen(p);
  gen(d->body());
  entry = build.GetInsertBlock();
  if (!entry->getTerminator())
    build.CreateBr(exit);

  // Insert the exit block and generate the actual
  // return statement,
  fn->getBasicBlockList().push_back(exit);
  build.SetInsertPoint(exit);

  if (fn->getReturnType()->isVoidTy())
    build.CreateRetVoid();
  else
    build.CreateRet(build.CreateLoad(ret));

  // Reset stateful info.
  ret = nullptr;
  fn = nullptr;
}




void
Generator::gen(Parameter_decl const* d)
{
  llvm::Type* t = get_type(d->type());
  llvm::Value* a = stack.top().get(d).second;
  llvm::Value* v = build.CreateAlloca(t);
  stack.top().rebind(d, v);
  build.CreateStore(a, v);
}


// Generate a new struct type.
void
Generator::gen(Record_decl const* d)
{
  // If we've already created a type, don't do
  // anything else.
  if (types.lookup(d))
    return;

  std::vector<llvm::Type*> ts;
  ts.reserve(16);

  // If d is the root of a polymorphic type hierarchy,
  // then generate a vptr as its first sub-object. This is
  // represented as an i8* since we haven't generated the
  // the table yet.
  if (Decl const* vr = d->vref())
    ts.push_back(get_type(vr->type()));

  // Add the base class sub-object before fields.
  //
  // TODO: Implement the empty base optimization.
  if (Type const* b = d->base())
    ts.push_back(get_type(b));

  // Construct the type over only the fields. If the record
  // is empty, generate a struct with exactly one  byte so that
  // we never have a type with 0 size.
  if (d->is_empty()) {
    ts.push_back(build.getInt8Ty());
  } else {
    for (Decl const* f : d->fields())
      ts.push_back(get_type(f->type()));
  }

  // This will automatically be added to the module,
  // but if it's not used, then it won't be generated.
  llvm::Type* t = llvm::StructType::create(cxt, ts, d->name()->spelling());
  types.bind(d, t);

  // Now, generate code for all other members.
  for (Decl const* m : d->members())
    gen(m);

  // Finally, generate the vtable.
  if (d->is_polymorphic())
    gen_vtable(d);
}


void
Generator::gen(Field_decl const* d)
{
  // NOTE: We should never actually get here.
  lingo_unreachable();
}



// Just call out to the function generator. Name
// mangling is handled in get_name().
void
Generator::gen(Method_decl const* d)
{
  gen(cast<Function_decl>(d));
}


void
Generator::gen(Module_decl const* d)
{
  // Establish the global binding environment.
  Symbol_sentinel scope(*this);

  // Initialize the module.
  //
  // TODO: Make the output name the ".ll" version of the
  // the input name. Although this might also depend on
  // whether we're generating IR or object code?
  assert(!mod);
  mod = new llvm::Module("a.ll", cxt);

  // Support for 2 phase generation
  // Declare all global declarations first
  for (Decl const* d1 : d->declarations()) {
    declare_global(d1);
  }

  // Generate all top-level declarations.
  for (Decl const* d1 : d->declarations()) {
    gen(d1);
  }

  // TODO: Make a second pass to generate global
  // constructors for initializers.
}


// ------------------------------------------------------------- //
//          Network specific declarations


// Note: We should never actually get here
void
Generator::gen(Layout_decl const* d)
{
  throw std::runtime_error("unreachable layout");
}


// TODO: implement me
void
Generator::gen(Decode_decl const* d)
{
  throw std::runtime_error("unreachable decode");
}


// TODO: implement me
void
Generator::gen(Table_decl const* d)
{
  throw std::runtime_error("unreachable table");
}


// TODO: implement me
void
Generator::gen(Key_decl const* d)
{
  throw std::runtime_error("unreachable key");
}


// TODO: implement me
void
Generator::gen(Flow_decl const* d)
{
  throw std::runtime_error("unreachable flow");
}


// TODO: implement me
void
Generator::gen(Port_decl const* d)
{
  throw std::runtime_error("unreachable port");
}


// TODO: implement me
void
Generator::gen(Extracts_decl const* d)
{
  throw std::runtime_error("unreachable extracts");
}


// TODO: implement me
void
Generator::gen(Rebind_decl const* d)
{
  throw std::runtime_error("unreachable rebind");
}


void
Generator::gen_vtable(Record_decl const* d)
{
  Decl_seq const& vtbl = *d->vtable();

  // Build the vtable type.
  //
  // TODO: The type is unnamed. Does this actually matter?
  //
  // FIXME: Appropriately mangle the vtable name.
  std::vector<llvm::Type*> types;
  std::vector<llvm::Constant*> values;
  for (Decl const* d : vtbl) {
    // Get the member type.
    llvm::Type* t = llvm::PointerType::getUnqual(get_type(d->type()));
    types.push_back(t);

    // And its initializer.
    llvm::Value* v = stack.lookup(d)->second;
    llvm::Function* f = llvm::cast<llvm::Function>(v);
    values.push_back(f);
  }

  // Build the type and initializer.
  //
  // TODO: The name is terrible.
  String vtn = d->name()->spelling() + "_vtbl";
  llvm::StructType* vtt = llvm::StructType::create(cxt, types);
  llvm::Constant* vti = llvm::ConstantStruct::get(vtt, values);

  // Generate the vtable global.
  new llvm::GlobalVariable(
    *mod,                                  // owning module
    vtt,                                   // type
    true,                                 // is constant
    llvm::GlobalVariable::ExternalLinkage, // linkage,
    vti,                                   // initializer
    vtn                                    // name
  );
}


llvm::Module*
Generator::operator()(Decl const* d)
{
  assert(is<Module_decl>(d));
  gen(d);
  return mod;
}

namespace
{

struct Declare_globals
{
  Generator& g;

  // Catch all unreachable
  template<typename T>
  void operator()(T const* d) { lingo_unreachable(); }

  void operator()(Variable_decl const* d) { return g.declare_global(d); }
  void operator()(Function_decl const* d) { return g.declare_global(d); }
  void operator()(Record_decl const* d) { return g.declare_global(d); }
};

} // namespace

void
Generator::declare_global(Decl const* d)
{
  apply(d, Declare_globals{*this});
}


void
Generator::declare_global(Variable_decl const* d)
{
  String      name = get_name(d);
  llvm::Type* type = get_type(d->type());

  // Try to generate a constant initializer.
  //
  // FIXME: If the initializer can be reduced to a value,
  // then generate that constant. If not, we need dynamic
  // initialization of global variables.
  llvm::Constant* init = nullptr;
  if (!d->is_foreign())
    init = llvm::Constant::getNullValue(type);


  // Note that the aggregate 0 only applies to aggregate
  // types. We can't apply it to initializers for scalars.
  llvm::GlobalVariable* var = new llvm::GlobalVariable(
    type,                                  // type
    false,                                 // is constant
    llvm::GlobalVariable::ExternalLinkage, // linkage,
    init,                                  // initializer
    name                                   // name
  );

  // Create a binding for the new variable.
  stack.top().bind(d, var);
}


void
Generator::declare_global(Function_decl const* d)
{
  // only emit a declaration of the function is marked
  // is_foreign only.
  if (d->is_foreign()) {
    // no mangling
    String name = d->name()->spelling();
    llvm::Type* type = get_type(d->type());

    // Build the function.
    llvm::FunctionType* ftype = llvm::cast<llvm::FunctionType>(type);
    fn = llvm::Function::Create(
      ftype,                           // function type
      llvm::Function::ExternalLinkage, // linkage
      name,                            // name
      mod);                            // owning module

    // Create a new binding for the variable.
    stack.top().bind(d, fn);

    return;
  }

  String name = get_name(d);
  llvm::Type* type = get_type(d->type());

  // Build the function.
  // Do not automatically add it to the module
  // It will be added to the module once we fully generate
  // the code for the function.
  llvm::FunctionType* ftype = llvm::cast<llvm::FunctionType>(type);
  fn = llvm::Function::Create(
    ftype,                           // function type
    llvm::Function::ExternalLinkage, // linkage
    name);                           // name


  // Create a new binding for the variable.
  stack.top().bind(d, fn);

  // reset stateful info
  fn = nullptr;
}


// TODO: implement this
// Since two pass elaboration does not current support
// record declarations anyway, it is not a big deal that this
// is not implemented, however it should be something that should
// be addressed once that happens.
void
Generator::declare_global(Record_decl const* d)
{
}

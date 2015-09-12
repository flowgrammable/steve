#include "builtin.hpp"


namespace steve
{

namespace
{


// empty block
Stmt*
make_empty_block()
{
  Stmt_seq s;
  return make_block_stmt(s);
}


// Used to construct __decode(cxt, decode_func : T)
// Needed since each decode dispatch has a different type
// Using this function instead of casting because dealing with
// casting in codegen seems easier than in steve
struct Match_dispatch_fn
{
  template<typename T>
  Decl const* operator()(T const* t) const { return dispatch(t); }

  // Fail on non-object types.
  template<typename T>
    static typename std::enable_if<!is_object_type<T>(), Decl const*>::type
  dispatch(T const* t)
  {
    lingo_unreachable();
  }

  template<typename T>
    static typename std::enable_if<is_object_type<T>(), Decl const*>::type
  dispatch(T const* t)
  {
    Decl_seq parms =
    {
      make_parameter_decl(get_identifier("cxt"), get_reference_type(get_context_type())),
      make_parameter_decl(get_identifier("table"), get_reference_type(t))
    };
  }
};


// __bind_offset(cxt : ref CXT, env_offset : int, offsetof : int)
// cxt: ref context
// env_offset: offset of the field within the environment
//              determined by walking the program and assignin unique values to extracts
// offset: offset of the field within the context
Function_decl*
bind_offset()
{
  String const* n = get_identifier(__bind_offset);
  Decl_seq parms =
  {
    make_parameter_decl(get_identifier("cxt"), get_reference_type(get_context_type())),
    make_parameter_decl(get_identifier("env_offset"), get_uint_type()),
    make_parameter_decl(get_identifier("offset"), get_uint_type())
  };

  return make_function_decl(n, parms, get_void_type(), make_empty_block());
}


// __bind_header(cxt: ref CXT, header_env : int)
// cxt: context
// offset: offset of the header within the buffer
Function_decl* 
bind_header()
{
  String const* n = get_identifier(__bind_header);
  Decl_seq parms =
  {
    make_parameter_decl(get_identifier("cxt"), get_reference_type(get_context_type())),
    make_parameter_decl(get_identifier("env_offset"), get_uint_type())
  };

  return make_function_decl(n, parms, get_void_type(), make_empty_block());
}


// __advance(cxt: CXT, n : int)
// advances the pointer in the context ahead by n bytes
Function_decl*
advance()
{
  String const* n = get_identifier(__advance);
  Decl_seq parms =
  {
    make_parameter_decl(get_identifier("cxt"), get_reference_type(get_context_type())),
    make_parameter_decl(get_identifier("offset"), get_uint_type())
  };

  return make_function_decl(n, parms, get_void_type(), make_empty_block());
}


// An intrinsic function which returns an object of context type
// In theory this will be part of the lowering process which retrieves
// the context type which gets passed around 
Function_decl*
get_context()
{
  String const* n = get_identifier(__get_context);
  Decl_seq parms;

  return make_function_decl(n, parms, get_context_type(), make_empty_block());
}


// Represent the context type as
// record Context { } for the sake of
// easy member access
Record_type const*
context()
{
  String const* n = get_identifier(__context_type);

  // FIXME: should we be using buffer types here?
  Buffer_type const* pkt_buf = get_buffer_type(get_int_type(), make_int_expr(0));
  Buffer_type const* meta_buf = get_buffer_type(get_int_type(), make_int_expr(0));

  Decl_seq mem {
    make_member_decl(get_identifier("packet"), pkt_buf),
    make_member_decl(get_identifier("metadata"), meta_buf)
  };

  Record_decl const* r = make_record_decl(n, mem); 

  return get_record_type(r);
}


// Builtin functions
std::unordered_multimap<std::string, Function_decl const*> builtin_functions_;


// Builtin record types
std::unordered_multimap<std::string, Record_type const*> builtin_types_;

} // namespace

// Call this function at the beginning to initilize builtins
void 
init_builtins()
{
  std::unordered_multimap<std::string, Record_type const*> 
  builtin_types
  {
    {__context_type, context()},
  };

  builtin_types_ = builtin_types;

  std::unordered_multimap<std::string, Function_decl const*> 
  builtin_func
  {
    {__bind_offset, bind_offset()},
    {__bind_header, bind_header()},
    {__advance, advance()},
    // {__get_context, get_context()}
  };

  builtin_functions_ = builtin_func;
}


std::unordered_multimap<String, Function_decl const*>
builtin_functions()
{
  return builtin_functions_;
}


Function_decl const*
builtin_function(String const n)
{
  auto search = builtin_functions_.find(n);
  if (search != builtin_functions_.end())
    return search->second;

  return nullptr;
}


Record_type const*
builtin_type(String const n)
{
  auto search = builtin_types_.find(n);
  if (search != builtin_types_.end())
    return search->second;
  
  return nullptr;
}


// This function has to be called AFTER the builtins are
// initialized
// Type 't' should be a table
// __match(cxt, table_id)
Function_decl const*
make_match_fn(Type const* t)
{
  lingo_assert(builtin_functions_.size() > 0);

  Match_dispatch_fn mfn;
  Decl const* d = apply(t, mfn);

  return nullptr;
}


} // namespace steve


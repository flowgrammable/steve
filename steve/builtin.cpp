#include "builtin.hpp"
#include "lookup.hpp"


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


// Used to construct __match(cxt, table : Table_type)
// Needed since each table has a different type
struct Match_dispatch_fn
{
  template<typename T>
  Function_decl const* operator()(T const* t) const { return dispatch(t); }

  // Fail on non-object types.
  template<typename T>
    static typename std::enable_if<!is_object_type<T>(), Function_decl const*>::type
  dispatch(T const* t)
  {
    lingo_unreachable();
  }

  template<typename T>
    static typename std::enable_if<is_object_type<T>(), Function_decl const*>::type
  dispatch(T const* t)
  {
    Decl_seq parms =
    {
      make_parameter_decl(get_identifier("_cxt_"), get_reference_type(get_context_type())),
      make_parameter_decl(get_identifier("_table_"), t)
    };

    return make_function_decl(get_identifier(__match), parms, get_void_type(), make_empty_block());
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


// __decode(cxt : CXT, decode_fn : (*)(cxt CXT)) -> void
// the decode dispatching function which dispatches a context
// off to given decoding function
Function_decl*
decode_fn()
{
  String const* n = get_identifier(__decode);

  Type_seq dec_parms {
    get_reference_type(get_context_type())
  };

  Type const* d_fn_t = get_function_type(dec_parms, get_void_type());

  Decl_seq parms =
  {
    make_parameter_decl(get_identifier("_cxt_"), get_reference_type(get_context_type())),
    make_parameter_decl(get_identifier("_decoder_"), d_fn_t)
  };

  return make_function_decl(n, parms, get_void_type(), make_empty_block());
}


// __lookup_hdr(cxt: CXT, n : int) ->int
// Causes a lookup of the last extracted header with the integer binding 'n'
// FIXME: this isnt right. the return type should be the type of the header
// also the syntax needs to change
Function_decl*
lookup_header()
{
  String const* n = get_identifier(__lookup_hdr);
  Decl_seq parms =
  {
    make_parameter_decl(get_identifier("cxt"), get_reference_type(get_context_type())),
    make_parameter_decl(get_identifier("n"), get_uint_type())
  };

  return make_function_decl(n, parms, get_int_type(), make_empty_block());
}


// __lookup_fld(cxt: CXT, n : int) -> int
// Causes a lookup of the last extracted field with the integer binding 'n'
// FIXME: this isnt right
// the return type should be the type of the field
// do we even need this?
Function_decl*
lookup_field()
{
  String const* n = get_identifier(__lookup_fld);
  Decl_seq parms =
  {
    make_parameter_decl(get_identifier("cxt"), get_reference_type(get_context_type())),
    make_parameter_decl(get_identifier("n"), get_uint_type())
  };

  return make_function_decl(n, parms, get_int_type(), make_empty_block());
}


// header_cast() is injected at the beginning of every decode function
// the result is declaring a variable named _header_ 
// and assigning a reinterpret cast of packet
// memory from the context as its value
Function_decl*
header_cast()
{
  String const* n = get_identifier(__header_cast);
  return make_function_decl(n, {}, get_void_type(), make_empty_block());
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
    {__decode, decode_fn()},
    {__header_cast, header_cast()},
    // {__lookup_hdr, lookup_header()},
    // {__lookup_fld, lookup_field()},
  };

  builtin_functions_ = builtin_func;

  for (auto it : builtin_functions_) {
    declare(it.second->name(), it.second);
  }
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
// Type 't' should be a table type
// __match(cxt, table_id : t)
//
// NOTE: This function makes the assumption that it is called
// within global scope or within the same scope that the pipeline
// is being define in
Function_decl const*
make_match_fn(Type const* t)
{
  lingo_assert(builtin_functions_.size() > 0);

  Match_dispatch_fn mfn;
  Function_decl const* d = apply(t, mfn);

  builtin_functions_.insert(std::make_pair(__match, d));

  // declare
  declare(d->name(), d);

  return d;
}


// fetch the correct match function
// with the appropriate table type as the parameter
Function_decl const*
get_match_fn(Type const* t)
{
  auto match_fn = builtin_functions_.equal_range(__match);
  
  for (auto it = match_fn.first; it != match_fn.second; it++) {
    Function_decl const* fn = it->second;
    // look at the second parameter (or at[1] on the 0 scale)
    lingo_assert(fn->parms().size() == 2);
    if (fn->parms().at(1)->type() == t)
      return fn;
  }

  return nullptr;
}




} // namespace steve


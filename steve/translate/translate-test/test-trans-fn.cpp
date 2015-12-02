#include "steve/prelude.hpp"
#include "steve/builder.hpp"
#include "steve/builtin.hpp"
#include "steve/lookup.hpp"
#include "steve/translate/translate.hpp"

using namespace steve;

void
translate_fn()
{
  Decl_seq parms {
    make_parm("n", get_int_type()),
    make_parm("b", get_bool_type())
  };
  Decl const* fn = make_function_decl(get_identifier("fn"), parms, get_void_type(), block({}));
  Decl const* var = make_var("v1", get_int_type(), zero());

  Expr const* c1 = call(fn, {id(var), truth()});

  Stmt_seq body {
    statement(c1),
    make_match_stmt(one(), 
      Stmt_seq {
        make_case(zero(), empty()),
        make_case(one(), empty()) 
      }),
  };

  Decl const* fn2 = make_function_decl(get_identifier("fn2"), parms, get_void_type(), block(body));


  std::cout << tostring(translate(fn));
  std::cout << tostring(translate(fn2));
}


void
translate_fn2()
{
  Decl_seq parms {
    make_parm("cxt", get_reference_type(get_context_type()))
  };

  Expr const* adds = add(one(), two());
  
  Stmt_seq body {
    statement(adds),
    make_match_stmt(one(), 
      Stmt_seq {
        make_case(zero(), empty()),
        make_case(one(), empty()) 
      }),
  };

  Decl const* fn = make_function_decl(get_identifier("fn2"), parms, get_void_type(), block(body));

  std::cout << tostring(translate(fn));
}


int main()
{
  Global_scope global;
  init_builtins();
  // translate_fn();
  translate_fn2();
}
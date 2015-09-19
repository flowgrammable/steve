#include "translate-decl.hpp"

namespace steve
{

struct Decl_translator
{
  std::string operator()(Variable_decl const*) { return ""; }
  std::string operator()(Constant_decl const*) { return ""; }
  std::string operator()(Function_decl const*) { return ""; }
  std::string operator()(Parameter_decl const*) { return ""; }
  std::string operator()(Record_decl const*) { return ""; }
  std::string operator()(Member_decl const*) { return ""; }
  std::string operator()(Variant_decl const*) { return ""; }
  std::string operator()(Enum_decl const*) { return ""; }
  std::string operator()(Decode_decl const*) { return ""; }
  std::string operator()(Table_decl const*) { return ""; }
  std::string operator()(Flow_decl const*) { return ""; }
  std::string operator()(Extracts_decl const*) { return ""; }
  std::string operator()(Rebind_decl const*) { return ""; }
};


std::string
translate(Decl const* s)
{
  Decl_translator decl_fn;
  return apply(s, decl_fn);
}

}

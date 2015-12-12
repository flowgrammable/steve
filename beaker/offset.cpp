#include "beaker/builder.hpp"
#include "beaker/length.hpp"
#include "beaker/offset.hpp"
#include "beaker/decl.hpp"


// Returns an expression which computes the byte offsetof a
// member within a record.
// 'e' is an offsetof expression.
//
// The byte offset of a member within a record type
// is the sum of the length of all fields preceding
// it within the record.
Expr*
get_offset(Decl const* layout, Decl const* mem)
{
  assert(is<Layout_decl>(layout));
  // keep track of all member declarations coming before mem
  Decl_seq pred;

  Expr* offsetof = zero();

  for (auto decl : as<Layout_decl>(layout)->fields()) {
    if (decl == mem) {
      break;
    }

    pred.push_back(decl);
  }

  for (auto decl : pred) {
    offsetof = add(offsetof, get_length(decl->type()));
  }

  return offsetof;
}


// Calcualte the offset of a field
// within a layout using a field name expression.
//
// FIXME: This currently does not handle nested layouts such
// as h1::h2::h3.
// This only works with one layout decl and a field
Expr*
get_offset(Field_name_expr const* e)
{
  // The first element in the field name should always be a
  // layout declaration.
  // This should be a guarantee provided by elaboration.
  Decl_seq const& decls = e->declarations();
  Layout_decl* layout = as<Layout_decl>(decls.front());
  assert(layout);

  // get the second element in the declaration sequence
  // this should be guaranteed to exist
  Expr* offset = get_offset(layout, decls.at(1));

  // create some iterators
  if (decls.size() > 2) {
    auto curr = decls.begin() + 1;
    auto next = decls.begin() + 2;

    // while the next element isn't the end
    while (next != decls.end()) {
      Field_decl* field = as<Field_decl>(*curr);
      assert(field);

      // this has to be a field with layout type
      // it cannot be anything else and this should
      // be a guarantee from elaboration
      Layout_type const* type = as<Layout_type>(field->type());
      assert(type);

      layout = type->declaration();
      assert(layout);

      offset = add(offset, get_offset(layout, *next));

      ++curr;
      ++next;
    }
  }

  return offset;
}

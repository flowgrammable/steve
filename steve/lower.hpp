#ifndef LOWER_HPP
#define LOWER_HPP

#include "steve/builder.hpp"
#include "steve/builtin.hpp"
#include "steve/type.hpp"
#include "steve/expr.hpp"
#include "steve/decl.hpp"
#include "steve/stmt.hpp"

#include "lingo/node.hpp"

namespace steve
{

Stmt_seq lower(Stmt const*);
Expr const* lower(Expr const*);
Decl const* lower(Decl const*);

} // namespace steve

#endif
#ifndef STEVE_TRANSLATE_STMT_HPP
#define STEVE_TRANSLATE_STMT_HPP

#include "translate.hpp"

// Translate a stmt into its string representation

namespace steve
{

cxx::Expr* translate(Stmt const* s);

}


#endif
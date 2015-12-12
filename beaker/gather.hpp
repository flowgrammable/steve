#include "beaker/prelude.hpp"

// This module defines utility for gathering a set of
// statically-sized literal expressions into one integer of fixed size
// which is the gathering of all those literals into one buffer.

Expr* gather(Expr_seq const&);

// Copyright (c) 2015 Flowgrammable.org
// All rights reserved

#include "op.hpp"

namespace steve
{


void 
print(Printer& p, Unary_op op)
{
  switch (op) {
    case num_neg_op: return print(p, '-');
    case num_pos_op: return print(p, '+');
    case bit_not_op: return print(p, '~');
    case log_not_op: return print(p, '!');
  }
  lingo_unreachable("invalid unary operator ({})", (int)op);
}


void 
print(Printer& p, Binary_op op)
{
  switch (op) {
    case num_add_op: return print(p, '+');
    case num_sub_op: return print(p, '-');
    case num_mul_op: return print(p, '*');
    case num_div_op: return print(p, '/');
    case num_mod_op: return print(p, '%');
    case bit_and_op: return print(p, '&');
    case bit_or_op: return print(p, '|');
    case bit_xor_op: return print(p, '^');
    case bit_lsh_op: return print(p, "<<");
    case bit_rsh_op: return print(p, ">>");
    case rel_eq_op: return print(p, "==");
    case rel_ne_op: return print(p, "!=");
    case rel_lt_op: return print(p, "<");
    case rel_gt_op: return print(p, ">");
    case rel_le_op: return print(p, "<=");
    case rel_ge_op: return print(p, ">=");
    case log_and_op: return print(p, "&&");
    case log_or_op: return print(p, "||");
  }
  lingo_unreachable("invalid binary operator ({})", (int)op);
}


void 
debug(Printer& p, Unary_op op)
{
  print(p, op);
}


void 
debug(Printer& p, Binary_op op)
{
  print(p, op);
}


}

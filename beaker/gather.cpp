#include "beaker/expr.hpp"
#include "beaker/type.hpp"
#include "beaker/length.hpp"
#include "beaker/evaluator.hpp"


Expr*
gather(Expr_seq const& subkeys)
{
  // maintain the largest allowable key buffer
  uint512_t buf = 0;

  Evaluator ev;

  // maintain the position to start writing
  int pos = 0;
  for (auto subkey : subkeys) {
    // get the precision of the subkey
    int prec = precision(subkey->type());
    Value const& val = ev.eval(subkey);
    // FIXME: for now we're only dealing with unsigned integer values
    assert(val.is_integer());
    std::stringstream ss;
    ss << val.get_integer().decimal_str();
    uint512_t i = 0;
    ss >> i;
    // shift the integer over by the amount already written
    i = i << pos;
    // add the length of the current integer to the pos
    pos += prec;
    // log-and the integer into the buffer
    buf |= i;
  }

  char* bytes = new char[pos / 8];
  char* key = reinterpret_cast<char*>(&buf);
  std::copy(key, key + (pos / 8), bytes);

  Array_value arr { bytes, (size_t) pos / 8 };
  Type const* z = get_integer_type();
  Expr* n = new Literal_expr(z, arr.len + 1);
  // Create the array type.
  Type const* c = get_character_type();
  Type const* t = get_array_type(c, n);

  return new Literal_expr(t, arr);
}

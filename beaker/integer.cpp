// Copyright (c) 2015 Andrew Sutton
// All rights reserved

#include "lingo/debug.hpp"
#include "integer.hpp"

#include <memory>

// Construct an integer with the value in s in base b. Behavior is
// undefined if s does not represent an integer in base b.
Integer::Integer(std::string const& s, int b)
  : base_(b)
{
  if (mpz_init_set_str(value_, s.c_str(), base_) == -1)
    assert(false);
}


namespace
{

// Returns the size of a buffer needed to store the textual
// representation of a formatted string.
inline std::size_t
get_buffer_size(const mpz_t& z, int b) {
  // Add 1 for a null terminator, 1 for a negative sign,
  // and room for prefix characters.
  std::size_t r = mpz_sizeinbase(z, b) + 2;
  if (b != 10)
    return r + 2;
  else
    return r;
}

} // namespace


// Streaming
std::ostream&
operator<<(std::ostream& os, const Integer& z)
{
  int  base = z.base();
  std::size_t n = get_buffer_size(z.data(), base);
  std::unique_ptr<char[]> buf(new char[n]);
  switch (base) {
  case 2:
    gmp_snprintf(buf.get(), n + 2, "0b%Zd", z.data());
    break;
  case 8:
    gmp_snprintf(buf.get(), n + 1, "0o%Zo", z.data());
    break;
  case 10:
    gmp_snprintf(buf.get(), n, "%Zd", z.data());
    break;
  case 16:
    gmp_snprintf(buf.get(), n + 2, "0x%Zx", z.data());
    break;
  }
  return os << buf.get();
}


// Decimal string representation of underlying data
std::string
Integer::decimal_str()
{
  int base = 10;
  std::size_t n = get_buffer_size(data(), base);
  std::unique_ptr<char[]> buf(new char[n]);
  std::string dec_str = mpz_get_str(buf.get(), base, data());
  return dec_str;
}


#ifndef INTEGER_HPP
#define INTEGER_HPP

#include <gmp.h>

#include "string.hpp"
#include "debug.hpp"

// The Integer class represents arbitrary integer values.
class Integer {
public:
  // Default constructor
  //
  // FIXME: Make a default constructor that takes a width specification.
  Integer();

  // Copy semantics
  Integer(const Integer&);
  Integer& operator=(const Integer&);

  // Value initialization.
  Integer(long, int = 10);
  Integer(String, int = 10);

  // Destructor
  ~Integer();

  // Arithmetic compound assignmnt operators.
  Integer& operator+=(const Integer&);
  Integer& operator-=(const Integer&);
  Integer& operator*=(const Integer&);
  Integer& operator/=(const Integer&);
  Integer& operator%=(const Integer&);

  Integer& operator<<=(const Integer&);
  Integer& operator>>=(const Integer&);

  Integer& neg();
  Integer& abs();

  // Observers
  int sign() const;
  bool is_positive() const;
  bool is_negative() const;
  bool is_nonpositive() const;
  bool is_nonnegative() const;


  int bits() const;
  int base() const;
  std::uintmax_t getu() const;
  std::intmax_t gets() const;
  const mpz_t& data() const;

private:
  mpz_t value_;
  int   base_;
};

// Equality
bool operator==(const Integer&, const Integer&);
bool operator!=(const Integer&, const Integer&);

// Ordering
bool operator<(const Integer&, const Integer&);
bool operator>(const Integer&, const Integer&);
bool operator<=(const Integer&, const Integer&);
bool operator>=(const Integer&, const Integer&);

// Arithmetic
Integer operator+(const Integer&, const Integer&);
Integer operator-(const Integer&, const Integer&);
Integer operator*(const Integer&, const Integer&);
Integer operator/(const Integer&, const Integer&);
Integer operator%(const Integer&, const Integer&);
Integer operator-(const Integer&);
Integer operator+(const Integer&);

Integer operator<<(const Integer&, const Integer&);
Integer operator>>(const Integer&, const Integer&);

// Streaming
std::ostream& operator<<(std::ostream&, const Integer&);

#include "integer.ipp"

#endif

#include <cctype>
#include <algorithm>
#include <unordered_set>

#include "string.hpp"


namespace cxx
{

template<typename I>
inline
String::String(I first, I last)
  : String(std::string(first, last)) { }

/// Returns true if the string is non-null.
inline 
String::operator bool() const { return str_; }

/// Returns the number of characters in the string.
inline std::size_t 
String::size() const { return str_->size(); }

/// Returns the underlying string pointer.
inline const std::string* 
String::ptr() const { return str_; }

/// Returns a reference to the underlying string.
inline const std::string& 
String::str() const { return *str_; }

/// Returns a pointer to the underlying character data.
inline const char* 
String::data() const { return str().c_str(); }

// Iterators
inline String::iterator 
String::begin() { return str_->begin(); }

inline String::iterator 
String::end() { return str_->end(); }

inline String::const_iterator
String::begin() const { return str_->begin(); }

inline String::const_iterator 
String::end() const { return str_->end(); }

// Convert a string to lowercase.
String
to_lower(String s) {
  std::string r(s.size(), 0);
  std::transform(s.begin(), s.end(), r.begin(), tolower);
  return r;
}

String
to_upper(String s) {
  std::string r(s.size(), 0);
  std::transform(s.begin(), s.end(), r.begin(), toupper);
  return r;
}

} // namespace cxx

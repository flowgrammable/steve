
#include "type.hpp"

namespace cxx
{

// FIXME: Implement check for declared but not defined classes.
bool
is_incomplete_object_type(Type* t) {
  return is<Incomplete_array_type>(t);
}

bool
is_incomplete_type(Type* t) {
  return is_incomplete_object_type(t) or is<Void_type>(t);
}

} // namespace cxx

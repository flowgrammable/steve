#include "table.hpp"

namespace fp
{

// Initialize the first len bytes of the key with those
// in the given buffer, and zero-fill the remainder.
Key::Key(Byte const* buf, int len)
{
  std::fill(std::copy(buf, buf + len, data), data + key_size, 0);
}


// Returns a reference to a flow. If no flow matches the
// key, the table-miss flow is returned.
inline Flow
Hash_table::search(Key const& k)
{
  auto iter = find(k);
  if (iter == end())
    return miss_;
  else
    return iter->second;
}


// Returns a reference to a flow. If no flow matches the
// key, the table-miss flow is returned.
// inline Flow const&
// Hash_table::search(Key const& k) const
// {
//   auto iter = find(k);
//   if (iter == end())
//     return miss_;
//   else
//     return iter->second;
// }

// (Openflow standard)
// If a flow entry with identical match fields and priority already resides in
// the requested table, then that entry, including its duration,
// must be cleared from the table, and the new flow entry added.
inline void
Hash_table::add(Key const& k, Flow const& f)
{
  auto iter = find(k);
  // If the entry doesn't exist in the table already.
  if (iter == end())
    insert({k, f});
  // If it does exist, erase the existing one and add the new one.
  else {
    erase(k);
    insert({k, f});
  }
}


// If no such entry exists, no action is taken.
inline void
Hash_table::rmv(Key const& k)
{
  erase(k);
}


// Resets the miss case to default.
inline void
Hash_table::rmv_miss()
{
  miss_ = Flow();
}

} // namespace fp

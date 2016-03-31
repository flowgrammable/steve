#include "port_table.hpp"
#include "port.hpp"

#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

namespace fp
{

// Port table definitions.
//
// Default port table constructor.
Port_table::Port_table()
  : Port_table(100)
{ }


// Port table constructor with initial size.
Port_table::Port_table(int size)
  : data_(size, nullptr)
{
}


// Port table destructor.
Port_table::~Port_table()
{
  data_.clear();
}


// Allocates a new internal ID for a port to use.
auto
Port_table::alloc(Port::Type port_type, std::string const& args, std::string const& name) -> value_type
{
  // Find an open slot and calculate its index.
  auto iter = std::find(data_.begin(), data_.end(), nullptr);
  Port::Id idx = std::distance(data_.begin(), iter);

  // Allocate the proper port type.
  switch (port_type)
  {
    case Port::Type::udp:
      data_[idx] = (value_type)new Port_udp(idx+1, args, name);
    break;
    case Port::Type::tcp:
      data_[idx] = (value_type)new Port_tcp(idx+1, args, name);
    break;
  }

  // Return a pointer to the newly allocated port object.
  return data_[idx];
}


// Deallocates the internal port ID given.
void
Port_table::dealloc(Port::Id id)
{
  if (data_[id-1])
    delete data_[id-1];
  data_[id-1] = nullptr;
}


// Accessors.
//

// Returns the port that matches the given 'id'. If not found,
// returns a nullptr.
auto
Port_table::find(Port::Id id) -> value_type
{
  if (data_[id-1])
    return data_[id-1];
  else
    return nullptr;
}


// Returns the port with the matching 'name'. If not found,
// returns a nullptr.
auto
Port_table::find(std::string const& name) -> value_type
{
  auto fn = [&name](Port* p)
  {
    if(p)
      return p->name_ == name;
    return false;
  };

  std::cout << "FINDING\n";
  auto res = std::find_if(data_.begin(), data_.end(), fn);
  std::cout << "FOUND\n";

  if (res == data_.end())
    return nullptr;
  else
    return *res;
}


auto
Port_table::list() -> store_type
{
  return data_;
}


} // end namespace fp

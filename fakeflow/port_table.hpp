#ifndef FP_PORT_TABLE_HPP
#define FP_PORT_TABLE_HPP

#include "port.hpp"
#include "port_udp.hpp"
#include "port_tcp.hpp"

#include <string>
#include <vector>
#include <climits>

namespace fp
{

// Global port table type.
class Port_table
{
  using store_type = std::vector<Port*>;
  using value_type = Port*;
  using iter_type  = std::vector<Port*>::iterator;
public:

  // Constructors.
  //
  // Default.
  Port_table();
  // Initial size.
  Port_table(int);

  // Destructor.
  ~Port_table();

  // Allocator.
  Port* alloc(Port::Type, std::string const&, std::string const&);
  // Deallocator.
  void  dealloc(Port::Id);

  // Accessors.
  value_type find(Port::Id);
  value_type find(std::string const&);
  store_type list();

private:
  store_type data_;
};

extern Port_table port_table;

} // end namespace fp

#endif

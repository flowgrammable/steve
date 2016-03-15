#ifndef FP_DATAPLANE_HPP
#define FP_DATAPLANE_HPP

#include <list>
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

#include "port.hpp"
#include "application.hpp"
// #include "thread.hpp"

namespace fp
{

extern Module_table module_table;
// extern Thread_pool thread_pool;

struct Table;

struct Dataplane
{
  using Port_list = std::list<Port*>;
  using Port_map  = std::unordered_map<uint32_t, Port*>;

  // Data plane name.
  std::string name_;

  // The set of tables applications can use.
  std::vector<Table*> tables_;

  // Application.
  Application* app_;

  Dataplane(std::string const&, std::string const&);
  ~Dataplane();

  // Resource alloc/dealloc.
  void add_port(Port*);
  void add_drop_port();
  void remove_port(Port*);

  Port* get_port(uint32_t) const;
  Port* get_drop_port() const { return drop_; }

  // Mutators.
  void up();
  void down();
  void configure();
  void process(Port*, Packet*);

  // Accessors.
  Application*        app();
  std::string         name() const;
  std::vector<Table*> tables() const;
  Table*              table(int);

  Port_list ports_;
  Port_map  portmap_;
  Port*     drop_;
};


// Returns the port with the given identifier.
inline Port*
Dataplane::get_port(uint32_t id) const
{
  auto iter = portmap_.find(id);
  if (iter != portmap_.end())
    return iter->second;
  return nullptr;
}

using Dataplane_table = std::unordered_map<std::string, Dataplane*>;

} // namespace

#endif

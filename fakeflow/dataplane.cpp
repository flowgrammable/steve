#include <algorithm>

#include "dataplane.hpp"
#include "context.hpp"
#include "timer.hpp"
#include "system.hpp"

#include <iostream>
#include <cassert>

namespace fp {

extern Module_table module_table;


// Data plane ctor.
Dataplane::Dataplane(std::string const& name, std::string const& app_name)
  : name_(name)
{
  auto app = module_table.find(app_name);
  if (app != module_table.end())
    app_ = app->second;
  else
    throw std::string("Unknown application name '" + app_name + "'");
}

Dataplane::~Dataplane()
{
}


// Adds the port to the local list.
void
Dataplane::add_port(Port* p)
{
	// app_->add_port(p);
}


// Removes the port from the local list if it exists.
void
Dataplane::remove_port(Port* p)
{
	// app_->remove_port(p);
}


// Starts the data plane packet processors. If the application has configured
// the data plane, it will install the application in the thread pool and start
// it. Otherwise it reports errors.
void
Dataplane::up()
{
  // if (!app_)
  //   throw std::string("No applicaiton is installed.");
  // else if (app_->state() == Application::State::READY) {
  //   thread_pool.install(app());
  //   thread_pool.start();
  // }
  // else if (app_->state() == Application::State::NEW)
  //   throw std::string("Data plane has not been configured, unable to start");
}


struct App1
{
  App1(Table* t)
    : table(dynamic_cast<Hash_table*>(t))
  { }

  Hash_table* table;

  inline void
  eth_d(Context* cxt, Port* p)
  {
    fp_bind_header(cxt, 0);
    // fp_output_port(cxt, p);
    fp_goto_table(cxt, table, 1, 0);
  }


  inline void
  pipeline(Context* cxt, Port* p)
  {
    eth_d(cxt, p);
  }
};


struct App2
{
  App2(Table* t)
    : table(dynamic_cast<Hash_table*>(t))
  { }

  Hash_table* table;

  void
  eth_d(Context* cxt, Port* p)
  {
    uint16_t type;
    fp_bind_header(cxt, 0);
    fp_bind_field(cxt, 12, 0, 6);
    fp_bind_field(cxt, 13, 6, 6);
    fp_bind_field(cxt, 14, 12, 2);
    fp::Byte* b = fp_read_field(cxt, 14);
    type = *reinterpret_cast<uint16_t*>(b);
    switch (type) {
      case 800: ipv4_d(cxt, p); break;
    }
  }


  void
  ipv4_d(Context* cxt, Port* p)
  {
    uint8_t protocol = 0;
    fp_bind_header(cxt, 1);
    fp_bind_field(cxt, 4, 4, 1);
    fp_bind_field(cxt, 5, 0, 1);
    fp_bind_field(cxt, 6, 1, 1);
    fp_bind_field(cxt, 7, 6, 2);
    fp_bind_field(cxt, 8, 5, 1);
    fp_bind_field(cxt, 9, 2, 2);
    fp_bind_field(cxt, 10, 8, 4);
    fp_bind_field(cxt, 11, 12, 4);

    fp::Byte* b = fp_read_field(cxt, 8);
    protocol = *reinterpret_cast<uint8_t*>(b);
    switch (protocol) {
      case 0: udp_d(cxt, p); break;
    }
  }


  void
  udp_d(Context* cxt, Port* p)
  {
    fp_bind_header(cxt, 2);
    fp_bind_field(cxt, 0, 0, 2);
    fp_bind_field(cxt, 1, 2, 2);
    fp_bind_field(cxt, 2, 4, 2);
    fp_bind_field(cxt, 3, 6, 2);
    fp_goto_table(cxt, table, 2, 11, 8);
  }


  void
  pipeline(Context* cxt, Port* p)
  {
    eth_d(cxt, p);
  }
};

// For manually passing in packets to the data plane.
void
Dataplane::process(Port* port, Packet* pkt)
{
  // std::cout << "PROCESSING\n";
  Context* c = new Context(pkt, port->id_, port->id_, 0);
  // thread_pool.assign(new Task("pipeline", c));
  // app_->lib().exec("pipeline", c);

  static App1 a(tables_.front());
  a.pipeline(c, port);
  //
  // static App2 b(tables_.front());
  // b.pipeline(c, port);

  // std::cout << "DONE PROCESSING\n";
}


// Stops the data plane packet processors, if they are running.
void
Dataplane::down()
{
 //  if (app_->state() == Application::State::RUNNING) {
 //   thread_pool.stop();
 //   thread_pool.uninstall();
 // }
 // else
 //   throw std::string("Data plane is not running.");
}


// Configures the data plane based on the application.
void
Dataplane::configure()
{
  assert(app_);

  if (app_->state() == Application::State::NEW) {
    std::cout << "RUNNING CONFIG\n";

    app_->lib().exec("config", this);
    app_->state_ = Application::State::READY;
  }
  else
    throw std::string("Data plane has already been configured.");
}


// Gets the data plane name.
std::string
Dataplane::name() const
{
  return name_;
}


// Gets the data planes application.
Application*
Dataplane::app()
{
  return app_;
}


// Gets the data planes tables.
std::vector<Table*>
Dataplane::tables() const
{
  return tables_;
}


// Gets the table at the given index.
Table*
Dataplane::table(int idx)
{
  return tables_.at(idx);
}


} // end namespace fp

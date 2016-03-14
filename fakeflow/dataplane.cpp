#include <algorithm>

#include "dataplane.hpp"
#include "context.hpp"
#include "timer.hpp"
#include "system.hpp"
// #include "fakeapps.hpp"

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



// For manually passing in packets to the data plane.
void
Dataplane::process(Port* port, Packet* pkt)
{
  // std::cout << "PROCESSING\n";
  Context* c = new Context(*pkt, this, port->id(), port->id(), 0);
  // thread_pool.assign(new Task("pipeline", c));
  app_->lib().exec("pipeline", c);

  // static App1 a(tables_.front());
  // a.pipeline(c, port);
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

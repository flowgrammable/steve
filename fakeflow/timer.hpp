#include <boost/timer.hpp>
#include <iostream>

struct Timer
{
  // start clock on begin
  Timer()
    : t()
  { }

  // end clock on dtor
  ~Timer()
  {
    double elapsed_time = t.elapsed();
    std::cout << "TIME: " << elapsed_time << '\n';
  }

  boost::timer t;
};

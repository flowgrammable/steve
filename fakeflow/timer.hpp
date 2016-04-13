#include <boost/timer/timer.hpp>
#include <iostream>
#include <chrono>

// The default clock type is the system clock.
using Clock = std::chrono::high_resolution_clock;

// Durations
using Nanoseconds = std::chrono::nanoseconds;
using Microseconds = std::chrono::microseconds;
using Milliseconds = std::chrono::milliseconds;
using Seconds = std::chrono::seconds;
using Minutes = std::chrono::minutes;
using Hours = std::chrono::hours;

// A duration is a (possibly negative) span of time between
// time points.
using Duration = Clock::duration;

// Floating point durations.
using Fp_seconds = std::chrono::duration<double, Seconds::period>;

struct Timer
{
  // start clock on begin
  Timer()
    : start(Clock::now())
  { }

  // end clock on dtor
  ~Timer()
  {
    std::cout << "TIME: " << elapsed() << '\n';
  }

  // Get current elapsed time.
  double elapsed() const
  {
    Fp_seconds secs = Clock::now() - start;
    return secs.count();
  }

  std::chrono::time_point<std::chrono::high_resolution_clock> start;
};

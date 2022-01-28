#pragma once

#include <ctime>
#include <chrono>

#include "../shared.cpp"

class Timer
{
  double lastLoopAt;

public:
  void init()
  {
    writeLog(__FILE__, __LINE__, "Timer::init\n");
    lastLoopAt = getTime();
  }

  double getTime()
  {
    using namespace std::chrono;
    return duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count() / 1.0e9;
  }

  float elapsed()
  {
    double time = getTime();
    float elapsed = (float)(time - lastLoopAt);
    lastLoopAt = time;
    return elapsed;
  }

  friend std::ostream &operator<<(std::ostream &os, const Timer &timer)
  {
    return os << "Interp{"
              << "lastLoopAt: " << timer.lastLoopAt << "\n"
              << "}";
  }
};
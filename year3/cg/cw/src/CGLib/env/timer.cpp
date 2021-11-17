#pragma once

#include "../contracts/all.cpp"
#include <ctime>
#include <chrono>

class Timer : public Initable
{
  double lastLoopAt;

public:
  void init()
  {
    lastLoopAt = getTime();
  }

  double getTime()
  {
    using namespace std::chrono;
    return duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count() / 1000000000.0;
  }

  float elapsed()
  {
    double time = getTime();
    float elapsed = (float)(time - lastLoopAt);
    lastLoopAt = time;
    return elapsed;
  }
};
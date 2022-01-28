#pragma once

class Throttle
{
private:
  /* data */
  int count;
  int throttle;

public:
  Throttle(int throttle) : count(0), throttle(throttle)
  {
  }

  void operator()(void (*fn)(void))
  {
    count++;
    count %= throttle;
    if (count == 0)
      fn();
  }
};
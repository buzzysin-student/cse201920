#pragma once

class Threadable
{
protected:
  // ? Call when external starting is necessary
  virtual void run() = 0;
};

#pragma once

class Cleanable
{
protected:
  // ? Call when starting operation
  virtual void cleanup() = 0;
};
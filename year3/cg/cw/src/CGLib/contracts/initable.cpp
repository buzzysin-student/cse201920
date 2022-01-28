#pragma once

class WindowInterface;

class Initable
{
protected:
  // ? Call when starting operation
  virtual void init() = 0;

public:
  class WithWrapper
  {
  public:
    virtual void init(WindowInterface &interface) = 0;
  };
};
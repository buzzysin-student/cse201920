#pragma once

class WindowInterface;

class Updatable
{
protected:
  // ? Call when updating something
  virtual void update() = 0;

public:
  class WithWrapper
  {
  public:
    virtual void update(WindowInterface &interface) = 0;
  };
};
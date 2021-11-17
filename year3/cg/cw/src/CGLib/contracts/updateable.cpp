#pragma once

class WindowWrapper;

class Updatable
{
protected:
  // ? Call when updating something
  virtual void update() = 0;

public:
  class WithWrapper
  {
  public:
    virtual void update(WindowWrapper wrapper) = 0;
  };
};
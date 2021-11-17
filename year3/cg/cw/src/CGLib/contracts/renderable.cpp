#pragma once

class WindowWrapper;

class Renderable
{
protected:
  // ? Call when starting operation
  virtual void render() = 0;

public:
  class WithWrapper
  {
  public:
    virtual void render(WindowWrapper wrapper) = 0;
  };
};
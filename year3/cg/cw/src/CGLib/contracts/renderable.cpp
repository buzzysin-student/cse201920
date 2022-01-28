#pragma once

class WindowInterface;

class Renderable
{
protected:
  // ? Call when starting operation
  virtual void render() = 0;

public:
  class WithWrapper
  {
  public:
    virtual void render(WindowInterface &interface) = 0;
  };

  class WithItems
  {
  public:
    virtual void render(WindowInterface &interface, std::vector<Item> item) = 0;
  };
};
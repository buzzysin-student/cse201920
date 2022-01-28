#pragma once

#include "../shared.cpp"
#include "window-interface.cpp"

class Environment
{
public:
  virtual void init(WindowInterface &interface) = 0;
  virtual void update(WindowInterface &interface) = 0;
  virtual void render(WindowInterface &interface) = 0;
  virtual void cleanup() = 0;
};
#pragma once

#include "../shared.cpp"
#include "../contracts/all.cpp"
#include "wrapper.cpp"

class Environment : public Initable::WithWrapper,
                    public Updatable::WithWrapper,
                    public Renderable::WithWrapper,
                    public Cleanable
{
public:
  virtual void init(WindowWrapper window) = 0;
  virtual void update(WindowWrapper window) = 0;
  virtual void render(WindowWrapper window) = 0;
  virtual void cleanup() = 0;
};
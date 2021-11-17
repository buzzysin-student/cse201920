#pragma once

#include "../contracts/all.cpp"
#include "../env/wrapper.cpp"

class Renderer : public Initable::WithWrapper,
                 public Renderable::WithWrapper,
                 public Cleanable
{
public:
  void init(WindowWrapper wrapper)
  {
  }

  void render(WindowWrapper wrapper)
  {
  }

  void cleanup()
  {
  }
};
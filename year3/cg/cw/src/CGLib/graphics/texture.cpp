#pragma once

#include "../contracts/all.cpp"

class Texture : public Initable, public Renderable, public Cleanable
{
  void init() {}
  void render() {}
  void cleanup() {}
};
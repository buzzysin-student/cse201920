#pragma once

#include "../../CGLib/all.cpp"

#include "Basic.cpp"

class TexturedCornellBox : public Basic
{
public:
  TexturedCornellBox() : Basic("textured-cornell-box.obj")
  {
  }
};

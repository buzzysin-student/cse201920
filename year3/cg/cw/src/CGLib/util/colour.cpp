#pragma once

#include "../shared.cpp"

#define BLACK Colour(0, 0, 0)
#define WHITE Colour(255, 255, 255)

uint32_t colourToUint32(Colour colour)
{
  int r = colour.red,
      g = colour.green,
      b = colour.blue;

  return (0xFF << 24) +
         (int(r) << 16) +
         (int(g) << 8) +
         (int(b) << 0);
}

Colour uint32ToColour(uint32_t uint32)
{
  int r = (0xFF & (uint32 >> 0xF)),
      g = (0xFF & (uint32 >> 0x8)),
      b = (0xFF & (uint32 >> 0x0));

  return Colour(r, g, b);
}
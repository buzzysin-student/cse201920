#pragma once

#include "../shared.cpp"

static const Colour BLACK = Colour(0, 0, 0);
static const Colour WHITE = Colour(255, 255, 255);
static const Colour NONE = Colour(0, 0, 0);

#define vfCOLOUR_DEFAULT vf(4, 255)

uint32_t
colourToUint32(Colour colour)
{
  int r = colour.red,
      g = colour.green,
      b = colour.blue;

  return (0xFF << 0x18) |
         (int(r) << 0x10) |
         (int(g) << 0x08) |
         (int(b) << 0x00);
}

Colour uint32ToColour(uint32_t uint32)
{
  int r = (uint32 >> 0x10) & 0xFF,
      g = (uint32 >> 0x08) & 0xFF,
      b = (uint32 >> 0x00) & 0xFF;

  return Colour(r, g, b);
}

vf uint32ToVf(uint32_t uint32)
{
  return {
      float((uint32 >> 0x18) & 0xFF),
      float((uint32 >> 0x10) & 0xFF),
      float((uint32 >> 0x08) & 0xFF),
      float((uint32 >> 0x00) & 0xFF),
  };
}

uint32_t vfToUint32(vf v)
{
  return (int(v[0]) << 0x18) |
         (int(v[1]) << 0x10) |
         (int(v[2]) << 0x08) |
         (int(v[3]) << 0x00);
}

Colour vfToColour(vf v)
{
  return Colour(v[1], v[2], v[3]);
}

vf colourToVf(Colour colour)
{
  return {0xFF, float(colour.red), float(colour.blue), float(colour.green)};
}
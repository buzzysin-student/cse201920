#pragma once

#include "../shared.cpp"
#include "interpolation.cpp"
#include "colour.cpp"

void drawLine(DrawingWindow &window, vf from, vf to, Colour colour = Colour(0, 0, 0))
{
  // ? Find the difference between the two positions
  vf delta = to - from;
  // ? The largest change in points determines the number
  // ? of pixels drawn for this line
  float pixels = vMax(delta) + 1;

  Interpolate::Vector interp{from, to, 0, pixels};

  for (size_t p = 0; p < pixels; p++)
  {
    vf point = interp(p);
    window.setPixelColour(point[0], point[1], colourToUint32(colour));
  }
}

void drawTriangle(DrawingWindow &window, mf points, Colour stroke = WHITE, Colour fill = BLACK)
{
  mf sortedPoints = sortVector<vf>(
      points, *[](vf p1, vf p2)
              { return int(p1[1] - p2[1]); });

  // ? Sort points by y-value
  vf a = sortedPoints[0],
     b = sortedPoints[1],
     c = sortedPoints[2];

  // ? Determine pixel count between points
  float deltaAB = vMax(a - b) + 1;
  float deltaAC = vMax(a - c) + 1;
  float deltaBC = vMax(b - c) + 1;

  // ? Create interpolaters
  Interpolate::Vector interpAB{a, b, 0, deltaAB};
  Interpolate::Vector interpAC{a, c, 0, deltaAC};
  Interpolate::Vector interpBC{b, c, 0, deltaAC};

  // ? Get midpoint
  vf m = interpAC(deltaAB);

  // ? Determine midpoint pixel count
  // float deltaAM = deltaAB;
  // float deltaMB = deltaAC - deltaAB + 1;

  for (size_t i = 0; i < deltaAB; i++)
  {
    vf pointOnAC = interpAC(i),
       pointOnAB = interpAB(i);

    drawLine(window, pointOnAC, pointOnAB, fill);
  }

  for (size_t i = 0; i < deltaBC; i++)
  {
    vf pointOnAC = interpAC(i+deltaAB),
       pointOnBC = interpBC(i);

    drawLine(window, pointOnAC, pointOnBC, fill);
  }

  // ? Fill in the top half

  // ? Draw strokes on top of fill
  drawLine(window, points[0], points[1], stroke);
  drawLine(window, points[0], points[1], stroke);
  drawLine(window, points[0], points[1], stroke);
}

void drawTexturedTriangle() {}
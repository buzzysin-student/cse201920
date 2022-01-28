#pragma once

#include "../shared.cpp"
#include "../util/all.cpp"

#include "../graphics/texture.cpp"
#include "../runtime/window-interface.cpp"

#include "interpolation.cpp"
#include "vect.cpp"
#include "algos.cpp"
#include "colour.cpp"

void drawLine(WindowInterface &interface, vf from, vf to, Colour colour)
{
  // std::cout << from << "," << to << "\n";
  // ? Get colour
  uint32_t uint32Colour = colourToUint32(colour);

  // ? If there is nothing to draw, don't draw anything
  if (uint32Colour == 0)
    return;

  int width = interface.settings.getWidth();
  int height = interface.settings.getHeight();

  // ? Find the difference between the two positions
  vf delta = mapVector2<float, float>(std::abs, to - from);
  // ? The largest change in points determines the number
  // ? of pixels drawn for this line
  float pixels = vMax(delta) + 1;

  Interpolate::Vector interp{from, to, 0, pixels};

  for (size_t p = 0; p < pixels; p++)
  {
    vf point = mapVector2<float, float>(std::round, interp(p));

    if (point[0] < 0 || point[1] < 0 || point[0] >= width || point[1] >= height)
    {
      continue;
    }

    interface.window.setPixelColour(point[0], point[1], uint32Colour);
  }
}

class VertexTransformer
{
public:
  vf basis_origin, tf_origin;
  mf m_to, m_from, m_scale;

  mf basis_change;
  vf basis_offset;

  VertexTransformer(vf basis_origin, vf tf_origin, mf m_to, mf m_from, mf m_scale)
      : basis_origin(basis_origin), tf_origin(tf_origin), m_to(m_to), m_from(m_from), m_scale(m_scale)
  {
    basis_change = m_to * inverse(m_from);
    basis_offset = m_scale * tf_origin;
  }

  vf operator()(vf point)
  {
    return m_scale * (basis_change * (point - basis_origin)) + basis_offset;
  }
};

void drawLineFromMap(WindowInterface &interface, vf from, vf to, VertexTransformer map, matrix<vf> source)
{
  // writeLog(__FILE__, __LINE__, "drawLineFromMap ");

  // ? Find the difference between the two positions
  vf delta = mapVector2<float, float>(std::abs, to - from);
  // ? The largest change in points determines the number
  // ? of pixels drawn for this line
  float pixels = vMax(delta) + 1;

  Interpolate::Vector interp{from, to, 0, pixels};

  for (size_t p = 0; p < pixels; p++)
  {
    vf point = mapVector2<float, float>(std::round, interp(p));
    vf tPoint = mapVector2<float, float>(std::round, map(point));
    vf colour = source[tPoint[0]][tPoint[1]];

    uint32_t uint32Colour = vfToUint32(colour);
    interface.window.setPixelColour(point[0], point[1], uint32Colour);
  }
}

void drawStrokedTriangle(WindowInterface &interface, mf points, Colour stroke)
{
  writeLog(__FILE__, __LINE__, "drawStrokedTriangle\n");

  // ? Draw strokes on top of fill
  drawLine(interface, points[0], points[1], stroke);
  drawLine(interface, points[1], points[2], stroke);
  drawLine(interface, points[2], points[0], stroke);
}

void drawFilledTriangle(WindowInterface &interface, mf points, Colour fill)
{
  writeLog(__FILE__, __LINE__, "drawFilledTriangle\n");

  mf sortedPoints = sortVector<vf>(points, [](vf p1, vf p2)
                                   { return int(p1[1] - p2[1]); });

  // ? Sort points by y-value
  vf a = sortedPoints[0],
     b = sortedPoints[1],
     c = sortedPoints[2];

  // ? Create interpolaters, interpolating y-coordinate
  Interpolate::Vector interpAC(a, c, a[1], c[1]);

  // ? Get point of base from B on AC
  vf m = interpAC(b[1]);

  // ? Get delta pixels
  float deltaAM = vMax(mapVector2<float, float>(std::abs, a - m)) + 1;
  float deltaMC = vMax(mapVector2<float, float>(std::abs, m - c)) + 1;

  // ? Create interpolation from base
  Interpolate::Vector interpAM(a, m, 0, deltaAM);
  Interpolate::Vector interpAB(a, b, 0, deltaAM);
  Interpolate::Vector interpMC(m, c, 0, deltaMC);
  Interpolate::Vector interpBC(b, c, 0, deltaMC);

  // ? Fill in the top half
  for (size_t i = 0; i < deltaAM; i++)
  {
    vf pAM = interpAM(i);
    vf pAB = interpAB(i);
    drawLine(interface, pAM, pAB, fill);
  }

  for (size_t i = 0; i < deltaMC; i++)
  {
    vf pMC = interpMC(i);
    vf pBC = interpBC(i);
    drawLine(interface, pMC, pBC, fill);
  }
}
void drawTriangle(WindowInterface &interface, mf points, long null, Colour fill)
{
  writeLog(__FILE__, __LINE__, "drawTriangle\n");

  int w = interface.settings.getWidth();
  int h = interface.settings.getHeight();
  int count = 0;

  for (int p = 0; p < points.size(); p++)
  {
    vf point = points[p];
    if (point[0] < 0 || point[0] >= w || point[1] < 0 || point[1] >= h)
      count++;
  }

  if (count == points.size())
    return;

  drawFilledTriangle(interface, points, fill);
}
void drawTriangle(WindowInterface &interface, mf points, Colour stroke, long null)
{
  writeLog(__FILE__, __LINE__, "drawTriangle\n");

  int w = interface.settings.getWidth();
  int h = interface.settings.getHeight();
  int count = 0;

  for (int p = 0; p < points.size(); p++)
  {
    vf point = points[p];
    if (point[0] < 0 || point[0] >= w || point[1] < 0 || point[1] >= h)
      count++;
  }

  if (count == points.size())
    return;

  drawStrokedTriangle(interface, points, stroke);
}
void drawTriangle(WindowInterface &interface, mf points, Colour stroke, Colour fill)
{
  writeLog(__FILE__, __LINE__, "drawTriangle\n");

  int w = interface.settings.getWidth();
  int h = interface.settings.getHeight();
  int count = 0;

  for (int p = 0; p < points.size(); p++)
  {
    vf point = points[p];
    if (point[0] < 0 || point[0] >= w || point[1] < 0 || point[1] >= h)
      count++;
  }

  if (count == points.size())
    return;

  drawFilledTriangle(interface, points, fill);

  drawStrokedTriangle(interface, points, stroke);
}

void drawTexturedTriangle(WindowInterface &interface, mf points, mf txPoints, Texture texture)
{
  writeLog(__FILE__, __LINE__, "drawTexturedTriangle\n");

  int w = interface.settings.getWidth();
  int h = interface.settings.getHeight();
  int count = 0;

  for (int p = 0; p < points.size(); p++)
  {
    vf point = points[p];
    if (point[0] < 0 || point[0] >= w || point[1] < 0 || point[1] >= h)
      count++;
  }

  if (count == points.size())
    return;

  auto sortY = [](vf p1, vf p2)
  { return int(p1[1] - p2[1]); };

  mf sPoints = sortVector<vf>(points, sortY);

  std::map<vf, vf> truncMap;
  std::map<vf, vf> refMap;
  for (size_t i = 0; i < sPoints.size(); i++)
  {
    truncMap[sPoints[i]] = truncate(sPoints[i], 2);
  }
  for (size_t i = 0; i < sPoints.size(); i++)
  {
    refMap[truncMap[points[i]]] = txPoints[i];
  }

  // ? Sort points by y-value
  vf a = truncMap[sPoints[0]],
     b = truncMap[sPoints[1]],
     c = truncMap[sPoints[2]];

  // ? Attempt the same with the texture points
  // ? remembering that the map needs to be maintained.
  vf txA = refMap[a],
     txB = refMap[b],
     txC = refMap[c];

  // ? Get texture points shape
  float txRows = texture.height(),
        txCols = texture.width();

  // ? Vertex base vectors (relative to A)
  vf AB_v = b - a,
     AC_v = c - a;
  // ? Texture base vectors (relative to A)
  vf AB_t = txB - txA,
     AC_t = txC - txA;

  // ? Transformation matrices
  mf
      m_v = transpose({AB_v, AC_v}), // from basis to vertices
      m_t = transpose({AB_t, AC_t}), // from basis to texturemap
      m_s = {{txCols - 1, 0},        // from texturemap to texture
             {0, txRows - 1}};

  // std::cout << refMap << "\n";

  // ? In goes a vertex, out comes a point on the texture
  VertexTransformer vertexTransform(a, txA, m_t, m_v, m_s);

  // ? Create interpolaters, interpolating y-coordinate
  Interpolate::Vector interpAC(a, c, a[1], c[1]);

  // ? Get point of base from B on AC
  vf m = interpAC(b[1]);

  // ? Get delta pixels
  float deltaAM = vMax(mapVector2<float, float>(std::abs, a - m)) + 1;
  float deltaMC = vMax(mapVector2<float, float>(std::abs, m - c)) + 1;

  // ? Create interpolation from base
  Interpolate::Vector interpAM(a, m, 0, deltaAM);
  Interpolate::Vector interpAB(a, b, 0, deltaAM);
  Interpolate::Vector interpMC(m, c, 0, deltaMC);
  Interpolate::Vector interpBC(b, c, 0, deltaMC);

  matrix<vf> pixels = texture.pixels();

  // ? Fill in the top half
  for (size_t i = 0; i < deltaAM; i++)
  {
    vf pAM = interpAM(i);
    vf pAB = interpAB(i);

    drawLineFromMap(interface, pAM, pAB, vertexTransform, pixels);
  }

  // ? Fill in the rest
  for (size_t i = 0; i < deltaMC; i++)
  {
    vf pMC = interpMC(i);
    vf pBC = interpBC(i);

    drawLineFromMap(interface, pMC, pBC, vertexTransform, pixels);
  }
}

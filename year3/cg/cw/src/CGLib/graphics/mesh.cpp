#pragma once

#include "../shared.cpp"
#include "../contracts/all.cpp"

#include "material.cpp"

class Mesh : public Renderable::WithWrapper
{
private:
  // Material material;
  vf points, txPoints, normals;
  mf triangles;
  std::vector<size_t> indices;

public:
  Mesh(float points[], float txPoints[], float normals[], size_t indices[]) : points(*points), txPoints(*txPoints), normals(*normals), indices(*indices)
  {
  }
  Mesh(vf points, vf txPoints, vf normals, std::vector<size_t> indices) : points(points), txPoints(txPoints), normals(normals), indices(indices)
  {
  }

  void init()
  {
  }

  void render(WindowWrapper wrapper)
  {
    vf ptBuf;
    for (size_t index : indices)
    {
      if (ptBuf.size() < 3)
        ptBuf.insert(ptBuf.begin(), points[index]);
      else
      {
        vf triangle{ptBuf[0], ptBuf[1], ptBuf[2]};
        ptBuf.clear(), ptBuf.shrink_to_fit();
      }
    }
  }
};

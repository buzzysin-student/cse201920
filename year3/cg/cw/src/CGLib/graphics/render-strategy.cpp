#pragma once

#include "../util/all.cpp"

#include "camera.cpp"
#include "material.cpp"

class WindowInterface;
class RenderStrategy
{
private:
  /* data */
  m4 viewMatrix;
  m4 modelMatrix;

public:
  RenderStrategy(/* args */) {}
  virtual ~RenderStrategy() {}

  virtual void init(mf viewMatrix, mf modelMatrix)
  {
    this->viewMatrix = viewMatrix;
    this->modelMatrix = modelMatrix;
  }

  virtual void render(mf triangles, mf txTriangles, mf normalTriangles, std::map<mf, Material> triangleMaterials, WindowInterface &interface, Camera camera)
  {
  }
  virtual void render(mf triangles, mf txTriangles, mf normalTriangles, std::map<mf, Material> triangleMaterials, WindowInterface &interface, Camera camera, std::function<void()> prepare)
  {
    prepare();
    render(triangles, txTriangles, normalTriangles, triangleMaterials, interface, camera);
  }
};

class Rasterise : public RenderStrategy
{
  Rasterise() : RenderStrategy() {}
  void render(mf triangles, mf txTriangles, mf normalTriangles, std::map<mf, Material> triangleMaterials, WindowInterface &interface, Camera camera) override
  {
  }
};

class Wireframe : public RenderStrategy
{
  Wireframe() : RenderStrategy() {}
  void render(mf triangles, mf txTriangles, mf normalTriangles, std::map<mf, Material> triangleMaterials, WindowInterface &interface, Camera camera) override
  {
  }
};

class RayTrace : public RenderStrategy
{
  RayTrace() : RenderStrategy() {}
  void render(mf triangles, mf txTriangles, mf normalTriangles, std::map<mf, Material> triangleMaterials, WindowInterface &interface, Camera camera) override
  {
  }
};

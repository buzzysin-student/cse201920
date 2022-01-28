#pragma once

#include "../../util/all.cpp"

#include "../../runtime/window-interface.cpp"

class Mesh;

class Item : public ScalableSpatialData
{
protected:
  std::vector<Mesh *> meshes;

public:
  Item() : ScalableSpatialData()
  {
  }

  Item(Mesh *mesh) : ScalableSpatialData(), meshes({mesh})
  {
  }

  Item(std::vector<Mesh *> meshes) : ScalableSpatialData(), meshes(meshes)
  {
  }

  virtual ~Item(){};

  virtual Mesh *getMesh()
  {
    return meshes[0];
  }
  virtual std::vector<Mesh *> getMeshes()
  {
    return meshes;
  }
  virtual void setMesh(Mesh *mesh)
  {
    this->meshes = {mesh};
  }
  virtual void setMeshes(std::vector<Mesh *> meshes)
  {
    this->meshes = meshes;
  }

  friend std::ostream &operator<<(std::ostream &os, const Item &item)
  {
    return os << "Item{"
              << "}";
  }
};
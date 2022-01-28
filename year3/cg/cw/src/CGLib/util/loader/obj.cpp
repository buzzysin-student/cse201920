#pragma once

#include "../../shared.cpp"
#include "../../graphics/material.cpp"

#include "../vect.cpp"

class OBJFile;

class OBJ : public MapKey
{
  using vi = std::vector<int>;

private:
  Material material;
  bool materialSet;

public:
  std::string name;

  vi idxVertices;
  vi idxTxPoints;
  vi idxNormals;

  OBJ(vi idxVertices, vi idxTxPoints, vi idxNormals)
      : idxVertices(idxVertices), idxTxPoints(idxTxPoints), idxNormals(idxNormals)
  {
    materialSet = false;
  }

  void setName(std::string name)
  {
    this->name = name;
  }

  void setMaterial(Material m)
  {
    material = m;
    materialSet = true;
  }

  Material getMaterial()
  {
    return material;
  }
  bool hasMaterial()
  {
    return materialSet;
  }

  friend std::ostream &operator<<(std::ostream &os, const OBJ &obj)
  {
    return os << "OBJ{"
              << "name: " << obj.name << ", "
              << "idxVertices: " << obj.idxVertices << ", "
              << "idxTxPoints: " << obj.idxTxPoints << ", "
              << "idxNormals: " << obj.idxNormals << ", "
              << "material: " << obj.material << ""
              << "}";
  }
};
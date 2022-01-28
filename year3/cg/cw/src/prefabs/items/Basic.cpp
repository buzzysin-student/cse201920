#pragma once

#include "../../CGLib/all.cpp"

class Basic : public Item
{

protected:
  OBJFile _file;
  Mesh _mesh;
  Item _item;

  void sync()
  {
    meshes = _item.getMeshes();
    position = _item.getPosition();
    rotation = _item.getRotation();
    scale = _item.getScale();
  }

public:
  Basic(std::string file) : _file(file), _mesh(_file), _item(&_mesh)
  {
    sync();
  }

  Basic() : Basic("basic.obj")
  {
  }

  void setMesh(Mesh *mesh) override
  {
    _item.setMesh(mesh);
    sync();
  }
  void setMeshes(std::vector<Mesh *> meshes) override
  {
    _item.setMeshes(meshes);
    sync();
  }
  void setPosition(vf position) override
  {
    _item.setPosition(position);
    sync();
  }
  void setRotation(vf rotation) override
  {
    _item.setRotation(rotation);
    sync();
  }
  void setScale(float scale) override
  {
    _item.setScale(scale);
    sync();
  }
};

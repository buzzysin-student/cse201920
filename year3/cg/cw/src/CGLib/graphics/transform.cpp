#pragma once

#include "../shared.cpp"

#include "../util/all.cpp"

#include "camera.cpp"
#include "items/item.cpp"

class Transform
{
private:
  m4 viewMatrix;
  m4 projMatrix;
  m4 modlMatrix;

public:
  m4 getViewMatrix(Camera camera)
  {
    vf position = camera.getPosition();
    vf rotation = camera.getRotation();

    return viewMatrix
        .rotate(rotation)
        .translate(position);
  }
  m4 getProjectionMatrix(float fov, float width, float height, float zNear, float zFar)
  {
    float aspectRatio = width / height;
    return projMatrix.project(fov, aspectRatio, zNear, zFar);
  }

  m4 getModelViewMatrix(Item item, m4 viewMatrix)
  {
    vf position = item.getPosition();
    vf rotation = item.getRotation();
    float scale = item.getScale();

    m4 t = modlMatrix
               .translate(position)
               .rotate(-rotation)
               .scale(scale);

    return m4(viewMatrix.get() * t.get());
  }
};
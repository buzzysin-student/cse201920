#pragma once

#include "../util/all.cpp"

#define super(Superclass) using super = Superclass

class Camera : public SpatialData
{
  float focalLength;

public:
  Camera() : SpatialData(), focalLength(2.0f)
  {
  }

  void setPosition(vf position) override
  {
    position[2] = -position[2];
    SpatialData::setPosition(position);
  }
  void setPositionZ(float z) override
  {
    z = -z;
    SpatialData::setPositionZ(z);
  }

  void setRotation(vf rotation) override
  {
    rotation[2] = -rotation[2];
    SpatialData::setRotation(rotation);
  }
  void setRotationZ(float z) override
  {
    z = -z;
    SpatialData::setRotationZ(z);
  }

  float getFocalLength()
  {
    return focalLength;
  }

  void setFocalLength(float focalLength)
  {
    this->focalLength = focalLength;
  }
};
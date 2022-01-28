#pragma once

#include "vect.cpp"
#include "algos.cpp"

class SpatialData
{
protected:
  vf position;
  vf rotation;
  m4 transformation;

public:
  SpatialData(/* args */) : position(3, 0.0f), rotation(3, 0.0f){};
  virtual ~SpatialData(){};

  vf getPosition() { return position; }
  virtual float getPositionX() { return position[0]; }
  virtual float getPositionY() { return position[1]; }
  virtual float getPositionZ() { return position[2]; }
  virtual void setPosition(vf position) { this->position = position; }
  virtual void setPositionX(float x) { position[0] = x; }
  virtual void setPositionY(float y) { position[1] = y; }
  virtual void setPositionZ(float z) { position[2] = z; }
  virtual void addPosition(vf position) { this->position += position; }
  virtual void addPositionX(float x) { addPosition({x, 0, 0}); }
  virtual void addPositionY(float y) { addPosition({0, y, 0}); }
  virtual void addPositionZ(float z) { addPosition({0, 0, z}); }

  vf getRotation() { return rotation; }
  virtual float getRotationX() { return rotation[0]; }
  virtual float getRotationY() { return rotation[1]; }
  virtual float getRotationZ() { return rotation[2]; }
  virtual void setRotation(vf rotation) { this->rotation = rotation; }
  virtual void setRotationX(float x) { rotation[0] = x; }
  virtual void setRotationY(float y) { rotation[1] = y; }
  virtual void setRotationZ(float z) { rotation[2] = z; }
  virtual void addRotation(vf rotation)
  {
    this->rotation += rotation;
    this->rotation = mapVector<float, float>(
        [](float angle)
        {
          float a = angle;
          while (!(-M_PI <= a && a < M_PI))
          {
            if (a < -M_PI)
              a += 2 * M_PI;
            if (a >= M_PI)
              a -= 2 * M_PI;
          }
          return a;
        },
        this->rotation);
  }
  virtual void addRotationX(float x) { addRotation({x, 0, 0}); }
  virtual void addRotationY(float y) { addRotation({0, y, 0}); }
  virtual void addRotationZ(float z) { addRotation({0, 0, z}); }

  virtual m4 asTransformation() { return transformation.rotate(rotation).translate(position); }

  void pivot(vf point, vf rotation)
  {
    vf v1 = normal(position);
    m4 pivot = transformation
                   .translate(point)
                   .rotate(rotation)
                   .translate(-point);
    std::cout << pivot << "\n";

    position = pivot.apply(position);
    vf v2 = normal(position);

    vf a1 = {std::acos(v1[0]),
             std::acos(v1[1]),
             std::acos(v1[2])};
    vf a2 = {std::acos(v2[0]),
             std::acos(v2[1]),
             std::acos(v2[2])};

    vf da = a2 - a1;

    addRotation(da);
  }
};

class ScalableSpatialData : public SpatialData
{
protected:
  float scale;

public:
  ScalableSpatialData(/* args */) : SpatialData(), scale(1){};
  virtual ~ScalableSpatialData(){};

  virtual float getScale() { return scale; }
  virtual void setScale(float scale) { this->scale = scale; }
  virtual void scaleBy(float scale) { this->scale *= scale; }

  virtual m4 asTransformation() override { return transformation.scale(scale).rotate(rotation).translate(position); }
};
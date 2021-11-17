#pragma once

#include "../shared.cpp"

using vf = std::vector<float>;

class Interpolate
{
public:
  float y1, y2, x1, x2;

  Interpolate(float start, float stop, float from, float to)
  {
    y1 = start;
    y2 = stop;

    x1 = from;
    x2 = to;

    if (x2 == x1)
    {
      std::cerr << "Interpolation range cannot be zero\n";
      throw -1;
    }
  }

  float gradient()
  {
    return (y2 - y1) / (x2 - x1);
  }

  float get(float value)
  {
    return y1 + gradient() * (value - x1);
  }

  float operator()(float value){
    return get(value);
  }

  class Vector
  {

  public:
    vf y1, y2;
    float x1, x2;

    Vector(vf start, vf stop, float from, float to)
    {
      y1 = start;
      y2 = stop;

      x1 = from;
      x2 = to;

      if (x2 == x1)
      {
        throw "Interpolation range cannot be zero";
      }
    }

    Vector(glm::vec3 start, glm::vec3 stop, float from, float to)
    {
      vf y1({start.x, start.y, start.z});
      vf y2({stop.x, stop.y, stop.z});

      x1 = from;
      x2 = to;
    }

    vf gradient()
    {
      size_t size = y1.size();
      vf gradient(size, 0.0f);

      for (size_t i = 0; i < size; i++)
      {
        Interpolate interpolate(y1[i], y2[i], x1, x2);
        gradient[i] = interpolate.gradient();
      }

      return gradient;
    }

    glm::vec3 gradientGLM()
    {
      glm::vec3 ggradient;
      vf vgradient = gradient();

      ggradient.x = vgradient[0];
      ggradient.y = vgradient[1];
      ggradient.z = vgradient[2];

      return ggradient;
    }

    vf getVector(float value)
    {
      vf result(y1.size(), 0.0f);
      vf m = gradient();

      for (size_t i = 0; i < result.size(); i++)
      {
        result[i] = y1[i] + m[i] * (value - x1);
      }

      return result;
    }

    glm::vec3 getVectorGLM(float value)
    {
      glm::vec3 result;
      vf vresult = getVector(value);

      result.x = vresult[0];
      result.y = vresult[1];
      result.z = vresult[2];

      return result;
    }

    vf operator()(float value) {
      return getVector(value);
    }
  };
};

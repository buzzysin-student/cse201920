#pragma once

#include "../shared.cpp"
#include "../util/all.cpp"

#include "../graphics/render-strategy.cpp"

class WindowSettings
{
protected:
  float zNear;
  float zFar;
  float fov;
  bool vSync;
  float height;
  float width;

  RenderStrategy renderStrategy;

public:
  static WindowSettings base()
  {
    return WindowSettings();
  }

  WindowSettings(/* args */) : zNear(0.1f),
                               zFar(500.0f),
                               fov(radians(90)),
                               vSync(false),
                               height(395),
                               width(480),
                               renderStrategy()
  {
  }

  void setZNear(float zNear)
  {
    this->zNear = zNear;
  }
  float getZNear()
  {
    return zNear;
  }

  void setZFar(float zFar)
  {
    this->zFar = zFar;
  }
  float getZFar()
  {
    return zFar;
  }

  void setvSync(bool vSync)
  {
    this->vSync = vSync;
  }
  bool getvSync()
  {
    return vSync;
  }

  void setWidth(float width)
  {
    this->width = width;
  }
  float getWidth()
  {
    return width;
  }

  void setHeight(float height)
  {
    this->height = height;
  }
  float getHeight()
  {
    return height;
  }

  void setFov(float fov)
  {
    this->fov = fov;
  }
  float getFov()
  {
    return fov;
  }

  void setRenderStrategy(RenderStrategy strategy)
  {
    renderStrategy = strategy;
  }
  RenderStrategy getRenderStrategy()
  {
    return renderStrategy;
  }
};
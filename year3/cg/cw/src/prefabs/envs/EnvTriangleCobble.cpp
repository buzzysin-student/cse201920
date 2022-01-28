#pragma once

#include "../../CGLib/all.cpp"
#include "../items/all.cpp"

class EnvTriangleCobble : public Environment
{
private:
  Renderer renderer;
  Camera camera;
  Scene scene;

public:
  EnvTriangleCobble()
  {
    Basic item;
    scene.setItems({item});
  }

  void init(WindowInterface &interface)
  {
    writeLog(__FILE__, __LINE__, "EnvTriangleCobble::init\n");
  }

  void update(WindowInterface &interface)
  {
    writeLog(__FILE__, __LINE__, "EnvTriangleCobble::update\n");
  }

  void render(WindowInterface &interface)
  {
    interface.window.clearPixels();
    writeLog(__FILE__, __LINE__, "EnvTriangleCobble::render\n");
    renderer.render(interface, camera, scene);
  }

  void cleanup()
  {
    writeLog(__FILE__, __LINE__, "EnvTriangleCobble::cleanup\n");
  }
};
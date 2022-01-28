#pragma once

#include "../../CGLib/all.cpp"
#include "../items/all.cpp"

class EnvCornell : public Environment
{
private:
  Renderer renderer;
  Camera camera;
  Scene scene;

  CornellBox item;

  bool autoRotate;
  size_t updates;

  const float TRNSLT = 1.0f / 4.0f;
  const float ROTATE = radians(5);

public:
  EnvCornell()
  {
    autoRotate = false;
    updates = 0;
  }

  void init(WindowInterface &interface) override
  {
    writeLog(__FILE__, __LINE__, "EnvCornell::init\n");

    scene.setItems({item});
    camera.setPosition({0, 0, 1});

    EventHandler cameraMovement = [&](SDL_Event event)
    {
      auto key = event.key.keysym.sym;

      if (event.type == SDL_KEYDOWN)
      {
        auto cb = camera.getPosition();

        if (key == SDLK_LEFT)
          camera.addPositionX(-TRNSLT);
        else if (key == SDLK_RIGHT)
          camera.addPositionX(TRNSLT);
        else if (key == SDLK_UP)
          camera.addPositionZ(TRNSLT);
        else if (key == SDLK_DOWN)
          camera.addPositionZ(-TRNSLT);
        else if (key == SDLK_a)
          camera.pivot(item.getPosition(), {0, -ROTATE, 0});
        else if (key == SDLK_d)
          camera.pivot(item.getPosition(), {0, ROTATE, 0});
        else if (key == SDLK_w)
          camera.pivot(item.getPosition(), {-ROTATE, 0, 0});
        else if (key == SDLK_s)
          camera.pivot(item.getPosition(), {ROTATE, 0, 0});
        else if (key == SDLK_RSHIFT)
          camera.setPosition({0, 0, 4}), camera.setRotation({0, 0, 0});
        else if (key == SDLK_z)
          autoRotate = !autoRotate;

        auto ca = camera.getPosition();

        if (cb != ca)
        {
          std::cout << "Event: Camera is at " << ca << ", oriented at "
                    << camera.getRotation() * (180 / M_PI) << "\n";
        }
      }
    };

    EventHandler windowControls = [&](SDL_Event event)
    {
      auto key = event.key.keysym.sym; 
      if (event.type == SDL_KEYDOWN && key == SDLK_q)
      {
        interface.setExitStatus(true);
      }

      if (event.window.type == SDL_WINDOWEVENT_SIZE_CHANGED)
      {
        interface.settings.setWidth(event.window.data1);
        interface.settings.setHeight(event.window.data2);
        interface.window = DrawingWindow(
            interface.settings.getWidth(),
            interface.settings.getHeight(),
            false);
      }
    };

    EventHandler keyLog = [](SDL_Event event)
    {
      if (event.type == SDL_KEYDOWN)
      {
        char c[2] = {(char)event.key.keysym.sym, 0};
        std::cout << "Key pressed: " << c << "\n";
      }
    };

    interface.addHandle(keyLog);
    interface.addHandle(cameraMovement);
    interface.addHandle(windowControls);
  }

  void update(WindowInterface &interface) override
  {
    writeLog(__FILE__, __LINE__, "EnvCornell::update\n");
    if (autoRotate)
    {
      camera.pivot(item.getPosition(), {-2 * M_PI / 30, 0, 0});
      updates += 1;
      updates %= 30;
    }
  }

  void render(WindowInterface &interface) override
  {
    interface.window.clearPixels();
    writeLog(__FILE__, __LINE__, "EnvCornell::render\n");
    renderer.render(interface, camera, scene);
  }

  void cleanup() override
  {
    writeLog(__FILE__, __LINE__, "EnvCornell::cleanup\n");
  }
};
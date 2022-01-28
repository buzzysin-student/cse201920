#pragma once

#include "../shared.cpp"
#include "../util/all.cpp"

#include "window-interface.cpp"
#include "timer.cpp"
#include "environment.cpp"

class Engine
{
  // const float FPS = 60.0f;
  const float UPS = 30.0f;

  WindowInterface interface;
  Timer timer;
  Environment &env;

public:
  Engine(Environment &env) : env(env)
  {
  }

  void run()
  {
    try
    {
      init();
      loop();
    }
    catch (...)
    {
    }

    cleanup();
  }

  void init()
  {
    writeLog(__FILE__, __LINE__, "Engine::init\n");

    interface.init();
    timer.init();
    env.init(interface);
  }

public:
  void update()
  {
    writeLog(__FILE__, __LINE__, "Engine::update\n");

    // ? Upate env
    env.update(interface);
  }

public:
  void render()
  {
    writeLog(__FILE__, __LINE__, "Engine::render\n");

    // ? Update the wrapper by calculating changes
    interface.update();

    // ? Commit env changes
    env.render(interface);
  }

  void cleanup()
  {
  }

  void loop()
  {
    writeLog(__FILE__, __LINE__, "Engine::loop\n");

    float elapsed;
    float updateTime = 0.0f;
    float updateInterval = 1.0f / UPS;

    while (!interface.getExitStatus())
    {
      elapsed = timer.elapsed();
      updateTime += elapsed;

      // ? Update view
      while (updateTime >= updateInterval)
      {
        update();
        updateTime -= updateInterval;
      }

      // ? Publish view to screen
      render();
    }
  }

  friend std::ostream &operator<<(std::ostream &os, const Engine &engine)
  {
    return os << "Engine{"
              << "}";
  }
};
#pragma once

#include "../shared.cpp"
#include "../contracts/all.cpp"

#include "wrapper.cpp"
#include "timer.cpp"
#include "environment.cpp"

class Engine : public FullyLoopable, public Threadable, public Updatable
{

  // const float FPS = 60.0f;
  const float UPS = 30.0f;

  WindowWrapper wrapper;
  Timer timer;
  Environment *env;

public:
  Engine(Environment *env) : env(env)
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
    wrapper.init();
    timer.init();
    env->init(wrapper);
  }

  void update()
  {
    env->update(wrapper);
  }

  void render()
  {
    wrapper.update();
  }

  void cleanup()
  {
  }

  void loop()
  {
    float elapsed;
    float updateTime = 0.0f;
    float updateInterval = 1.0f / UPS;

    while (true /* !wrapper.shouldClose() */)
    {
      elapsed = timer.elapsed();
      updateTime += elapsed;

      // keyboard events

      while (updateTime >= updateInterval)
      {
        update();
        updateTime -= updateInterval;
      }
    }
  }
};
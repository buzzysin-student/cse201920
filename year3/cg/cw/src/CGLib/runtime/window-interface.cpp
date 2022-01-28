#pragma once

#include "../shared.cpp"
#include "../util/all.cpp"

#include "window-settings.cpp"

const int WIDTH = 480;
const int HEIGHT = 395;

using EventHandler = std::function<void(SDL_Event)>;

class WindowInterface
{
public:
  DrawingWindow window;
  WindowSettings settings;

private:
  std::vector<EventHandler> windowEventHandlers;
  std::vector<int> windowEventHandleIds;
  int windowEventHandleId = 0;
  bool exitStatus;

public:
  WindowInterface() : exitStatus(false) {}
  WindowInterface(WindowSettings settings) : settings(settings), exitStatus(false)
  {
  }

  void clearEventQueue()
  {
    SDL_Event event;
    while (SDL_PollEvent(&event))
      ;
  }

  void init()
  {
    writeLog(__FILE__, __LINE__, "WindowInterface::init\n");

    // ? Initialise the window
    window = DrawingWindow(settings.getWidth(), settings.getHeight(), false);
    clearEventQueue();
  }

  void update()
  {
    writeLog(__FILE__, __LINE__, "WindowInterface::update\n");
    handleEvents();
    window.renderFrame();
  }

  int addHandle(EventHandler handle)
  {
    writeLog(__FILE__, __LINE__, "WindowInterface::addHandle\n");

    windowEventHandlers.push_back(handle);
    return windowEventHandleId++;
  }

  void removeEventHandle(int id)
  {
    writeLog(__FILE__, __LINE__, "WindowInterface::removeEventHandle\n");

    auto cbkIterator = windowEventHandlers.begin();

    for (auto idIterator = windowEventHandleIds.begin(); idIterator != windowEventHandleIds.end();)
    {
      int thisId = *idIterator;

      if (thisId == id)
      {
        idIterator = windowEventHandleIds.erase(idIterator);
        cbkIterator = windowEventHandlers.erase(cbkIterator);
      }
      else
      {
        idIterator++;
        cbkIterator++;
      }
    }
  }

  bool getExitStatus() { return exitStatus; }
  void setExitStatus(bool exitStatus)
  {
    this->exitStatus = exitStatus;
  }

  friend std::ostream &operator<<(std::ostream &os, const WindowInterface &interface)
  {
    return os << "Wrapper{"
              << "}";
  }

private:
  void handleEvents()
  {
    writeLog(__FILE__, __LINE__, "WindowInterface::handleEvents\n");

    SDL_Event event;
    // ? Check for events
    if (!SDL_PollEvent(&event))
      return;

    if (event.type == SDL_QUIT)
    {
      SDL_Quit();
      setExitStatus(true);
    }

    // ? Execute Handlers
    for (int i = 0; i < windowEventHandlers.size(); i++)
    {
      auto handler = windowEventHandlers[i];
      handler(event);
    }

    // ? Clear event queue
    clearEventQueue();
  }
};
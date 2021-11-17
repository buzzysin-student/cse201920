#pragma once

#include "../shared.cpp"
#include "../contracts/all.cpp"

const int WIDTH = 300;
const int HEIGHT = 400;

using KeyEventCallback = void (*)(SDL_KeyboardEvent);

class WindowWrapper : public Initable,
                      public Updatable
{
private:
  DrawingWindow window;
  std::vector<KeyEventCallback> windowKeyEventHandlers;
  std::vector<int> windowKeyHandleIds;
  int windowKeyHandleId = 0;

public:
  void init()
  {
    // ? Initialise the window
    window = DrawingWindow(WIDTH, HEIGHT, false);
    // ? Create empty vector for key callbacks
    windowKeyEventHandlers = std::vector<KeyEventCallback>();
  }

  void update()
  {
    handleKeyEvents();
  }

  int addKeyhandle(void (*handle)(SDL_KeyboardEvent))
  {
    windowKeyEventHandlers.push_back(handle);
    return windowKeyHandleId++;
  }

  void removeKeyHandle(int id)
  {
    auto cbkIterator = windowKeyEventHandlers.begin();

    for (auto idIterator = windowKeyHandleIds.begin(); idIterator != windowKeyHandleIds.end();)
    {
      int thisId = *idIterator;

      if (thisId == id)
      {
        idIterator = windowKeyHandleIds.erase(idIterator);
        cbkIterator = windowKeyEventHandlers.erase(cbkIterator);
      }
      else
      {
        idIterator++;
        cbkIterator++;
      }
    }
  }

private:
  void handleKeyEvents()
  {
    SDL_Event event;

    while (true)
    {
      // ? Check if event poll failed
      if (!window.pollForInputEvents(event))
        continue;

      // ? Check for key press
      if (event.type != SDL_KEYDOWN)
        continue;

      // ? Execute callbacks
      for (auto callback : windowKeyEventHandlers)
        callback(event.key);
    }
  }
};
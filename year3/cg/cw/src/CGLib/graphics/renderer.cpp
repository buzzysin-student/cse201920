#pragma once

#include "../runtime/window-interface.cpp"

#include "mesh.cpp"
#include "camera.cpp"
#include "scene.cpp"
#include "transform.cpp"

class Renderer
{

public:
  Transform transform;

  void init(WindowInterface &interface)
  {
  }

  void render(WindowInterface &interface, Camera camera, Scene scene)
  {
    writeLog(__FILE__, __LINE__, "Renderer::render\n");
    interface.window.clearPixels();

    std::vector<Mesh> meshes = scene.getMeshes();
    std::map<Mesh, std::vector<Item>> items = scene.getItems();

    for (auto it = items.begin(); it != items.end(); ++it)
    {
      Mesh mesh = it->first;
      std::vector<Item> meshItems = items[mesh];

      if (meshItems.size())
        mesh.renderList(interface, meshItems, camera, scene);
    }
  }

  void cleanup()
  {
  }

  friend std::ostream &operator<<(std::ostream &os, const Renderer renderer)
  {
    return os << "Renderer{"
              << "}";
  }
};
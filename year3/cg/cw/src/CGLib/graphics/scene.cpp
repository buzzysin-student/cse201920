#pragma once

#include "mesh.cpp"
#include "items/item.cpp"

class Scene
{
private:
  bool changed;
  std::map<Mesh, std::vector<Item>> meshItems;

  std::map<size_t, Mesh> meshMap;
  std::map<size_t, std::vector<Item>> itemMap;

public:
  Scene() : changed(false) {}

  void setItems(std::vector<Item> items)
  {
    meshMap.clear();
    itemMap.clear();
    addItems(items);
  }

  std::map<Mesh, std::vector<Item>> getItems()
  {
    if (changed)
    {
      std::map<Mesh, std::vector<Item>> _meshItems;
      for (auto it = meshMap.begin(); it != meshMap.end(); ++it)
      {
        _meshItems[it->second] = itemMap[it->first];
      }

      meshItems = _meshItems;
      changed = false;
    }

    return meshItems;
  }

  void addItem(Item item)
  {
    std::vector<Mesh *> meshes = item.getMeshes();
    for (size_t i = 0; i < meshes.size(); i++)
    {
      Mesh mesh = *meshes[i];
      auto meshItems = itemMap.find(mesh.getId());
      if (meshItems != itemMap.end())
      {
        meshItems->second.push_back(item);
      }
      else
      {
        meshMap.emplace(mesh.getId(), mesh);
        itemMap.emplace(mesh.getId(), std::vector<Item>({item}));
      }
    }
    
    changed = true;
  }

  void addItems(std::vector<Item> items)
  {

    for (size_t i = 0; i < items.size(); i++)
    {
      auto item = items[i];
      addItem(item);
    }
  }

  std::vector<Mesh> getMeshes()
  {
    std::vector<Mesh> meshes;

    for (auto it = meshMap.begin(); it != meshMap.end(); ++it)
    {
      meshes.push_back(it->second);
    }

    return meshes;
  }

  friend std::ostream &operator<<(std::ostream &os, const Scene &scene)
  {
    return os << "Scene{"
              << "}";
  }
};

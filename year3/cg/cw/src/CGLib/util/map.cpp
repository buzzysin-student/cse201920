#pragma once

#include "../shared.cpp"

template <typename K, typename V>
std::ostream &operator<<(std::ostream &os, const std::map<K, V> &map)
{
  os << "[";

  int i = 0;
  for (auto it = map.begin(); it != map.end(); ++it)
  {
    i++;
    auto end = i < map.size() ? ", " : "";
    os << "{\"<" << it->first << ">\": " << it->second << "}" << end;
  }

  os << "]";

  return os;
}

template <typename K, typename V>
std::ostream &printMap(std::ostream &os, const std::map<K, V> &map)
{
  os << "[";

  int i = 0;
  for (auto it = map.begin(); it != map.end(); ++it)
  {
    i++;
    auto end = i < map.size() ? ", " : "";
    os << "{<" << it->first << ">: " << it->second << "}" << end;
  }

  os << "]";

  return os;
}

static size_t MapKeyId = 0;

class MapKey
{
protected:
  size_t id;

public:
  MapKey()
  {
    id = MapKeyId++;
  }

  size_t getId() { return id; }

  //! Sketch definition. Override if more precise definitions are needed.
  //! If the keys are the same, it just means this is the same initialised
  //! object
  inline friend bool operator==(MapKey &k, MapKey &l)
  {
    return k.id == l.id;
  }

  // ? Required for allowing sorting of keys in std::map
  inline friend bool operator<(const MapKey &k, const MapKey &l)
  {
    return k.id < l.id;
  }

  friend std::ostream &operator<<(std::ostream &os, const MapKey &k)
  {
    return os << "MapKey{"
              << "id: " << k.id
              << "}";
  }
};

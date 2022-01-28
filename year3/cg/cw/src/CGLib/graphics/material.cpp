#pragma once

#include "../shared.cpp"
#include "texture.cpp"

class Material
{
  std::string name;

  Texture texture;
  Texture normalMap;

  bool textureSet;
  bool normalMapSet;

  vf ambient;
  vf diffuse;
  vf specular;

  float refraction;
  float reflection;

public:
  Material()
  {
    *this = Material(vfCOLOUR_DEFAULT, vfCOLOUR_DEFAULT, vfCOLOUR_DEFAULT, Texture(), 1, 0);
  }
  Material(vf colour, float reflection = 0)
  {
    *this = Material(colour, colour, colour, Texture(), 1, reflection);
  }
  Material(Texture texture, float reflection = 0)
  {
    *this = Material(vfCOLOUR_DEFAULT, vfCOLOUR_DEFAULT, vfCOLOUR_DEFAULT, texture, 1, reflection);
  }
  Material(vf ambient, vf diffuse, vf specular, float reflection = 0)
  {
    *this = Material(ambient, diffuse, specular, Texture(), 1, reflection);
  }
  Material(vf ambient, vf diffuse, vf specular, Texture texture, float refraction, float reflection)
      : texture(texture), refraction(refraction), reflection(reflection)
  {
    if (ambient.size() == 3)
    {
      ambient.insert(ambient.begin(), 255);
    }
    if (diffuse.size() == 3)
    {
      diffuse.insert(diffuse.begin(), 255);
    }
    if (specular.size() == 3)
    {
      specular.insert(specular.begin(), 255);
    }

    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;

    textureSet = texture.hasLoaded();
  }

  void setName(std::string name)
  {
    this->name = name;
  }
  std::string getName()
  {
    return name;
  }

  void setAmbient(vf ambient)
  {
    this->ambient = ambient;
  }
  vf getAmbient() { return ambient; }

  void setDiffuse(vf diffuse)
  {
    this->diffuse = diffuse;
  }
  vf getDiffuse() { return this->diffuse; }

  void setSpecular(vf specular)
  {
    this->specular = specular;
  }
  vf getSpecular() { return specular; }

  void setReflection(float reflection)
  {
    this->reflection = reflection;
  }
  float getReflection() { return reflection; }

  void setRefraction(float refraction)
  {
    this->refraction = refraction;
  }
  float getRefraction() { return refraction; }

  void setTexture(Texture texture)
  {
    this->texture = texture;
    textureSet = true;
  }
  Texture getTexture() { return texture; }
  bool hasTexture() { return textureSet; }

  void setNormalMap(Texture normalMap)
  {
    this->normalMap = normalMap;
    normalMapSet = true;
  }
  Texture getNormalMap() { return normalMap; }
  bool hasNormalMap() { return normalMapSet; }

  friend std::ostream &operator<<(std::ostream &os, const Material &material)
  {
    Texture texture = material.texture;
    return os << "Material{"
              << "name: " << material.name << ", "
              << "ambient: " << material.ambient << ", "
              << "diffuse: " << material.diffuse << ", "
              << "specular: " << material.specular << ", "
              << "texture: " << texture << ", "
              << "}";
  }
};

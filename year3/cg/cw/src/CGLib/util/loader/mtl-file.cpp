#pragma once

#include "../../shared.cpp"
#include "../../graphics/material.cpp"

#include "../../util/vect.cpp"

class MTLFile
{
  std::vector<Material> materials;
  std::map<std::string, Texture> textureCache;
  std::string name;

public:
  MTLFile(std::string name)
  {
    *this = parseMTLFile(name);
    this->name = name;
  }
  MTLFile(std::vector<Material> materials,
          std::map<std::string, Texture> textureCache = std::map<std::string, Texture>()) : materials(materials)
  {
  }

  static MTLFile parseMTLFile(std::string name)
  {
    writeLog(__FILE__, __LINE__, std::string("Parsing MTL at ") + name + "\n");
    std::string path;
    path = path.append("resources/materials/").append(name);

    std::ifstream file(path);

    if (!file.is_open())
    {
      std::cerr << "Could not open/find " << path << ".\n";
      throw std::invalid_argument("Invalid argument");
    }

    std::vector<Material> materials;
    std::string mtlName;

    bool first = true;

    vf ambient = vfCOLOUR_DEFAULT;
    vf diffuse = vfCOLOUR_DEFAULT;
    vf specular = vfCOLOUR_DEFAULT;

    Texture texture;
    std::map<std::string, Texture> textureCache;

    float refraction = 1;
    float reflection = 0;

    auto strToF = [](std::string s)
    { return std::stof(s); };

    for (std::string line; std::getline(file, line);)
    {
      std::vector<std::string> tokens = getTokens(line, ' ');
      std::string tokenDef = tokens[0];
      std::vector<std::string> tokenArgs(tokens.begin() + 1, tokens.end());

      if (tokenDef == "newmtl")
      {
        writeLog(__FILE__, __LINE__, "Trying to save MTL.\n");
        if (!first)
          saveMTL(mtlName, materials, ambient, diffuse, specular, texture, refraction, reflection);

        mtlName = tokenArgs[0];
        first = false;
      }
      else if (tokenDef == "Ka")
      {
        writeLog(__FILE__, __LINE__, "Trying to add ambient component.\n");
        ambient = mapVector<std::string, float>(strToF, tokenArgs) * 255;
      }
      else if (tokenDef == "Kd")
      {
        writeLog(__FILE__, __LINE__, "Trying to add diffuse component.\n");
        diffuse = mapVector<std::string, float>(strToF, tokenArgs) * 255;
      }
      else if (tokenDef == "Ks")
      {
        writeLog(__FILE__, __LINE__, "Trying to add specular component.\n");

        specular = mapVector<std::string, float>(strToF, tokenArgs) * 255;
      }
      else if (tokenDef == "Ni")
      {
        writeLog(__FILE__, __LINE__, "Trying to add refractive component.\n");

        refraction = strToF(tokenArgs[0]);
      }
      else if (tokenDef == "map_Kd")
      {
        std::string fname = tokenArgs[0];

        if (textureCache.find(fname) != textureCache.end())
        {
          texture = textureCache[fname];
        }
        else
        {
          writeLog(__FILE__, __LINE__, std::string("Trying to load texture map: ") + fname + "\n");
          texture = Texture::loadPPMTexture(fname);
          textureCache[fname] = texture;
        }
      }
    }

    saveMTL(mtlName, materials, ambient, diffuse, specular, texture, refraction, reflection);
    MTLFile mtlFile = MTLFile(materials, textureCache);
    return mtlFile;
  }

  bool hasTextureWithName(std::string name)
  {
    return textureCache.find(name) != textureCache.end();
  }
  Texture getTextureWithName(std::string name)
  {
    return textureCache.find(name)->second;
  }

  bool hasMaterialWithName(std::string name)
  {
    auto getName = [](Material m)
    { return m.getName(); };

    auto names = mapVector<Material, std::string>(getName, materials);
    for (auto it = names.begin(); it != names.end(); ++it)
    {
      if (*it == name)
        return true;
    }

    return false;
  }
  Material getMaterialWithName(std::string name)
  {
    for (auto it = materials.begin(); it != materials.end(); ++it)
    {
      if (it->getName() == name)
        return *it;
    }
    std::cerr << "Material with name " << name << "does not exist on this .mtl file:\n"
              << *this << "\n";
    throw std::invalid_argument("Invalid argument");
  }

  friend std::ostream &operator<<(std::ostream &os, const MTLFile &mtlFile)
  {
    return os << "MTLFile{"
              << "name: " << mtlFile.name << ", "
              << "materials: " << mtlFile.materials << ", "
              << "textureCache: " << mtlFile.textureCache << ", "
              << "}";
  }

private:
  static void saveMTL(
      std::string &name, std::vector<Material> &materials,
      vf &ambient, vf &diffuse, vf &specular,
      Texture texture, float &refraction, float &reflection)
  {
    Material material(ambient, diffuse, specular,
                      texture, refraction, reflection);

    material.setName(name);
    materials.push_back(material);

    ambient = vfCOLOUR_DEFAULT;
    diffuse = vfCOLOUR_DEFAULT;
    specular = vfCOLOUR_DEFAULT;
    texture = Texture();
    refraction = 1;
    reflection = 0;
  }
};
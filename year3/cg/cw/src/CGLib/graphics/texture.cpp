#pragma once

#include "../util/log.cpp"
#include "../util/vect.cpp"
#include "../util/colour.cpp"

class Texture
{
private:
  std::string name;
  matrix<vf> texture;
  bool textureLoaded;

public:
  Texture()
  {
    *this = Texture("NOT_SET", {{vfCOLOUR_DEFAULT}});
  }

  Texture(std::string name)
  {
    if (name.find("ppm") != std::string::npos)
    {
      *this = loadPPMTexture(name);
    }
    else
    {
      *this = Texture(name, {{vfCOLOUR_DEFAULT}});
    }
  }

private:
  Texture(std::string name, matrix<vf> texture)
  {
    this->name = name;
    this->texture = texture;
    this->textureLoaded = true;
  }

public:

  bool hasLoaded() { return textureLoaded; }

  size_t width()
  {
    return texture.size();
  }
  size_t height()
  {
    return texture[0].size();
  }
  matrix<vf> pixels()
  {
    return texture;
  }

  static Texture loadPPMTexture(std::string name)
  {
    writeLog(__FILE__, __LINE__, "Texture::loadPPMTexture\n");

    std::string path;
    path = path.append("resources/textures/").append(name);

    TextureMap textureMap(path);

    size_t height = textureMap.height,
           width = textureMap.width;
    size_t depth = 4; // * FORMAT is ARGB

    std::vector<uint32_t> pixels = textureMap.pixels;

    matrix<vf> texture(height, std::vector<vf>(width, vf(depth)));

    for (size_t r = 0; r < height; r++)
    {
      for (size_t c = 0; c < width; c++)
      {
        size_t i = (r * width) + c;
        texture[r][c] = uint32ToVf(pixels[i]);
      }
    }

    return Texture(name, texture);
  }

  std::vector<vf> &operator[](int i)
  {
    return this->texture[i];
  }

  friend std::ostream &operator<<(std::ostream &os, const Texture &texture)
  {
    Texture t = texture;
    return os << "Texture{"
              << "name: " << t.name << ", "
              << "textureLoaded: " << t.textureLoaded << ", "
              << "height: " << t.height() << ", "
              << "width: " << t.width() << ", "
              << "}";
  }
};
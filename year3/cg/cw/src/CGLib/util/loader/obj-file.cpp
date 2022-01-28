#pragma once

#include "../../shared.cpp"

#include "../vect.cpp"
#include "../log.cpp"
#include "../text.cpp"

#include "obj.cpp"
#include "mtl-file.cpp"

class OBJFile
{
  using vi = std::vector<int>;

public:
  std::string name;

  mf vertices;
  mf txPoints;
  mf normals;

  std::vector<OBJ> objs;
  std::vector<MTLFile> mtlFiles;

  OBJFile(std::string name, mf vertices, mf txPoints, mf normals, std::vector<OBJ> objs, std::vector<MTLFile> mtlFiles)
      : vertices(vertices), txPoints(txPoints), normals(normals),
        objs(objs), mtlFiles(mtlFiles)
  {
  }

  OBJFile(std::string name)
  {
    *this = parseOBJFile(name);
    this->name = name;
  }

  friend std::ostream &operator<<(std::ostream &os, const OBJFile &objFile)
  {
    return os << "OBJFile{"
              << "name: " << objFile.name << ", "
              << "vertices: " << objFile.vertices << ", "
              << "txPoints: " << objFile.txPoints << ", "
              << "normals: " << objFile.normals << ", "
              << "objs: " << objFile.objs << ""
              << "}";
  }

private:
  static OBJFile parseOBJFile(std::string name)
  {
    std::string path;
    path = path.append("resources/models/").append(name);

    std::ifstream file(path);

    if (!file.is_open())
    {
      std::cerr << "Could not find/open file " << path << ".\n";
      throw std::invalid_argument("Invalid argument");
    }

    mf vertices;
    mf txPoints;
    mf normals;

    std::vector<OBJ> objs;
    std::string objName = "";

    std::vector<MTLFile> mtlFiles;
    Material material;

    vi idxVertices;
    vi idxTxPoints;
    vi idxNormals;

    auto strToF = [](std::string s)
    { return std::stof(s); };

    for (std::string line; std::getline(file, line);)
    {
      std::vector<std::string> tokens = getTokens(line, ' ');
      std::string tokenDef = tokens[0];
      std::vector<std::string> tokenArgs(tokens.begin() + 1, tokens.end());

      if (tokenDef == "v")
      {
        writeLog(__FILE__, __LINE__, "Trying to add points.\n");
        vf vertex = mapVector2<std::string, float>(strToF, tokenArgs);
        vertices.push_back(vertex);
      }
      else if (tokenDef == "vt")
      {
        writeLog(__FILE__, __LINE__, "Trying to add texture points.\n");
        vf txPoint = mapVector2<std::string, float>(strToF, tokenArgs);
        txPoints.push_back(txPoint);
      }
      else if (tokenDef == "vn")
      {
        writeLog(__FILE__, __LINE__, "Trying to add normals.\n");
        vf normal = mapVector2<std::string, float>(strToF, tokenArgs);
        normals.push_back(normal);
      }
      else if (tokenDef == "mtllib")
      {
        writeLog(__FILE__, __LINE__, "Trying to parse MTL file\n");
        MTLFile mtlFile = MTLFile::parseMTLFile(tokenArgs[0]);
        mtlFiles.push_back(mtlFile);
      }
      else if (tokenDef == "f")
      {
        writeLog(__FILE__, __LINE__, "Trying to parse face index group.\n");

        for (size_t i = 1; i < tokens.size(); i++)
        {
          std::vector<std::string> faceTokens = getTokens(tokens[i], '/');

          auto parsedFaceToken = interpretFaceToken(faceTokens);
          auto idxVertex = parsedFaceToken[0];
          auto idxTexture = parsedFaceToken[1];
          auto idxNormal = parsedFaceToken[2];

          // ? Face definitions in .objs are 1-indexed.
          // ? Subtracting 1 yields the 0-index version
          idxVertices.push_back(idxVertex > 0 ? idxVertex - 1 : idxVertex);
          idxTxPoints.push_back(idxTexture > 0 ? idxTexture - 1 : idxTexture);
          idxNormals.push_back(idxNormal > 0 ? idxNormal - 1 : idxNormal);
        }
      }
      else if (tokenDef == "o")
      {
        writeLog(__FILE__, __LINE__, "Trying to save obj.\n");
        pushObj(objName, idxVertices, idxTxPoints, idxNormals, material, objs);
        objName = tokens[1];
      }
      else if (tokenDef == "usemtl")
      {
        writeLog(__FILE__, __LINE__, "Trying to use MTL file\n");
        std::string mtlName = tokenArgs[0];
        for (size_t i = 0; i < mtlFiles.size(); i++)
        {
          auto mtlFile = mtlFiles[i];
          if (mtlFile.hasMaterialWithName(mtlName))
          {
            material = mtlFile.getMaterialWithName(mtlName);
            break;
          }
        }
      }
      else
      {
        // Token to ignore
      }
    }

    pushObj(objName, idxVertices, idxTxPoints, idxNormals, material, objs);

    return buildObjFile(name, vertices, txPoints, normals, objs, mtlFiles);
  }

  static OBJFile buildObjFile(std::string name, mf vertices, mf txPoints, mf normals, std::vector<OBJ> objs, std::vector<MTLFile> mtlFiles)
  {
    vf xs = col(vertices, 0);
    vf ys = col(vertices, 1);
    vf zs = col(vertices, 2);

    float xMin = vMin(xs), xMax = vMax(xs);
    float yMin = vMin(ys), yMax = vMax(ys);
    float zMin = vMin(zs), zMax = vMax(zs);

    float sf = 1/std::sqrt(std::pow(xMax-xMin, 2)+std::pow(yMax-yMin, 2)+std::pow(zMax-zMin, 2));

    vertices *= sf;

    return OBJFile(name, vertices, txPoints, normals, objs, mtlFiles);
  }

  static void pushObj(std::string objName,
                      vi &idxVertices, vi &idxTxPoints, vi &idxNormals,
                      Material &material, std::vector<OBJ> &objs)
  {
    if (!idxVertices.size())
      return;

    OBJ obj(idxVertices, idxTxPoints, idxNormals);

    obj.setName(objName);
    obj.setMaterial(material);

    objs.push_back(obj);

    idxVertices.clear();
    idxTxPoints.clear();
    idxNormals.clear();

    material = Material();
  }

  static std::vector<int> interpretFaceToken(std::vector<std::string> token)
  {
    auto convert = [](std::string c)
    {
      return c.size() > 0 ? std::stoi(c) : -1;
    };

    switch (token.size())
    {
    case 1:
      return {convert(token[0]), -1, -1};
    case 2:
      return {convert(token[0]), convert(token[1]), -1};
    case 3:
      return {convert(token[0]), convert(token[1]), convert(token[2])};
    default:
      return {-1, -1, -1};
    }
  }
};
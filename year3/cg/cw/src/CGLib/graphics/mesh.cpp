#pragma once

#include "../shared.cpp"
#include "../util/all.cpp"

#include "../runtime/window-interface.cpp"

#include "material.cpp"
#include "transform.cpp"
#include "items/item.cpp"

class Scene;

class Mesh : public MapKey
{
private:
  OBJFile objFile;
  std::map<OBJ, std::vector<mf>> objTriangles, objTxTriangles, objNormalTriangles;

  // ? Vector of <thing>
  // std::vector<mf> triangles, txTriangle, normalTriangle;
  std::map<mf, Material> triangleMaterials;

  m4 transformation;

  m4 projMatrix;
  m4 viewMatrix;
  m4 modelMatrix;

  mf getCanvasIntersectionPoint(mf triangle, WindowInterface interface, Camera camera)
  {
    float f = camera.getFocalLength();
    float width = interface.settings.getWidth();
    float height = interface.settings.getHeight();
    vf cameraPos = camera.getPosition();

    mf cameraTriangle = (viewMatrix.reverse() * modelMatrix)
                            .apply(triangle);

    mf uvTriangle = mapVector<vf, vf>(
        [cameraPos, width, height, f](vf point)
        {
          float x = point[0], y = point[1], z = point[2];
          vf uvPoint = {
              width / 2 + (f * x / z) * width,
              height / 2 - (f * y / z) * height,
              1
          };
          return uvPoint;
        },
        cameraTriangle);

    return uvTriangle;
  }

public:
  Mesh(OBJFile objFile) : objFile(objFile)
  {
    writeLog(__FILE__, __LINE__, "Mesh::Mesh\n");

    for (size_t i = 0; i < objFile.objs.size(); i++)
    {
      OBJ obj = objFile.objs[i];

      std::vector<int> indices = obj.idxVertices;
      size_t count = indices.size() / 3;

      std::vector<mf> triangles, txTriangles, normalTriangles;

      for (size_t i = 0; i < count; i++)
      {
        std::vector<int> idx = {indices[i * 3], indices[i * 3 + 1], indices[i * 3 + 2]};

        if (objFile.vertices.size() > 0)
        {
          mf idxVertices = {objFile.vertices[idx[0]], objFile.vertices[idx[1]], objFile.vertices[idx[2]]};
          triangles.push_back(idxVertices);

          if (obj.hasMaterial())
          {
            Material material = obj.getMaterial();
            triangleMaterials[idxVertices] = material;
          }
        }
        if (objFile.txPoints.size() > 0)
        {
          mf idxTxPoints = {objFile.txPoints[idx[0]], objFile.txPoints[idx[1]], objFile.txPoints[idx[2]]};
          txTriangles.push_back(idxTxPoints);
        }
        if (objFile.normals.size() > 0)
        {
          mf idxNormals = {objFile.normals[idx[0]], objFile.normals[idx[1]], objFile.normals[idx[2]]};
          normalTriangles.push_back(idxNormals);
        }
      }

      objTriangles[obj] = triangles;
      objTxTriangles[obj] = txTriangles;
      objNormalTriangles[obj] = normalTriangles;
    }
  }

  void render(WindowInterface &interface, Camera camera, Scene &scene)
  {
    writeLog(__FILE__, __LINE__, "Mesh::render\n");

    for (auto it = objTriangles.begin(); it != objTriangles.end(); ++it)
    {
      OBJ obj = it->first;
      std::vector<mf> triangles = it->second;
      std::vector<mf> txTriangles = objTxTriangles[obj];
      std::vector<mf> normalTriangles = objNormalTriangles[obj];

      RenderStrategy strategy = interface.settings.getRenderStrategy();

      for (size_t i = 0; i < triangles.size(); i++)
      {
        mf triangle = triangles[i];

        mf triangleOnImagePlane = getCanvasIntersectionPoint(triangle, interface, camera);

        auto triangleMaterial = triangleMaterials.find(triangle);
        bool triangleHasMaterial = triangleMaterial != triangleMaterials.end();

        if (triangleHasMaterial)
        {
          auto material = triangleMaterials[triangle];

          if (!txTriangles.empty())
          {
            if (material.hasTexture())
            {
              mf txTriangle = txTriangles[i];
              drawTexturedTriangle(interface, triangleOnImagePlane, txTriangle, material.getTexture());
            }
          }

          drawTriangle(interface, triangleOnImagePlane, vfToColour(material.getDiffuse()), NULL);

          if (!normalTriangles.empty() && material.hasNormalMap())
          {
            // TODO
          }
        }
      }
    }
  }

  void renderList(WindowInterface &interface, std::vector<Item> items, Camera camera, Scene &scene)
  {
    writeLog(__FILE__, __LINE__, "Mesh::renderList\n");

    projMatrix = transformation.project(
        interface.settings.getFov(),
        interface.settings.getWidth() / interface.settings.getHeight(),
        interface.settings.getZNear(),
        interface.settings.getZFar());

    viewMatrix = transformation
                     .rotate(camera.getRotation())
                     /* Something about shifting the world instead of the camera means -position */
                     .translate(camera.getPosition());

    for (size_t i = 0; i < items.size(); i++)
    {
      Item item = items[i];
      modelMatrix = item.asTransformation();

      render(interface, camera, scene);

      modelMatrix = modelMatrix.identity();
    }
  }

  std::vector<OBJ> getOBJs()
  {
    return objFile.objs;
  }

  friend std::ostream &operator<<(std::ostream &os, const Mesh &mesh)
  {
    return os << "Mesh{"
              << "objs: " << mesh.objFile << ", "
              << "triangleMaterials: " << mesh.triangleMaterials << ", "
              << "}";
  }
};

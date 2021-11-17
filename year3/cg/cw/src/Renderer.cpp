#include "CGLib/all.cpp"

class GreyscaleSquare : public Environment
{

  Camera camera;
  Renderer renderer;

public:
  GreyscaleSquare()
  {
    Camera camera;
    Renderer renderer;
  }
  void init(WindowWrapper wrapper)
  {
    renderer.init(wrapper);

    Mesh mesh({}, {}, {}, {});
    Texture texture;
    Material material;

    
  }
  void update(WindowWrapper wrapper)
  {

    // ? Keyboard shenanigans
  }
  void render(WindowWrapper wrapper)
  {
    renderer.render(wrapper);
  }
  void cleanup()
  {
  }
};

int main(int argc, char *argv[])
{

  GreyscaleSquare env;
  Engine engine(&env);

  engine.run();

  return 0;
}
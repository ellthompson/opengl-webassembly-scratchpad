// graph.cpp
//

#include "graph.h"
#include <glm/glm.hpp>
#define LZZ_INLINE inline
namespace scene
{
  Graph::Graph ()
            {
      world = Model();
      Model bunny = Model("bunny.obj");
      Model teapot = Model("teapot.obj");
      teapot.setTranslate(glm::vec3(5.0f, 0.0f, 0.0f));
      teapot.setScale(glm::vec3(0.5f));
      bunny.setScale(glm::vec3(20.0f));
      world.children.push_back(bunny);
      world.children.push_back(teapot);
    }
}
namespace scene
{
  vector <glm::vec3> Graph::getSceneVertices ()
                                         {
      return world.getVertices();
    }
}
#undef LZZ_INLINE

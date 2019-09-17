// graph.h
//

#ifndef LZZ_graph_h
#define LZZ_graph_h
#include "model.h"
#define LZZ_INLINE inline
namespace scene
{
  class Graph
  {
    Model world;
  public:
    Graph ();
    vector <glm::vec3> getSceneVertices ();
  };
}
#undef LZZ_INLINE
#endif

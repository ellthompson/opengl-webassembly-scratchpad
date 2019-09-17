// model.h
//

#ifndef LZZ_model_h
#define LZZ_model_h
#include <glm/glm.hpp>
#include <iostream>
#include <vector>
using namespace std;
#define LZZ_INLINE inline
namespace scene
{
  class Model
  {
  public:
    glm::vec3 scalingFactors;
    glm::vec3 rotationFactors;
    glm::vec3 translationFactors;
    vector <glm::vec3> vertices;
    vector <Model> children;
    Model ();
    Model (std::string modelFilename);
    void setScale (glm::vec3 newScalingFactors);
    void setScale (float newScalingFactor);
    glm::mat4 getScale ();
    void setRotate (glm::vec3 newRotationFactors);
    glm::mat4 getRotate ();
    void setTranslate (glm::vec3 newTranslationFactors);
    glm::mat4 getTranslate ();
    glm::mat4 getTransform ();
    vector <glm::vec3> getVertices ();
    int loadModel (std::string filename);
  };
}
#undef LZZ_INLINE
#endif

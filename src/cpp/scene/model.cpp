// model.cpp
//

#include "model.h"
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#define LZZ_INLINE inline
using namespace std;
namespace scene
{
  Model::Model ()
            {
      scalingFactors = glm::vec3(1.0f);
      rotationFactors = glm::vec3(0.0f);
      translationFactors = glm::vec3(0.0f);
    }
}
namespace scene
{
  Model::Model (std::string modelFilename)
                                     {
      scalingFactors = glm::vec3(1.0f);
      rotationFactors = glm::vec3(0.0f);
      translationFactors = glm::vec3(0.0f);
      loadModel(modelFilename);
    }
}
namespace scene
{
  void Model::setScale (glm::vec3 newScalingFactors)
                                               {
      scalingFactors = newScalingFactors;
    }
}
namespace scene
{
  void Model::setScale (float newScalingFactor)
                                          {
      scalingFactors = glm::vec3(newScalingFactor);
    }
}
namespace scene
{
  glm::mat4 Model::getScale ()
                         {
      glm::mat4 M = glm::mat4(1.0f);
      M[0][0] = scalingFactors[0];
      M[1][1] = scalingFactors[1];
      M[2][2] = scalingFactors[2];
      return M;
    }
}
namespace scene
{
  void Model::setRotate (glm::vec3 newRotationFactors)
                                                 {
      rotationFactors = newRotationFactors;
    }
}
namespace scene
{
  glm::mat4 Model::getRotate ()
                          {
      glm::quat quaternion = glm::quat(rotationFactors);
      glm::mat4 M = glm::toMat4(quaternion);
      return M;
    }
}
namespace scene
{
  void Model::setTranslate (glm::vec3 newTranslationFactors)
                                                       {
      translationFactors = newTranslationFactors;
    }
}
namespace scene
{
  glm::mat4 Model::getTranslate ()
                             {
      glm::mat4 M = glm::mat4(1.0f);
      M[3][0] = translationFactors[0];
      M[3][1] = translationFactors[1];
      M[3][2] = translationFactors[2];
      return M;
    }
}
namespace scene
{
  glm::mat4 Model::getTransform ()
                             {
      return getTranslate() * getRotate() * getScale();
    }
}
namespace scene
{
  vector <glm::vec3> Model::getVertices ()
                                   {
      vector<glm::vec3> verticesOut;
      for (int i = 0; i < vertices.size(); i++) {
        glm::vec4 homogenousVertex = glm::vec4(vertices.at(i), 1.0f);
        glm::vec3 transformedVertex = glm::vec3(getTransform() * homogenousVertex);
        verticesOut.push_back(transformedVertex);
        // verticesOut.push_back(vertices.at(i));
      }
      for (int c = 0; c < children.size(); c++) {
        vector<glm::vec3> childVertices = children.at(c).getVertices();
        for (int i = 0; i < childVertices.size(); i++) {
          glm::vec4 homogenousVertex = glm::vec4(childVertices.at(i), 1.0f);
          glm::vec3 transformedVertex = glm::vec3(getTransform() * homogenousVertex);
          verticesOut.push_back(transformedVertex);
          // verticesOut.push_back(childVertices.at(i));
        }
      }
      return verticesOut;
    }
}
namespace scene
{
  int Model::loadModel (std::string filename)
                                        {
        vector<glm::vec3> verticesIn;
        vector<unsigned int> faces;
        FILE * file = fopen(filename.c_str(), "r");
        if( file == NULL ){
            printf("Impossible to open the file !\n");
            return false;
        }
        while( 1 ){
          char lineHeader[128];
          int res = fscanf(file, "%s", lineHeader);
          if (res == EOF) {
              break;
          }
          if ( strcmp( lineHeader, "v" ) == 0 ){
            glm::vec3 vertex;
            fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
            verticesIn.push_back(vertex);
          }
          else if ( strcmp( lineHeader, "f" ) == 0 ){
            glm::vec3 face;
            unsigned int vI1;
            unsigned int vI2;
            unsigned int vI3;
            fscanf(file, "%d %d %d\n", &vI1, &vI2, &vI3 );
            faces.push_back(vI1);
            faces.push_back(vI2);
            faces.push_back(vI3);
          }
        }

        for (int i = 0; i < faces.size(); i++) {
          vertices.push_back(verticesIn.at(faces.at(i) - 1));
        }
        return 0;
    }
}
#undef LZZ_INLINE

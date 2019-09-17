#ifndef CAMERA_H
#define CAMERA_H

#include <tuple>
#include <glm/glm.hpp>

using namespace std;

namespace projection
{
    class Camera
    {
        float zoom;
        float activeCameraXPos;
        float activeCameraYPos;
        float ratio;
      public:
        glm::vec3 position;
        float cameraXPos;
        float cameraYPos;
        Camera();
        glm::mat4 cameraTranslation;
        int canvasWidth;
        int canvasHeight;
        float getZoom();
        void setZoom(float);
        float getRatio();
        void updateScreenDimensions(int newCanvasWidth, int newCanvasHeight);
        glm::vec3 vertexWorldToCamera(glm::vec3 vertexIn);
        glm::vec3 vertexCameraToWorld(glm::vec3 vertexIn);
        glm::mat4 getMVP();
        glm::vec3 getCameraPos();
        glm::mat4 getCameraTranslation();
        glm::mat4 getProjection();
        glm::mat4 getModel();
    };
}
#endif

#include "camera.h"
#include "../config/constants.h"
#include <cmath>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace std;
using namespace config;

namespace projection
{
  Camera::Camera() {
    position = glm::vec3(0.0f, 10.0f, 10.0f);
    canvasWidth = 1280;
    canvasHeight = 720;
    zoom = 1.0f;
  }
  float Camera::getZoom() {
    return zoom;
  }
  void Camera::setZoom(float newZoom) {
    zoom = newZoom;
  }
  void Camera::updateScreenDimensions(int newCanvasWidth, int newCanvasHeight) {
    canvasWidth = newCanvasWidth;
    canvasHeight = newCanvasHeight;
    zoom = pow(2.0f, ceil(log2(WORLD_HEIGHT_PX / canvasHeight)));
  }
  glm::vec3 Camera::vertexWorldToCamera(glm::vec3 vertexIn) {
    glm::vec3 vertex = getMVP() * glm::vec4(vertexIn, 1.0f);
    return glm::vec3(vertex);
  }
  glm::vec3 Camera::vertexCameraToWorld(glm::vec3 vertexIn) {
    glm::vec3 vertex = glm::inverse(getMVP()) * glm::vec4(vertexIn, 1.0f);
    return glm::vec3(vertex);
  }
  glm::mat4 Camera::getMVP() {
    return getProjection() * getCameraTranslation() * getModel();
  }
  glm::vec3 Camera::getCameraPos() {
    return position;
  }
  glm::mat4 Camera::getCameraTranslation() {
    glm::vec3 center = glm::vec3(0.0f, 0.0f, 0.0f);
    return glm::lookAt(getCameraPos(), center, glm::vec3(0.0f, 1.0f, 0.0f));
  }
  glm::mat4 Camera::getProjection() {
    float halfCanvWidth = (canvasWidth / 2.0f) * getZoom();
    float halfCanvHeight = (canvasHeight / 2.0f) * getZoom();
    return glm::perspective(glm::radians(45.0f), (float) canvasWidth / (float)canvasHeight, 0.1f, 100.0f);
    // return glm::ortho(-halfCanvWidth, halfCanvWidth, -halfCanvHeight, halfCanvHeight, -10000.0f, 10000.0f);
  }
  glm::mat4 Camera::getModel() {
    return glm::mat4(1.0f);
  }
}

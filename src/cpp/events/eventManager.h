#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <emscripten.h>
#include <emscripten/val.h>
#include <glm/glm.hpp>
#include <glm_helpers.h>
#include <json/json.h>
#include "../scene/graph.h"
#include "../scene/model.h"

using namespace emscripten;
using namespace std;
using namespace glm;
using namespace scene;

namespace events
{
    Graph sceneGraph = Graph();
    bool sceneGraphUpdated;

    Model generateModel(Json::Value modelJson) {
      Model model = Model(modelJson["modelFilename"].asString());
      cout << modelJson["modelFilename"].asString() << endl;
      glm::vec3 scale(1.0f);
      glm::vec3 rotation(0.0f);
      glm::vec3 translation(0.0f);
      for (int i = 0; i < 3; i++) {
        scale[i] = modelJson["scale"][i].asFloat();
        rotation[i] = modelJson["rotation"][i].asFloat();
        translation[i] = modelJson["translation"][i].asFloat();
      }
      model.setScale(scale);
      model.setRotate(rotation);
      model.setTranslate(translation);
      vector<Model> children;
      for (int i = 0; i < modelJson["children"].size(); i++) {
        children.push_back(generateModel(modelJson["children"][i]));
      }
      model.children = children;
      return model;
    }

    extern "C" void EMSCRIPTEN_KEEPALIVE update_scene_graph(uint8_t* buffer) {
       Json::Value root;
       Json::Reader reader;
       std::string sceneGraphString = std::string((char *)buffer);
       bool parsingSuccessful = reader.parse(sceneGraphString, root);

       Model world = generateModel(root["world"]);
       sceneGraph.updateWorld(world);
    }
}
#endif

#include <functional>
#include <emscripten.h>
#include <emscripten/val.h>
#include <SDL.h>
#include <GLES3/gl3.h>
#include <GLES2/gl2ext.h>
#define GL_GLEXT_PROTOTYPES 1
#include <GL/glu.h>
#include <SDL_opengl.h>
#include <SDL_opengles2.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <streambuf>
#include <glm/glm.hpp>
#include <glm_helpers.h>

#include "config/constants.h"
#include "projection/camera.h"
#include "scene/graph.h"

using namespace std;
using namespace emscripten;
using namespace config;
using namespace projection;
using namespace scene;

GLchar* vertexSource = NULL;
GLchar* fragmentSource = NULL;

Camera camera = Camera();
Graph sceneGraph = Graph();

std::function<void()> loop;
void main_loop() { loop(); }

int main()
{
    std::ifstream vertexShaderFile("vertexShader.vert");
    std::string vertexShaderString((std::istreambuf_iterator<char>(vertexShaderFile)),
                      std::istreambuf_iterator<char>());
    int vertexn = vertexShaderString.length();
    char vertexCharArray[vertexn + 1];
    strcpy(vertexCharArray, vertexShaderString.c_str());
    vertexSource = vertexCharArray;

    std::ifstream fragmentShaderFile("fragmentShader.frag");
    std::string fragmentShaderString((std::istreambuf_iterator<char>(fragmentShaderFile)),
                      std::istreambuf_iterator<char>());
    int fragmentn = fragmentShaderString.length();
    char fragmentCharArray[fragmentn + 1];
    strcpy(fragmentCharArray, fragmentShaderString.c_str());
    fragmentSource = fragmentCharArray;

    SDL_Window *window;
    SDL_CreateWindowAndRenderer(1280, 720, 0, &window, nullptr);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    GLuint vbo;
    glGenBuffers(1, &vbo);

    vector<glm::vec3> vertices = sceneGraph.getSceneVertices();

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);

    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glBindAttribLocation(shaderProgram, 0, "position");
    glUseProgram(shaderProgram);

    GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
    glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), 0);
    glEnableVertexAttribArray(posAttrib);

    loop = [&]
    {
      float A = 0.01f;
      glm::mat4 M = glm::mat4(1.0);
      M[0][0] = cos(A);
      M[2][0] = sin(A);
      M[0][2] = -sin(A);
      M[2][2] = cos(A);

      camera.position = glm::vec3(M * glm::vec4(camera.position, 1.0f));

      GLuint MVPUniform = glGetUniformLocation(shaderProgram, "MVP");
      glUniformMatrix4fv(MVPUniform, 1, GL_FALSE, &camera.getMVP()[0][0]);

      glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);

      glDrawArrays(GL_TRIANGLES, 0, vertices.size());

      SDL_GL_SwapWindow(window);
    };

    main_loop();
    emscripten_set_main_loop(main_loop, 0, true);

    return EXIT_SUCCESS;
}

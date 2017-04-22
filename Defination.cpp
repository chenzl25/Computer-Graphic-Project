//
// Created by hao on 4/22/17.
//

#include "Defination.h"

const GLuint WIDTH = 800, HEIGHT = 600;

double lastX = WIDTH / 2, lastY = HEIGHT / 2;

const char objVSPath[] = "obj.vs";
const char objFragPath[] = "obj.frag";
const char lampVSPath[] = "lamp.vs";
const char lampFragPath[] = "lamp.frag";
const char wallPicPath[] = "wall.jpg";
const char skyPicPath[] = "sky.png";

Camera camera(vec3(0, 10, 3));

bool keys[1024];

const GLfloat cube[576] = {
        -0.5f, -0.5f, -0.5f, 0.0f,  0.0f, -1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 0.0f,  0.0f, -1.0f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 0.0f,  0.0f, -1.0f, 1.0f,  1.0f,
        0.5f, 0.5f, -0.5f, 0.0f,  0.0f, -1.0f, 1.0f, 1.0f,
        -0.5f, 0.5f, -0.5f, 0.0f,  0.0f, -1.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f,  0.0f, -1.0f, 0.0f, 0.0f,

        -0.5f, -0.5f, 0.5f, 0.0f,  0.0f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 0.0f,  0.0f, 1.0f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 0.0f,  0.0f, 1.0f, 1.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 0.0f,  0.0f, 1.0f, 1.0f, 1.0f,
        -0.5f, 0.5f, 0.5f, 0.0f,  0.0f, 1.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 0.0f,  0.0f, 1.0f, 0.0f, 0.0f,

        -0.5f, 0.5f, 0.5f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, -1.0f,  0.0f,  0.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f,

        0.5f, 0.5f, 0.5f,  1.0f,  0.0f,  0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f,  1.0f,  0.0f,  0.0f, 1.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f, 0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f, 0.0f, 1.0f,
        0.5f, -0.5f, 0.5f,  1.0f,  0.0f,  0.0f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.5f,  1.0f,  0.0f,  0.0f, 1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f, 1.0f, 1.0f,
        0.5f, -0.5f, 0.5f,  0.0f, -1.0f,  0.0f, 1.0f, 0.0f,
        0.5f, -0.5f, 0.5f,  0.0f, -1.0f,  0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.5f,  0.0f, -1.0f,  0.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f,

        -0.5f, 0.5f, -0.5f,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f,
        0.5f, 0.5f, -0.5f,  0.0f,  1.0f,  0.0f, 1.0f, 1.0f,
        0.5f, 0.5f, 0.5f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f,
        -0.5f, 0.5f, 0.5f,  0.0f,  1.0f,  0.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, -0.5f,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f
};

glm::vec3 cubePositions[] = {
        glm::vec3(17.5f, 7.5f, 17.5f),
        glm::vec3(17.5f, 7.5f, -17.5f),
        glm::vec3(-17.5f, 7.5f, 17.5f),
        glm::vec3(-17.5f, 7.5f, -17.5f),

        glm::vec3(30.0f, 5.0f, 24.0f),
        glm::vec3(30.0f, 5.0f, -24.0f),
        glm::vec3(-30.0f, 5.0f, 24.0f),
        glm::vec3(-30.0f, 5.0f, -24.0f),

        glm::vec3(-40.0f, 5.0f, 0.0f),
        glm::vec3(40.0f,  5.0f, 0.0f),
        glm::vec3(0.0f,  5.0f, 40.0f),
        glm::vec3(0.0f,  5.0f, -40.0f)
};

glm::vec3 cubeScales[] = {
        glm::vec3(15.0f,  15.0f, 15.0f),
        glm::vec3(15.0f,  15.0f, 15.0f),
        glm::vec3(15.0f,  15.0f, 15.0f),
        glm::vec3(15.0f,  15.0f, 15.0f),

        glm::vec3(10.0f,  10.0f, 2.0f),
        glm::vec3(10.0f,  10.0f, 2.0f),
        glm::vec3(10.0f,  10.0f, 2.0f),
        glm::vec3(10.0f,  10.0f, 2.0f),

        glm::vec3(10.0f,  10.0f, 2.0f),
        glm::vec3(10.0f,  10.0f, 2.0f),
        glm::vec3(2.0f,  10.0f, 10.0f),
        glm::vec3(2.0f,  10.0f, 10.0f)
};
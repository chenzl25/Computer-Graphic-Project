//
// Created by hao on 4/22/17.
//

#ifndef CG_PROJECT_SHADER_H
#define CG_PROJECT_SHADER_H

#include "Headers.h"

using namespace std;

class Shader {
public:
    GLuint Program;

    Shader(const GLchar* vertexPath, const GLchar* fragmentPath);

    void Use();
};


#endif //CG_PROJECT_SHADER_H

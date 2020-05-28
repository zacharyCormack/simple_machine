#pragma once
#include "shader.hpp"

class program {
    int GL_ID;
    void bind(float* points);
public:
    void draw(int GL_type,  int start, int end, float* points);
	program(shader* shaders);
	~program();
};

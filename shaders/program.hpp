#pragma once
#include "shader.hpp"

class program {
	short GL_ID;
	void bind(float* points);
public:
	void draw(short GL_type,  short start, short end, float* points);
	program(shader* shaders);
	~program();
};

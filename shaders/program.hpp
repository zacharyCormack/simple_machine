#pragma once
#include "shader.hpp"

class program {
	short GL_ID;
	void bind(float* points);
	void activate();
public:
	void (*draw)(int GL_type,  short start, short end, float* points);
	program(shader* shaders);
	~program();
};

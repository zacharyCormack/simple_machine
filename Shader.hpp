#pragma once
#include <OpenGL/OpenGL.h>
#include "glad.h"
#include <GLFW/glfw3.h>

class Shader {
private:
	char* GLSL_code;
public:
	unsigned get_GL_shader();
	Shader(const char*);
};
#pragma once
#include <OpenGL/OpenGL.h>
#include <GLFW/glfw3.h>

class Shader
{
private:
	unsigned* ID;
public:
	unsigned get_GL_shader();
	Shader(const char*, unsigned);
};
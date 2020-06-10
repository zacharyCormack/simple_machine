#include "Shader.hpp"

Shader::Shader(const char* text, unsigned type)
{
	unsigned shader;
	shader = glCreateShader(type);
	glShaderSource(shader, 1, &text, NULL);
	glCompileShader(shader);
	ID = &shader;
}

unsigned Shader::get_GL_shader()
{
	return *ID;
}
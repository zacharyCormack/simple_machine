#pragma once

class Shader {
private:
	char* GLSL_code;
public:
	unsigned get_GL_shader();
	Shader(const char*);
};
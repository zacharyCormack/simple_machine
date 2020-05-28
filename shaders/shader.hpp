#pragma once

class shader {
private:
	char* GLSL_code;
public:
	int* get_GL_shader();
	shader(char* code);
	~shader();
};
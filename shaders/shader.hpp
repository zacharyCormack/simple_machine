#pragma once

class shader {
private:
	char* GLSL_code;
public:
	short* get_GL_shader();
	shader(const char*);
	~shader();
};
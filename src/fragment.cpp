#include "Shader.hpp"

const char* fragment_shader_text =
"#version 330 core\n\
layout (location = 0) in precision lowp int col_id\n\
uniform ivec4 palette;\n\
out precision lowp ivec4 colour;\n\
void main()\n\
{\n\
	if (col_id == 0)\n\
	{\n\
		colour = palette.a;\n\
	}\n\
	else if (col_id == 1)\n\
	{\n\
		colour = palette.b;\n\
	}\n\
	else if (col_id == 2)\n\
	{\n\
		colour = palette.c;\n\
	}\n\
	else\n\
	{\n\
		colour = palette.d;\n\
	}\n\
}\0";

Shader fragment_shader(fragment_shader_text, GL_FRAGMENT_SHADER);
#include "Shader.hpp"

const char* perspective_shader_text =

"#version 330 core\n\
layout (location = 1) in dvec3 point_a;\n\
layout (location = 2) in dvec3 point_b;\n\
uniform dvec3 perspective_point;\n\
int main()\n\
{\n\
	\n\
}\0";

Shader perspective_shader(perspective_shader_text, GL_VERTEX_SHADER);
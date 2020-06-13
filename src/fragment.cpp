#include "Shader.hpp"

const char* fragment_shader_text =
R"(
"#version 330 core
layout (location = 0) in precision lowp int col_id
uniform precision lowp ivec4 palette_r;
uniform precision lowp ivec4 palette_g;
uniform precision lowp ivec4 palette_b;
out vec4 colour;
void main()
{
	if (col_id == 0)
	{
		colour = vec4(palette_r.a, palette_g.a, palette_b.a, 0);
	}
	else if (col_id == 1)
	{
		colour = vec4(palette_r.b, palette_g.b, palette_b.b, 0);
	}
	else if (col_id == 2)
	{
		colour = vec4(palette_r.c, palette_g.c, palette_b.c, 0);
	}
	else
	{
		colour = vec4(palette_r.d, palette_g.d, palette_b.d, 0);
	}
}\0)";

Shader fragment_shader(fragment_shader_text, GL_FRAGMENT_SHADER);
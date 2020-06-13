#include "Shader.hpp"

const char* rope_shader_text =
R"(
#version 330 core
void main()
{
	
}\0)";

Shader rope_shader(rope_shader_text, 0x8DD9);
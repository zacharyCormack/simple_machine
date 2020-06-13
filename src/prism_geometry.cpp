#include "Shader.hpp"

const char* prism_shader_text =
R"(
#version 330 core
void main()
{
	
}\0)";

Shader prism_shader(prism_shader_text, 0x8DD9);
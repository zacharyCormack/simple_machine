#include "Shader.hpp"

const char* ball_shader_text =
R"(
#version 330 core
void main()
{
	
}\0)";

Shader ball_shader(ball_shader_text, 0x8DD9);

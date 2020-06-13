#include "Shader.hpp"

const char* lift_shader_text = "#version 330 core\n"
R"(
#version 330 core
void main()
{
	
}\0)";

Shader lift_shader(lift_shader_text, 0x8DD9);
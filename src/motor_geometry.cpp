#include "Shader.hpp"

const char* motor_shader_text =
R"(
#version 330 core
void main()
{
	
}\0)";

Shader motor_shader(motor_shader_text, 0x8DD9);
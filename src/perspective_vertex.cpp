#include "Shader.hpp"

const char* perspective_shader_text =
R"(
#version 330 core
layout (location = 0) in dvec3 point;
uniform dvec3 perspective;
uniform dvec2 view_angle;
int main()
{
	dvec3 a = point - perspective;
	gl_Position = vec3
	(
		(atan(a.z, sqrt(a.x*a.x+a.y*a.y))-view_angle.a)/0.698132,
		(atan(a.x, a.y)-view_angle.b)*2.31766,
		-pow(a.x*a.x+a.y*a.y+a.z*a.z, 1/3)
	);
}\0)";

Shader perspective_shader(perspective_shader_text, GL_VERTEX_SHADER);
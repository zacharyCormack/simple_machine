#pragma once
#include "Shader.hpp"
#include "Program.hpp"
#include "ball_geometry.cpp"
#include "fragment.cpp"
#include "lift_geometry.cpp"
#include "motor_geometry.cpp"
#include "perspective_vertex.cpp"
#include "prism_geometry.cpp"
#include "rope_geometry.cpp"

//Shader ball_shader, fragment_shader, lift_shader, motor_shader, perspective_shader, prism_shader, rope_shader;
Shader rope_shaders[3] = {perspective_shader, rope_shader, fragment_shader};
Program draw_rope(rope_shaders, GL_TRIANGLES);
Shader motor_shaders[3] = {perspective_shader, motor_shader, fragment_shader};
Program draw_motor(motor_shaders, GL_TRIANGLES);
Shader prism_shaders[3] = {perspective_shader, prism_shader, fragment_shader};
Program draw_prism(prism_shaders, GL_TRIANGLES);
Shader lift_shaders[4] = {perspective_shader, rope_shader, lift_shader, fragment_shader};
Program draw_lift(lift_shaders, GL_TRIANGLES);
Shader ball_shaders[3] = {perspective_shader, ball_shader, fragment_shader};
Program draw_ball(ball_shaders, GL_TRIANGLES);
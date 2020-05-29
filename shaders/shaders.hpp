#pragma once
#include "shader.hpp"
#include "program.hpp"
#include "ball_geometry.cpp"
#include "fragment.cpp"
#include "lift_geometry.cpp"
#include "motor_geometry.cpp"
#include "perspective_vector.cpp"
#include "prism_geometry.cpp"
#include "rope_geometry.cpp"

shader ball_shader, fragment_shader, lift_shader, motor_shader, perspective_shader, prism_shader, rope_shader;
shader rope_shaders[3] = {perspective_shader, rope_shader, fragment_shader};
program draw_rope(rope_shaders);
shader motor_shaders[3] = {perspective_shader, motor_shader, fragment_shader};
program draw_motor(motor_shaders);
shader prism_shaders[3] = {perspective_shader, prism_shader, fragment_shader};
program draw_prism(prism_shaders);
shader lift_shaders[4] = {perspective_shader, rope_shader, lift_shader, fragment_shader};
program draw_lift(lift_shaders);
shader ball_shaders[3] = {perspective_shader, ball_shader, fragment_shader};
program draw_ball(ball_shaders);
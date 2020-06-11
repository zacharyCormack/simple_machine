#pragma once
#include "line.hpp"
#include "Component.hpp"
inline line add_lines(line, line);
inline line sub_lines(line, line);
inline angle measure(line, line);
inline double ang_to_num(angle);
inline angle num_to_ang(double);
inline line uvec(line);
inline line uvec(angle, angle);
inline line vec_mult(line, double*);
inline double* line_x_y_z(line);
inline double line_dist(line);
inline void framebuffer_size_callback(GLFWwindow*, int, int);
inline void process_input(GLFWwindow*);
inline void pan(float);
inline double* collision_detect_and_react(Component::Instance, Component::Instance);
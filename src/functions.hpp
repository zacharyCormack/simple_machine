#pragma once
#include "line.hpp"
#include "Component.hpp"
angle measure(line, line);
double ang_to_num(angle);
angle num_to_ang(double);
line uvec(line);
line uvec(angle, angle);
line vec_mult(line, double*);
double* line_x_y_z(line);
double line_dist(line);
void framebuffer_size_callback(GLFWwindow*, int, int);
void process_input(GLFWwindow*);
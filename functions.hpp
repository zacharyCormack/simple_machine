#pragma once
#include "line.hpp"
#include "Component.hpp"
angle measure(line, line);
line uvec(line);
line uvec(angle, angle);
line vec_mult(line, double*);
double* line_x_y_z(line);
double line_dist(line);
void framebuffer_size_callback(GLFWwindow*, int, int);
void processInput(GLFWwindow*);
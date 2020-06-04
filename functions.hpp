#pragma once
#include "line.hpp"
#include "Component.hpp"
angle measure(line, line);
line uvec(line);
line uvec(angle);
line vec_mult(line, double*);
double* line_dist(line);
void framebuffer_size_callback(GLFWwindow*, int, int);
void processInput(GLFWwindow*);
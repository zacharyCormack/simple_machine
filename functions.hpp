#pragma once
#include "line.hpp"
#include "Component.hpp"
angle measure(line, line);
line uvec(line);
line vec_mult(line, double*);
double* line_dist(line);
void component_draw(Component::Instance*, Program*);
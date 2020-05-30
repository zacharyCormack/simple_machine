#include "component.hpp"
#include "forces.hpp"
#include "shaders.hpp"

force forces[] = {input};
double coefficients[] = {1.0};
void move(double) {/* do nothing */};
component lift(draw_rope, forces, coefficients, &move);
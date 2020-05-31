#include "component.hpp"
#include "forces.hpp"
#include "shaders.hpp"

double coefficients[] = {0.0, 0.0, 0.0, 0.0, 1.0};
void move(component::instance* object) {/* do nothing */};
component lift(draw_motor, coefficients, &move);
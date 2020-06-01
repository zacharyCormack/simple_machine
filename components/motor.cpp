#include "Component.hpp"
#include "forces.hpp"
#include "Shaders.hpp"

double coefficients[] = {0.0, 0.0, 0.0, 0.0, 1.0};
void move(Component::Instance* object) {/* do nothing */};
Component lift(draw_motor, coefficients, &move);
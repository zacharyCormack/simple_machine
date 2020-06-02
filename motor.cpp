#include "Component.hpp"
#include "forces.hpp"
#include "shaders.hpp"

double motor_coefficients[] = {0.0, 0.0, 0.0, 0.0, 1.0};
void move(Component::Instance* object) {/* do nothing */};
Component motor(draw_motor, motor_coefficients, &move);
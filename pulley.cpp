#include "Component.hpp"
#include "forces.hpp"
#include "shaders.hpp"

double pulley_coefficients[] = {0.2, 0.0, 1.0, 0.0, 0.0};
void move_pulley(Component::Instance* object) {
	object->velocity.x[0] += object->velocity.x[1];
	object->velocity.y[0] += object->velocity.z[1];
	object->velocity.z[0] += object->velocity.z[1];
	/* do stuff to core if necessary */
};
Component pulley(draw_ball, pulley_coefficients, &move_pulley);
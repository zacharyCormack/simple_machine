#include "Component.hpp"
#include "forces.hpp"
#include "shaders.hpp"

double lift_coefficients[] = {0.0, 0.3, 1.0, 1.0, 1.0};
void move_lift(Component::Instance* object) {
	object->velocity.x[0] += object->velocity.x[1];
	object->velocity.y[0] += object->velocity.z[1];
	object->velocity.z[0] += object->velocity.z[1];
	/* do stuff to core if necessary */
};
Component lift(draw_lift, lift_coefficients, &move_lift);
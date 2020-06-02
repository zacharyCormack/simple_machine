#include "Component.hpp"
#include "forces.hpp"
#include "shaders.hpp"

double rope_coefficients[] = {0.1, 0.0, 1.0, 3.5, 0.0};
void move_rope(Component::Instance* object) {
	object->velocity.x[0] += object->velocity.x[1];
	object->velocity.y[0] += object->velocity.z[1];
	object->velocity.z[0] += object->velocity.z[1];
	/* do stuff to core if necessary */
};
Component rope(draw_rope, rope_coefficients, &move_rope);
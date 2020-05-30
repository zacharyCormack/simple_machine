#include "component.hpp"
#include "forces.hpp"
#include "shaders.hpp"

force forces[] = {tension, normal, gravity, input};
double coefficients[] = {1.0, 1.0, 0.3, 1.0};
void move_object(component::instance* object) {
	object->velocity.x[0] += object->velocity.x[1];
	object->velocity.y[0] += object->velocity.z[1];
	object->velocity.z[0] += object->velocity.z[1];
	/* do stuff to core if necessary */
};
component lift(draw_rope, forces, coefficients, &move_object);
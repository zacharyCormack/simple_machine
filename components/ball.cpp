#include "component.hpp"
#include "forces.hpp"
#include "shaders.hpp"

//friction, gravity, normal, tension, input
double coefficients[] = {1.0, 1.0, 1.0, 0.0, 0.0};
void move_object(component::instance* object) {
	object->velocity.x[0] += object->velocity.x[1];
	object->velocity.y[0] += object->velocity.z[1];
	object->velocity.z[0] += object->velocity.z[1];
	/* do stuff to core if necessary */
};
component lift(draw_ball, coefficients, &move_object);
#include "components/Component.hpp"
#include "forces.hpp"
#include "shaders.hpp"

//friction, gravity, normal, tension, input
double coefficients[] = {1.0, 1.0, 1.0, 0.0, 0.0};
void move_object(Component::Instance* object) {
	object->velocity.x[0] += object->velocity.x[1];
	object->velocity.y[0] += object->velocity.z[1];
	object->velocity.z[0] += object->velocity.z[1];
	/* do stuff to core if necessary */
};
Component ball(draw_ball, coefficients, &move_object);
#include "component.hpp"
#include "prism.hpp"
#include "program.hpp"

component::component(program draw, force* forces_to_bind, double* coefficients_to_bind, void(*react)(component::instance*)) {
	forces = forces_to_bind;
	coefficients = coefficients_to_bind;
	drawer = draw;
	move = react;
}

component::instance component::make_instance(prism base, short variation) {
	instance new_component(base, variation, this);
	return new_component;
}

component::instance::instance(prism base, short variation, component* instance_of) {
	core = base;
	variation_val = variation;
	type = instance_of;
	acting_forces = type->forces;
	velocity.x[0] = (core.core.x[0] + core.core.x[1]) / 2;
	velocity.y[0] = (core.core.y[0] + core.core.y[1]) / 2;
	velocity.z[0] = (core.core.z[0] + core.core.z[1]) / 2;
	velocity.x[1] = 0;
	velocity.y[1] = 0;
	velocity.z[1] = 0;
	for(short i = 0; i < sizeof(type->forces)/sizeof(force); i++) {
		type->forces[i].bind_object(this, *type, &ID, type->coefficients[i]);
	}
}

void component::instance::act_on(ball target) {
	for(short i = 0; i < sizeof(acting_forces) / sizeof(force); i++) {
		accelerate(acting_forces[i].exert(target, ID));
	}
}

void component::instance::iterate() {
	type->move(this);
    /* draw component */
}
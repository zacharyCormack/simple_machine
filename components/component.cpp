#include "component.hpp"
#include "prism.hpp"
#include "program.hpp"
#include "forces.hpp"
component::component(program draw, double coefficients_to_bind[5], void(*react)(component::instance*)) {
	coefficients = coefficients_to_bind;
	drawer = &draw;
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
	velocity.x[0] = (core.core.x[0] + core.core.x[1]) / 2;
	velocity.y[0] = (core.core.y[0] + core.core.y[1]) / 2;
	velocity.z[0] = (core.core.z[0] + core.core.z[1]) / 2;
	velocity.x[1] = 0;
	velocity.y[1] = 0;
	velocity.z[1] = 0;
}

void component::instance::accelerate(double* delta_v) {
    velocity.x[1] += delta_v[0];
    velocity.y[1] += delta_v[1];
    velocity.z[1] += delta_v[2];
}

void component::instance::iterate() {
	type->move(this);
	component_draw(this, type->drawer->draw);
}

force* component::forces = (force []){friction, gravity, normal, tension, input};
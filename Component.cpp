#include "Component.hpp"
#include "prism.hpp"
#include "Program.hpp"
#include "forces.hpp"
Component::Component(Program draw, double coefficients_to_bind[5], void(*react)(Component::Instance*)) {
	coefficients = coefficients_to_bind;
	drawer = &draw;
	move = react;
}

Component::Instance Component::make_Instance(prism base, short variation) {
	Instance new_Component(base, variation, this);
	return new_Component;
}

Component::Instance::Instance(prism base, short variation, Component* Instance_of) {
	core = base;
	variation_val = variation;
	type = Instance_of;
	velocity.x[0] = (core.core.x[0] + core.core.x[1]) / 2;
	velocity.y[0] = (core.core.y[0] + core.core.y[1]) / 2;
	velocity.z[0] = (core.core.z[0] + core.core.z[1]) / 2;
	velocity.x[1] = 0;
	velocity.y[1] = 0;
	velocity.z[1] = 0;
}

void Component::Instance::accelerate(double* delta_v) {
	velocity.x[1] += delta_v[0];
	velocity.y[1] += delta_v[1];
	velocity.z[1] += delta_v[2];
}

void Component::Instance::iterate() {
	type->move(this);
	component_draw(this, type->drawer);
}

Force* Component::forces = (Force []){friction, gravity, normal, tension, input};
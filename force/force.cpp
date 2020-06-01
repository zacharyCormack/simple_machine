#include "Force.hpp"

std::vector<Force*> Force::forces_ptr = {};

Force::Force(double*(*equation)(angle, double), double str) {
	calc_Force = equation;
	strength = str;
	this_Force = forces_ptr.size();
	forces_ptr.push_back(this);
}

double* Force::exert(Component::Instance actor_a, Component::Instance actor_b) {
	double* Force_exerted = (*calc_Force)(measure(actor_a.core.core, actor_b.core.core), actor_a.type->coefficients[this_Force]);
	actor_a.accelerate(line_dist(vec_mult(uvec(actor_a.core.core), Force_exerted)));
	actor_b.accelerate(line_dist(vec_mult(uvec(actor_b.core.core), Force_exerted)));
}

Force::~Force() {
	forces_ptr[forces_ptr.size()-1]->this_Force = this_Force;
	forces_ptr[this_Force] = forces_ptr[forces_ptr.size()-1];
	forces_ptr.pop_back();
}
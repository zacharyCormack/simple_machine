#include "force.hpp"

std::vector<force*> force::forces_ptr = {};

force::force(double*(*equation)(angle, double), double str) {
	calc_force = equation;
	strength = str;
	this_force = forces_ptr.size();
	forces_ptr.push_back(this);
}

double* force::exert(component::instance actor_a, component::instance actor_b) {
	double* force_exerted = (*calc_force)(measure(actor_a.core.core, actor_b.core.core), actor_a.type->coefficients[this_force]);
	actor_a.accelerate(line_dist(vec_mult(uvec(actor_a.core.core), force_exerted)));
	actor_b.accelerate(line_dist(vec_mult(uvec(actor_b.core.core), force_exerted)));
}

force::~force() {
	forces_ptr[forces_ptr.size()-1]->this_force = this_force;
	forces_ptr[this_force] = forces_ptr[forces_ptr.size()-1];
	forces_ptr.pop_back();
}
#include "Force.hpp"

Force::Force(double*(*equation)(angle, double, double))
{
	calc_force = equation;
	this_force = forces_ptr.size();
	forces_ptr.push_back(this);
}

double* Force::exert(Component::Instance actor_a, Component::Instance actor_b)
{
	double* force_exerted = (*calc_force)(
		measure(actor_a.core.core, actor_b.core.core),
		actor_a.type->coefficients[this_force],
		line_dist(add_lines(actor_a.velocity, actor_b.velocity))
	);
	return force_exerted;
}

Force::~Force()
{
	forces_ptr[forces_ptr.size()-1]->this_force = this_force;
	forces_ptr[this_force] = forces_ptr[forces_ptr.size()-1];
	forces_ptr.pop_back();
}
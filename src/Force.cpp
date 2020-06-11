#include "Force.hpp"
#include <cmath>

Force::Force(double*(*equation)(angle, double, double))
{
	calc_force = equation;
	this_force = forces_ptr.size();
	forces_ptr.push_back(this);
}

double* Force::exert(Component::Instance actor_a, Component::Instance actor_b, angle ang)
{
	double* force_exerted = (*calc_force)
	(
		ang,
		actor_a.type->coefficients[this_force]*actor_b.type->coefficients[this_force],
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
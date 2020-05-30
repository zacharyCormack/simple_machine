#include "force.hpp"
#include <cmath>

force::force(double*(*equation)(angle, double), double str) {
	calc_force = equation;
	strength = str;
}

double* force::exert(ball target, int actor_ID) {
	double* force_exerted = (*calc_force)(acts_on[actor_ID].core.rotation, coefficients_of_actors[actor_ID]);
	target.accelerate(force_exerted);
	return cbrt(force_exerted[0]*force_exerted[0] + force_exerted[1]*force_exerted[1] + force_exerted[2]*force_exerted[2]);
}

void force::bind_object(component::instance* actor, component actor_type, short* actor_ID, double coefficient) {
	acts_on.push_back(*actor);
	coefficients_of_actors.push_back(coefficient);
}
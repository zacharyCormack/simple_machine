#include "Force.hpp"

double* act_gravity(angle ang, double coefficient) {
	double force_vec[3] = {0, 0, coefficient*9.807};
	return force_vec;
};

Force gravity(act_gravity);
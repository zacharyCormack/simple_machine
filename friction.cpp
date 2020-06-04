#include "Force.hpp"

double* act_fricion(angle ang, double coefficient) {
	double force_vec[3] = {coefficient*0.5, 0, 0};
	return line_dist(vec_mult(uvec(ang), force_vec));
};

Force friction(act_fricion);
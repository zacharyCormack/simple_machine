#include "Force.hpp"

double* act_normal(angle ang, double coefficient) {
	double force_vec[3] = {coefficient*10, 0, 0};
	return line_dist(vec_mult(uvec(ang), force_vec));
};

Force normal(act_normal);
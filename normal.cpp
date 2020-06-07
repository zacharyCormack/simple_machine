#include "Force.hpp"

double* act_normal(angle ang, double coefficient) {
	double force_vec[3] = {coefficient*10, 0, 0};
	return line_x_y_x(vec_mult(uvec(ang), force_vec));
};

Force normal(act_normal);
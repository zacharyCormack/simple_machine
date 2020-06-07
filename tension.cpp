#include "Force.hpp"

double* act_tension(angle ang, double coefficient) {
	double force_vec[3] = {coefficient*3.5, 0, 0};
	return line_x_y_x(vec_mult(uvec(ang), force_vec));
};

Force tension(act_tension);
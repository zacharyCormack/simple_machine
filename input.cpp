#include "Force.hpp"

double* act(angle ang, double coefficient) {
	double force_vec[3] = {coefficient*0.5, 0, 0};
	return line_x_y_x(vec_mult(uvec(ang, (angle){(char)(0)}), force_vec));
};

Force input(act);
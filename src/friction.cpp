#include "Force.hpp"

double* act_fricion(angle ang, double coefficient) {
	double force_vec[3] = {coefficient*0.5, 0, 0};
	return line_x_y_z(vec_mult(uvec(ang,  (angle){(char)(0)}), force_vec));
};

Force friction(act_fricion);
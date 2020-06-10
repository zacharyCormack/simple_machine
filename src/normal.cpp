#include "Force.hpp"

double* act_normal(angle ang, double coefficient, double velocity)
{
	double force_vec[] = {std::numeric_limits<double>::max(), 0, 0, 0};
	return line_x_y_z(vec_mult(uvec(ang, (angle){(char)(0)}), force_vec));
};

Force normal(act_normal);
#include "Force.hpp"

double* act(angle ang, double coefficient, double velocity)
{
	double force_vec[] = {coefficient*0.5, 0, 0, std::numeric_limits<double>::min()};
	return line_x_y_z(vec_mult(uvec(ang, (angle){(char)(0)}), force_vec));
};

Force input(act);
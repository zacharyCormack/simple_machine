#include "Force.hpp"

double* act_gravity(angle ang, double coefficient, double velocity)
{
	double force_vec[] = {0, 0, coefficient*9.807, __DBL_MIN__};
	return force_vec;
};

Force gravity(act_gravity);
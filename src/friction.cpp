#include "Force.hpp"

double* act_fricion(angle ang, double coefficient, double velocity)
{
	double force_vec[] = {coefficient*0.5*(velocity>0 ? velocity+1 : velocity-1), 0, 0, 0};
	return line_x_y_z(vec_mult(uvec(ang,  (angle){(char)(0)}), force_vec));
};

Force friction(act_fricion);
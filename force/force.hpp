#pragma once
#include "component.hpp"
#include "ball.hpp"
#include "angle.hpp"
#include <vector>

class force {
	double strength;
	double*(*calc_force)(angle, double);
	std::vector<component::instance> acts_on;
	std::vector<double> coefficients_of_actors;
public:
	double* exert(ball, int);
	void bind_object(component::instance*, component, short*, double);//0 on success
	force(double*(*equation)(angle, double), double);
};

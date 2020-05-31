#pragma once
#include "component.hpp"
#include "angle.hpp"
#include "functions.hpp"
#include <vector>

class force {
	double strength;
	double*(*calc_force)(angle, double);
	static std::vector<force*> forces_ptr;
	int this_force;
public:
	double* exert(component::instance, component::instance);
	void bind_object(component::instance*, component, short*, double);
	force(double*(*equation)(angle, double), double);
	~force();
};

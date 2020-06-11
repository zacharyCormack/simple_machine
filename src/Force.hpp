#pragma once
#include "Component.hpp"
#include "angle.hpp"
#include <vector>

class Force
{
	double*(*calc_force)(angle, double, double);
	int this_force;
public:
	static std::vector<Force*> forces_ptr;
	double* exert(Component::Instance, Component::Instance, angle);
	void bind_object(Component::Instance*, Component, short*, double);
	Force(double*(*)(angle, double, double));
	~Force();
};
#include "functions.hpp"
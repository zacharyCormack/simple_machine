#pragma once
#include "Component.hpp"
#include "angle.hpp"
#include <vector>

class Force
{
	double*(*calc_force)(angle, double, double);
	static std::vector<Force*> forces_ptr;
	int this_force;
public:
	double* exert(Component::Instance, Component::Instance);
	void bind_object(Component::Instance*, Component, short*, double);
	Force(double*(*)(angle, double, double));
	~Force();
};
#include "functions.hpp"
#pragma once
#include "Component.hpp"
#include "angle.hpp"
#include <vector>

class Force {
	double*(*calc_Force)(angle, double);
	static std::vector<Force*> forces_ptr;
	int this_Force;
public:
	double* exert(Component::Instance, Component::Instance);
	void bind_object(Component::Instance*, Component, short*, double);
	Force(double*(*equation)(angle, double));
	~Force();
};
#include "functions.hpp"
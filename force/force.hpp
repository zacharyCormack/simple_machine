#pragma once
#include "component.hpp"
#include "ball.hpp"
#include "angle.hpp"

class force {
	double strength;
	double*(*calc_force)(angle direction, int coefficient);
	component::component_type* acts_on;
public:
	int exert(ball target, int actor_ID);
	void bind_object(component::component_type actor, component actor_type, int* actor_ID, int coefficient);//0 on success
	force(double*(*equation)(angle, int), double str);
};

#pragma once
#include "component.hpp"
#include "component_instance.hpp"
#include "ball.hpp"
#include "angle.hpp"

class force {
	double strength;
	int(calculate)(angle direction, int coefficient);
public:
	void exert(ball target, int actor_ID);
	void bind(component_instance actor, int* actor_ID);
	force(void(exert_method)(component_instance, component_instance), component* type_a, component* type_b);
	~force();
};

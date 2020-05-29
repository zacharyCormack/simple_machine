#pragma once
#include "prism.hpp"
#include "program.hpp"
#include "force.hpp"

class component {
	program drawer;
	void(*receive_force)(int);
public:
	class component_type {
		int variation_val;
		force* acting_forces;
		int ID;
	public:
		component* type;
		struct prism core;
		void act_on(ball target);
		component_type(prism base, int variation, component component_type);
	};
	int* coefficients;
	force* forces;
	component_type make_instance(prism base, int variation);
	component(program draw, force* forces_to_bind, int* coefficients_to_bind, void(*react)(int));
};
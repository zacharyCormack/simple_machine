#pragma once
#include "prism.hpp"
#include "program.hpp"
#include "force.hpp"

class component {
public:
	class instance {
		short variation_val;
		short ID;
		force* acting_forces;
		void accelerate(double*);
	public:
		component* type;
		struct prism core;
		line velocity;
		void act_on(ball);
		void iterate();
		instance(prism, short, component*);
	};
	double* coefficients;
	force* forces;
	instance make_instance(prism, short);
	component(program, force*, double*, void(*)(instance*));
private:
	void(*move)(instance*);
	program drawer;
};
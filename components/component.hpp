#pragma once
#include "prism.hpp"
#include "program.hpp"
#include "force.hpp"

class component {
public:
	class instance {
		short variation_val;
	public:
		component* type;
		prism core;
		line velocity;
		void iterate();
		void accelerate(double*);
		instance(prism, short, component*);
	};
	double* coefficients;
	static force* forces;
	instance make_instance(prism, short);
	component(program, double*, void(*)(instance*));
private:
	void(*move)(instance*);
	program* drawer;
};
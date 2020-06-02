#pragma once
#include "prism.hpp"
#include "Program.hpp"
#include "Force.hpp"

class Component {
public:
	class Instance {
		short variation_val;
	public:
		Component* type;
		prism core;
		line velocity;
		void iterate();
		void accelerate(double*);
		Instance(prism, short, Component*);
	};
	double* coefficients;
	static Force* forces;
	Instance make_Instance(prism, short);
	Component(Program, double*, void(*)(Instance*));
private:
	void(*move)(Instance*);
	Program* drawer;
};
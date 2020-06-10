#pragma once
#include "prism.hpp"
#include "Program.hpp"
#include <OpenGL/OpenGL.h>

class Component
{
public:
	class Instance
	{
		unsigned VBO;
		unsigned VAO;
	public:
		Component* type;
		prism core;
		line velocity;
		void iterate();
		void accelerate(double*);
		Instance(prism, Component*);
	};
	double* coefficients;
	Component(Program, double [5], void(*)(Instance*), void(*)(prism), unsigned short*);
private:
	void(*move)(Instance*);
	void(*bind_points)(prism);
	Program* drawer;
	unsigned EBO;
};
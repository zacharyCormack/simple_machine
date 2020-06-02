#pragma once
#include "Force.hpp"
#include "Program.hpp"
#include "Component.hpp"
#include <vector>

class Machine {
	double perspective_point[3];
	std::vector<Component::Instance> components;
public:
	void draw();
	void iterate();
	void pan(double [3]);
	void bind(Component::Instance);
	Machine(double [3]);
};
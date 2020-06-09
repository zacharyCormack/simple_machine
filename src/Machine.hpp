#pragma once
#include "Force.hpp"
#include "Program.hpp"
#include "Component.hpp"
#include <vector>

class Machine {
	double perspective_point[3];
	std::vector<Component::Instance> components;
	std::vector<float> colour_scheme;
public:
	void draw();
	void iterate();
	void pan(double [3]);
	void add(Component::Instance);
	void bind();
	Machine(double [3], std::vector<float>);
};
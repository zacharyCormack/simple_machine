#pragma once
#include "prism.hpp"
#include "shader.hpp"

class component {
	class component_type {
		prism core;
		shader drawer;
		int variation;
	public:
		component_type(prism base, int special_val);
	};
public:
	component();
	~component();
};

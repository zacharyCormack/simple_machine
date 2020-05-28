#pragma once
#include "component.hpp"
#include "force.hpp"

class component_instance {
	component type;
	force* forces;
public:
	void act_on(ball target);
	component_instance(component component_type, void(*bind_type)(char* args));
	~component_instance();
};

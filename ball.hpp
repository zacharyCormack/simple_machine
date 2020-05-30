#pragma once
#include "line.hpp"

class ball {
	line motion;
	static short size;
public:
	void draw();
	void checkforce(component::instance item, force potential_force);
	void accelerate(double delta_v[3]);
	ball(short start_x, short start_y, short start_z);
	~ball();
};

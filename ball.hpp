#pragma once
#include "line.hpp"

class ball {
    line motion;
    static int size;
public:
    void draw();
    void checkforce(component::component_type item, force potential_force);
    void accelerate(double delta_v[3]);
	ball(int start_x, int start_y, int start_z);
	~ball();
};

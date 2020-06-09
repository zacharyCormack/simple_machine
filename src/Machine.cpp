#include "Machine.hpp"

Machine::Machine(double start_perspective[3], std::vector<float> colours) {
	perspective_point[0] = start_perspective[0];
	perspective_point[1] = start_perspective[1];
	perspective_point[2] = start_perspective[2];
    colour_scheme = colours;
}

void Machine::add(Component::Instance new_component) {
	components.push_back(new_component);
}

void Machine::iterate() {
	for(unsigned short int i = 0; i < components.size(); i++) {
		/* do force calculations */
	}
}

void Machine::draw() {
	for(unsigned short int i = 0; i < components.size(); i++) {
		/* draw components */
	}
}

void Machine::pan(double new_perspective[3]) {
	/* set this machine's perspective points */
    bind();
}

void Machine::bind() {
    /* tell shaders to use this machine's perspective, colour scheme, etc. */
}
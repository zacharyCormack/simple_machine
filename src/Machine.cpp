#include "Machine.hpp"

Machine::Machine(double start_perspective[3], std::vector<int> colours)
{
	perspective_point[0] = start_perspective[0];
	perspective_point[1] = start_perspective[1];
	perspective_point[2] = start_perspective[2];
	colour_scheme = colours;
}

void Machine::add(Component::Instance new_component)
{
	components.push_back(new_component);
}

void Machine::iterate()
{
	for (unsigned short i = 0; i < components.size(); i++)
	{
		prism core_i = components[i].core;
		for (unsigned short j = 0; j < components.size(); j++)
		{
			if (i!=j)
			{
				double* force_to_push = collision_detect_and_react(components[i], components[j]);
				components[i].accelerate(force_to_push);
				components[j].accelerate(force_to_push);
			}
		}
	}
}

void Machine::draw()
{
	for (unsigned short i = 0; i < components.size(); i++)
	{
		/* draw components */
	}
}

void Machine::pan(double new_perspective[3])
{
	perspective_point[0] = new_perspective[0];
	perspective_point[1] = new_perspective[1];
	perspective_point[2] = new_perspective[2];
	bind();
}

void Machine::bind()
{
	/* tell shaders to use this machine's perspective, colour scheme, etc. */
}
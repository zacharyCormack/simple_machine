#include "Component.hpp"
#include "forces.hpp"
#include "shaders.hpp"
#include <cmath>

double rope_coefficients[] = {0.1, 0.15, 1.0, 3.5, 0.0};

void move_rope(Component::Instance* object)
{
	object->velocity.x[0] += object->velocity.x[1]/0.15;
	object->velocity.y[0] += object->velocity.y[1]/0.15;
	object->velocity.z[0] += object->velocity.z[1]/0.15;
	object->core.thickness[1] -= object->velocity.z[1]/0.4;
	object->core.rotation = num_to_ang(ang_to_num(object->core.rotation) -
	sqrt((object->velocity.x[1]) * (object->velocity.x[1]) + (object->velocity.y[1]) * (object->velocity.y[1])) / 0.4);
};

void bind_rope_points(prism core)
{
	const unsigned short size = 6;
	float vertices[size] =
{
		core.core.x[0],
		core.core.y[0],
		core.core.z[0],
		core.thickness[1],
		ang_to_num(core.rotation),
		3
	};
	glBufferData(GL_ARRAY_BUFFER, sizeof(float), &vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 13, (void*)0);
	glEnableVertexAttribArray(0);
}

unsigned short rope_indices[] =
{
	0, 1, 2,
	3, 2, 4,
	0, 1, 5
};

Component rope(draw_rope, rope_coefficients, &move_rope, &bind_rope_points, rope_indices);
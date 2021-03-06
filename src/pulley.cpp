#include "Component.hpp"
#include "forces.hpp"
#include "shaders.hpp"
#include <cmath>

double pulley_coefficients[] = {0.2, 0.4, 1.0, 0.0, 0.0};

void move_pulley(Component::Instance* object)
{
	object->velocity.x[0] += object->velocity.x[1]/0.4;
	object->velocity.y[0] += object->velocity.y[1]/0.4;
	object->velocity.z[0] += object->velocity.z[1]/0.4;
	object->core.rotation = num_to_ang(ang_to_num(object->core.rotation) + (1)/object->core.thickness[0]);
};

void bind_pulley_points(prism core)
{
	const unsigned short size = 9;
	float vertices[size] =
{
		core.core.x[0], core.core.y[0], core.core.z[0],
		core.core.x[1], core.core.y[1], core.core.z[1],
		core.thickness[0], ang_to_num(core.rotation), 2
	};
	glBufferData(GL_ARRAY_BUFFER, sizeof(float), &vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 13, (void*)0);
	glEnableVertexAttribArray(0);
}

unsigned short pulley_indices[] =
{
	0, 1, 2, 6, 7, 8,
	3, 4, 5, 6, 7, 8
};

Component pulley(draw_ball, pulley_coefficients, &move_pulley, &bind_pulley_points, pulley_indices);
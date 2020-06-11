#include "Component.hpp"
#include "forces.hpp"
#include "shaders.hpp"

double lift_coefficients[] = {0.0, 0.3, 1.0, 1.0, 1.0};

void move_lift(Component::Instance* object)
{
	object->velocity.x[0] += object->velocity.x[1]/0.3;
	object->velocity.y[0] += object->velocity.z[1]/0.3;
	object->velocity.z[0] += object->velocity.z[1]/0.3;
	/* do stuff to core if necessary */
};

void bind_lift_points(prism core)
{
	const unsigned short size = 9;
	float vertices[size] =
	{
		core.core.x[0],
		core.core.y[0],
		core.core.z[0],
		core.core.x[1],
		core.core.y[1],
		core.core.z[1],
		core.thickness[1],
		ang_to_num(core.rotation),
		3
	};
	glBufferData(GL_ARRAY_BUFFER, sizeof(float), &vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 13, (void*)0);
	glEnableVertexAttribArray(0);
}

unsigned short lift_indices[] =
{
	8,
	0, 1, 2, 3, 4, 5,
	6, 7,
	0, 1
};

Component lift(draw_lift, lift_coefficients, &move_lift, &bind_lift_points, lift_indices);
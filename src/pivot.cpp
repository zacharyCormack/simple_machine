#include "Component.hpp"
#include "forces.hpp"
#include "shaders.hpp"

double pivot_coefficients[] = {0.0, 1.0, 1.0, 0.0, 0.0};

void move_pivot(Component::Instance* object)
{
	object->velocity.x[0] += object->velocity.x[1];
	object->velocity.y[0] += object->velocity.z[1];
	object->velocity.z[0] += object->velocity.z[1];
	/* do stuff to core if necessary */
};

void bind_pivot_points(prism core)
{
	const unsigned short size = 0;
	/* make size something other than 0 */
	float vertices[size];
	/* decide points somehow */
	glBufferData(GL_ARRAY_BUFFER, sizeof(float), &vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 13, (void*)0);
	glEnableVertexAttribArray(0);
}

unsigned short pivot_indices[] =
{
	/* put indices here */
};
Component pivot(draw_prism, pivot_coefficients, &move_pivot, &bind_pivot_points, pivot_indices);
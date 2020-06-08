#include "Component.hpp"
#include "forces.hpp"
#include "shaders.hpp"

double rope_coefficients[] = {0.1, 0.15, 1.0, 3.5, 0.0};

void move_rope(Component::Instance* object) {
	object->velocity.x[0] += object->velocity.x[1]/0.15;
	object->velocity.y[0] += object->velocity.y[1]/0.15;
	object->velocity.z[0] += object->velocity.z[1]/0.15;
	/* do stuff to core if necessary */
};

void bind_rope_points(prism core) {
	const unsigned short int size = 0;
	/* make size something other than 0 */
	float vertices[size];
	/* decide points somehow */
	glBufferData(GL_ARRAY_BUFFER, sizeof(float), &vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 13, (void*)0);
	glEnableVertexAttribArray(0);
}

unsigned short rope_indices[] = {
	/* put indices here */
};

Component rope(draw_rope, rope_coefficients, &move_rope, &bind_rope_points, rope_indices);
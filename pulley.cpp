#include "Component.hpp"
#include "forces.hpp"
#include "shaders.hpp"

double pulley_coefficients[] = {0.2, 0.4, 1.0, 0.0, 0.0};

void move_pulley(Component::Instance* object) {
	object->velocity.x[0] += object->velocity.x[1]/0.4;
	object->velocity.y[0] += object->velocity.z[1]/0.4;
	object->velocity.z[0] += object->velocity.z[1]/0.4;
	/* do stuff to core if necessary */
};

void bind_pulley_points(prism core) {
	const unsigned short int size = 0;
	/* make size something other than 0 */
	float vertices[size];
	/* decide points somehow */
	glBufferData(GL_ARRAY_BUFFER, sizeof(float), &vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 13, (void*)0);
	glEnableVertexAttribArray(0);
}

unsigned short pulley_indices[] = {
	/* put indices here */
};

Component pulley(draw_ball, pulley_coefficients, &move_pulley, &bind_pulley_points, pulley_indices);
#include "Component.hpp"
#include "forces.hpp"
#include "shaders.hpp"

double lift_coefficients[] = {0.0, 0.3, 1.0, 1.0, 1.0};

void move_lift(Component::Instance* object) {
	object->velocity.x[0] += object->velocity.x[1]/0.3;
	object->velocity.y[0] += object->velocity.z[1]/0.3;
	object->velocity.z[0] += object->velocity.z[1]/0.3;
	/* do stuff to core if necessary */
};

void bind_lift_points(prism core) {
	const unsigned short int size = 0;
	/* make size something other than 0 */
	float vertices[size];
	/* decide points somehow */
	glBufferData(GL_ARRAY_BUFFER, sizeof(float), &vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 13, (void*)0);
	glEnableVertexAttribArray(0);
}

unsigned short lift_indices[] = {
	/* put indices here */
};

Component lift(draw_lift, lift_coefficients, &move_lift, &bind_lift_points, lift_indices);
#include "Component.hpp"
#include "forces.hpp"
#include "shaders.hpp"

//friction, gravity, normal, tension, input
double ball_coefficients[] = {1.0, 1.0, 1.0, 0.0, 0.0};

void move_ball(Component::Instance* object) {
	object->velocity.x[0] += object->velocity.x[1];
	object->velocity.y[0] += object->velocity.z[1];
	object->velocity.z[0] += object->velocity.z[1];
	/* do stuff to core if necessary */
};

void bind_ball_points(prism core) {
	const unsigned short int size = 4;
	float vertices[size*3] = {
		core.core.x[0], core.core.y[0], core.core.z[0], line_dist(core.core)
	};
	glBufferData(GL_ARRAY_BUFFER, sizeof(float), &vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 13, (void*)0);
	glEnableVertexAttribArray(0);
}

unsigned short ball_indices[] = {
	/* put indices here */
};

Component ball(draw_ball, ball_coefficients, &move_ball, &bind_ball_points, ball_indices);
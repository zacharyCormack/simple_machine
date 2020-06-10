#include "Component.hpp"
#include "forces.hpp"
#include "shaders.hpp"

double motor_coefficients[] = {0.0, 0.0, 0.0, 0.0, 1.0};

void move_motor(Component::Instance* object) {/* do nothing */};

void bind_motor_points(prism core)
{
	const unsigned short size = 0;
	/* make size something other than 0 */
	float vertices[size];
	/* decide points somehow */
	glBufferData(GL_ARRAY_BUFFER, sizeof(float), &vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 13, (void*)0);
	glEnableVertexAttribArray(0);
}

unsigned short motor_indices[] =
{
	/* put indices here */
};

Component motor(draw_motor, motor_coefficients, &move_motor, &bind_motor_points, motor_indices);
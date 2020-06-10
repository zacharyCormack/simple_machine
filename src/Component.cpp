#include "Component.hpp"
#include "functions.hpp"
Component::Component(Program draw, double coefficients_to_bind[5], void(*react)(Component::Instance*), void(*bind_vertices)(prism), unsigned short* indices)
{
	coefficients = coefficients_to_bind;
	drawer = &draw;
	move = react;
	bind_points = bind_vertices;
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 13, (void*)12);
}

Component::Instance::Instance(prism base, Component* Instance_of)
{
	core = base;
	type = Instance_of;
	velocity.x[0] = (core.core.x[0] + core.core.x[1]) / 2;
	velocity.y[0] = (core.core.y[0] + core.core.y[1]) / 2;
	velocity.z[0] = (core.core.z[0] + core.core.z[1]) / 2;
	velocity.x[1] = 0;
	velocity.y[1] = 0;
	velocity.z[1] = 0;
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &VAO);
}

void Component::Instance::accelerate(double* delta_v)
{
	velocity.x[1] += delta_v[0];
	velocity.y[1] += delta_v[1];
	velocity.z[1] += delta_v[2];
}

void Component::Instance::iterate()
{
	(*(type->move))(this);
	(*(type->bind_points))(core);
	type->drawer->draw(VAO, VBO, type->EBO);
}

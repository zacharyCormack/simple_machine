#include "Program.hpp"

Program::Program(Shader* shaders, int draw_type)
{
	type = draw_type;
	unsigned program_ID = glCreateProgram();
	for(unsigned short i = 0; i < sizeof(shaders)/sizeof(Shader); i++)
{
		glAttachShader(program_ID, shaders[i].get_GL_shader());
	}
	glLinkProgram(program_ID);
	ID = program_ID;
}

void Program::draw(unsigned VAO, unsigned VBO, unsigned EBO)
{
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
}

void Program::activate()
{
	glUseProgram(ID);
}
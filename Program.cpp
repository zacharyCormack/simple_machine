#include "Program.hpp"

Program::Program(Shader* shaders, int draw_type) {
	type = draw_type;
	unsigned* program_ID;
	/* do OpenGL stuff */
	ID = *program_ID;
}

void Program::draw(unsigned VAO, unsigned VBO, unsigned EBO) {
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
}

void Program::activate() {
	/* do OpenGL stuff */
}
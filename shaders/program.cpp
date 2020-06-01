#include "Program.hpp"

Program::Program(Shader* shaders, int draw_type) {
    type = draw_type;
    unsigned* program_ID;
    /* do OpenGL stuff */
    ID = *program_ID;
}

void Program::draw(float* points) {
    bind(points);
    /* do OpenGL stuff */
}

void Program::bind(float* points) {
    unsigned VAO, VBO, EBO;
    /* do OpenGL stuff */
}

void Program::activate() {
    /* do OpenGL stuff */
}
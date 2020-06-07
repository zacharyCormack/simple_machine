#include "functions.hpp"

angle measure(line a, line b) {
	
}

line uvec(line vec) {

}

line uvec(angle vecx, angle vecy) {

}

/*
 * mag[0] is magnitude in direction of vector, 
 * mag[1, 2] are perpendicular
 */
line vec_mult(line vec, double* mag) {

}

double* line_x_y_x(line dist) {
	
}

double line_dist(line dist) {
	
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}
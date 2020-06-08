#include "functions.hpp"
#include <cmath>

angle measure(line a, line b) {
	
}

line uvec(line vec) {
	double len = line_dist(vec);
	vec.x[1] = (vec.x[1] - vec.x[0]) / len;
	vec.y[1] = (vec.y[1] - vec.y[0]) / len;
	vec.z[1] = (vec.z[1] - vec.z[0]) / len;
	vec.x[0] = 0;
	vec.y[0] = 0;
	vec.z[0] = 0;
}

line uvec(angle vecx, angle vecy) {

}

/*
 * mag[0] is magnitude in direction of vector, 
 * mag[1, 2] are perpendicular
 */
line vec_mult(line vec, double* mag) {

}

double* line_x_y_z(line dist) {
	return (double []){
		dist.x[1] - dist.x[0],
		dist.y[1] - dist.y[0],
		dist.z[1] - dist.z[0]
	};
}

double line_dist(line dist) {
	return cbrt(
		(dist.x[0]-dist.x[1]) * (dist.x[0]-dist.x[1]) +
		(dist.y[0]-dist.y[1]) * (dist.y[0]-dist.y[1]) +
		(dist.z[0]-dist.z[1]) * (dist.z[0]-dist.z[1])
	);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}
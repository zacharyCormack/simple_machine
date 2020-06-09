#include "functions.hpp"
#include <cmath>

angle measure(line a, line b) {
	angle angle_a_z = num_to_ang(atan((a.z[1]-a.z[0]) / sqrt(a.x[1]-a.x[0])*(a.x[1]-a.x[0]) + (a.y[1]-a.y[0])*(a.y[1]-a.y[0])));
	angle angle_a = num_to_ang(atan(sqrt((a.y[1]-a.y[0])*(a.y[1]-a.y[0]) + (a.z[1]-a.z[0])*(a.z[1]-a.z[0])) / (a.x[1]-a.x[0])));
	angle angle_b_z = num_to_ang(atan((b.z[1]-b.z[0]) / sqrt(b.x[1]-b.x[0])*(b.x[1]-b.x[0]) + (b.y[1]-b.y[0])*(b.y[1]-b.y[0])));
	angle angle_b = num_to_ang(atan(sqrt((b.y[1]-b.y[0])*(b.y[1]-a.y[0]) + (b.z[1]-b.z[0])*(b.z[1]-b.z[0])) / (b.x[1]-b.x[0])));
	return num_to_ang(ang_to_num(angle_a) - acos(sqrt(
		cos(ang_to_num(angle_b)) * cos(ang_to_num(angle_b)) +
		cos(ang_to_num(angle_a_z)+ang_to_num(angle_b_z)) * cos(ang_to_num(angle_a_z)+ang_to_num(angle_b_z))
	)));
}

double ang_to_num(angle ang) {
	return (ang.portion / (char)255) * 2 * M_PI;
}

angle num_to_ang(double num) {
	a:
	if(num > 2*M_PI) {
		num -= 2*M_PI;
		goto a;
	}
	else if(num < 0) {
		num += 2*M_PI;
		goto a;
	}
	return (angle){(char)floor(num*256)};
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

line uvec(angle vecxy, angle vecz) {
	return (line){
		.x = {0, cos(ang_to_num(vecxy))*cos(ang_to_num(vecz))},
		.y = {0, sin(ang_to_num(vecxy))*cos(ang_to_num(vecz))},
		.z = {0, sin(ang_to_num(vecxy))}
	};
}


//mag[0] is magnitude in direction of vector, mag[1, 2] are perpendicular
line vec_mult(line vec, double* mag) {
	return (line){
		.x = {vec.x[0]*mag[0] - vec.y[0]*mag[1] - vec.z[0]*mag[2], vec.x[1]*mag[0] - vec.y[1]*mag[1] - vec.z[1]*mag[2]},
		.y = {vec.x[0]*mag[1] + vec.y[0]*mag[0] + vec.z[0]*mag[1], vec.x[1]*mag[1] + vec.y[1]*mag[0] + vec.z[1]*mag[1]},
		.z = {vec.x[0]*mag[2] + vec.y[0]*mag[2] + vec.z[0]*mag[0], vec.x[1]*mag[2] + vec.y[1]*mag[2] + vec.z[1]*mag[0]}
	};
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

void process_input(GLFWwindow* window) {
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}
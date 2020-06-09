#include "forces.hpp"
#include "components.hpp"
#include "shaders.hpp"
#include "Machine.hpp"
#include "functions.hpp"

int main() {
	/* initiate OpenGL */
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	#endif
	GLFWwindow* window = glfwCreateWindow(800, 600, "MACHINE", NULL, NULL);
	if (window == NULL)
	{
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	/* make objects */
	Machine machine((double [3]){0, 0, 0}, (std::vector<float>){0});
	/* bind objects */
	bool window_should_close = false;
	while(!glfwWindowShouldClose(window)) {
		machine.iterate();
		/* potentially, pan */
		machine.draw();
		/* check if window should close */
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
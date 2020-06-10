#include "forces.hpp"
#include "components.hpp"
#include "shaders.hpp"
#include "Machine.hpp"
#include "functions.hpp"
#include <chrono>

int main()
{
	auto start_time = std::chrono::high_resolution_clock::now();
	auto current_time = std::chrono::high_resolution_clock::now();
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	#endif
	GLFWwindow* window = glfwCreateWindow(800, 600, "MACHINE", NULL, NULL);
	if(window == NULL)
	{
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	/* make objects */
	std::vector<int> colour_palette;
	colour_palette.push_back(0xFF0000FF);
	colour_palette.push_back(0x964B00FF);
	colour_palette.push_back(0x2F2F2FFF);
	colour_palette.push_back(0xD2B48CFF);
	Machine machine((double [3]){0, 0, 0}, colour_palette);
	/* bind objects */
	bool window_should_close = false;
	while(!glfwWindowShouldClose(window))
{
		process_input(window);

		machine.iterate();
		pan(std::chrono::duration_cast<std::chrono::duration<float> >(current_time - start_time).count());
		machine.draw();
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
#include "Renderer.h"
#include "Matikka.h"
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
	{
		num += 1;
		if (num > 3)
			num = 0;
	}
	GLfloat cameraSpeed = 0.025f;
	if (key == GLFW_KEY_W)
		cam_pos += cameraSpeed * cam_up; 
	if (key == GLFW_KEY_S)
		cam_pos -= cameraSpeed * cam_up;
	if (key == GLFW_KEY_A)
		cam_pos -=glm::normalize(glm::cross(cam_front, cam_up)) * cameraSpeed;
	if (key == GLFW_KEY_D)
		cam_pos +=glm::normalize(glm::cross(cam_front, cam_up)) * cameraSpeed;

}
int main(int argc, char* argv[])
{
	if (Init() != 0)
		return error_code;
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

	glfwSetKeyCallback(window, key_callback);
	
	while (!glfwWindowShouldClose(window))
	{
		Render();
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
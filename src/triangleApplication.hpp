#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>

class TriangleApplication {
public:
	void run();

private:
	GLFWwindow* window;
	VkInstance instance;

	void initWindow();

	void initVulkan();

	void createInstance();

	bool checkValidationLayerSupport();
	void mainLoop();
	void cleanup();



};
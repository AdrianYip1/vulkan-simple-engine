#include "tut_window.hpp"

namespace tut {

	TutWindow::TutWindow(int w, int h, std::string name) : width{ w }, height{ h }, windowName{ name } {
		initWindow();
	}

	TutWindow::~TutWindow() {
		glfwDestroyWindow(window);
		glfwTerminate();

	}
	void TutWindow::initWindow() {
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // to disable openGL
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // to disable resizing

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
	}

} //namespace tut
#include "first_app.hpp"

namespace tut {

void FirstApp::run() {
	while (!tutWindow.shouldClose()) {
		glfwPollEvents();
	}
}
} //namespace tut
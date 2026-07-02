#pragma once

#include "tut_window.hpp"

namespace tut {
class FirstApp {

public:
	static constexpr int WIDTH = 800;
	static constexpr int HEIGHT = 600;

	void run();

private:
	TutWindow tutWindow{ WIDTH, HEIGHT, "Vulkan Window" };

};
}
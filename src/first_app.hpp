#pragma once

#include "tut_window.hpp"
#include "tut_pipeline.hpp"
#include "tut_device.hpp"

namespace tut {
	class FirstApp {

	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		void run();

	private:
		TutWindow tutWindow{ WIDTH, HEIGHT, "Vulkan Window" };
		TutDevice tutDevice{ tutWindow };
		TutPipeline tutPipeline{ tutDevice, "shaders/simple_shader.vert.spv", "shaders/simple_shader.frag.spv", TutPipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT) };
	};
}
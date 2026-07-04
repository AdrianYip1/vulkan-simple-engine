#pragma once

#include "tut_window.hpp"
#include "tut_pipeline.hpp"
#include "tut_device.hpp"
#include "tut_swap_chain.hpp"

#include <memory>
#include <vector>

namespace tut {
	class FirstApp {

	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		FirstApp();
		~FirstApp();

		FirstApp(const FirstApp&) = delete;
		FirstApp& operator=(const FirstApp&) = delete;
		void run();

	private:
		void createPipelineLayout();
		void createPipeline();
		void createCommandBuffers();
		void drawFrame();


		TutWindow tutWindow{ WIDTH, HEIGHT, "Vulkan Window" };
		TutDevice tutDevice{ tutWindow };
		TutSwapChain tutSwapChain{ tutDevice, tutWindow.getExtent()};
		std::unique_ptr<TutPipeline> tutPipeline;
		VkPipelineLayout pipelineLayout;
		std::vector<VkCommandBuffer> commandBuffers;
	};
}
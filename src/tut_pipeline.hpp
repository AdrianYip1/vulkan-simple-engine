#pragma once

#include <string>
#include <vector>
#include "tut_device.hpp"

namespace tut {

	struct PipelineConfigInfo {};

	class TutPipeline {
	public:
		TutPipeline(TutDevice& device,
			const std::string& vertFilepath,
			const std::string& fragFilepath,
			const PipelineConfigInfo& configInfo);
		~TutPipeline() {};

		TutPipeline(const TutPipeline&) = delete;
		void operator=(const TutPipeline&) = delete;

		static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

	private:
		static std::vector<char> readFile(const std::string& filepath);

		void createGraphicsPipeline(const std::string& vertFilepath,
			const std::string& fragFilepath,
			const PipelineConfigInfo& configInfo);

		void createShaderModule(const std::vector<char>& code,
			VkShaderModule* shaderModule);

		TutDevice& tutDevice;
		VkPipeline graphicsPipeline;
		VkShaderModule vertShaderModule;
		VkShaderModule fragShaderModule;
	};

} //namespace tut
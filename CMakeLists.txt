cmake_minimum_required(VERSION 3.15)
project(vulkanLearning VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Vulkan REQUIRED)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(external/glfw)

add_subdirectory(external/enginemath)

add_executable(vulkanLearning src/main.cpp 
"src/tut_window.cpp" 
"src/first_app.cpp" 
"src/tut_pipeline.cpp"
"src/tut_device.cpp"
"src/tut_swap_chain.cpp")

target_link_libraries(vulkanLearning PRIVATE 
	enginemath::enginemath
	Vulkan::Vulkan
	glfw)

add_custom_command(TARGET vulkanLearning POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/shaders" "$<TARGET_FILE_DIR:vulkanLearning>/shaders")


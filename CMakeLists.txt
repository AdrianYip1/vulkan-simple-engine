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

add_library(stb INTERFACE)
target_include_directories(stb INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/external/stb)

add_executable(vulkanLearning
    src/main.cpp
    src/triangleApplication.cpp
    src/triangleApplication.hpp)

target_link_libraries(vulkanLearning PRIVATE 
	enginemath::enginemath
	Vulkan::Vulkan
	glfw
    stb)

add_custom_command(TARGET vulkanLearning POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/shaders" "$<TARGET_FILE_DIR:vulkanLearning>/shaders")

add_custom_command(TARGET vulkanLearning POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/textures" "$<TARGET_FILE_DIR:vulkanLearning>/textures")


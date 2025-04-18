cmake_minimum_required(VERSION 3.12)

project(blood-marble)

add_executable(blood-marble main.cpp)

target_include_directories(blood-marble PRIVATE deps/glm
												deps/stb
												deps/glfw/include
												deps/glew/include)

target_link_directories(blood-marble PRIVATE deps/glfw/lib-vc2022
											 deps/glew/lib/release/x64)

target_link_libraries(blood-marble PRIVATE glfw3.lib
										   glew32.lib)

add_custom_command(TARGET blood-marble POST_BUILD
				  COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_SOURCE_DIR}/deps/glew/bin/Release/x64/glew32.dll" "${CMAKE_BINARY_DIR}/glew32.dll")


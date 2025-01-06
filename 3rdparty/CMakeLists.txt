set(GLFW_BUILD_WAYLAND ON)
set(GLFW_BUILD_X11 OFF)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/glfw)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/glm)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/spdlog)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/imgui)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/glad)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sdl2)

cmake_minimum_required(VERSION 3.10)

project(imgui)

# add_definitions(-DIMGUI_DISABLE)
# add_definitions(-DIMGUI_IMPL_WEBGPU_BACKEND_DAWN )
# MESSAGE(==========qwewqe==========="${GLFW_INCLUDE_DIR}/../")
add_definitions(-D_EXPORT)
add_compile_options(-fPIC)
file(GLOB ImguiSource "*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/backends/*.cpp" )

add_library(imgui STATIC ${ImguiSource})
# target_include_directories(imgui PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/backends)

target_link_libraries(imgui ${GLFW_LIB})

target_include_directories(imgui PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/backends>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

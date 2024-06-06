cmake_minimum_required(VERSION 3.26)
project(AzurEngine)
set(CMAKE_CXX_STANDARD 17)

#添加预编译宏
IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    MESSAGE( "current platform: Linux ")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    add_definitions(-DAZUR_PLATFORM_WINDOWS)
    MESSAGE( "current platform: Windows")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
    MESSAGE( "current platform: FreeBSD")
ELSE ()
    MESSAGE( "other platform: ${CMAKE_SYSTEM_NAME}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")

#设置路径变量
set(LIB_PATH ${CMAKE_BINARY_DIR}/bin)
set(EXE_PATH ${CMAKE_BINARY_DIR}/bin)
set(AZUR_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Azur)
set(Sandbox_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Sandbox)
set(LIBRARY_OUTPUT_PATH ${LIB_PATH})
set(EXECUTABLE_OUTPUT_PATH ${EXE_PATH})       #设置可执行文件的输出目录

#设置第三方库
find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
set(LINK_LIB PRIVATE glfw OpenGL::GL GLEW::GLEW glad::glad glm::glm spdlog::spdlog imgui::imgui)

add_subdirectory(${AZUR_PATH})
add_subdirectory(${Sandbox_PATH})


message(${CMAKE_BUILD_TYPE})

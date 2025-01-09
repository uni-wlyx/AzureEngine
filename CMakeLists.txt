cmake_minimum_required(VERSION 3.26)
project(AzureEngine)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_TOOLCHAIN_FILE )




#添加预编译宏
IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    MESSAGE( "current platform: Linux ")
    add_definitions(-DAZURE_PLATFORM_LINUX)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    add_definitions(-DAZURE_PLATFORM_WINDOWS)
    MESSAGE( "current platform: Windows")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
    MESSAGE( "current platform: FreeBSD")
ELSE ()
    MESSAGE( "other platform: ${CMAKE_SYSTEM_NAME}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")

#设置路径变量
set(LIB_PATH ${CMAKE_BINARY_DIR}/bin)
set(EXE_PATH ${CMAKE_BINARY_DIR}/bin)
set(AZURE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Azure)
set(Sandbox_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Sandbox)
set(LIBRARY_OUTPUT_PATH ${LIB_PATH})
set(EXECUTABLE_OUTPUT_PATH ${EXE_PATH})       #设置可执行文件的输出目录
set(CONTENT_PATH ${CMAKE_SOURCE_DIR}/Content)


set(TRD_PATH ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty)

#设置第三方库


set (GLAD_INCLUDE_DIR ${TRD_PATH}/glad/include)
set(GLAD_LIB glad)

set(GLM_INCLUDE_DIR ${TRD_PATH}/glm)

set(STB_INCLUDE_DIR ${TRD_PATH}/stb)

set ( IMGUI_INCLUDE_DIRS 
                ${TRD_PATH}/imgui/ 
                ${TRD_PATH}/imgui/backends)
set ( IMGUI_LIBRARY imgui )

set (SPDLOG_INCLUDE_DIR ${TRD_PATH}/spdlog/include)
set (SPDLOG_LIB spdlog::spdlog)

set (OPENGL_LIB OpenGL::GL)

set ( SDL2_INCLUDE_DIR ${TRD_PATH}/sdl2/include)
set ( SDL2_LIB SDL2::SDL2main SDL2::SDL2)
add_definitions(-DSDL_MAIN_HANDLED)

# option(AZURE_USE_SDL2 "Use SDL2 or GLFW3" ON)

# include_directories(${TRD_PATH}/spdlog/include)
# # include_directories(${TRD_PATH}/imgui)
# # include_directories(${TRD_PATH}/imgui/backends)
# include_directories(${TRD_PATH}/glm)


set ( Engine_INCLUDES
    ${GLAD_INCLUDE_DIR}
    ${GLM_INCLUDE_DIR}
    ${STB_INCLUDE_DIR}
    ${IMGUI_INCLUDE_DIRS}
    ${SPDLOG_INCLUDE_DIR}
    ${SDL2_INCLUDE_DIR}
    )

set ( Engine_LIBS
    ${OPENGL_LIB}
    ${SPDLOG_LIB}
    ${IMGUI_LIBRARY}
    ${GLAD_LIB}
    ${SDL2_LIB}
    )


add_subdirectory(${TRD_PATH})


# find_package(${CMAKE_CURRENT_SOURCE_DIR}/3rdpart/glfw CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
# find_package(GLEW REQUIRED)
# find_package(glad CONFIG REQUIRED)
# find_package(glm CONFIG REQUIRED)
# find_package(spdlog CONFIG REQUIRED)
# find_package(imgui CONFIG REQUIRED)
# set(Engine_LIBS PRIVATE glfw)

#set(Engine_LIBS PRIVATE glfw OpenGL::GL GLEW::GLEW glad::glad glm::glm spdlog::spdlog imgui::imgui)

include_directories(${Engine_INCLUDES})

add_subdirectory(${AZURE_PATH})
add_subdirectory(${Sandbox_PATH})

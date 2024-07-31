cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 17)
set(AZurLibeName Azure)

project(${AZurLibeName} VERSION 0.1.0)

get_filename_component(PARENT_FOLDER_ABSOLUTE2 ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
file(GLOB_RECURSE LIBSOURCE "*.cpp" "*.h")

include_directories(${AZURE_PATH})

#add_definitions(-DAZURE_PLATFORM_WINDOWS)
add_definitions(-DAZURE_EXPORT)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DAZ_ENABLE_ASSERTS)
endif ()


add_library(${AZurLibeName} SHARED ${LIBSOURCE})

target_precompile_headers(${AZurLibeName} PRIVATE azpch.h)
#target_include_directories(${AZurLibeName} PRIVATE  "${CMAKE_CURRENT_LIST_DIR}/source")
target_link_libraries(${AZurLibeName} PRIVATE ${LINK_LIB})

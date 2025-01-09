cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 17)


MESSAGE("operation system is ${CMAKE_SYSTEM}")

get_filename_component(PARENT_FOLDER_ABSOLUTE2 ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
file(GLOB_RECURSE SOURCE_FILE "*.cpp" "*.h")

# mess
include_directories(${AZURE_PATH})
link_directories(${LIB_PATH})

add_executable(AzureEngine ${SOURCE_FILE})

target_link_libraries(AzureEngine PRIVATE Azure)
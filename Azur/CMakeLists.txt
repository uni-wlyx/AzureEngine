cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 17)
set(AZurLibeName Azur)

project(${AZurLibeName} VERSION 0.1.0)

get_filename_component(PARENT_FOLDER_ABSOLUTE2 ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
file(GLOB_RECURSE LIBSOURCE "*.cpp" "*.h")

include_directories(${AZUR_PATH}/Azur)

#add_definitions(-DAZUR_PLATFORM_WINDOWS)
add_definitions(-DAZUR_EXPORT)

add_library(${AZurLibeName} SHARED ${LIBSOURCE})



#target_include_directories(${AZurLibeName} PRIVATE  "${CMAKE_CURRENT_LIST_DIR}/source")
target_link_libraries(${AZurLibeName} ${LINK_LIB})
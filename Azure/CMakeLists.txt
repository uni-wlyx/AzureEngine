cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 17)
set(AZurLibeName Azure)

project(${AZurLibeName} VERSION 0.1.0)

get_filename_component(PARENT_FOLDER_ABSOLUTE2 ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
file(GLOB_RECURSE LIBSOURCE "*.cpp" "*.h")

include_directories(${AZURE_PATH})

#add_definitions(-DAZURE_PLATFORM_WINDOWS)
add_definitions(-DAZURE_EXPORT)
# if(CMAKE_BUILD_TYPE STREQUAL "Debug")
add_definitions(-DAZ_ENABLE_ASSERTS)
# endif ()

add_definitions(-DGLM_ENABLE_EXPERIMENTAL)

add_library(${AZurLibeName} SHARED ${LIBSOURCE})

target_precompile_headers(${AZurLibeName} PRIVATE azpch.h)
#target_include_directories(${AZurLibeName} PRIVATE  "${CMAKE_CURRENT_LIST_DIR}/source")
target_link_libraries(${AZurLibeName} PRIVATE ${LINK_LIB})


#迁移资源文件夹
file(COPY ${CONTENT_PATH} DESTINATION ${EXE_PATH})

add_custom_command(
    TARGET ${AZurLibeName}  POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CONTENT_PATH}
    $<TARGET_FILE_DIR:${AZurLibeName}>/Content
)


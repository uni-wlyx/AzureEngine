project(glad)

add_compile_options(-fPIC)

file(GLOB_RECURSE GLAD_SOURCE "*.cpp")

add_library(glad STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/glad.c)

target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/include)



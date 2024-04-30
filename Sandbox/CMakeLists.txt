cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 17)


MESSAGE("operation system is ${CMAKE_SYSTEM}")


#message("${AZUR_PATH}")
include_directories(${AZUR_PATH})
link_directories(${LIB_PATH})

add_executable(AzurEngine main.cpp)

target_link_libraries(AzurEngine ${LINK_LIB} Azur.dll)
cmake_minimum_required(VERSION 3.20)

set(This queue)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_subdirectory(googletest)

set(Sources
    queue.cc    
)

add_library(${This} STATIC ${Sources})

add_subdirectory(test)
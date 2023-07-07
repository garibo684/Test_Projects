cmake_minimum_required(VERSION 3.14)
project(Library)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(lib_test lib_test.cc)
target_link_libraries(lib_test ${GTEST_LIBRARIES} pthread)
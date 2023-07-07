cmake_minimum_required(VERSION 3.14)
project(my_project)



find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTests queue_test.cc)
add_executable(runProduction queue.cc)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)


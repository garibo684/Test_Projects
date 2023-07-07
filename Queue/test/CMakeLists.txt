cmake_minimum_required(VERSION 3.20)

set(This queue_test)

set(Sources 
    queue_test.cc    
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    queue
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
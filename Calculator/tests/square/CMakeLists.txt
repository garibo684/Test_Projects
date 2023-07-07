add_executable(SquareTest 
     square_test.cc)

target_link_libraries(SquareTest PRIVATE
    GTest::GTest
    square
    )

add_test(
    NAME SquareTest
    COMMAND SquareTest
)
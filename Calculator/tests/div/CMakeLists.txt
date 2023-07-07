add_executable(DivTest
    div_test.cc)

target_link_libraries(DivTest PRIVATE
    GTest::GTest
    div
    )

add_test(
    NAME DivTest
    COMMAND DivTest
)
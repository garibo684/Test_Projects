add_executable(MultTest
    mult_test.cc)

target_link_libraries(MultTest PRIVATE
    GTest::GTest
    mult
    )

add_test(
    NAME MultTest
    COMMAND MultTest
)
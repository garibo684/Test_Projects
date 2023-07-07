add_executable(SubsTest
    subs_test.cc)
    
target_link_libraries(SubsTest PRIVATE
    GTest::GTest
    subs
    )

add_test(
    NAME SubsTest
    COMMAND SubsTest
)
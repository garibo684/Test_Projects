find_package(GTest REQUIRED)

add_subdirectory(sum)
add_subdirectory(subs)
add_subdirectory(mult)
add_subdirectory(div)
add_subdirectory(factorial)
add_subdirectory(square)

function(do_test target result)
  add_test(NAME ${target}_test COMMAND ${target})
  set_tests_properties(${target}_test
      PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
    
endfunction()

do_test(app1 "Factorial\\(5\\) = 120\nSum\\(6, -2\\) = 4\nSubs\\(-6, 5\\) = -11\nDiv\\(-8, 2\\) = -4\n")
do_test(app2 "Factorial\\(5\\) = 120\nSum\\(6, 2\\) = 8\nMult\\(7, -3\\) = -21\nSquare\\(-7\\) = -49\n")


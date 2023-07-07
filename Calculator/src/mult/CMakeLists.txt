add_library(mult 
        mult.cc
        private/private_sum.cc)

target_link_libraries(mult PRIVATE
    sum
    )

target_include_directories(mult
    PUBLIC
      "${PROJECT_SOURCE_DIR}/src/include"
    PRIVATE
      private
    )
add_library(square
    square.cc)

target_link_libraries(square PRIVATE
    mult
    )

target_include_directories(square
    PUBLIC 
      "${PROJECT_SOURCE_DIR}/src/include"
    )
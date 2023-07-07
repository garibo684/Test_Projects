add_library(Book Book.cc)

target_include_directories(Book PUBLIC
    "${PROJECT_SOURCE_DIR}/src/include"
    )
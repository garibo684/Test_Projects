add_library(Borrower Borrower.cc)

target_include_directories(Borrower PUBLIC
    "${PROJECT_SOURCE_DIR}/src/include"
    )

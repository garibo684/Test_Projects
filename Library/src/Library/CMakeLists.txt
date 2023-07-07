add_library(Library Library.cc)

target_link_libraries(Library PRIVATE
    Borrower
    Book
    )

target_include_directories(Library PUBLIC
    "${PROJECT_SOURCE_DIR}/src/include"
    )

    
add_executable(lib_app 
    app.cc
    )

target_link_libraries(lib_app PRIVATE
    Book
    Borrower
    Library
    )
    
add_library(subs
    subs.cc)

target_include_directories(subs PUBLIC 
    "${PROJECT_SOURCE_DIR}/src/include"
    )

target_compile_definitions(subs 
    PUBLIC PUBLIC_SUBS
    PRIVATE PRIVATE_SUBS
    )  

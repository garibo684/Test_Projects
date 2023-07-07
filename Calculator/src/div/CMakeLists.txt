add_library(div
    div.cc
    private/private_subs.cc
    )

target_link_libraries(div PRIVATE
    subs
    )

target_include_directories(div
    PUBLIC
      "${PROJECT_SOURCE_DIR}/src/include"
    PRIVATE
      private
    )
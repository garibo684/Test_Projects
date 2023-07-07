cmake_minimum_required(VERSION 3.15)
project(Currency_Converter VERSION 1.0)

option(TOORFROMTL "Convert To or From TL" ON)

add_subdirectory(converter)

configure_file(ConverterConfig.h.in ConverterConfig.h)

add_executable(currency_converter main.cc)

target_include_directories(currency_converter PUBLIC
                           ${PROJECT_BINARY_DIR}
                           )

target_include_directories(currency_converter PUBLIC
                           "${PROJECT_BINARY_DIR}/converter"
                           )

target_link_libraries(currency_converter converter)

target_link_directories(currency_converter PRIVATE
                        "converter"
                        )   

install(TARGETS currency_converter DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/ConverterConfig.h" DESTINATION include)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
include(CPack)

                            
                            
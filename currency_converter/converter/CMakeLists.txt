add_library(converter converter.cc)

install(TARGETS converter DESTINATION lib)
install(FILES converter.h DESTINATION include)
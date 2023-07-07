#include <iostream>
#include "build/ConverterConfig.h"
#include "converter/converter.h"

int main(int argc, char* argv[]) {
  const float inputValue = std::stod(argv[1]);

#ifdef TOORFROMTL
  converter::ConvertToTL(inputValue, "Dolar");
  converter::ConvertToTL(inputValue, "Euro");
#else
  converter::ConvertFromTL(inputValue, "Dolar");
  converter::ConvertFromTL(inputValue, "Euro");
#endif

  return 0;
}
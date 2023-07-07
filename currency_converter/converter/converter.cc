#include <iostream>
#include "converter.h"

float converter::ConvertFromTL(float a, const std::string& c) {
  if (c == "Dolar") {
    std::cout << "\n" << a << " TL  ==  " << a * 23.5952f << " Dolar" << std::endl;
  } else if (c == "Euro") {
      std::cout << "\n" << a << " TL  ==  " << a * 25.7914f << " Euro" << std::endl;
  }
}
float converter::ConvertToTL(float a, const std::string& c) {
  if (c == "Dolar") {
    std::cout << "\n" << a << " TL  ==  " << a / 23.5952f << " Dolar" << std::endl;
  } else if (c == "Euro") {
      std::cout << "\n" << a << " TL  ==  " << a / 25.7914f << " Euro" << std::endl;
  }
}
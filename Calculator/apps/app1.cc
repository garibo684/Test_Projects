#include <iostream>
#include "factorial.h"
#include "subs.h"
#include "sum.h"
#include "div.h"

int main() {
  std::cout << "Factorial(5) = " << Factorial(5) << "\n"
            << "Sum(6, -2) = " << Sum(6, -2) << "\n"
            << "Subs(-6, 5) = " << Subs(-6, 5) << "\n"
            << "Div(-8, 2) = " << Div(-8, 2) << "\n";
  return 0;
}


#include <iostream>
#include "square.h"
#include "factorial.h"
#include "mult.h"
#include "sum.h"

int main() {
  std::cout << "Factorial(5) = " << Factorial(5) << "\n"
            << "Sum(6, 2) = " << Sum(6, 2) << "\n"
            << "Mult(7, -3) = " << Mult(7, -3) << "\n"
            << "Square(-7) = " << Square(-7) << "\n";
  return 0;
}
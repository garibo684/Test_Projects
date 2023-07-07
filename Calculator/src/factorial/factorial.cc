#include "factorial.h"
#include "mult.h"

uint32_t Factorial(uint32_t x) {
  uint32_t factorial = 1;
  while (x) {
    factorial = Mult(factorial, x);
    x--;
  }
  return factorial;
}


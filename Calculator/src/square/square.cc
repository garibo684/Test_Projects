#include "square.h"
#include "mult.h"

uint32_t Square(int32_t x) {
  uint32_t square = Mult(x, x);
  return square;
}
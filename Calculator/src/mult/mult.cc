#include "mult.h"
#include "private_sum.h"

int32_t Mult(int32_t x, int32_t y) {
  int32_t mult = 0;
  int32_t temp_x = x;
  int32_t temp_y = y;

  if (x < 0 && y > 0) {
    x = -x;
  } else if (x > 0 && y < 0) {
      y = -y;
  } else if (x < 0 && y < 0) {
      x = -x;
      y = -y;
  }

  while (x) {
    mult = PrivateSum(mult, y);
    x--;
  }

  if (temp_x < 0 && temp_y > 0 || temp_x > 0 && temp_y < 0) {
    return -mult;
  } else {
      return mult;
  }
}

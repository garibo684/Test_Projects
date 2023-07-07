#include "div.h"
#include "private_subs.h"
#include <iostream>

int32_t Div(int32_t x, int32_t y) {
  if (y == 0) {
    std::cout << "Number / 0 = Uncertain" << std::endl;
    return NULL;
  }
  int32_t div = 0;
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

  while (x > 0) {
    x = PrivateSubs(x, y);
    div++;
  }

  if (temp_x < 0 && temp_y > 0 || temp_x > 0 && temp_y < 0) {
    return -(div);
  } else {
      return div;
  }
}
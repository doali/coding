#include "fibo.h"

unsigned int f(unsigned int k) {
  switch (k) {
  case 0:
    return 0;
  case 1:
    return 1;
  case 2:
    return 1;
  default:
    return f(k - 1) + f(k - 2);
  }
}

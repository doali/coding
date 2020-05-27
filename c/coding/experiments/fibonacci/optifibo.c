#include "optifibo.h"

unsigned int f_opti(unsigned int k) {
  int tmp = 0;
  static unsigned int val1 = 0, val2 = 1;
  static unsigned int i;
  static char state = 0;

  switch (state) {
  case 0:
    for (i = 1; i < k; i++) {
      state = 1;
      return val1 + val2;
    case 1:;
      tmp = val1;
      val1 = val2;
      val2 = tmp + val1;
    }
  }
  return -1;
}

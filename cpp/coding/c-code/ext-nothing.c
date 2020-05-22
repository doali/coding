#include <stdio.h>

void do_nothing(const char *message);
// extern "C" void do_nothing(const char *message);

void do_nothing(const char *message) {
  printf("%s\n", __func__);
  printf("%s\n", message);
}

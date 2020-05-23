#include <stdio.h>

int main(int argc, char **argv) {
  int t[] = {1, 2, 3, 4};
  for (int i = 0; i < 4; ++i) {
    printf("%p|%d\n", &t[i], t[i]);
  }

  printf("\n");

  for (int *p = t; p < &t[4]; ++p) {
    printf("%p|%d\n", p, *p);
  }

  printf("\n");

  for (int i = 0; i < (int)(sizeof(t) / sizeof(t[0])); ++i) {
    printf("%p|%d\n", &*(t + i), *(t + i));
  }

  return 0;
}

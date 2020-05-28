#include <stdio.h>
#include <stdlib.h>

#define PRINT_SZ(T, X) printf("%6s|%2lu byte(s)\n", T, sizeof(X))

typedef struct {
  char c;
  short s;
  int i;
  char *p_c;
  short *p_s;
  int *p_i;
} s_t;

int main(int argc, char **argv) {
  // -----------------------------------------------------------------------------
  s_t s = {'c', 1, 1, NULL, NULL, NULL};

  PRINT_SZ("char", s.c);
  PRINT_SZ("short", s.s);
  PRINT_SZ("int", s.i);
  PRINT_SZ("char*", s.p_c);
  PRINT_SZ("short*", s.p_s);
  PRINT_SZ("int*", s.p_i);
  // -----------------------------------------------------------------------------

  return 0;
}

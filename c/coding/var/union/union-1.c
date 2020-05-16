#include <stdio.h>

#define SZ_U(X) printf("%p|%lu\n", X, sizeof(*X));
#define LINE_BREAK printf("\n");

union mytypes_t {
  char c[10];
  int i;
  float f;
} mytypes, u_1; // VARIABLES

typedef union {
  int i;
  double f;
} u_select; // ALIAS

int main(int argc, char **argv) {

  // Exactly one member can be used
  mytypes.c[0] = 'a';
  mytypes.c[1] = 'b';
  mytypes.c[2] = 'c';
  mytypes.c[3] = 'd';
  mytypes.c[4] = 'e';
  mytypes.c[5] = 'f';
  mytypes.c[6] = 'g';
  mytypes.c[7] = 'h';
  mytypes.c[8] = 'i';
  mytypes.c[9] = '\0';

  printf("%s\n", mytypes.c);
  printf("%lu <= just to show the alignment problem\n", sizeof(mytypes.c));
  SZ_U(&mytypes)

  LINE_BREAK
  u_1.f = 3.14;
  printf("%f\n", u_1.f);
  SZ_U(&u_1)

  // Since we use typedef
  LINE_BREAK
  u_select u_2 = {.f = 2.0};
  printf("%f\n", u_2.f);
  SZ_U(&u_2);

  return 0;
}

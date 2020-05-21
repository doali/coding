#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define LINE_BREAK printf("\n");

typedef u_int8_t (*p_f)(u_int8_t, u_int8_t);

const u_int8_t e1_e2[] = {0, 1, 2, 3};

unsigned int sz_e1_e2() { return sizeof(e1_e2); }

void op(const char *, p_f);

u_int8_t f_and(u_int8_t a, u_int8_t b) { return a & b; }
u_int8_t f_or(u_int8_t a, u_int8_t b) { return a | b; }
u_int8_t f_xor(u_int8_t a, u_int8_t b) { return a ^ b; }

int main(int argc, char **argv) {
  op("&", f_and);

  LINE_BREAK
  op("|", f_or);

  LINE_BREAK
  op("^", f_xor);

  return 0;
}

void op(const char *name, p_f f) {
  printf("e1 e2 | e1 %s e2 |\n", name);
  printf("------|---------|\n");
  printf("%x %s %x | %7x |\n", 0, name, 0, f(0, 0));
  printf("%x %s %x | %7x |\n", 0, name, 1, f(0, 1));
  printf("%x %s %x | %7x |\n", 1, name, 0, f(1, 0));
  printf("%x %s %x | %7x |\n", 1, name, 1, f(1, 1));
}

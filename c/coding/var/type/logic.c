#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define LINE_BREAK printf("\n");

typedef u_int8_t (*p_f_b)(u_int8_t, u_int8_t);
typedef u_int16_t (*p_f_n)(u_int8_t, u_int8_t);

typedef u_int8_t (*p_f_u)(u_int8_t);

void op_b(const char *, p_f_b);

void op_u(const char *, p_f_u);

void op_shift(const char *, p_f_n, u_int16_t, u_int8_t);

u_int8_t f_and(u_int8_t a, u_int8_t b) { return a & b; }
u_int8_t f_or(u_int8_t a, u_int8_t b) { return a | b; }
u_int8_t f_xor(u_int8_t a, u_int8_t b) { return a ^ b; }

/**
 * \return u_int16_t
 */
u_int16_t f_shift_l(u_int8_t a, u_int8_t n) { return a << n; }
/**
 * \return u_int16_t
 */
u_int16_t f_shift_r(u_int8_t a, u_int8_t n) { return a >> n; }

u_int8_t f_cmp1(u_int8_t a) { return ~a; }
u_int8_t f_cmp2(u_int8_t a) { return -a; }

int main(int argc, char **argv) {
  op_b("&", f_and);

  LINE_BREAK
  op_b("|", f_or);

  LINE_BREAK
  op_b("^", f_xor);

  LINE_BREAK
  op_shift("<<", f_shift_l, 1, 8);

  LINE_BREAK
  op_shift(">>", f_shift_r, 128, 8);

  LINE_BREAK
  op_u("~", f_cmp1);

  LINE_BREAK
  op_u("-", f_cmp2);

  return 0;
}

void op_u(const char *name, p_f_u u) {
  printf("e  | %s e  |\n", name);
  printf("---|------|\n");
  printf("%s%x | %4x |\n", name, 0, u(0));
  printf("%s%x | %4x |\n", name, 1, u(1));
}

void op_b(const char *name, p_f_b f) {
  printf("e1 e2 | e1 %s e2 |\n", name);
  printf("------|---------|\n");
  printf("%x %s %x | %7x |\n", 0, name, 0, f(0, 0));
  printf("%x %s %x | %7x |\n", 0, name, 1, f(0, 1));
  printf("%x %s %x | %7x |\n", 1, name, 0, f(1, 0));
  printf("%x %s %x | %7x |\n", 1, name, 1, f(1, 1));
}

void op_shift(const char *name, p_f_n f, u_int16_t start, u_int8_t n) {
  printf("n | e = %3d %s n    |\n", start, name);
  printf("--|-----------------|\n");
  for (u_int8_t shift = 0; shift <= n; ++shift)
    printf("%1x | %16d|\n", shift, f(start, shift));
}

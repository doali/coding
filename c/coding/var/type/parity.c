#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * \param n number to check
 * \return 1 if true else 0 is returned
 */
u_int8_t is_odd8(u_int8_t n);

u_int8_t is_odd32(u_int n);

u_int8_t is_odd_kernighan(u_int n);

// -----------------------------------------------------------------------------
int main(int argc, char **argv) {
  printf("Check parity : number of bits equal to 1\n");
  puts("");
  printf("-------------------------------------------\n");
  printf("<n> | method_1 | method_2 | method_3 | test\n");
  printf("----|----------|----------|----------|-----\n");
  for (u_int8_t n = 0; n < 129; ++n) {
    printf("%4d|%10d|%10d|%10d|%5d\n", n, is_odd8(n), is_odd32(n),
           is_odd_kernighan(n), is_odd_kernighan(n) == is_odd32(n));
  }

  return EXIT_SUCCESS;
}
// -----------------------------------------------------------------------------

u_int8_t is_odd8(u_int8_t n) {
  u_int8_t result = 0;
  u_int8_t n_even = 0;

  if (!n)
    return result;

  u_int8_t mask;
  for (mask = 128; mask > 0; mask >>= 1) { /*
                                            * 128 : 1000 0000
                                            * Et si plus de 8 bits ?
                                            * ...
                                            * pas pratique !!
                                            */
    if (n & mask)
      ++n_even; // counts number of 1 in n
  }
  result = (n_even % 2);

  return result;
}

u_int8_t is_odd32(u_int n) {
  u_int nb_bit1 = 0;
  for (u_int shift = 0; shift < 32; ++shift) {
    if (n & (1 << shift))
      ++nb_bit1;
  }

  return nb_bit1 & 1; /*
                       * (number & 1) on teste si on termine par 1
                       * si dernier bit à 1 alors number est impair
                       */
}

u_int8_t is_odd_kernighan(u_int data) { // le plus efficace
  int nb_bit1 = 0;

  while (data > 0) {
    ++nb_bit1;
    data &= data - 1;
  }

  return nb_bit1 & 1;
}

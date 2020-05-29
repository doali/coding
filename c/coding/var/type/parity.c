#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * \param n number to check
 * \return 1 if true else 0 is returned
 */
u_int8_t is_odd(u_int8_t n);

// -----------------------------------------------------------------------------
int main(int argc, char **argv) {
  for (u_int8_t n = 0; n < 129; ++n) {
    printf("%3d|%1d\n", n, is_odd(n));
  }

  return EXIT_SUCCESS;
}
// -----------------------------------------------------------------------------

u_int8_t is_odd(u_int8_t n) {
  u_int8_t result = 0;
  u_int8_t n_even = 0;

  if (!n)
    return !result;

  u_int8_t mask;
  for (mask = 128; mask > 0; mask >>= 1) {
    if (n & mask)
      ++n_even;
  }
  result = (n_even % 2);

  return result;
}

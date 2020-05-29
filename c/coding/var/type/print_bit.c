#include <stdio.h>
#include <stdlib.h>
// -----------------------------------------------------------------------------
#define MAX_BITS                                                               \
  64 /*                                                                        \
      * IMPLIQUE PAS MAL DE SUBTILITES !!                                      \
      * 1 << idx <= ATTENTION, on est avec des int...                          \
      * du coup !!                                                             \
      * (long)1 << idx <= OK !!                                                \
      */
#define BITS_FOR_BYTE 8
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// VAR...
// -----------------------------------------------------------------------------

static char T_BIT8[MAX_BITS] = {0};

// -----------------------------------------------------------------------------
// INTERFACE
// -----------------------------------------------------------------------------

/**
 * const char *bit8toc(long n);
 */
const char *bit8toc(long n);

/**
 * void print_bit8(long n);
 */
void print_bit8(long n);

// -----------------------------------------------------------------------------
// TEST
// -----------------------------------------------------------------------------

void test() {
  for (long val = 0; val < 255; ++val) {
    bit8toc(val);
    print_bit8(val);
  }
}

// -----------------------------------------------------------------------------
// MAIN
// -----------------------------------------------------------------------------

int main(int argc, char **argv) {
  test();

  if (argc != 2) {
    printf("Usage: %s <number_+>\n", argv[0]);
    return EXIT_FAILURE;
  }

  bit8toc(atol(argv[1]));    // Etant donnée la taille => atol (et non atoi)
  print_bit8(atol(argv[1])); // Idem

  return EXIT_SUCCESS;
}

// -----------------------------------------------------------------------------
// FUNCTIONS...
// -----------------------------------------------------------------------------

const char *bit8toc(long n) {
  for (long idx = 0; idx < MAX_BITS; ++idx) {
    T_BIT8[MAX_BITS - idx - 1] = (n & ((long)1 << idx)) ? '1' : '0';
    // ((long)1 ...) TRANSTYPAGE TRES IMPORTANT !!
  }

  return T_BIT8;
}

void print_bit8(long n) {
  printf("%20ld|", n);
  for (char step = 0; step < MAX_BITS / BITS_FOR_BYTE; ++step) {
    for (char index = 0; index < BITS_FOR_BYTE; ++index) {
      printf("%c", T_BIT8[index + step * BITS_FOR_BYTE]);
    }
    printf(" ");
  }
  printf("\n");
}

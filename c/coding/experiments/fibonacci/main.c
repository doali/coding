#include "fibo.h"
#include "optifibo.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define LINE_BREAK printf("\n")

// -----------------------------------------------------------------------------
/**
 */
static unsigned char is_digit(const char *);

/**
 */
static void fib(unsigned int);

/**
 */
static void usage(const char *);
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// MAIN
// -----------------------------------------------------------------------------
int main(int argc, char **argv) {
  if (argc != 2) {
    usage(argv[0]);
    return EXIT_FAILURE;
  }

  if (!is_digit(argv[1])) {
    usage(argv[0]);
    return EXIT_FAILURE;
  }

  fib(atoi(argv[1]));

  return EXIT_SUCCESS;
}
// -----------------------------------------------------------------------------

static unsigned char is_digit(const char *str) {
  for (int i = 0; str[i] != '\0'; ++i) {
    if (!isdigit(str[i])) {
      return 0;
    }
  }

  return 1;
}

static void fib(unsigned int k) {
  printf("|%-4s|%-9s|\n", "N", "fib(N)");
  printf("|--------------|\n");
  for (unsigned int i = 0; i <= k; ++i)
    printf("|%4d|%4d|%4d|\n", i, f(i), f_opti(i));
}

static void usage(const char *prog_name) {
  printf("Usage %s <unsigned_integer>\n", prog_name);
}

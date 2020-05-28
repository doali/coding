#include "powerof2.h"
#include <stdio.h>
#include <stdlib.h>

#define LINE_BREAK puts("")

typedef int (*p_f)(unsigned int);

/**
 * \param n denotes max range
 * \param task denotes the operation
 */
static void test(unsigned int n, p_f task);

// -----------------------------------------------------------------------------
int main(int argc, char **argv) {
  test(2050, is_power_of_2);

  return EXIT_SUCCESS;
}
// -----------------------------------------------------------------------------

static void test(unsigned int n, p_f task) {

  printf("Is n a power of 2 ?\n");

  LINE_BREAK;

  printf("|  n  |?|\n");
  printf("|-----|-|\n");

  for (unsigned int element = 0; element < n; ++element) {
    printf("|%5d|%x|\n", element, task(element));
  }
}

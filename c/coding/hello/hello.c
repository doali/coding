#include <stdio.h>

/* Compilation
 * gcc -o hello hello.c
 */

/* Execution
 * ./hello
 */

void do_something() {
  printf(__func__);
  printf("\n");
  printf("Hi doing something\n");
}

int main() {
  printf(__func__);
  printf("\n");

  do_something();

  return 0;
}

#include <stdio.h> // en-tete standard
                   // directive preprocesseur => #include

/* Compilation
 * gcc -Wall -ggdb -o hello hello.c
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

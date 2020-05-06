#include <stdio.h>
#include <stdlib.h>

int add(int, int);
int mul(int, int);

int print_number(int);

int (*p_op)(int, int);

int main(int argc, char **argv) {

  int res = 0;

  // Syntax 1
  p_op = add;
  res = p_op(1, 1);
  print_number(res);

  // Syntax 2
  p_op = &add;         // &
  res = (*p_op)(1, 1); // *
  print_number(res);

  return EXIT_SUCCESS;
}

int add(int x, int y) { return x + y; }

int print_number(int number) {
  printf("%d\n", number);
  return 1;
}

#include <stdio.h>

// global variable
int x = 1234;

void function_1() {
  // Using global variable
  printf("%d\n", x);
}

int main() {
  int x = 4321;
  function_1();
  printf("%d\n", x);
}

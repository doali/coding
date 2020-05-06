#include <stdio.h>

// function pointer
typedef int (*p_f)(int);

/*
 * Let us says this is our base function
 */
p_f f(int x) {

  ++x; // just to modify x

  /*
   * Inner function
   * - declaration
   * - definition
   */
  int sum(int y) { return x + y; }

  return &sum;
}

int main(void) {

  // Base value
  const int base = 10;
  printf("Base value:%d\n", base);

  // Function wrapper
  printf("Wrapper|f:%p\n", &f);

  // Capture function
  p_f closure = f(base);
  printf("Inner|closure:%p\n", &closure);

  // Execute captured function (.e.g in a specific context)
  int res = closure(1);
  printf("closure(1) = %d\n", res);

  printf("base:%d\n", base);
  printf("f:%p\n", &f); // or shortly f
  for (int element = 0; element < 10; ++element) {
    printf("(%d|%p)=>%d\n", element, &closure, closure(element));
  }
  return 0;
}

/*
 * https://zestedesavoir.com/tutoriels/755/le-langage-c-1/notions-avancees/les-pointeurs-de-fonction/
 * https://www.geeksforgeeks.org/nested-functions-c/
 */

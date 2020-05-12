#include <stdio.h>
#include <stdlib.h>

typedef int (*p_f)(int);

int main(int argc, char *argv[]) {

  p_f f(int a) { // declaration + definition

    int g(int b) { return a + b; } // declaration + definition

    void print(const char *msg) { // declaration + definition

      int z(int p) { return a * p; }

      int p = 100;
      int res = z(p); // call function
      printf("%d, %d <= %d", a, p, res);

      printf("%s\n", msg);
    }

    print(" coucou !!"); // call function

    return &g; // function pointer
  }

  p_f k;     // function pointer
  k = f(10); // function call + context saved
  k(0);      // function call in context saved
  k(1);      // idem
  k(2);      // idem

  for (int i = 0; i < 10; ++i) {
    int res = k(i); // idem
    printf("%d\n", res);
  }

  return 0;
}

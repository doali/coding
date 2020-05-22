#include <stdio.h>

int main(int argc, char **argv) {
  struct {
    int a;  // OK
    int b;  // OK (a + b)
    int c;  // OK
    char d; // KO !! (c + d) = 4 + 1 => non alignés => 3 octets de padding
  } s_1;    // 16 octets

  printf("%lu\n", sizeof(s_1));

  /*
   * https://www.geeksforgeeks.org/bit-fields-c/
   */
  struct c {
    int a;
    int b;
    int c;
  } s_2; // 12 octets

  printf("%lu\n", sizeof(s_2)); // multiple de 4 (qui correspond à sizeof(int))

  return 0;
}

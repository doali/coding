#include <stdalign.h>
#include <stdio.h>

#define LINE_BREAK printf("\n");

#ifdef LOG
#define URL_ALIGNMENT                                                          \
  "https://zestedesavoir.com/tutoriels/755/le-langage-c-1/"                    \
  "1043_aggregats-memoire-et-fichiers/4279_structures/"                        \
  "#4-les-structures-litterales"
#else
#define URL_ALIGNMENT "http zestedesavoir here"
#endif

int main(void) {
  printf("_Bool: %zu\n", _Alignof(_Bool));
  printf("char: %zu\n", _Alignof(char));
  printf("short: %zu\n", _Alignof(short));
  printf("int : %zu\n", _Alignof(int));
  printf("long : %zu\n", _Alignof(long));
  printf("long long : %zu\n", _Alignof(long long));
  printf("float : %zu\n", alignof(float));
  printf("double : %zu\n", alignof(double));
  printf("long double : %zu\n", alignof(long double));

  /*
   * https://zestedesavoir.com/tutoriels/755/le-langage-c-1/1043_aggregats-memoire-et-fichiers/4279_structures/#4-les-structures-litterales
   */
  LINE_BREAK
  printf("%s\n", URL_ALIGNMENT);

  return 0;
}

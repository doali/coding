#include "a.h" // function declarations

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

  // FILE* : pointeur de flux
  FILE *f_out = fopen("out.txt", "a");
  FILE *f_in = fopen("in.txt", "r");

  int c = 0;
  while ((c = getc(f_in)) != EOF) {
    putc(c, f_out);
  }
  fclose(f_out);
  fclose(f_in);

  /*
   * functions calls
   * - declarations ? yes from #include "a.h"
   * - definitions ? yes from object file a.o
   * =>gcc -c a.c
   * ------------------------
   * =>gcc -o file.exe file.c a.o
   * ------------------------
   */
  hello();
  coucou();
  test();
  plus();

  return 0;
}

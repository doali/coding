#include <stdio.h> // en-tete standard
                   // directive preprocesseur => #include
                   // copie le contenu du fichier stdio.h

/* Compilation
 * gcc -Wall -ggdb -o hello hello.c
 */

/* Execution
 * ./hello
 */

#define LINE_BREAK printf("====================================\n");

void do_something() {
  printf(__func__);
  printf("\n");
  printf("Hi doing something\n");
}

int main() {
  LINE_BREAK
  printf("%d\n", __LINE__); // line number of the current file being compiled
  printf("%s\n", __FILE__); // name of the current file being compiled
  printf("%s\n", __DATE__); // current date
  printf("%s\n", __TIME__); // current time
  LINE_BREAK

  printf(__func__);
  printf("\n");

  do_something();

  return 0;
}

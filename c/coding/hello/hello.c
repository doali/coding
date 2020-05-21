#include <stdio.h> // en-tete standard
                   // directive preprocesseur => #include
                   // copie le contenu du fichier stdio.h
// --------------------------------------------------------------------------------
// INFO : Compile and Run
// --------------------------------------------------------------------------------
/* Compile
 * -----------
 * gcc -Wall -ggdb -o hello hello.c
 * -----------
 * gcc -Werror -ggdb -o hello hello.c
 * -----------
 */

/* Run
 * ---------
 * ./hello
 * ---------
 */
// --------------------------------------------------------------------------------
// PREPROCESSOR
// --------------------------------------------------------------------------------
//#define LOG
#ifdef LOG // needed if no -DLOG option while compiling
/*
 * #ifdef LOG
 * we can comment this line even if we want to use LOG
 * provided we compile this way
 * gcc -DLOG -o string string.c
 */
#define LINE_BREAK printf("%40s:%d\n", __func__, __LINE__);
#else
#define LINE_BREAK printf("\n");
#endif
// --------------------------------------------------------------------------------
// FUNCTIONS
// --------------------------------------------------------------------------------
void do_something() { // declaration + definition
  printf(__func__);
  printf("\n");
  printf("Hi doing something\n");
}
// --------------------------------------------------------------------------------
// ENTRY POINT
// --------------------------------------------------------------------------------
int main() { // declaration + definition
  LINE_BREAK
  printf("%d\n", __LINE__); // line number of the current file being compiled
  printf("%s\n", __FILE__); // name of the current file being compiled
  printf("%s\n", __DATE__); // current date
  printf("%s\n", __TIME__); // current time
  LINE_BREAK

  printf(__func__);
  printf("\n");

  do_something(); // call function

  return 0; // to ENV, i.e. to the OS
}

#include <stdio.h>

#define CONCAT(A, B) A##B
#define WRAPP(X) #X
#define TO_STR(X)                                                              \
  WRAPP(X) // permet l'expanding lors de la précompilation
           // et produit l'effet souhaite !! (IMPORTANT) <====

int main(int argc, char **argv) {
  const char *CONCAT(str, _0) = "bof";
  printf("str_0, on sait qu'il existe, mais %s\n", str_0); // HORREUR !!

  /*
   * ----------------------------------------------------------------
   * POINT IMPORTANT (imbrication de macros, expanding, évaluation...
   * ----------------------------------------------------------------
   */
  printf("%s\n", TO_STR(CONCAT(MACRO, _A_GOGO))); // avec WRAPP(X) => :-)

  return 0;
}

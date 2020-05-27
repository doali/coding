#include <stdio.h>

#define WRAPP(X) (#X)             // permet d'envelopper X de guillements
#define CONS_LIB_NAME(X) lib##X.a // malgré le . on a une concaténation :-)

//#define TO_STR(X) #X // pas l'effet souhaité lors d'imbrication de macros...
#define TO_STR(X)                                                              \
  WRAPP(X) // permet l'expanding lors de la précompilation
           // et produit l'effet souhaite !! (IMPORTANT) <====

int main(int argc, char **argv) {
  printf("%s\n", WRAPP(COUCOU));

  /*
   * ----------------------------------------------------------------
   * POINT IMPORTANT (imbrication de macros, expanding, évaluation...
   * ----------------------------------------------------------------
   * LE PROBLEME
   * ----------------------------------------------------------------
   */

#define TO_STR(X)                                                              \
#X // RM on redefinit ici pour l'exercice... mais à ne pas faire

  printf("%s\n", TO_STR(CONS_LIB_NAME(titi))); // sans WRAPP(X) => :-(

  /* On obtient en sortie
   *
   * CONS_LIB_NAME(titi)
   *
   * ce que l'on ne veut pas... il manque l'expanding !!
   * Pour cela il faut transformer la macro et ajouter UN NIVEAU de substitution
   */

  /* ----------------------------------------------------------------
   * LA SOLUTION
   * ----------------------------------------------------------------
   * Ajout d'un niveau supplémentaire de substitution
   */

#define TO_STR(X)                                                              \
  WRAPP(X) // RM on redéfinit ici pour l'exercice... mais à ne pas faire

  printf("%s\n", TO_STR(CONS_LIB_NAME(titi))); // avec WRAPP(X) => :-)

  /* On obtient en sortie
   *
   * libtiti.a
   *
   * On observe en sortie l'évaluation de CONS_LIB_NAME(titi), ce que l'on
   * souhaitait
   */

  return 0;
}

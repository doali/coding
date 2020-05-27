#include "util.h"
#include <stdio.h>

#define CONSTANTE 1024 // définition classique d'une constante

#define PLUS_C(A, B)                                                           \
  int c = A + B; // expression C valide
                 // mais peu pratique à utiliser
                 // il faut se rappeler que l'on a déclaré et défini
                 // la variable c

#define PLUS(A, B)                                                             \
  A + B; // expression C valide
         // bien mieux !!

#define FICHIER_A "fichier_a.c" // utile pour FILE* :-)

#define WRAPP(W) #W
// permet d'envelopper W de guillemets
// fonctionne
// - uniquement dans la définition de la macro
// - sur un PARAMETRE (pas de #MON_AUTRE_MACRO(A, B) <= marchera pas !!)

#define LOG(X)                                                                 \
  printf("%s\n", #X) // #X à proscrire dans ce cas d'utilisation
                     // problèmes des virgules
                     // (c.f le code ci-dessous) !!
#define LOG_S(X)                                                               \
  printf("%s\n", X) // on passe une "string" !!
                    // plus clair, évite le problème des virgules

#define CONCAT(X, Y)                                                           \
  X##_##Y // concatenation !!
          // fonctionne uniquement dans la defintion de la macro

int CONCAT(func, add)(int a, int b);
// Produira via substitution
// int func_add(int a, int b);
// Mais est-ce vraiment pratique ? :-/
// On peut faire tout et n'importe quoi.
// Ceci est plutôt n'importe quoi :-P

extern void notes(void);

int main(int argc, char **argv) {

  printf("%d\n", CONSTANTE);

  PLUS_C(1, 1); // fonctionne mais pas pratique :-P
  printf("%d\n", c);

  int d = PLUS(1, 2); // plus exploitable :-)
  printf("%d\n", d);

  printf("%s\n", FICHIER_A);

  const char *str_ab = WRAPP(ab); // enveloppe avec des guillemets
  printf("%s\n", str_ab);

  LOG(fonctionne car pas de virgule : - /);
  // LOG(marche pas, car des virgules !!); // <= cette forme est à proscrire !!
  LOG_S("ceci est un message de log bien mieux non ? :)"); // <= bien mieux !!

  int res = func_add(1, 3);
  printf("%p", CONCAT(func, add));
  /* Si on remplace %p par %s, on obtient le message suivant
   * => format specifies type 'char *' but the argument has type 'int (*)(int,
   * int)' On a donc une interpretation comme un pointeur sur fonction
   * - ne pas faire ce genre de macro...
   */
  printf("%d\n", res);

  const char *p_str = "C'est plus simple comme ça";
  INFO_ADDR_VAL(p_str);
  INFO_ADDR_VAL_STR(p_str);

  int i = 10;
  int *p_i = &i;
  INFO_ADDR_VAL(p_i);
  INFO_ADDR_VAL_INT(p_i);

  printf("a" WRAPP(Z) "\n");
  SHOW(res);

  notes();

  return 0;
}

int CONCAT(func, add)(int a, int b) { return a + b; }

#include <stdio.h>

// http://casteyde.christian.free.fr/cpp/cours/online/x1432.html
int i = 12;       /* i est accessible de tous les fichiers. */
const int j = 11; /* Synonyme de "static const int j = 11;". */

extern const int k; /* Déclare d'abord la variable k... */
const int k = 12;   /* puis donne la définition. */

int main(void) {
  printf("%d\n", i);
  printf("%d\n", j);
  printf("%d\n", k);

  return 0;
}

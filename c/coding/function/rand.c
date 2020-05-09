/*
 * https://nicolasj.developpez.com/articles/libc/hasard/
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// rand() est limité par RAND_MAX

int main(int argc, char **argv) {
  if (argc == 2) {
    int r = rand(); // meme graine => meme suite de nombre à chaque exécution
                    // => utiliser une nouvelle graine => srand(...) !!!
    printf("%d|%d\n", r, r % atoi(argv[1]));
    // Modification de la graine
    srand(time(
        NULL)); // <= IMPORTANT : appeler srand pour fixer une nouvelle graine
    r = rand(); // génération d'un nombre aléatoire
    printf("%d|%d\n", r, r % atoi(argv[1])); // entre 0 et (atoi(argv[1]) - 1)
  } else {
    printf("Usage: %s <number>\n", argv[0]);
  }
}

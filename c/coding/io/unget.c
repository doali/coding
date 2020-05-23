#include <stdio.h>
#include <stdlib.h>

#define ENTREE "entree.txt"

int main(void) {
  FILE *f_in;
  int c;

  if ((f_in = fopen(ENTREE, "r")) == NULL) {
    fprintf(stderr, "\nErreur: Impossible de lire le fichier %s\n", ENTREE);
    return (EXIT_FAILURE);
  }

  while ((c = fgetc(f_in)) != EOF) {
    if (c == '0') {
      ungetc('a', f_in); // on empile => sera le dernier lu
      ungetc('b', f_in); // on empile => le second lu
      ungetc('c', f_in); // on empile => le premier lu
      // ungetc injecte dans le flux des caractères: a, b et c
      // lors de la lecture, le dernier caractere pushed sera le premier lu
      // etc...
    }
    putchar(c); // on lit dans le flux en tenant compte de ce qui a été empilé
  }
  fclose(f_in);

  return (EXIT_SUCCESS);
}

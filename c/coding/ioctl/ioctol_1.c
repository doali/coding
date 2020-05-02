#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  printf("argc:%d\n", argc);

  for (int indice = 0; indice < argc; ++indice) {
    printf("%d : %s\n", indice, argv[indice]);
  }

  for (char **p = &argv[0]; p < &argv[4]; p++) {
    printf("%p %s\n", p, *p);
  }
}

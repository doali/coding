#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  struct {
    int id;
    const char *word;
  } key; // key is a variable of type struct { ... }

  key.id = 10;
  key.word = "anonymous structure";

  printf("%d:%s\n", key.id, key.word);

  return EXIT_SUCCESS;
}

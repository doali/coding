#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage() { printf("Type a value in {'red', 'green', 'blue'}\n"); }

int main(int argc, char **argv) {
  if (argc == 2)
    printf("Value:%s\n", argv[1]);
  else {
    usage();
    return EXIT_FAILURE;
  }

  const char *label = argv[1];

  if (strcmp(label, "red") == 0)
    // Utilisation de l'étiquette label_red alors que celle-ci est déclarée plus
    // loin.
    // C'est dû au fait que les étiquettes ont une portée de fonction !!
    // Elles sont visibles partout dans une fonction => leurs noms doivent-être
    // uniques
    goto label_red;
  else if (strcmp(label, "green") == 0)
    goto label_green;
  else if (strcmp(label, "blue") == 0)
    goto label_blue;
  else {
    usage();
    goto end;
  }

label_red:
  printf("red\n");
  goto end;

label_green:
  printf("label:green\n");
  goto end;

label_blue:
  printf("label:blue\n");

end:
  printf("label:end\n");

  return EXIT_SUCCESS;
}

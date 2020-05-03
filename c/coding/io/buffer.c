#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Interesting reading here
 * https://stackoverflow.com/questions/5431941/why-is-while-feof-file-always-wrong
 */

int read_file(const char *file_name) {
  if (!file_name) {
    perror("Null pointer");
    return EXIT_FAILURE;
  }

  FILE *fstream = fopen(file_name, "r");
  if (!fstream) {
    perror("No file found here\n");
    return EXIT_FAILURE;
  }

  int c = fgetc(fstream);
  while (c != EOF) {
    fprintf(stdout, "%c", c);
    c = fgetc(fstream);
  }

  if (fstream)
    fclose(fstream);

  return EXIT_SUCCESS;
}

int main(int argc, char **argv) {
  if (argc == 2) {
    read_file(argv[1]);
  }

  return EXIT_SUCCESS;
}

#include "macro.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define F_C "macro.c"
#define F_H "macro.h"

#define LINE_BREAK(NB_C)                                                       \
  do {                                                                         \
    for (int i = 0; i < NB_C; ++i) {                                           \
      printf("%c", '-');                                                       \
    }                                                                          \
    printf("\n");                                                              \
  } while (0)

#define LINE_BREAK_80 LINE_BREAK(80)

int read_file(const char *);

int main(int argc, char **argv) {
  LINE_BREAK_80;
  read_file(F_C);
  LINE_BREAK_80;
  read_file(F_H);

  return EXIT_SUCCESS;
}

int read_file(const char *file_name) {

  FILE *stream = fopen(file_name, "r");

  if (!stream) {
    perror("Error fopen\n");
    return EXIT_FAILURE;
  }

  int c = 0;
  while ((c = fgetc(stream)) != EOF) {
    printf("%c", c);
  }

  if (!c) {
    perror("Error fgetc\n");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

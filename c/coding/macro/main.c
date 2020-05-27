#include "libread.h"

#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME_C "libread.c"
#define FILE_NAME_H "libread.h"

#define LINE_BREAK(NB_C)                                                       \
  do {                                                                         \
    for (int i = 0; i < NB_C; ++i) {                                           \
      printf("%c", '-');                                                       \
    }                                                                          \
    printf("\n");                                                              \
  } while (0)

#define LINE_BREAK_80 LINE_BREAK(80)

int main(int argc, char **argv) {
  LINE_BREAK_80;
  read_file_by_char(FILE_NAME_C);

  LINE_BREAK_80;
  read_file_by_line(FILE_NAME_H);

#ifdef INFO
  PRINT_INFO;
#endif

  return EXIT_SUCCESS;
}

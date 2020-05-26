#include "libread.h"
#include "macro.h"

#include <errno.h>
#include <stdlib.h>

int r_file_char(FILE *stream) {
  int c = 0;
  while ((c = fgetc(stream)) != EOF) {
    printf("%c", c);
  }

  if (errno) {
    perror(__func__);
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

int r_file_line(FILE *stream) {
  u_long l_n = 0;
  char *buff = (char *)malloc(sizeof(char) * MAX_BUFF);
  size_t buff_sz = (size_t)MAX_BUFF;

  while ((getline(&buff, &buff_sz, stream) != -1)) {
    printf("%4lu %s", ++l_n, buff);
  }

  FREE(buff);

  if (errno) {
    perror(__func__);
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

int read_file(const char *file_name, e_mode mode) {
  if (!file_name) {
    perror("Error file_name\n");
    return EXIT_FAILURE;
  }

  FILE *stream = fopen(file_name, "r");

  if (!stream) {
    perror("Error fopen\n");
    return EXIT_FAILURE;
  }

  fun_read read_stream;

  switch (mode) {
  case LINE:
    read_stream = &r_file_line;
    break;
  case CHAR:
    read_stream = &r_file_char;
    break;
  default:
    break;
  }

  if (read_stream)
    read_stream(stream);

  return EXIT_SUCCESS;
}

int read_file_by_char(const char *file_name) {
  return read_file(file_name, CHAR);
}

int read_file_by_line(const char *file_name) {
  return read_file(file_name, LINE);
}

/*!
 * \file copy-file-doc.c
 * \brief copy a file
 */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_BREAK printf("\n")

/*!
 * Copy src to dst
 * \param src source file
 * \param dst destination file
 * \return status
 */
static int copy_file(const char *dst, const char *src);

// -----------------------------------------------------------------------------
// MAIN
// -----------------------------------------------------------------------------
int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage %s <src_file> <dst_file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  if (!strcmp(argv[2], argv[1]))
    return EXIT_FAILURE;

  copy_file(argv[2], argv[1]); // COPY

  return EXIT_SUCCESS;
}
// -----------------------------------------------------------------------------

static int copy_file(const char *dst, const char *src) {
  // -- var
  errno = 0;

  FILE *f_src = NULL;
  FILE *f_dst = NULL;
  // -- var

  // --- checking
  if (!dst || !src) {
    return EXIT_FAILURE;
  }

  f_src = fopen(src, "r");

  if (!f_src) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  f_dst = fopen(dst, "w");

  if (!f_dst) {
    perror("fopen");
    fclose(f_src);
  }
  // --- checking

  // --- copy
  char c;
  while ((c = getc(f_src)) != EOF) {
    fputc(c, f_dst);
  }
  // -- copy

  fclose(f_src);
  fclose(f_dst);

  return EXIT_SUCCESS;
}

/**
 * \file array-2.c
 * \brief Arrays
 */
#include <stdio.h>
#include <stdlib.h>

#define ROW 4
#define COL 2

#define LINE_BREAK(X)                                                          \
  if (X == 0)                                                                  \
    printf("\n");                                                              \
  else                                                                         \
    printf("\n----------------------------------------------------------\n");

/**
 * \brief fetch a value in an array at [r][c]
 * \fn int fetch(char *t, int r, int c) { return *(t + (c + r * COL)); }
 * \param t array of char
 * \param r row
 * \param c column
 * \return data in t[r][c]
 */
int fetch(char *t, int r, int c) { return *(t + (c + r * COL)); }

int main(int argc, char **argv) {

  // -----------------------------------------------------------------------------
  LINE_BREAK(1)
  // -----------------------------------------------------------------------------
  char t_0[][COL] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
  printf("%p:%lu (bytes)\n", t_0, sizeof(t_0));
  for (int i_r = 0; i_r < ROW; ++i_r) {
    for (int i_c = 0; i_c < COL; ++i_c) {
      printf("|%p [%d]", &t_0[i_r][i_c], t_0[i_r][i_c]);
    }
    printf("|\n");
  }

  // -----------------------------------------------------------------------------
  LINE_BREAK(1)
  // -----------------------------------------------------------------------------
  size_t sz_t_1 = sizeof(char) * ROW * COL;
  char *t_1 = (char *)malloc(sz_t_1);
  printf("%p:%lu (bytes)\n", t_1, sz_t_1);
  char *p = t_1;
  for (int i_r = 0; i_r < ROW; ++i_r) {
    for (int i_c = 0; i_c < COL; ++i_c) {
      *p = i_c + i_r * COL;
      printf("|%p [%d]", p, *p);
      ++p;
    }
    printf("|\n");
  }

  LINE_BREAK(0)
  printf("Acces to an element [r][c]");
  LINE_BREAK(0)
  printf("%p|[%d][%d]|%d\n", t_1, 1, 1, fetch(t_1, 1, 1));
  printf("%p|[%d][%d]|%d\n", t_1, 2, 0, fetch(t_1, 2, 0));
  printf("%p|[%d][%d]|%d\n", t_1, 2, 1, fetch(t_1, 2, 1));

  if (t_1) {
    free(t_1);
    t_1 = NULL;
  }

  return 0;
}

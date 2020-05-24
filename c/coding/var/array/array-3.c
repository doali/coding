#include <stdio.h>
#include <stdlib.h>

#define PRINT_SZ(T, X) printf("%16s|%4lu bytes\n", T, sizeof(X));
#define PRINT_SZ_N(T, X, N)                                                    \
  printf("%10s (x%2d)|%4lu bytes\n", T, N, sizeof(X) * N);

#define LINE_BREAK printf("\n");
#define LINE_BREAK_SECTION(TITLE)                                              \
  printf(TITLE);                                                               \
  printf("\n");
#define LINE_BREAK_LINE printf("------------------------------------------\n");

typedef struct {
  char c;
  short s;
  int i;
  char *p_c;
  short *p_s;
  int *p_i;
} s_t;

int main(int argc, char **argv) {
  // -----------------------------------------------------------------------------
  LINE_BREAK_LINE

  s_t s = {'c', 1, 1, NULL, NULL, NULL};

  PRINT_SZ("char", s.c);
  PRINT_SZ("short", s.s);
  PRINT_SZ("int", s.i);
  PRINT_SZ("char*", s.p_c);
  PRINT_SZ("short*", s.p_s);
  PRINT_SZ("int*", s.p_i);

  // -----------------------------------------------------------------------------

  // -----------------------------------------------------------------------------
  // ALLOCATION
  // -----------------------------------------------------------------------------

  LINE_BREAK_LINE

  const u_int8_t ROW = 4;
  const u_int8_t COL = 2;

  short **matrix = (short **)malloc(sizeof(int *) * ROW);
  PRINT_SZ("short**", matrix);
  PRINT_SZ_N("short**", matrix, ROW);

  LINE_BREAK
  LINE_BREAK_SECTION("ALLOCATION")
  LINE_BREAK

  if (matrix != NULL) {
    for (u_int8_t i_r = 0; i_r < ROW; ++i_r) {
      matrix[i_r] = (short *)malloc(sizeof(**matrix) * COL);
      //*(matrix + i_r) = (short*)malloc(sizeof(**matrix) * COL);
      for (u_int8_t i_c = 0; i_c < COL; ++i_c) {
        matrix[i_r][i_c] = i_r * COL + i_c;
        printf("%p|[%d][%d]|%d\n", &matrix[i_r][i_c], i_r, i_c,
               matrix[i_r][i_c]);
      }
      printf("\n");
    }
  }
  printf("%p|%lu (bytes)\n", matrix,
         (sizeof(**matrix) * COL * ROW) + (sizeof(int *) * ROW));

  // -----------------------------------------------------------------------------
  // FREE
  // -----------------------------------------------------------------------------

  LINE_BREAK_LINE
  LINE_BREAK_SECTION("DEALLOCATION")
  LINE_BREAK

  // COL
  printf("|%15s||%15s||%10s|\n", "(short**)", "(short*)", "(short)");
  short **p_deallocator = matrix;
  for (u_int8_t row = 0; row < ROW; ++row) {
    printf("|%15p->%15p->%10d|\n", p_deallocator, *(p_deallocator + row) + 0,
           *(*(p_deallocator + row) + 0));
    printf("|%15p->%15p->%10d|\n", p_deallocator, *(p_deallocator + row) + 1,
           *(*(p_deallocator + row) + 1)); // since 2 columns (COL = 2)

    free(*(p_deallocator + row)); // free (short)
    // free(p_deallocator[row]);  // or else, same as above
    *(p_deallocator + row) = NULL; // INIT to NULL
    // p_deallocator[row] = NULL;     // or else, same as above
  }
  // ROW
  free(p_deallocator);  // free (short *)
  p_deallocator = NULL; // INIT to NULL

  LINE_BREAK_LINE

  return 0;
}

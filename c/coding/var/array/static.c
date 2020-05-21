#include <stdio.h>
#include <stdlib.h>

#define FREE(X)                                                                \
  if (X)                                                                       \
    free(X);

#define LINE_BREAK printf("\n");

#define ID(X) printf("%s\n", X);

int *int_arr(unsigned int, int);

void print_int(unsigned int, int *, const char *sep);

int main(int argc, char **argv) {

  // static array
  int s_arr_1[] = {1, 2, 3, 4};
  ID("s_arr_1")
  print_int(4, s_arr_1, ":");

  LINE_BREAK
  // static array
  // const unsigned int SZ_2 = 6; <= DOES NOT WORK FOR ARRAYS
  int s_arr_2[6] = {0};
  // int s_arr_2[SZ_2] = {0}; <= DOES NOT WORK
  ID("s_arr_2")
  print_int(6, s_arr_2, ",");

  LINE_BREAK
  // static array
  int s_arr_3[3] = {};
  ID("s_arr_3")
  print_int(3, s_arr_3, ";");

  LINE_BREAK
  // static array
  int s_arr_4[15] = {1, 2, 5, 4, 3, 234};
  ID("s_arr_4")
  print_int(15, s_arr_4,
            " "); // from index 6 to 14, s_arr_4 values are not initialized

  LINE_BREAK
  // dynamic array
  const int D_ARR_SZ = 10;
  int *d_arr = int_arr(D_ARR_SZ, 4);
  ID("D_ARR_SZ")
  print_int(D_ARR_SZ, d_arr, " ");

  FREE(d_arr)

  LINE_BREAK

  return 0;
}

int *int_arr(unsigned int sz, int init_val) {
  int *arr = (int *)malloc(sizeof(int));
  for (unsigned int index = 0; index < sz; ++index)
    arr[index] = init_val;

  return arr;
}

void print_int(unsigned int sz, int *array, const char *sep) {
  if (array) {
    for (unsigned int index = 0; index < sz; ++index) {
      if (sep)
        printf("%d%s", array[index], sep);
      else
        printf("%d", array[index]);
    }
  }
}

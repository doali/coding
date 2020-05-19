#include "operation.h"
#include <stdio.h>
#include <stdlib.h>

typedef int (*p_f)(int, int);
// typedef int (*t_op[4])(int, int);
typedef p_f t_op[4];

int is_usage(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: %s <number> <number>\n", argv[0]);
    return 1;
  }

  return 0;
}

int main(int argc, char **argv) {
  if (is_usage(argc, argv) > 0)
    return -1;

  int a = atoi(argv[1]);
  int b = atoi(argv[2]);

  t_op t = {&op_add, &op_sub, &op_mul, &op_div};
  const int SZ = sizeof(t) / sizeof(t[0]);
  for (int index = 0; index < SZ; ++index) {
    p_f f = t[index];
    printf("%p|(%d, %d)=%d\n", f, a, b, f(a, b));
  }

  return 0;
}

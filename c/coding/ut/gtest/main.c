#include <stdio.h>
#include <stdlib.h>

void scenario(int, int, int);
void usage(const char *);

/*
int main(int nbargs, char *argv[]) {
  if (nbargs == 4) {
    scenario(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
  } else {

    usage(argv[0]);
  }

  return 0;
}
*/

void usage(const char *prog_name) {
  fprintf(stdout, "Usage %s <int> <int> <int>\n", prog_name);
}

/**
 * @return greatest number
 */
int compare(int a, int b, int c) {
  fprintf(stdout, "%s\n", __func__);
  int max = a;
  if (b > a) {
    max = b;
  }
  if (c > max) {
    max = c;
  }

  return max;
}

void scenario(int a, int b, int c) {
  fprintf(stdout, "%s\n", __func__);
  fprintf(stdout, "%d %d %d\n", a, b, c);
  int max = compare(a, b, c);
  fprintf(stdout, "max : %d\n", max);
}

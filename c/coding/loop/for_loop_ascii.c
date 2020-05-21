#include <stdio.h>

void print_ascii(void);

int main(int argc, char **argv) {
  print_ascii();
  return 0;
}

void print_ascii() {
  for (char c = 'A'; c <= 'z'; ++c) {
    fprintf(stdout, "%c|%d\n", c, c);
  }
}

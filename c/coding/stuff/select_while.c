#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

#define WAIT_SEC 1

typedef int (*condition)(int);

static int counter = 3;

int exit_ifzero(int val) { return (val == 0); }

void wait(unsigned long w_sec) {
  struct timeval tv = {.tv_sec = w_sec, .tv_usec = 0};
  select(1, NULL, NULL, NULL, &tv);
}

void loop(condition exit_if) {
  while (!exit_if(counter)) {
    printf("[%2d]\n", counter--);
    wait(WAIT_SEC);
  }
}

int main(void) {
  printf("start\n");
  while (counter > 0) {
    loop(exit_ifzero);
  }
  printf("stop\n");

  exit(EXIT_SUCCESS);
}

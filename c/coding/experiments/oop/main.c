#ifndef _MAIN_
#define _MAIN_

#include "person.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

Person *new_person(char *, char *);
int *delete_person(Person *);

#define FREE(X)                                                                \
  do {                                                                         \
    if (X) {                                                                   \
      printf("%p|call to free(...)\n", X);                                     \
      free(X);                                                                 \
      X = NULL;                                                                \
    }                                                                          \
  } while (0)

int main(int args, char **argv) {
  printf("args:%d\n", args);
  for (int index_el = 0; index_el < args; index_el++) {
    printf("argv[%d]:%s\n", index_el, argv[index_el]);
  }

  if (args < 3) {
    return -1;
  }

  Person *p = new_person(argv[1], argv[2]);
  char buf[100];
  printf("%s\n", p->meth_1(buf));

  // FREE(p);
  delete_person(p);

  return 0;
}

#endif // _MAIN_

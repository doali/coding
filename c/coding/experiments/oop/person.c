#include "person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef LOG // needed if no -DLOG option while compiling
#define LINE_BREAK printf("%40s:%d\n", __func__, __LINE__);
#else
#define LINE_BREAK printf("\n");
#endif

char *_to_s(char *, Person *);

p_f1 to_str(char *, Person *);

Person *new_person(const char *name, const char *last) {
  Person *p = (Person *)malloc(sizeof(Person));

  if (p != NULL) {
    p->fd_1 = (char *)name;
    p->fd_2 = (char *)last;
    p->meth_1 = to_str(NULL, p);
  }

  LINE_BREAK

  return p;
}

int delete_person(Person *p) {
  if (p != NULL) {
    free(p);
    p = NULL;
  }

  LINE_BREAK

  return (NULL == p) ? 0 : 1;
}

p_f1 to_str(char *buf, Person *p) {
  char *to_s(char *buf) {
    snprintf(buf, 100, "{%s, %s}", p->fd_1, p->fd_2);

    return buf;
  }

  p_f1 pf_to_s = to_s;

  return pf_to_s;
}

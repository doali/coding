#ifndef _PERSON_
#define _PERSON_

typedef struct person Person;
typedef char *(*p_f1)(char *);

struct person {
  char *fd_1;
  char *fd_2;
  p_f1 meth_1;
};

#endif // _PERSON_

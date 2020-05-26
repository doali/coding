#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_BREAK printf("\n")

typedef struct {
  char c;   // 1 byte
  int i;    // 4 bytes
  double d; // 8 bytes
  short s;  // 2 bytes
} s_0;

typedef struct {
  double d; // 8 bytes
  int i;    // 4 bytes
  short s;  // 2 bytes
  char c;   // 1 byte
} s_1;

typedef struct {
  int i;    // 4 bytes
  short s;  // 2 bytes
  char c;   // 1 byte
  double d; // 8 bytes
} s_2;

typedef enum { T_0, T_1, T_2, SZ_T } e_t;

typedef struct {
  e_t t;
  union {
    s_0 *s0;
    s_1 *s1;
    s_2 *s2;
  } u;
} s_g;

size_t sz_str(e_t t) {
  size_t sz = 0;
  switch (t) {
  case T_0:
    sz = sizeof(s_0);
    break;
  case T_1:
    sz = sizeof(s_1);
    break;
  case T_2:
    sz = sizeof(s_2);
    break;
  default:
    printf("Error s_str\n");
    break;
  }

  return sz;
}

void print_s_0(s_0 *);
void print_s_1(s_1 *);
void print_s_2(s_2 *);

int print_s(s_g *p_s) {
  int type = -1;

  switch (p_s->t) {
  case T_0: {
    print_s_0((s_0 *)p_s->u.s0);
    type = T_0;
    break;
  }
  case T_1: {
    print_s_1((s_1 *)p_s->u.s1);
    type = T_1;
    break;
  }
  case T_2: {
    print_s_2((s_2 *)p_s->u.s2);
    type = T_2;
    break;
  }
  default: {
    printf("Error print_s\n");
    break;
  }
  }

  return type;
}

void print_s_0(s_0 *p) {
  printf("%20p|%4lu (octets)|%20c|%8s|\n", &p->c, sizeof(p->c), p->c, "char");
  printf("%20p|%4lu (octets)|%20i|%8s|\n", &p->i, sizeof(p->i), p->i, "int");
  printf("%20p|%4lu (octets)|%20d|%8s|\n", &p->s, sizeof(p->s), p->s, "short");
  printf("%20p|%4lu (octets)|%20f|%8s|\n", &p->d, sizeof(p->d), p->d, "double");
}

void print_s_1(s_1 *p) {
  printf("%20p|%4lu (octets)|%20c|%8s|\n", &p->c, sizeof(p->c), p->c, "char");
  printf("%20p|%4lu (octets)|%20i|%8s|\n", &p->i, sizeof(p->i), p->i, "int");
  printf("%20p|%4lu (octets)|%20d|%8s|\n", &p->s, sizeof(p->s), p->s, "short");
  printf("%20p|%4lu (octets)|%20f|%8s|\n", &p->d, sizeof(p->d), p->d, "double");
}

void print_s_2(s_2 *p) {
  printf("%20p|%4lu (octets)|%20c|%8s|\n", &p->c, sizeof(p->c), p->c, "char");
  printf("%20p|%4lu (octets)|%20i|%8s|\n", &p->i, sizeof(p->i), p->i, "int");
  printf("%20p|%4lu (octets)|%20d|%8s|\n", &p->s, sizeof(p->s), p->s, "short");
  printf("%20p|%4lu (octets)|%20f|%8s|\n", &p->d, sizeof(p->d), p->d, "double");
}

int main(int argc, char **argv) {
  s_0 s0 = {'z', 1, 1.0, 1};
  s_1 s1 = {1.0, 1, 1, 'c'};
  s_2 s2 = {1, 1, 'r', 1.0};

  s_g sg0 = {T_0, {&s0}};
  s_g sg1 = {T_1, .u.s1 = &s1};
  s_g sg2 = {T_2, .u.s2 = &s2};

  s_g *p_s[SZ_T] = {&sg0, &sg1, &sg2};

  for (u_char t = T_0; t < SZ_T; ++t) {
    int type = print_s(p_s[t]);
    printf("SZ: %4lu (octets)\n", sz_str((e_t)type));
    LINE_BREAK;
  }

  return 0;
}

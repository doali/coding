#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_BREAK printf("\n");

struct no_align {
  char c;      // 1 => +7
  double d;    // 8
  int i;       // 4
  char t_c[3]; // 3
               // padding => +1
};

typedef struct align {
  double d;    // 8
  int i;       // 4
  char t_c[3]; // 3
  char c;      // 1
} s_align;

enum e_type { S_NO, S_YES };

typedef struct {
  enum e_type type;
  union {
    struct align *s_a;
    struct no_align *s_no;
  };
} s_g;

void p_sno(struct no_align *p) {
  printf("%20p|%4lu (octets)|%20c\n", &p->c, sizeof(p->c), p->c);
  printf("%20p|%4lu (octets)|%20f\n", &p->d, sizeof(p->d), p->d);
  printf("%20p|%4lu (octets)|%20i\n", &p->i, sizeof(p->i), p->i);
  printf("%20p|%4lu (octets)|%20s\n", &p->t_c, sizeof(p->t_c), p->t_c);
}

void p_sa(struct align *p) {
  printf("%20p|%4lu (octets)|%20f\n", &p->d, sizeof(p->d), p->d);
  printf("%20p|%4lu (octets)|%20i\n", &p->i, sizeof(p->i), p->i);
  printf("%20p|%4lu (octets)|%20s\n", &p->t_c, sizeof(p->t_c), p->t_c);
  printf("%20p|%4lu (octets)|%20c\n", &p->c, sizeof(p->c), p->c);
}

void p_s(s_g *p_s_g) {
  switch (p_s_g->type) {
  case S_NO: {
    p_sno((struct no_align *)p_s_g->s_no);
    break;
  }
  case S_YES: {
    p_sa((struct align *)p_s_g->s_a);
    break;
  }
  default:
    perror("Error\n");
  }
}

int main(int argc, char **argv) {
  s_g p_s_g;

  struct no_align n_align = {'z', 10, 1, {'a', 'b', '\0'}};

  p_s_g.type = S_NO;
  p_s_g.s_no = &n_align;

  p_s(&p_s_g);

  LINE_BREAK
  printf("SZ: %4lu (octets)\n", sizeof(n_align));

  LINE_BREAK

  s_align align;
  align.d = 10;
  align.i = 1;
  align.t_c[0] = 'a';
  align.t_c[1] = 'b';
  align.t_c[2] = '\0';
  align.c = 'z';

  p_s_g.type = S_YES;
  p_s_g.s_a = &align;

  p_s(&p_s_g);

  LINE_BREAK
  printf("SZ: %4lu (octets)\n", sizeof(align));

  return 0;
}

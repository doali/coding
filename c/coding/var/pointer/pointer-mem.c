#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRINT_C(C) printf("data   %4lu (bytes)|%20p|%20c|\n", sizeof(C), &C, C);
#define PRINT_P_C(P_C)                                                         \
  printf("data   %4lu (bytes)|%20p|%20p|%20c|\n", sizeof(P_C), &P_C, P_C, *P_C);
#define PRINT_P_S(P_S)                                                         \
  printf("data   %4lu (bytes)|%20p|%20p|%20s|\n", sizeof(P_S), &P_S, P_S, P_S);
#define PRINT_I(I) printf("data   %4lu (bytes)|%20p|%20d|\n", sizeof(I), &I, I);
#define PRINT_P_I(P_I)                                                         \
  printf("data   %4lu (bytes)|%20p|%20p|%20d|\n", sizeof(P_I), &P_I, P_I, *P_I);

#define PRINT_TAB(T)                                                           \
  printf("%p|T\n", T);                                                         \
  printf("%p|&T\n", &T);                                                       \
  printf("%p|&T[0]\n", &T[0]);

#define FREE(X)                                                                \
  if (X != NULL) {                                                             \
    printf("free(%p)\n", X);                                                   \
    free(X);                                                                   \
    X = NULL;                                                                  \
  }

struct no_align {
  char c;
  double d;
  int i;
  char t_c[3];
};

struct align {
  double d;
  int i;
  char t_c[3];
  char c;
};

void print_mem(const char *, uint);

void test_char() {
  char c_1 = 'a';
  char c_2 = 'b';
  char c_3 = 'c';
  PRINT_C(c_1)
  PRINT_C(c_2)
  PRINT_C(c_3)

  char *p_c1 = &c_1;
  char *p_c2 = &c_2;
  char *p_c3 = &c_3;
  PRINT_P_C(p_c1)
  PRINT_P_C(p_c2)
  PRINT_P_C(p_c3)

  int i_1 = 1;
  int i_2 = 2;
  PRINT_I(i_1)
  PRINT_I(i_2)

  int *p_i1 = &i_1;
  int *p_i2 = &i_2;
  PRINT_P_I(p_i1)
  PRINT_P_I(p_i2)

  print_mem(&c_1, 100);
}

void test_str() {
  const char *str = "bleue comme une orange";
  // char *str = "bleue comme une orange";
  PRINT_P_S(str);

  const char t_str[] = {'y', 'o', 'l', 'e', 'n', 'e', '\0'};
  // char t_str[] = {'y', 'o', 'l', 'e', 'n', 'e', '\0'};
  PRINT_P_S(t_str);
  PRINT_TAB(t_str);

  {
    const char *p_it = t_str;
    const unsigned int SZ = sizeof(t_str[0]);
    while (*p_it != '\0') {
      PRINT_P_C(p_it);
      p_it += SZ;
    }
  }

  printf("size(%s)=%lu\n", str, strlen(str));

  char *m_str = (char *)malloc(sizeof(char) * (strlen(str) + 1));
  memcpy(m_str, str, sizeof(char) * (strlen(str) + 1));
  // m_str[strlen(str)] = '\0';
  PRINT_P_S(m_str);

  printf("%s\n", m_str);

  print_mem(str, 40);
  print_mem(t_str, 40);
  print_mem(m_str, 40);

  FREE(m_str)
}

void test_memcpy() {
  printf("|%c|%d|\n", '\0', '\0');

  char t_titi[] = {'t', 'i', 't', 'i', '\0'};
  printf("%20p|%s %lu %lu\n", t_titi, t_titi, sizeof(t_titi), strlen(t_titi));

  const char *s_titi = "titi";
  printf("%20p|%s %lu %lu\n", s_titi, s_titi, sizeof(s_titi), strlen(s_titi));

  char *b_titi = (char *)malloc(sizeof(char) * (strlen(s_titi) + 1));
  memcpy(b_titi, t_titi, (strlen(s_titi) + 1));
  printf("%20p|%s %lu %lu\n", b_titi, b_titi, sizeof(b_titi), strlen(b_titi));

  print_mem(t_titi, 10);
  print_mem(s_titi, 10);
  print_mem(b_titi, 10);

  FREE(b_titi)
}

int main(int argc, char **argv) {
  test_char();
  test_str();
  test_memcpy();
}

void print_mem(const char *p, uint size) {
  printf("MEM (begining):%p\n", p);
  for (unsigned long i = 0; i < size; ++i) {
    printf("offset %4lu (bytes)|%20p|%20c|%20d|\n", i, p, *p /* -> char */,
           *p /* -> int */);
    ++p;
  }
  printf("MEM (end):%p\n", p);
}

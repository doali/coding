#include <stdio.h>
#include <stdlib.h>

#define FREE(X)                                                                \
  if (X) {                                                                     \
    free(X);                                                                   \
    X = NULL;                                                                  \
  }

typedef struct {
  long long int m_l_l_i; // 8
  long long m_l_l;       // 8
  long int m_l_i;        // 8
  long m_l;              // 8
  int m_i;               // 4
  short int m_s_i;       // 2
  short m_s;             // 2
  char m_c;              // 1 (+7 padding)
} s_type;

int print_line(char **hyphen, const unsigned int size) {
  unsigned int sz = size + 1;
  *hyphen = (char *)malloc(sizeof(char) * sz);
  if (!*hyphen)
    return -1;

  (*hyphen)[size] = '\0';
  for (unsigned int i = 0; i < size; ++i) {
    (*hyphen)[i] = '-';
  }

  return 0;
}

int main(int argc, char **argv) {
  s_type s_t = {33, 32, 31, 30, 22, 11, 10, 'a'};

  char *hyphen = NULL;
  printf("%-14s|%-14s|%-14s|%-14s\n", "@", "TYPE", "byte(s)", "value");
  if (!print_line(&hyphen, 14)) {
    printf("%s|%s|%s|%s\n", hyphen, hyphen, hyphen, hyphen);

    printf("%-14p|%-14s|%-14lu|%lld\n", &s_t.m_l_l_i, "long long int",
           sizeof(s_t.m_l_l_i), s_t.m_l_l_i);
    printf("%-14p|%-14s|%-14lu|%lld\n", &s_t.m_l_l, "long long",
           sizeof(s_t.m_l_l), s_t.m_l_l);
    printf("%-14p|%-14s|%-14lu|%ld\n", &s_t.m_l_i, "long int",
           sizeof(s_t.m_l_i), s_t.m_l_i);
    printf("%-14p|%-14s|%-14lu|%ld\n", &s_t.m_l, "long", sizeof(s_t.m_l),
           s_t.m_l);
    printf("%-14p|%-14s|%-14lu|%d\n", &s_t.m_i, "int", sizeof(s_t.m_i),
           s_t.m_i);
    printf("%-14p|%-14s|%-14lu|%d\n", &s_t.m_s_i, "short int",
           sizeof(s_t.m_s_i), s_t.m_s_i);
    printf("%-14p|%-14s|%-14lu|%d\n", &s_t.m_s, "short", sizeof(s_t.m_s),
           s_t.m_s);
    printf("%-14p|%-14s|%-14lu|%c\n", &s_t.m_c, "char", sizeof(s_t.m_c),
           s_t.m_c);
  }
  printf("%lu (struct) \n", sizeof(s_t));
  unsigned long sz = sizeof(char) + sizeof(short) + sizeof(short int) +
                     sizeof(int) + sizeof(long) + sizeof(long int) +
                     sizeof(long long) + sizeof(long long int);

  printf("%lu (aligned) == %lu (sum of each member size)\n", sizeof(s_t), sz);

  FREE(hyphen);

  return 0;
}

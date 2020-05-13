#include <stdio.h>
#include <stdlib.h>

#define LINE_BREAK printf("\n");

typedef struct node node_t;

struct node {
  int val;
  node_t *next;
};

void print_l(node_t *l) {
  node_t *p_l = l;
  while (p_l != NULL) {
    printf("%p -> [%d | %p]\n", p_l, p_l->val, p_l->next);
    p_l = p_l->next;
  }
}

void print_t_n(int sz, node_t *t_l[sz]) {
  for (int i = 0; i < sz; ++i) {
    printf("%p -> [%d | %p]\n", t_l[i], t_l[i]->val, t_l[i]->next);
  }
}

int main(int argc, char **argv) {
  int i = 1;
  int *p_i = &i;

  printf("%p|%d\n", &i, i);
  printf("%p|%d\n", p_i, *p_i);

  LINE_BREAK
  node_t l_4 = {4, NULL};
  node_t l_3 = {3, &l_4};
  node_t l_2 = {2, &l_3};
  node_t l_1 = {1, &l_2};

  printf("%p|&l_1\n", &l_1);

  LINE_BREAK
  print_l(&l_1);

  LINE_BREAK
  node_t *t_l[4] = {&l_1, &l_2, &l_3, &l_4};
  print_t_n(4, t_l);

  LINE_BREAK
  print_l(NULL);
  print_t_n(0, NULL); // BAD

  return 0;
}

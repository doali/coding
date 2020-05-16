#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *next;
} node_t;

int pop(node_t **head) {
  int retval = -1;
  node_t *next_node = NULL;

  if (*head == NULL) {
    return -1;
  }

  next_node = (*head)->next;
  retval = (*head)->val;
  free(*head);
  *head = next_node;

  return retval;
}

int remove_by_value(node_t **head, int val) {
  // TODO
  return 0;
}

void print_list(node_t *l) {
  node_t *p = (node_t *)l;
  printf("[");
  while (p != NULL) {
    printf("%d", p->val);
    if (p->next != NULL)
      printf(", ");
    p = p->next;
  }
  printf("]\n");
}

int main(int argc, char **argv) {
  node_t *test_list = (node_t *)malloc(sizeof(node_t));
  test_list->val = 1;
  test_list->next = (node_t *)malloc(sizeof(node_t));
  test_list->next->val = 2;
  test_list->next->next = (node_t *)malloc(sizeof(node_t));
  test_list->next->next->val = 3;
  test_list->next->next->next = (node_t *)malloc(sizeof(node_t));
  test_list->next->next->next->val = 4;
  test_list->next->next->next->next = NULL;

  print_list(test_list);

  if (argc == 2) {
    remove_by_value(&test_list, atoi(argv[1]));
  }

  print_list(test_list);
  print_list(NULL);
}

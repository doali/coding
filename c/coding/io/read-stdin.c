#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MESS_QUIT ("Quit ? [y / n]:")

/*
 * This program is NOT CORRECT
 * It seems to be but many problems can occur
 * due to scanf, fgetc...
 */

void table_scenario(void);
int *create_table(unsigned int n_e);
void delete_table(int *p);
void fill_table(int n, int *table);
void print_table(int n, int *t);

void fill_table(int n, int *table) {
  assert(n >= 0);

  if (table) {
    for (int index = 0; index < n; ++index) {
      printf("[%d]:", index);
      scanf("%d", (table + index));
    }
    fgetc(stdin);
  }

  return;
}

int *create_table(unsigned int n_e) {
  assert(n_e >= 0);

  int *p_i = NULL;

  if (n_e > 0)
    p_i = (int *)malloc(sizeof(int) * n_e);

  return p_i;
}

void delete_table(int *p) {
  if (p) {
    free(p);
    p = NULL;
  }
  return;
}

void print_table(int n, int *t) {
  assert(n >= 0);

  printf("[");

  if (t) {
    for (int index = 0; index < n; ++index) {
      printf(" %d", t[index]);
    }
  }

  printf(" ]\n");

  return;
}

void table_scenario() {
  unsigned int sz = 0;
  int *t = NULL;

  printf("Array size:");
  scanf("%d", &sz);

  t = create_table(sz);
  fill_table(sz, t);
  print_table(sz, t);
  delete_table(t);

  return;
}

void select_getchar(void (*f)(void)) {
  do {
    f();

    printf("\n");

    printf(MESS_QUIT);
    if (getchar() == 'y') {
      break;
    }
    getchar(); // capture le caractère rendu par <enter>
               // nécessaire, sinon on refait un tour de boucle
               // avec comme valeur saisie <enter>

  } while (1);

  return;
}

void do_1() { printf(__func__); }
void do_2() { printf(__func__); }
void do_3() { printf(__func__); }

void select_fgetc(void (*f)(void)) {
  do {
    f();

    printf("\n");

    printf(MESS_QUIT);
    if (fgetc(stdin) == 'y') {
      break;
    }
    fgetc(stdin);

  } while (1);

  return;
}

int main(int argc, char **argv) {

  // select_getchar(do_1);
  // select_fgetc(do_2);

  // select_getchar(table_scenario);
  select_fgetc(table_scenario);

  return 0;
}

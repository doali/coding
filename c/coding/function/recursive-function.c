#include <stdio.h>
#include <stdlib.h>

/*
 * Recursive function
 */
int len(const char *p) { return (!p || *p == '\0') ? 0 : (1 + len(p + 1)); }

void print_char(const char *p_str) {
  printf("[");
  if (p_str) {
    // Important : use another pointer to keep clean original pointer
    for (const char *p_curr = p_str; *p_curr != '\0'; ++p_curr) {
      printf("%c", *p_curr);
      if (*(p_curr + 1) != '\0')
        printf(", ");
    }
  }
  printf("]\n");
}

int main(int argc, char **argv) {

  struct s { // struct declaration + definition
    int i;
    const char *str;
  } s_s, s_s_2 = {2, "s_s_2"}; // VARIABLES definitions

  s_s.i = 1;       // initialization
  s_s.str = "s_s"; // initialization

  typedef struct s S;
  void print_s(S * p_s) {
    if (!p_s)
      printf("%p\n", p_s);

    // Memory alignment !!
    printf("%p|%ld|\n", p_s, sizeof(*p_s));
    printf("%p|%ld|i:%d\n", &(p_s->i), sizeof(p_s->i), p_s->i);
    printf("%p|%ld|str:%s\n", &(p_s->str), sizeof(p_s->str), p_s->str);
  }

  print_s(&s_s);
  print_s(&s_s_2);

  const char *p_str = "p_str";
  printf("%s\n", p_str);
  print_char(p_str);

  print_char(NULL);

  const char t_b[] = {'b', 'o', 'n', 'j', 'o', 'u', 'r', '\0'};
  printf("%s\n", t_b);
  printf("len(%s)=%d\n", t_b, len(t_b));

  printf("len(NULL)=%d\n", len(NULL));
  printf("len(%s)=%d\n", "", len(""));
  printf("len(%s)=%d\n", "abc", len("abc"));

  return 0;
}

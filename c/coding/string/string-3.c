#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FREE(X)                                                                \
  if (X) {                                                                     \
    printf(">>> free pointer >>>>>>>>>>>>>>>>>>>>>\n");                        \
    printf("%14s|%14s|\n", "&X", "X");                                         \
    printf("%14p|%14p|free(X)\n", &X, X);                                      \
    free(X);                                                                   \
    X = NULL;                                                                  \
    printf("%14p|%14p|X = NULL\n", &X, X);                                     \
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");                        \
  }

void display_buf(const char *, const u_int32_t, const char *);

int main(int argc, char *argv) {
  // --- strlen(...)
  const char *str_0 = "This is a const char*";
  printf("%s\n", str_0);
  unsigned long str_0_sz = strlen(str_0);
  printf("strlen(%s)=%lu\n", str_0, str_0_sz);

  // char *strcpy(char *dest, const char *src); <= (!) '\0' is COPIED !! :-)
  /*
   * char *strncpy(char *dest, const char *src, size_t n);
   * <= '\0' COPIED if enough space (dest) !!
   */
  char *m_str_0 = (char *)malloc(sizeof(char) * (strlen(str_0) + 1));
  strncpy(m_str_0, str_0, strlen(str_0) + 1);
  printf("%s\n", str_0);
  printf("%s\n", m_str_0);
  display_buf(m_str_0, 40, "m_str_0");
  display_buf(str_0, 40, "str_0");

  FREE(m_str_0);

  // char *strcat(char *dest, const char *src); <= (!) '\0' is added, ending
  // dest !! :-)
  /*
   * char *strncat(char *dest, const char *src, size_t n);
   * <= '\0' ADDED if enough space (dest) !!
   */
  char b_str_0[32] = "first part message";
  char b_str_1[32] = ", second part";
  printf("%s\n", b_str_0);
  printf("%s\n", b_str_1);
  display_buf(b_str_0, 40, "b_str_0");
  display_buf(b_str_1, 40, "b_str_1");
  strcat(b_str_0, b_str_1);
  printf("%s\n", b_str_0);
  display_buf(b_str_0, 40, "b_str_0");

  return 0;
}

void display_buf(const char *t_b, const u_int32_t sz, const char *name) {
  printf(">>> buffer >>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
  printf("%s\n", name);
  printf("--------------------------------------\n");
  for (u_int64_t index = 0; index < sz; ++index) {
    printf("%4lu|%10p|%c\n", index, t_b + index, *(t_b + index));
  }
  printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
}

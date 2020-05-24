#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SZ 16

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

void display_buf(char *, const u_int32_t, const char *);

int main(int argc, char **argv) {
  // --- buffer
  char t_b[BUF_SZ] = {121}; // y <= char
  display_buf(t_b, BUF_SZ, "t_b");

  char str[] = {'a', 'b', 'c', 'D', 'e', 'f', '\0'}; // do not forget '\0'
  printf("%s\n", str);
  printf("%c\n", *(str + 1));
  str[0] = 'C'; // OK since we have a buffer of char

  // --- dynamic char
  char *s = (char *)malloc(sizeof(char) * BUF_SZ);
  // (!) provide enough space for '\0' at the end
  memcpy(s, str, strlen(str) + 1); // +1 <= for '\0'
                                   // terminal $ man memcpy
  printf("%s\n", s);
  s[0] = 'k';
  printf("%c\n", *(s + 3));
  display_buf(s, sizeof(char) * strlen(s) + 1, "s");

  FREE(s);

  return 0;
}

void display_buf(char *t_b, const u_int32_t sz, const char *name) {
  printf(">>> buffer >>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
  printf("%s\n", name);
  printf("--------------------------------------\n");
  for (u_int64_t index = 0; index < sz; ++index) {
    printf("%4lu|%10p|%c\n", index, t_b + index, *(t_b + index));
  }
  printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
}

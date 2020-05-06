#include <stdio.h>
#include <stdlib.h>

// stddef.h ANSI

#define TAB_SZ 8

enum chp { SHORT = 4, LONG = 8 };

typedef char UNSIGNED_8BITS;
typedef char *STRING;
typedef char *CHAPTER_S[SHORT];
typedef char *CHAPTER_L[LONG];
typedef int TAB_8[TAB_SZ];

int main(int argc, char **argv) {
  // ---
  UNSIGNED_8BITS c = 'c';
  printf("%c\n", c);

  // ---
  STRING str = (char *)("This is a simple message");
  printf("%s\n", str);

  // ---
  CHAPTER_S chp_s = {"un", "deux", "trois", "quatre"};
  for (int i_s = 0; i_s < SHORT; ++i_s) {
    printf("%s\n", chp_s[i_s]);
  }

  // ---
  CHAPTER_L chp_l = {"Un", "Deux", "Trois", "Quatre",
                     "uN", "dEux", "tRois", "qUatre"};
  STRING *p_s;
  for (p_s = &chp_l[0]; p_s != &chp_l[LONG]; ++p_s) {
    printf("%s\n", *p_s);
  }

  // ---
  TAB_8 t = {0};
  for (int i = 0; i < TAB_SZ; ++i) {
    printf("[%d]:%d\n", i, t[i]);
  }

  return EXIT_SUCCESS;
}

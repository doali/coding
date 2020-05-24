#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FREE(X)                                                                \
  if (X) {                                                                     \
    printf("%p|call to free(...)\n", X);                                       \
    free(X);                                                                   \
    X = NULL;                                                                  \
  }

#define CHECK_NULL(X)                                                          \
  if (X)                                                                       \
    printf("%p|%p\n", &X, X);                                                  \
  else                                                                         \
    printf("%p|%p\n", &X, X);

//#define LOG
#ifdef LOG
/*
 * #ifdef LOG
 * we can comment this line even if we want to use LOG
 * provided we compile this way
 * gcc -DLOG -o string string.c
 */
#define LINE_BREAK printf("%80s:%d\n", __func__, __LINE__);
#else
#define LINE_BREAK printf("\n");
#endif

int main(int argc, char **argv) {
  char s_0[] = "one extra char at the end, be careful"; // + '\0'
  printf("%2lu|%s", strlen(s_0), s_0);

  const char s_1[] = "constant string";
  LINE_BREAK
  printf("%2lu|%s", strlen(s_1), s_1);

  const char s_2[11] = "abcdefghij"; // abcdefghij + '\0'
  LINE_BREAK
  printf("%2lu|%s", strlen(s_2), s_2);

  const char s_2_1[20] = "abcdefghij"; // abcdefghij + '\0'
  LINE_BREAK
  printf("%2lu|%s", strlen(s_2), s_2);
  LINE_BREAK
  printf("s_2_1 <===== \n");
  for (int i = 0; i < 20; ++i) {
    printf("%2u|%c\n", i, s_2_1[i]);
  }
  printf("s_2_1 =====>");

  char s_3[] = {'a', 'b', 'c', '\0'};
  LINE_BREAK
  printf("%2lu|%s", strlen(s_3), s_3);

  char s_4[] = "abc";
  LINE_BREAK
  printf("%2lu|%s", strlen(s_4), s_4);

  // ---

  char *str_3 = (char *)"dynamic string str3";
  LINE_BREAK
  printf("%2lu|%str", strlen(str_3), str_3);

  char *str_4 = (char *)"dynamic string str4";
  LINE_BREAK
  printf("%2lu|%str", strlen(str_4), str_4);

  const char *str_5 = "dynamic string str5";
  LINE_BREAK
  printf("%2lu|%str", strlen(str_5), str_5);

  const char *const str_6 = "dynamic string str5";
  LINE_BREAK
  printf("%2lu|%str", strlen(str_6), str_6);

  // ---

  LINE_BREAK
  const unsigned int SZ_0 = 15;
  char *str_7 = (char *)malloc(sizeof(char) * SZ_0);
  if (str_7) {
    const unsigned int TRANSLATION = 65;
    unsigned int i = 0;
    for (; i < (SZ_0 - 1); ++i) {
      *(str_7 + i) = (char)(i + TRANSLATION);
      printf("%2u|%10p|%c\n", i, str_7 + i, *(str_7 + i));
    }
    *(str_7 + (SZ_0 - 1)) = '\0';
    LINE_BREAK
    printf("%2u|%10p|%c (<= '\\0')\n", i, str_7 + i, *(str_7 + i));

    LINE_BREAK
    printf("%2u|%10p|%s\n", 0, str_7, str_7);
  }

  LINE_BREAK
  CHECK_NULL(str_7)
  FREE(str_7)
  CHECK_NULL(str_7)

  return 0;
}

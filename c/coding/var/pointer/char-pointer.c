#include <stdio.h>
#include <stdlib.h>

#define LINE_BREAK printf("\nsrc_line:%d ---\n\n", __LINE__)

int main(int argc, char **argv) {
  // ---------------------------------------------------------------------------
  // memory
  // ---------------------------------------------------------------------------
  // char : 1 byte
  // void : 8 bytes (since x86_64 arch)
  printf("%lu byte|char\n", sizeof(char));
  printf("%lu bytes|void*\n", sizeof(void *));

  LINE_BREAK;

  const char *word = "hello";

  printf("%p|->%s\n", &word, word);
  printf("%p|%c\n", word, *word);
  printf("%p|%c\n", word, word[0]);
  printf("%p|%s\n", word, word);

  LINE_BREAK;

  for (const char *p_c = word; *p_c != '\0'; ++p_c) {
    // ++p_c <= 1 byte since size(char) == 1
    printf("%p|%c\n", p_c, *p_c);
  }

  LINE_BREAK;

  for (int index = 0; word[index] != '\0'; ++index) {
    printf("%p|%c\n", &(word[index]), word[index]);
  }

  LINE_BREAK;

  void *p_void = NULL;
  printf("%lu|%p\n", sizeof(p_void), p_void);
  printf("%lu|%p\n", sizeof(p_void), p_void);

  // const char *p_char = "p_char";
  const char p_char[] = "p_char"; // {'p', '_', 'c', 'h', 'a', 'r', '\0'}
  printf("%lu|%p|%s (%lu bytes)\n", sizeof(p_char), p_char, p_char,
         sizeof(p_char));

  LINE_BREAK;

  const char t[] = "coucou"; // {'c', 'o', 'u', 'c', 'o', 'u', '\0'}
                             // => (-1) /* in the loop !! */
  for (size_t index = 0; index < (sizeof(t) / sizeof(t[0])) - 1; ++index) {
    printf("%p|%c\n", &t[index], t[index]);
  }

  LINE_BREAK;

  // ---------------------------------------------------------------------------
  //
  const char *t_word[] = {"hello", " ",
                          "world"}; // array of POINTERs => 8 bytes each

  // https://stackoverflow.com/questions/37538/how-do-i-determine-the-size-of-my-array-in-c
  size_t s_t_word = sizeof(t_word) / sizeof(const char *);
  for (size_t index = 0; index < s_t_word; ++index) {
    printf("%p|->%s\n", &t_word[index], t_word[index]);
  }

  return 0;
}

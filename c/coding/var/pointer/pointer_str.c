#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FREE(POINTER)                                                          \
  printf(" --- FREE [POINTER]\n");                                             \
  if (POINTER) {                                                               \
    printf("%p -> %p\n", &POINTER, POINTER);                                   \
    free(POINTER);                                                             \
    POINTER = NULL;                                                            \
    printf("free(POINTER)\n");                                                 \
    printf("%p -> %p\n", &POINTER, POINTER);                                   \
  }

int create_buff(char **buff, int size) {
  *buff = (char *)malloc(sizeof(char) * size);

  return (*buff) ? EXIT_SUCCESS : EXIT_FAILURE;
}

int main(int argc, char **argv) {
  const char *MESSAGE = "Ceci est un message";
  printf("MESSAGE :%s\n", MESSAGE);

  // ---
  char *buff = NULL;
  const int SUCCESS =
      create_buff(&buff, 1024); // 1024 octects since 1 char => 1 octec

  if (SUCCESS) {
    strcpy(buff, MESSAGE); // strcpy ends with '\0' in buff
    printf("Buffer (malloc): %s", buff);
  }
  // ---
  FREE(buff)

  // ---
  char buf[strlen(MESSAGE) + 1]; // +1 for '\0'
  strcpy(buf, MESSAGE);          // strcpy ends with '\0' in buff
  printf("Buffer (stack) :%s\n", buf);

  // ---
  char *word = (char *)malloc(sizeof(char) * 100);
  if (word) {
    strcpy(word, MESSAGE); // strcpy ends with '\0' in buff
    printf("Word :%s\n", word);
  }
  // ---
  FREE(word)

  return EXIT_SUCCESS;
}

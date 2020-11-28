#include <stdio.h>

void str2ascii(char* msg) {
  if (msg == NULL) {
    return;
  }

  char *p_msg = msg;
  while (*p_msg != '\0') {
    printf("%c|%d\n", *p_msg, *p_msg);
    ++p_msg;
  }
}

int main(int argn, char **argv) {
  int index = argn - 1;
  do {
    printf("[%d]:%s\n", index, argv[index]);
    str2ascii(argv[index]);
    --index;
  } while (index >= 0);

  return 0;
}
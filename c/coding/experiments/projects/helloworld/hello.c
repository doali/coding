#include <stdio.h>
#include <string.h> // strlen

void str2ascii(char *msg)
{
  if (msg == NULL)
  {
    return;
  }

  char *p_msg = msg;
  while (*p_msg != '\0')
  {
    printf("|%c|%3d|\n", *p_msg, *p_msg);
    ++p_msg;
  }
}

int str2ascii_(const char *str)
{
  if (str == NULL)
    return -1;
  size_t sz = strlen(str);
  for (int index = 0; index < sz; index++)
  {
    printf("|%3d|%c|\n", str[index], str[index]);
  }
  return 0;
}

int main(int argn, char **argv)
{
  int index = argn - 1;
  do
  {
    printf("[%d]:%s\n", index, argv[index]);
    str2ascii(argv[index]);
    --index;
  } while (index >= 0);

  return 0;
}

#include <stdio.h>
#include <unistd.h>

typedef char BUFF_1024[1024];

int main(int argc, char **argv) {
  BUFF_1024 buf = {'\0'};

  gethostname(buf, 1024);
  printf("%s\n", buf);

  return 0;
}

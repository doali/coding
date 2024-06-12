#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy_and_print_string(const char *str) {
    char buf[32];
    strcpy(buf, str);
    printf(buf);
    printf("\n");

}

int main(int argc, char *argv[]) {
    copy_and_print_string(argv[1]);
    exit(EXIT_SUCCESS);
}
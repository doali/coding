#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Le CANARI
// - sans le canari pas détection
// - avec le canari, on a une détection à la compilation
// Consequence, on appelle une fonction "check" et le programme
// est plus gros

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
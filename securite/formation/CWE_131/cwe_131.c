#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
    création d'un buffer de N bytes
*/
int main(int argc, char** argv) {
    int len; // transformer en uint32_t
    char* str;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <len>\n", argv[0]);
        exit(1);
    }

    len = atoi(argv[1]);

    if (len < 0) return 1; // ajouter un controle tout simplement ici

    len++;  // pour le NULL final d'une chaine de caractères

    str = malloc(len);
    assert(str != NULL);

    printf("Vous avez créé un buffer de %d bytes\n", len);

    return (0);
}
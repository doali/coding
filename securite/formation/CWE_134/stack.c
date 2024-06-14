#include "stdio.h"

// julianor.tripod.com <3

// Desactiver l'ASLR (pour eviter les adresses random)
// - dans mon cas, pas la peine, le random ne marche pas..

// L'idee derriere le CW3_134 est

int add(int a, int b){
    int buff[255];
    int t = a + b;
    return t;
}

int main(int argc, char** argv){
    int buff[255];
    int i = 40;
    int j = 2;
    int nb = 0;

    int t = add(i,j);

    printf("%d + %d = %d\n",i,j,t);
    printf("hello\n%n", &nb);
    printf("nb : %d\n", nb);
    printf("i = %2$d, j = %1$d\n", j, i);    
}

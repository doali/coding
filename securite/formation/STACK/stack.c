#include "stdio.h"

int add(int a, int b){
    int buff[255];
    int t = a + b;
    return t;
}

int main(int argc, char** argv){
    int buff[255];
    int i = 40;
    int j = 2;

    int t = add(i,j);

    printf("%d + %d = %d\n",i,j,t);
}
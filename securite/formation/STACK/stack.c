#include "stdio.h"

int add(int a, int b){
    int t = a + b;
    return t;
}

int main(int argc, char** argv){
    int i = 40;
    int j = 2;

    int t = add(i,j);

    printf("%d + %d = %d\n",i,j,t);
}
#include <stdio.h>

int pi = 3141592;

int sum(int a, int b) { return a + b; }
int mul(int a, int b) { return a * b; }
int sub(int a, int b) { return a - b; }

static int doMystic(int a) { printf("... =>%d\n", a); return a; }

void dom(int a) {
    printf("%d\n", doMystic(a));
}
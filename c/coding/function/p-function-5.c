#include <stdio.h>

int add(int, int);

typedef int (*ptf_0)(int, int);
typedef int (*ptf_1)();

int main(void)
{
    int a = 40;
    int b = 2;

    printf("%s|%d+%d=%d\n", "_____", a, b, add(a, b));

    ptf_0 p0 = add;
    printf("%s|%d+%d=%d\n", "ptf_0", a, b, p0(a, b));

    ptf_1 p1 = add;
    printf("%s|%d+%d=%d\n", "ptf_1", a, b, p1(a, b));

    return 0;
}

int add(int a, int b)
{
    return a + b;
}

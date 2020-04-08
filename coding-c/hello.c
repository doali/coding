#include <stdio.h>

/* Compilation 
 * gcc -o hello_c hello.c
 */

/* Execution
 * ./hello_c
 */

void doSomething()
{
    printf("function");
}

int main()
{
    printf("main\n");
    doSomething();

    return 0;
}

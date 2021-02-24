#include <stdlib.h>
#include <stdio.h>

extern int pi;

extern int sum(int, int);
extern int mul(int, int);
extern int sub(int, int);
extern void dom(int);

int g(int, int);

typedef int (*pf)(int, int);

void f(const char* s)
{
    int g(int a, int b) 
    {
        return a + b;
    }

    struct inner
    {
        pf op;
    } titi;

    g(0, 1);  

    titi.op = g;
    printf("titi %d\n", titi.op(100, 66));

    s = "titi                                                                       p";   
    printf("%d\n", g(10000, 1));
    printf("%s\n", s);
}

typedef int (*op)(int, int);

static int global = 23;

static int fun() 
{
    static int gseed = 0;    
    return ++gseed;    
}


int main(int nargs, char** argvs)
{
    printf("nargs: %d\n", nargs);

    for (int index = 0; index < nargs; ++index)
    {
        printf("argsv: %s\n", *(argvs + index));
    }

    const char* message = "coucou";       
    printf("%p|%s\n", message, message);
    message = "ceci est une chaine";  
    printf("%p|%s\n", message, message);

    f("toto");
       
    char* pc = "titi";
    printf("%s\n", pc);

    //int (*op)(int, int);

    op pf = &sum;    

    for (int i = 0; i < 5; ++i) 
    {
        printf("%d\n", (*pf)(i, i));
    }

    pf = mul;

    op t_op[] = {sum, mul, sub};

    printf("Debut\n");
    for (int operation = 0; operation < 2; ++operation) 
    {        
        for (int i = 0; i < 4; ++i)
        {
            printf("%d\n", t_op[operation](i, i));
        }
    }    

    printf("%d\n", global);
    printf("%d\n", fun(1));
    printf("%d\n", fun(10));
    printf("%d\n", fun(1));
    printf("%d\n", fun(1));

    printf("%d\n", pi);

    dom(243);

    return EXIT_SUCCESS;
}

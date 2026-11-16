// Compiler x86-64 clang 18.1.0
#include <string.h>
#include <stdio.h>

#define BUFSIZE 2

void checkAuth(char *i_tab)
{
    bool authOK = false; // En pile
    char buf[BUFSIZE]; // En pile

    printf("AVANT strcpy, authOK = %d\n", authOK);
    strncpy(buf, i_tab, 2); // SOLUTION possible

    if(authOK == true)
    {
       printf("Accès à la section secrète\n");
    }
    else
    {
        printf("Accès refusé\n");
    }
}

int main()
{
    char userTab[BUFSIZE + 1];

    userTab[0] = 'a';
    userTab[1] = 'b';
    userTab[2] = 'c';

    printf("Adresse userTab = %p\n", &userTab[0]);
    checkAuth(userTab);

    return 0;
}

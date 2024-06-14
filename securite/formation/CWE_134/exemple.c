#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
 
#define	BUF_SIZE	1024
 
int
main(int argc, char** argv)
{
    int32_t	miaou = 1;
    char	buf[BUF_SIZE];
 
    printf("@argv : %p - *argv %p - **argv : %c\n",&argv, *argv ,**argv);
    printf("argv[0] : %p - argv[1] %p\n",&argv[0],&argv[1]);
    printf("argv[0] %s\n",argv[0]);
    printf("argv[1] %s\n",argv[1]);
    printf("sizeof(int) : %ld - @argc : %p - @miaou : %p - @buf : %p\n",sizeof(int),&argc,&miaou,buf);
    if(argc != 2)
	{
	    fprintf(stderr, "Usage: %s <str>\n", argv[0]);
	    exit(1);
	}
 
    printf("Before formating: miaou: [%p] = %d\n", &miaou, miaou);
 
    strncpy(buf, argv[1], sizeof(buf));
    // There a user is able to read/write the stack, for example the canary "miaou"
    printf(argv[1]);
    printf("\n");
 
    printf("After formating: miaou: [%p] = %d\n", &miaou, miaou);    
 
// Il faut ecrire a l'adresse de miaou
// - regarder dans la pile
// le %n nous permet d'ecrire !! Et c'est la tout le probleme et le risque
// Il faut pour se proteger faire printf("%s", ...)

    return(0);
}
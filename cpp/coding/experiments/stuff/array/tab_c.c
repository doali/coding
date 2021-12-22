#include <stdlib.h>
#include <stdio.h>

#define TAILLE 10

int main() 
{
	int *t_0 = (int*)malloc(sizeof(int) * TAILLE);
	for (int i = 0; i < TAILLE; ++i)
	{
		*(t_0 + i) = i;
		printf("%2d|%p\n", t_0[i], (t_0 + i));
	}
	free(t_0);

	return 0;
}

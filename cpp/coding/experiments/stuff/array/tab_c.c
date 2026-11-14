#include <stdlib.h>
#include <stdio.h>

#define TAILLE 10

int main() 
{
  printf("sizeof(int)=%lu\n", sizeof(int));
  printf("sizeof(int) * TAILLE=%lu\n", sizeof(int) * TAILLE);

	int *t_0 = (int*)malloc(sizeof(int) * TAILLE);
	for (int i = 0; i < TAILLE; ++i)
	{
		*(t_0 + i) = i;
		printf("%2d|%p\n", t_0[i], (t_0 + i));
	}

  printf("sizeof(*t_0) * TAILLE=%lu\n", sizeof(*t_0) * TAILLE);

	free(t_0);

	return 0;
}

#include <stdlib.h>
#include <stdio.h>

void display(int *i)
{
	printf("%d\n", *i);
}

int main() 
{
	int *p_int;
	p_int = malloc(sizeof(int));
	*p_int = 1;
	display(p_int);
	free(p_int);

	// pointeur générique
	void* p_void;
	p_void = malloc(sizeof(int));
	*(int*)p_void = 2; // <= cast obligatoire : indirection, arithmétique des pointeurs
	display(p_void);
	free(p_void);

	return 0;
}

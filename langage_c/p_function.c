#include <stdio.h>
#include <stdlib.h>

int mult(int a, int b)
{
	return a * b;
}

int add(int a, int b)
{
	return a + b;
}

int main(int nbargs, char* argsv[])
{
	int res = 0;
	int (*pf)(int, int) = NULL;

	printf("%d\n", res);

	pf = mult;
	res = pf(2, 2);

	res = printf("%d\n", res);

	pf = add;
	res = pf(1, 2);

	printf("%d\n", res);
	return 0;
}

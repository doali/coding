#include <stdio.h>
#include <stdlib.h>

static int op_mult(int a, int b)
{
	return a * b;
}

static int op_add(int a, int b)
{
	return a + b;
}

static int op_div(int a, int b, int *r)
{
	if (b > 0)
	{
		*r = a % b;
	}

	return (a / b);
}

int main(int nbargs, char* argsv[])
{
	int res = 0;
	int (*pf)(int, int) = NULL;

	printf("%d\n", res);

	pf = op_mult;
	res = pf(2, 2);

	res = printf("%d\n", res);

	pf = op_add;
	res = pf(1, 2);

	printf("%d\n", res);

	int (*pf_div)(int,int,int*) = op_div;
	int r;
	res = pf_div(6, 4, &r);

	printf("%d %d\n", res, r);

	return 0;
}

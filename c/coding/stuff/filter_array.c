#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef bool(*lambda)(int);

int filter(int*, lambda, int*, size_t);

bool heaven(int e)
{
	return (e % 2) == 0;
}

bool less_than_4(int ref) 
{
	return (ref < 4);
}

int filter(int* r, lambda f, int* lst, size_t s)
{

	if (s == 0 || lst == NULL) return -1;

	size_t len = 0;
	for (unsigned int index = 0; index < s; ++index)
	{
		if (f(*(lst + index)) == 1)
		{
			*(r + len) = *(lst + index);
			printf("%d->%d\n", index, *(r + len));
			++len;
		}
	}

	return len;
}

void print_lst(int* l, size_t s)
{
	if (s >= 0) 
	{
		if (s != 0)
			printf("[%d", l[0]);
		else
			printf("[");
	}
	for (unsigned int index = 1; index < s; ++index)
	{
		printf(", %d", *(l + index));
	}
	printf("]\n");
}

void test_lst() 
{
	int l0[] = {};
	int l1[] = {1};
	int l2[] = {1, 2};
	int l3[] = {1, 2, 3};
	int l4[] = {1, 2, 3, 4};

	int* t_l[] = {l0, l1, l2, l3, l4};

	for (unsigned int index = 0; index < 5; ++index)
	{
		print_lst(*(t_l + index), index);
	}
}

int main(int argc, char** argv)
{
	for (unsigned int num = 0; num < 10; ++num)
	{
		printf("%d:%d\n", num, heaven(num));
	}

	const size_t size = 9;
	int lst[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	print_lst(lst, size);

	int res[size]; 
	size_t res_len = filter(res, less_than_4, lst, size);
	if (res_len > 0) 
		print_lst(res, res_len);
	

	test_lst();

	return EXIT_SUCCESS;
}

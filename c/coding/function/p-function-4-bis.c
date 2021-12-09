#include <stdio.h>

int main()
{
	int (*f(int a))(int) {
		int g(int b) {
			return a + b;
		};
		return g;
	};

	int a = 3;
	int b = 40;

	printf("f(%d, %d)=%d\n", a, b, f(a)(b));

	return 0;
}

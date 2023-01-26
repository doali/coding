#include <stdio.h>

int main(void)
{
	void f(const char* msg) {
		printf("%s\n", msg);
	}

	f("hello");

	return 0;
}

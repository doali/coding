#include <stdio.h>

int (*f(int a))(int) {
	int g(int b) {
		return a + b;
	};
	return g;
}

int main() {
	printf("f(4)(3)=%d\n", f(4)(3));
	return 0;
}

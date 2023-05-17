#include <iostream>

struct A
{
	A() { std::cout << __func__ << std::endl; }
};

struct C
{
	C(A a) : _a{a} { std::cout << __func__ << std::endl; }
	A _a;
};

int main(void)
{
	A o;
	C{o};

	double a{1};

	bool res = false;
	res = (1 == 1.0f);

	if (res) std::cout << "TRUE" << std::endl;
	return EXIT_SUCCESS;
}

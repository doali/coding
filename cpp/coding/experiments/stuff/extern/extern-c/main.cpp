#include <iostream>

extern "C"
{
#include "op.h"
}

extern "C"
{
	int pow_2(int);
}

int main(int argc, char **argv)
{
	std::cout << add(40, 2) << std::endl;
	std::cout << mult(21, 2) << std::endl;
	std::cout << pow_2(3) << std::endl;

	std::cout << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << pow_2(i) << std::endl;
	}

	return 0;
}

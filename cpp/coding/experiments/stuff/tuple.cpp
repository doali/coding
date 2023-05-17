#include <stdio.h>
#include <tuple>
#include <cstdlib>
#include <iostream>

int main(int argc, char **argv)
{

	if (argc != 4)
	{
		std::cout << "Enter a 3-uplet" << std::endl;
		return 0;
	}

	int x{atoi(argv[1])};
	int y{atoi(argv[2])};
	int z{atoi(argv[3])};

	std::cout << "x=" << argv[1] << " y=" << argv[2] << " z=" << argv[3] << std::endl;
	std::cout << "x=" << x << " y=" << y << " z=" << z << std::endl;

	// if (std::tie(5, 1, 1) == std::tie(x, y, z)) {
	if (std::forward_as_tuple(5, 1, 1) == std::forward_as_tuple(x, y, z))
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << "KO" << std::endl;
	}

	if ((5 == x) && (1 == y) && (1 == z))
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << "KO" << std::endl;
	}

	return 0;
}

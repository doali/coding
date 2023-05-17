#include <iostream>

/*
 * {}-initializer
 * https://www.modernescpp.com/index.php/initialization
 * https://stackoverflow.com/questions/43762651/how-does-stdtie-work
 *
 * std::tie
 * https://www.geeksforgeeks.org/tuples-in-c/
 */

struct A
{
	int _a;
	A(int a) : _a(a) { std::cout << __func__ << std::endl; }
};

void affiche(const A& p_a)
{
	std::cout << p_a._a << std::endl;
};

int main(int argc, char** argv)
{
	A l_a{1};
	affiche(l_a);

	l_a = 2;
	affiche(l_a);

	l_a = {3};
	affiche(l_a);

	return 0;
}

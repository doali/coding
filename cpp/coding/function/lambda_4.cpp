#include <iostream>

auto f(int a) { return [a](int b) -> int { return a + b; }; }

int main()
{
	std::cout << f(10)(4) << std::endl;
	return 0;
}

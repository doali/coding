#include <iostream>
#include <functional>

int main(void)
{
	auto f = [](std::string msg) {
		std::cout << msg << std::endl;
	};

	f("titi");

	std::function<int(int, int)> f_add = [](int a, int b) {
		return a + b;
	};

	int res{f_add(40, 2)};

	std::cout << res << std::endl;

	return 0;
}

#include <iostream>

auto f(int);

int main()
{
	auto f = [](int a) {
		auto g = [a](int b){
			return a + b;
		};
		return g;
	};

	for (auto i: {1, 2, 3, 4, 5, 6}) std::cout << f(4)(i) << std::endl;
	std::cout << "f(4)(3)=" << f(4)(3) << std::endl;
}

auto f(int a) {
	return [a](int b) -> int {
		return a + b;
	};
}

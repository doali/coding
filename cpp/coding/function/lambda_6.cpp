#include <iostream>
#include <vector>

namespace algo {
	static auto compute = [](int a, int b) -> int { return a + b; };
};

namespace algo_currified {
	static auto compute = [](int a) { return ([a](int b) -> int { return a + b; }); };
};

int main() {
	auto f = [](int a) {
		auto g = [a](int b) -> int {
			return a + b;
		};
		return g;
	};

	std::vector<int> v{1, 2, 3, 4, 5};
	auto f_10 = f(10);
	for (auto e: v)
		std::cout << "f(" << e << ") -> 10 + " << e << " = " << f_10(e) << std::endl;

	int a{3}, b{4};
	std::cout << "compute(" << a << ", " << b << ")=" << algo::compute(a, b) << std::endl;
	// curryfication
	std::cout << "compute_currified(" << a << ", " << b << ")=" << algo_currified::compute(a)(b) << std::endl;

	return 0;
}

// ================================================================================
// https://en.cppreference.com/w/cpp/utility/functional/function
// ================================================================================

#include <iostream>
#include <functional>

struct F
{
	void operator()(std::string msg) {
		std::cout << "--- ";
		std::cout << msg;
		std::cout << " ---" << std::endl;
	}
};

int main(int argc, char** argv)
{
	auto wrapper = [](std::string msg) -> void {
		std::cout << "=== ";
		std::cout << msg << " ";
		std::cout << " ===" << std::endl;
	};

	void (*f)(std::string);

	f = wrapper;

	std::string msg{"informations"};
	wrapper(msg);
	f(msg);

	F()(msg);

	std::function<void(std::string)> func;
	func = f;
	func(msg);
	
	F ff;
	func = ff;
	func("titi");

	return EXIT_SUCCESS;
}

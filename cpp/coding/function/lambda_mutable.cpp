#include <iostream>

void log(std::string const &msg)
{
	std::cout << msg << std::endl;
}

void log(std::string const &msg, const int& a)
{
	std::cout << msg << a << std::endl;
}

int main()
{
	log(">>");

	int n(23);
	([&n]() mutable -> void {
		n++;
		log("id:", n);
	})();

	log("<<");

	return 0;
}

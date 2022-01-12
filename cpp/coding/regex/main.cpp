#include <iostream>
#include <array>

namespace http_regex {
	std::array<std::string, 2> http_ref{
		"https://en.cppreference.com/w/cpp/regex",
		"http://www.vishalchovatiya.com/regex-c/"
	};
};

int main()
{
	for (auto const &ref : http_regex::http_ref) std::cout << ref << std::endl;
	return 0;
}

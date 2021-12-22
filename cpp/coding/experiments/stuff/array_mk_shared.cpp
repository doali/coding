#include <string>
#include <iostream>
#include <memory>
#include <array>

int main()
{
	std::array<std::shared_ptr<std::string>, 5> arr;

	arr[0] = std::make_shared<std::string>("titi");
	arr[1] = std::make_shared<std::string>("et");
	arr[2] = std::make_shared<std::string>("rominet");
	arr[3] = std::make_shared<std::string>("4");
	arr[4] = std::make_shared<std::string>("2");

	for (std::shared_ptr<std::string> e: arr)
	{
		(*e) += "...";
		std::cout << e << '|' << *e << std::endl;
	}

	return 0;
}

#include <iostream>
#include <array>
#include <memory>

#define element(X) std::make_shared<int>(X)

namespace cst {
	unsigned int const TAILLE{10};
}

int main() 
{
	std::array<std::shared_ptr<int>, cst::TAILLE> arr;
	for (int i = 0; auto &e: arr)
	{
		e = element(i++);	
		std::cout << e << "|" << *e << std::endl;
	};

	return 0;
}

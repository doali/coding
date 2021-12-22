#include <iostream>
#include <array>

namespace cst {
	unsigned int const TAILLE{10};
}

int main() 
{
	int *t_1{new int[cst::TAILLE]{}};
	for (unsigned int i = 0; i < cst::TAILLE; ++i)
	{
		t_1[i] = i;
		std::cout << t_1[i] << '|' << (t_1 + i) << std::endl;
	}
	delete [] t_1;

	return 0;
}

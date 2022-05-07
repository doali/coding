#include <iostream>

namespace nm_1 {
	int id_1;
}

namespace nm_2 {
	int id_2;
};

;
;
;
;;;

int main(int argc, char** argv)
{
	nm_1::id_1 = 10;
	int l_nm_1{nm_1::id_1};
	std::cout << l_nm_1 << std::endl;
	return EXIT_SUCCESS;
}

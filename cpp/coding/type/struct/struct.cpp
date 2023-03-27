#include <iostream>

namespace // anonymous namespace (visibility limited to this file) (similar to "static" keyword for C language regarding visibility)
{
	struct _titi
	{
		int x{1}; // initialization
		int y;
	} titi{// variable
		   3,
		   4};

	using s_titi = struct _titi; // new way for typedef
	typedef struct _titi oldschool_titi;

	std::ostream &operator<<(std::ostream &os, const struct _titi &element)
	{
		return os << "{" << element.x << ", " << element.y << "}";
	}
}

int main(void)
{
	std::cout << titi << std::endl; // variable !!

	struct _titi t_0 = {1, 2};
	std::cout << t_0 << std::endl;

	_titi t_1 = {1, 2}; // struct keyword optional
	std::cout << t_1 << std::endl;

	s_titi s_t; // thanks to using
	std::cout << s_t << std::endl;

	oldschool_titi o_t; // thanks to typedef
	std::cout << o_t << std::endl;

	exit(0);
}

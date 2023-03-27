#include <iostream>

struct _titi
{
	int x{1};
	int y;
} titi{
	3, 4};

using s_titi = struct _titi;
typedef struct _titi oldschool_titi;

std::ostream &operator<<(std::ostream &os, const struct _titi &element)
{
	return os << "{" << element.x << ", " << element.y << "}";
}

int main(void)
{
	struct _titi t = {1, 2};
	std::cout << t << std::endl;
	std::cout << titi << std::endl;

	s_titi s_t;
	std::cout << s_t << std::endl;

	oldschool_titi o_t;
	std::cout << o_t << std::endl;

	exit(0);
}

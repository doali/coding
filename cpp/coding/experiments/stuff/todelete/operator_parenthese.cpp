#include <iostream>

namespace xlj 
{
struct op
{
	unsigned int _ite;

	op(unsigned int ite) : _ite(ite) {}

	bool operator()(bool affiche = false)
	{
		static unsigned int ite = 0;
		if (affiche) 
		{
			std::cout << ite << std::endl;
		}
		return ite++ < _ite;
	}
};
}

static const unsigned int glob_init{3};

unsigned int generateur_0()
{
	static unsigned int curr{::glob_init};

	return curr++;
}

auto generateur_1(const unsigned int init)
{
	unsigned int curr{init};

	return ([curr]() mutable -> unsigned int {
		return curr++;
	});
}

auto generateur_2(const unsigned int init)
{
	return ([init]() mutable -> unsigned int {
		static unsigned int curr{init};
		return curr++;
	});
}


int main(int argc, char** argv)
{
	xlj::op is(7);

	unsigned int temoins{0};
	while (is())
	{
		std::cout << temoins++ << std::endl;
	}

	xlj::op gen{10};

	gen(true);
	gen(true);

	std::cout << "generateur_1" << std::endl;
	auto gen_1 = generateur_1(1);
	std::cout << gen_1() << std::endl;
	std::cout << gen_1() << std::endl;

	std::cout << "generateur_2" << std::endl;
	auto gen_2 = generateur_2(2);
	std::cout << gen_2() << std::endl;
	std::cout << gen_2() << std::endl;

	std::cout << "generateur_0" << std::endl;
	std::cout << generateur_0() << std::endl;
	std::cout << generateur_0() << std::endl;

	return 0;
}

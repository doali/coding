#include <iostream>

struct A
{
	static unsigned int cpt;
	unsigned int index;
	A() { std::cout << __func__ << ":" << (index = cpt++) << std::endl; }
	A(A& other) { std::cout << __func__ << std::endl; }
	~A() { std::cout << __func__ << ":" << index << std::endl; }
	void operator=(const A& other) { std::cout << __func__ << std::endl; }
};

unsigned int A::cpt {0};

std::string &caller(std::string &outer)
{
	outer = "titi";
	return outer;
}

int main(int argc, char** argv)
{
	A a;
	A();
	A b;
	b = a;
	std::string str_caller {"coucou"};
	std::cout << caller(str_caller) << std::endl;
	std::cout << str_caller << std::endl;
	return EXIT_SUCCESS;
}

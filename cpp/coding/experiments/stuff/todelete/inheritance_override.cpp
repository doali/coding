#include <iostream>

struct A
{
	virtual ~A() = default;
};

struct B : A 
{
	~B() override = default;
};

int main(int argc, char** argv)
{
	std::cout << "START" << std::endl;
	{
		A();
		B();
	}
	std::cout << "END" << std::endl;
	return 0;
}

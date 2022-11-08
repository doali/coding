#include <iostream>

template<typename T, T t>
struct Titi
{
	Titi();
};

template<typename T, T t>
Titi<T, t>::Titi() 
{
	std::cout << __func__ << std::endl;
	std::cout << t << std::endl;
}

int main(int argc, char** argv)
{
	Titi<int, 3>{};
	return 0;
}

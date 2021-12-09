#include <iostream>

struct A {
	A() { std::cout << "A()" << std::endl; }
	~A() { std::cout << "~A()" << std::endl; }
	A(A const&) { std::cout << "A(const&)" << std::endl; }
	void operator=(A const&) { std::cout << "operator=" << std::endl; }
};

int main() {
	//A a;
	//A();
	//A a = A();
	/*
	A a, b;
	b = a;
	*/
	/*
	A a;
	A b = a;
	*/
	/*
	A a, b;
	b = A();
	*/

	std::cout << "uncomment code" << std::endl;

	return 0;
}

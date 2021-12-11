#include <vector>
#include <iostream>
#include <memory>

#define NEW_LINE std::cout << std::endl

void display_section(const std::string &msg)
{
	std::cout << msg << "--------------------" << std::endl;
}

struct A 
{
	static unsigned int _counter;
	unsigned int _id;
	A() : _id(++_counter) { std::cout << "A() for " << _id << std::endl; }
	~A() { std::cout << "~A() for " << _id << std::endl; }
	void doSomething() { std::cout << "A():" << _id << "/" << _counter << "|" << "doSomething" << std::endl; }
};

unsigned int A::_counter = 0;

int main() 
{
	display_section("v_cpy");
	std::vector<A> vA_cpy{A(), A(), A()};
	vA_cpy.push_back(A());
	//A a;
	//vA_cpy.push_back(a);
	for (auto &e: vA_cpy) { e.doSomething(); }

	NEW_LINE;

	display_section("v_ptr");
	std::vector<A*> vA_ptr{new A(), new A(), new A()};
	for (auto e: vA_ptr) { e->doSomething(); }
	for (auto e: vA_ptr) { delete e; }

	NEW_LINE;

	display_section("cpy");
	A a_cpy;
	a_cpy.doSomething();

	NEW_LINE;

	display_section("ptr");
	A* a_ptr{new A()};
	a_ptr->doSomething();
	delete a_ptr;

	NEW_LINE;

	display_section("unique_ptr");
	std::unique_ptr<A> a_unique_ptr = std::make_unique<A>();
	a_unique_ptr->doSomething();

	NEW_LINE;

	std::cout << ">> bloc" << std::endl;
	{
		display_section("shared_ptr");
		std::vector<std::shared_ptr<A>> vA_shared_ptr{
			std::make_shared<A>(),
			std::make_shared<A>(),
			std::make_shared<A>(),
			std::make_shared<A>()
		};
		for (auto e: vA_shared_ptr) { e->doSomething(); }
	}
	std::cout << "<< bloc" << std::endl;

	return 0;
}

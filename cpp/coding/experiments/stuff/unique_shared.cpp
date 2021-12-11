#include <vector>
#include <iostream>
#include <memory>

struct A 
{
	static unsigned int _counter;
	unsigned int _id;
	A() : _id(++_counter) {};
	void doSomething() { std::cout << "A():" << _id << "/" << _counter << "|" << "doSomething" << std::endl; }
};

unsigned int A::_counter = 0;

int main() 
{
	std::vector<A> vA_cpy{A(), A(), A()};
	for (auto &e: vA_cpy) { e.doSomething(); }

	std::vector<A*> vA_ptr{new A(), new A(), new A()};
	for (auto e: vA_ptr) { e->doSomething(); }
	for (auto e: vA_ptr) { delete e; }

	A a_cpy;
	a_cpy.doSomething();

	A* a_ptr{new A()};
	a_ptr->doSomething();
	delete a_ptr;

	std::unique_ptr<A> a_unique_ptr = std::make_unique<A>();
	a_unique_ptr->doSomething();

	{
		std::vector<std::shared_ptr<A>> vA_shared_ptr{
			std::make_shared<A>(),
			std::make_shared<A>(),
			std::make_shared<A>(),
			std::make_shared<A>()
		};
		for (auto e: vA_shared_ptr) { e->doSomething(); }
	}

	return 0;
}

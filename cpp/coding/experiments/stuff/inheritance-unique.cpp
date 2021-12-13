#include <iostream>
#include <memory>
#include <vector>

struct A {
	virtual void doSomething() { std::cout << __func__ << std::endl; }

	A() { std::cout << __func__ << std::endl; }
	virtual ~A() { std::cout << __func__ << std::endl; }
};

struct B : public A {
	void doSomething() override { std::cout << "B is doing..." << std::endl; }

	B() { std::cout << __func__ << std::endl; }
	~B() override { std::cout << __func__ << std::endl; }
};

struct C : public A {

	void doSomething() override { std::cout << "C is doing..." << std::endl; }
	C() { std::cout << __func__ << std::endl; }
	~C() override { std::cout << __func__ << std::endl; }
};

int main() {
	std::vector<std::shared_ptr<A>> v{
		std::make_shared<B>(),
		std::make_shared<C>()
	};
	
	for (auto &e: v) {
		e->doSomething();
	}

	return 0;
}

#include <iostream>
#include <vector>

struct A {
	virtual void doSomething() {
		std::cout << "A doSomething" << std::endl;
	}
};

struct B : public A {
	virtual void doSomething() final {
		A::doSomething();
		std::cout << "B doSomething" << std::endl;
	}
};

struct C : public A {
	virtual void doSomething() final {
		std::cout << "C doSomething" << std::endl;
	}
};

int main() {
	A().doSomething();
	B().doSomething();
	C().doSomething();

	//
	std::cout << std::endl;

	A a, b, c;
	a = A();
	a.doSomething();
	b = B();
	b.doSomething();
	c = C();
	c.doSomething();
	
	//
	std::cout << std::endl;

	A aa;
	aa.doSomething();
	B bb;
	bb.doSomething();
	C cc;
	cc.doSomething();

	//
	std::cout << std::endl;

	A *aaa = new A();
	aaa->doSomething();
	A *bbb = new B();
	bbb->doSomething();
	A *ccc = new C();
	ccc->doSomething();

	//
	std::cout << std::endl;

	std::vector<A> vAcpy;
	vAcpy.push_back(A());
	vAcpy.push_back(B());
	vAcpy.push_back(C());

	for (A &e: vAcpy) e.doSomething();

	//
	std::cout << std::endl;

	A a2;
	std::vector<A*> vAptr{&a2, new B(), new C()};
	for (A* e: vAptr) e->doSomething();

	return 0;
}

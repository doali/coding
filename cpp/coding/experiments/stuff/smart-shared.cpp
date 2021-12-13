#include <iostream>
#include <memory>
#include <vector>

struct A {
	std::string _a;
	A(std::string a) : _a(a) {}
	~A() { std::cout << __func__ << std::endl; }
	friend std::ostream & operator<<(std::ostream&, A const&);
};

std::ostream & operator<<(std::ostream &os, A const& a) {
	os << a._a;
	return os;
}

int main() {
	A *old(new A("old"));

	std::unique_ptr<A> u_a{std::make_unique<A>("A")};
	std::cout << *u_a << std::endl;

	A *a(new A("titi"));
	std::unique_ptr<A> a_0(a);


	std::shared_ptr<A> o{std::make_shared<A>("A1")};
	
	std::cout << ">> main" << std::endl;
	{
		std::vector<std::shared_ptr<A>> vect{
			o,
			std::make_shared<A>("A2"),
			std::make_shared<A>("A3"),
		};

		for (auto e: vect) {
			std::cout << *e << std::endl;
		}
	}
	std::cout << "<< main" << std::endl;

	delete old;

	return 0;
}

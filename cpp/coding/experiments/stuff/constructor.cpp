#include <iostream>
#include <memory>

struct A 
{
	static unsigned int _counter;
	unsigned int _id{_counter};
	void log(std::string const &msg) { std::cout << ++_id << ":" << ++_counter << "|" << msg << std::endl; }
	A() { log(__func__); }
	A(const A &a) { std::string s("copy "); s += __func__; log(s); }
	A& operator=(const A &a) { std::cout << __func__ << std::endl; return *this; }
	~A() { std::cout << _id << "|" << __func__ << std::endl; }
	void titi() { std::cout << "titi:" << _id << std::endl; }
};

unsigned int A::_counter(0);

int main()
{
	A a; a.titi();
	A b = a;
	A c = A();
	A();
	{
		A a;
	}
	A* d(new A());

	delete d;

	std::shared_ptr<A> sa(std::make_shared<A>()); sa->titi();
	std::shared_ptr<A>(std::make_shared<A>())->titi();

	return 0;
}

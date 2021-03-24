#include <iostream>

class A
{
	public:
		int fd_a;

		A(int a) {
			this->fd_a = a;
		}

	friend std::ostream& operator<<(std::ostream& os, const A& a)
	{
		os << "FD:" << a.fd_a;
		return os;
	}
};

int main(void) {
	auto x = 1.123;
	std::cout << x << std::endl;

	auto y = [] (int first, int second)
	{
    		return first + second;
	};

	int res = y(1, 10);

	std::cout << res << std::endl;

	int ret = ([] (int first, int second)
	{
    		return first + second;
	})(10, 10);

	std::cout << ret << std::endl;

	//auto a = A(666);
	A a(666);
	std::cout << a << std::endl;

	A *b = new A(777);

	([&] (int added)
	{
		b->fd_a = b->fd_a + added;
	})(10);

	std::cout << *b << std::endl;

	return 0;
}

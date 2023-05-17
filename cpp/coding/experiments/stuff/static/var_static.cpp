#include <iostream>

int inc()
{
	static int cpt_inc{0};
	return ++cpt_inc;
}

struct A
{
	int f()
	{
		static int cpt{0};
		return ++cpt;
	}

	const A &addr()
	{
		static const A a;
		std::cout << &a << std::endl;
		return a;
	}
};

static void display(int p_val)
{
	std::cout << p_val << std::endl;
}

int main(int argc, char **argv)
{
	//
	int res_inc;
	res_inc = inc();
	res_inc = inc();
	res_inc = inc();
	display(res_inc);

	A a;
	int res;
	res = a.f();
	res = a.f();
	res = a.f();
	display(res);

	a.addr();
	a.addr();
	display(a.f());

	A b;
	b.addr();
	display(b.f());

	A c;
	c.addr();
	display(c.f());

	bool l_b{false};
	std::cout << (l_b ? "true" : "false") << std::endl;

	l_b = true;

	std::cout << (l_b ? "true" : "false") << std::endl;

	return 0;
}

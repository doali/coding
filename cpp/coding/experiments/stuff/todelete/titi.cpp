#include <iostream>
#include <memory>
#include <string.h>

#define SIZE 30

struct A
{
	virtual void say() = 0;
	A() = default;
	virtual ~A() = default;
};

struct B : public A
{
	B() : A()
	{
		std::cout << __func__ << std::endl;
	}

	~B() 
	{
		std::cout << __func__ << std::endl;
	}

	void say() override;
};

void B::say()
{
	std::cout << __func__ << std::endl;
}

void display(int id, char* label)
{
	printf("%2d:%s\n", id, label);
}

int main(int argc, char** argv)
{
	std::cout << "before" << std::endl;
	{
		std::shared_ptr<A> s_a{
			std::make_shared<B>()
		};
	}
	std::cout << "after" << std::endl;

	std::cout << __LINE__ << std::endl;
	{
		A *p_a{new B()};
		delete p_a;
	}
	std::cout << __LINE__ << std::endl;

	struct
	{
		int id;
		char label[SIZE];
	} s_c;

	memset(&s_c, 0, sizeof(s_c));
	s_c.id = 42;
	strncpy(s_c.label, "label", SIZE);
	display(s_c.id, s_c.label);

	auto id = [](int n) -> int { return n; };
	std::cout << id(4) << std::endl;

	struct Id
	{
		void operator()()
		{
			std::cout << "nothing serious" << std::endl;
		}
	};

	Id{}();

	return 0;
}

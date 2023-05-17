#include <iostream>
#include <memory>
#include <string.h>

static void g(int id, const char* msg) {
	printf("%2d:%s\n", id, msg);
};

struct A {
	A() {
		std::cout << __func__ << std::endl;
	}
	~A() { 
		std::cout << __func__ << std::endl;
	}
};

int main(int argc, char** argv)
{
	A();
	new A();
	new A;
	new A{};

	int l_r = ([=](int p_i){ return 2 * p_i; })(2);
	std::cout << "res=" << l_r << std::endl;
	std::unique_ptr<A> l_a { new A()};
	
	typedef struct {
		int id;
		char msg[256];
	} s_msg;

	s_msg l_m {
		1,
		"titi"
	};

	void (*f)(int, const char*) = g;

	auto h = [=](int id, std::string const &msg) {
		std::cout << id << ":" << msg << std::endl;
	};


	f(l_m.id, l_m.msg);

	s_msg *l_m_1 = (s_msg*)malloc(sizeof(s_msg));
	memset(l_m_1, 0, sizeof(*l_m_1));

	memcpy(l_m_1, &l_m, sizeof(*l_m_1));
	h(l_m_1->id, l_m_1->msg);

	free(l_m_1);

	return 0;
}

#include <iostream>
#include <memory>
#include <array>
#include <vector>

/*
 * Liens
 * Initialization
 * - https://stackoverflow.com/questions/18222926/why-is-list-initialization-using-curly-braces-better-than-the-alternatives
 * - https://www.developpez.net/forums/d1312051/c-cpp/cpp/liste-d-initialisation-cpp/
 */

// Quelques tests (c'est le bazar...)

struct A
{
	A() { std::cout << __func__ << std::endl; }
	A(int i) { std::cout << __func__ << "{" << i << "}" << std::endl; }
	~A() { std::cout << __func__ << std::endl; }
};

struct B
{
	B() { std::cout << __func__ << std::endl; }
	B(int i) { std::cout << __func__ << "{" << i << "}" << std::endl; }
};

struct C
{
	C() { std::cout << __func__ << std::endl; }
	A a;
	B b;
};

struct un
{
	un(std::string m = "un") { std::cout << __func__ << "{" << m << "}" << std::endl; }
};

struct deux : virtual un
{
	deux() : un("deuxio")
	{
		std::cout << __func__ << std::endl;
		un("bis");
	}
	un ain{"bis-bis"};
};

struct trois : deux
{
	trois() { std::cout << __func__ << std::endl; }
};

struct D
{
	D()
	{
		std::cout << ">>" << __func__ << std::endl;
		a = A();
		b = B();
		std::cout << __func__ << "<<" << std::endl;
	}
	B b;
	A a;
};

struct E
{
	E() : b2(B(2)) /* 2 */, a1(A(1)) /* 4 */, a2(A(2)) /* 6 */
	{
		std::cout << __func__ << std::endl;
		b1 = B(1) /* 7 */;
	}
	B b1; // 1
	B b2; // 2--> (je prends dans la liste)
	B b3; // 3
	A a1; // 4--> (je prends dans la liste)
	B b4; // 5
	A a2; // 6--> (je prends dans la liste)
};

struct F
{
	// F() : b(B()) { std::cout << __func__ << std::endl; }
	F() { std::cout << __func__ << std::endl; }
	B b;
	A a;
};

class Fred
{
public:
	Fred() = default;
	Fred(int i, int j);
	// Suppose qu'il n'y a aucun constructeur par défaut
};

struct Collection
{
	std::vector<A> _lst;
	Collection() = default;
	Collection(std::vector<A> const &v) : _lst(v) {}
	~Collection()
	{
		std::cout << __func__ << std::endl;
	}
};

struct G
{
	static uint id;
	uint _id;
	G() { std::cout << __func__ << "{" << (_id = ++id) << "}" << std::endl; }
	G(G const &g) { std::cout << __func__ << "{" << (_id = ++id) << "} from " << g._id << std::endl; }
	void operator=(G const &g) { std::cout << __func__ << "{" << _id << "<=" << g._id << "}" << std::endl; }
	~G() { std::cout << __func__ << "{" << _id << "}" << std::endl; }
};

uint G::id = 0;

int main()
{
    // === Compréhension 1
	std::cout << "====" << std::endl;
	C();
	std::cout << "====" << std::endl;
	D();
	std::cout << "====" << std::endl;
	E();
	std::cout << "====" << std::endl;
	F();

    // === Compréhension 2
    std::vector<A> v{A(), A(), A(), A()};
	std::cout << "====" << std::endl;
	{
		Collection c{v};
	}
	std::cout << "====" << std::endl;

    // === Compréhension 3
	trois();

    // === Compréhension 4
	G g1;
	G g2;

	g1 = g2;

	G g3 = g1;

	G g4 = G();

	return 0;
}

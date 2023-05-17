#include <iostream>

struct Version 
{
	int _1 {1};
	int _2 {2};
	int _3 {3};

	friend std::ostream& operator<<(std::ostream&, const Version&);

	bool operator==(const Version o) const
	{
		return (_1 == o._1 && _2 == o._2 && _3 == o._3);
	}
};

std::ostream& operator<<(std::ostream& os, const Version& v)
{
	os << "{" << v._1 << ":" << v._2 << ":" << v._3 << "}";
	return os;
}

int main(int argc, char** argv)
{
	auto cmp = [](Version &vl, Version &vr) {
		std::cout << ((vl == vr) ? "OK" : "KO") << std::endl;
	};

	auto display = [](Version &va, Version &vb) {
		std::cout << va << std::endl;
		std::cout << vb << std::endl;
	};

	Version v0;
	Version v1 {2, 2, 3};

	display(v0, v1);
	cmp(v0, v1);

	v0 = v1;
	display(v0, v1);
	cmp(v0, v1);

	return EXIT_SUCCESS;
}

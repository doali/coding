#include <iostream>

struct A
{
	A() = default;
	
	A(std::string msg) :
		m_msg(msg)
	{
		
	}
	void info() 
	{
		std::cout << __func__ << std::endl;
	}

	std::string m_msg;
};

struct Client
{
	Client(std::string msg)
	{
		m_a.m_msg = msg;
	}
	A m_a;
};

int main(int argc, char** argv)
{
	Client c("titi");
	c.m_a.info();
	
	std::cout << c.m_a.m_msg << std::endl;

	return 0;
}

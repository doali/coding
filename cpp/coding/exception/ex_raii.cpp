#include <iostream>

struct LanceException
{
	LanceException(int id) : _id(id)
	{
		std::cout << __func__ << ":DEB" << std::endl;
		if (id > 10)
		{
			throw id;
			std::cout << __func__ << ":Jamais appele" << std::endl;
		} 
		else
		{
			std::cout << __func__ << ":Comportement normal" << std::endl;
			// ...
		}
		
		std::cout << __func__ << ":FIN" << std::endl;
	}

	~LanceException()
	{
		std::cout << __func__ << "(" << _id << ")" << std::endl;
	}

	int _id;
};

int main(int argc, char **argv)
{
	std::cout << __func__ << ":DEB" << std::endl;
	try
	{
		LanceException a(0);
		LanceException(1);
		LanceException b(2);
		{
			LanceException c(11);
		}
	}
	catch (int &ref)
	{
		std::cout << __func__ << ":Attrapee" << ":" << ref << std::endl;
	}
	std::cout << __func__ << ":FIN" << std::endl;
};

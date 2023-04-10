#include <iostream>
#include <fstream>

void log(const std::string &message) {
	std::cout << message << std::endl;
}

void read_file(std::string path_name)
{
	std::string line;
	std::ifstream ifs;
	ifs.open(path_name);
	if (ifs.is_open())
	{
		while (getline(ifs, line))
		{
			std::cout << line << std::endl;
		}
	}
	ifs.close();
}

int main(int args, char **argv)
{
	try {
		if (args > 1) read_file(argv[1]);
	} catch (...) {
		std::cout << "nothing to hope" << std::endl;
	}

	return 0;
}

#include "B.h"
#include <iostream>

void B::do_something() const noexcept
{
	std::cout << "B:" << __func__ << std::endl;
}

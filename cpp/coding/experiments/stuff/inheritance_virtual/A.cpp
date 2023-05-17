#include "A.h"
#include <iostream>

void A::do_something() const noexcept
{
	std::cout << "A:" << __func__ << std::endl;
}

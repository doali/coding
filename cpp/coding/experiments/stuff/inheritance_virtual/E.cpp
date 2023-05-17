#include "E.h"

#include <iostream>

void E::pure() const noexcept
{
	std::cout << "E:" << __func__ << std::endl;
}

#include "base.h"

#include <iostream>

Base::Base():
    m_id("Base")
{
   /* std::cout << "constructeur de A" << std::endl;
    std*/::cout << "m_id 'Base'" << std::endl;
}

void Base::faire() const
{
    std::cout << "faire de A" << " " << m_id << std::endl;
}

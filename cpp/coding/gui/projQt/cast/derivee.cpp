#include "derivee.h"

#include <iostream>

Derivee::Derivee():
    Base()
{
    std::cout << "constructeur de B" << std::endl;
    m_id = "Derivee";
    std::cout << "m_id 'Derivee'" << std::endl;
}

Derivee::Derivee(const Derivee& cpDerivee): Base(cpDerivee)
{
//    std::cout << "constructeur de recopie de B" << std::endl;
}

Derivee::~Derivee()
{
//    std::cout << "destructeur de B" << std::endl;
}

void Derivee::faire() const
{
    std::cout << "faire de B" << " " << m_id << std::endl;
}

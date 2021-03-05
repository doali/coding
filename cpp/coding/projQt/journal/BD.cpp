#include "BD.h"
#include <cstdlib>

#include <sstream>

BD::BD(int id):
    _id(id)
{

}

BD::~BD()
{

}

bool BD::isConnected() const
{
    return (std::rand() % 2);
}

std::string BD::toString() const
{
    std::stringstream ss("");
    ss << "BD {ID :" << this->getId() << ", Connected :" << this->isConnected() << "}";

    return ss.str();
}

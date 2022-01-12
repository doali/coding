#include "Nitp.h"

#include <sstream>

int Nitp::_idUnique = 0;

Nitp::Nitp(std::string ref):
    _id(_idUnique++),
    _ref(ref)
{

}

Nitp::~Nitp()
{

}

std::string Nitp::toString() const
{
    std::stringstream ss("");
    ss << "NITP {ID :" << this->getId() << ", REF :" << this->getRef() << "}";

    return ss.str();
}

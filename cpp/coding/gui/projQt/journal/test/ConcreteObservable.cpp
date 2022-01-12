#include "ConcreteObservable.h"

#include <sstream>

int ConcreteObservable::_idUnique = 0;

ConcreteObservable::ConcreteObservable():
    _id(_idUnique++),
    _ref("")
{

}

ConcreteObservable::ConcreteObservable(std::string ref):
    _id(_idUnique++),
    _ref(ref)
{

}

ConcreteObservable::~ConcreteObservable()
{

}

std::string ConcreteObservable::toString() const
{
    std::stringstream ss("");
    ss << "{ID :" << this->getId() << " [" << this->getNbObserver() << "], REF :" << this->getRef() << "}";

    return ss.str();
}


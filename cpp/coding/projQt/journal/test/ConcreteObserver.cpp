#include "ConcreteObserver.h"
#include "ConcreteObservable.h"

#include <sstream>

int ConcreteObserver::_idUnique = 0;

ConcreteObserver::ConcreteObserver():
    _id(_idUnique++),
    _ref("")
{

}

ConcreteObserver::ConcreteObserver(std::string ref):
    _id(_idUnique++),
    _ref(ref)
{

}

ConcreteObserver::~ConcreteObserver()
{

}

void ConcreteObserver::update(const Observable& observable)
{
    std::cout << this->toString() << " notified by " << "\n";
    std::cout << "\t" << static_cast<const ConcreteObservable&>(observable).toString() << std::endl;
}

std::string ConcreteObserver::toString() const
{
    std::stringstream ss("");
    ss << "{ID :" << this->getId() << ", REF :" << this->getRef() << "}";

    return ss.str();
}

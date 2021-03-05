#include "util/Observable.h"
#include "util/Observer.h"

#include <algorithm>

Observable::~Observable()
{
    ItListObserver itListObserver;
    for(itListObserver = this->_listObserver.begin(); itListObserver != this->_listObserver.end(); ++itListObserver)
    {
        (*itListObserver)->remove(*this);
    }
}

void Observable::add(Observer& observer)
{
    this->_listObserver.push_back(&observer);
}

void Observable::remove(Observer& observer)
{
    ItListObserver itListObserver = std::find(this->_listObserver.begin(), this->_listObserver.end(), &observer);
    if (itListObserver != this->_listObserver.end())
    {
        this->_listObserver.erase(itListObserver);
    }
}

void Observable::notifyAll() const
{
    for (ConstItListObserver constItListObserver = this->_listObserver.begin(); constItListObserver != this->_listObserver.end(); ++constItListObserver)
    {
        (*constItListObserver)->update(*this);
    }
}

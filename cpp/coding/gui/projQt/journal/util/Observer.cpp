#include "util/Observer.h"
#include "util/Observable.h"

#include <algorithm>

Observer::~Observer()
{
    ItListObservable itListObservable;
    for(itListObservable = this->_listObservable.begin(); itListObservable != this->_listObservable.end(); ++itListObservable)
    {
        (*itListObservable)->remove(*this);
    }
}

void Observer::add(Observable& observable)
{
    this->_listObservable.push_back(&observable);
}

void Observer::remove(Observable& observer)
{
    ItListObservable itListObservable = std::find(this->_listObservable.begin(), this->_listObservable.end(), &observer);
    if (itListObservable != this->_listObservable.end())
    {
        this->_listObservable.erase(itListObservable);
    }
}

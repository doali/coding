#ifndef CONCRETEOBSERVABLE_H
#define CONCRETEOBSERVABLE_H

#include "util/Observable.h"

#include <iostream>

class ConcreteObservable: public Observable
{
public:
    ConcreteObservable();
    ConcreteObservable(std::string);
    virtual ~ConcreteObservable();

    inline int getId() const { return this->_id; }
    inline void setId(const int id) { this->_id = id; }

    inline std::string getRef() const { return this->_ref; }
    inline void setRef(const std::string ref) { this->_ref = ref; }

    inline unsigned int getNbObserver() const { return this->_listObserver.size(); }

    virtual std::string toString() const;

private:
    int _id;
    std::string _ref;

    static int _idUnique;
};

#endif // CONCRETEOBSERVABLE_H

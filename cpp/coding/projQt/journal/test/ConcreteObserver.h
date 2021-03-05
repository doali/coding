#ifndef CONCRETEOBSERVER_H
#define CONCRETEOBSERVER_H

#include "util/Observer.h"

#include <iostream>

class ConcreteObserver: public Observer
{
public:
    ConcreteObserver();
    ConcreteObserver(std::string);
    ~ConcreteObserver();

    inline int getId() const { return this->_id; }
    inline void setId(const int id) { this->_id = id; }

    inline std::string getRef() const { return this->_ref; }
    inline void setRef(const std::string ref) { this->_ref = ref; }

    std::string toString() const;

    virtual void update(const Observable&);

private:
    int _id;
    std::string _ref;
    static int _idUnique;
};

#endif // CONCRETEOBSERVER_H

#ifndef BD_H
#define BD_H

#include "test/ConcreteObservable.h"

#include <string>

class BD: public ConcreteObservable
{
public:
    BD(int id);
    ~BD();

    inline int getId() const { return this->_id; }
    inline void setId(const int id) { this->_id = id; }

    bool isConnected() const;

    std::string toString() const;

private:
    int _id;
};

#endif // BD_H

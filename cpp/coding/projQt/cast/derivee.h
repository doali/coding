#ifndef DERIVEE_H
#define DERIVEE_H

#include "base.h"

class Derivee : public Base
{
public:
    Derivee();
    Derivee(const Derivee&);
    virtual ~Derivee();
    virtual void faire() const;
};

#endif // DERIVEE_H

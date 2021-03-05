#ifndef BASE_H
#define BASE_H

#include <string>
#include <iostream>

class Base
{
public:
    std::string m_id;

public:    
    Base();
    Base(Base const&) {};// { std::cout << "constructeur de recopie A" << std::endl; }

    virtual ~Base() {};// { std::cout << "destructeur de A" << std::endl; }
    virtual void faire() const;
};

#endif // BASE_H

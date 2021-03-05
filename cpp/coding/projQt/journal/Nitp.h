#ifndef NITP_H
#define NITP_H

#include <string>

#include "test/ConcreteObservable.h"

class Nitp: public ConcreteObservable
{
public:
    Nitp(std::string);
    ~Nitp();

    inline int getId() const { return this->_id; }
    inline void setId(const int id) { this->_id = id; }

    inline std::string getRef() const { return this->_ref; }
    inline void setRef(const std::string ref) { this->_ref = ref; }

    virtual std::string toString() const;

private:
    int _id;
    std::string _ref;
    static int _idUnique;
};

#endif // NITP_H

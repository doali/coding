#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <vector>

class Observer;

typedef std::vector<Observer*> ListObserver;
typedef ListObserver::iterator ItListObserver;
typedef ListObserver::const_iterator ConstItListObserver;

class Observable
{
public:
    virtual ~Observable() = 0;

    void add(Observer&);
    void remove(Observer&);
    void notifyAll() const;

protected:
    ListObserver _listObserver;
};

#endif // OBSERVABLE_H

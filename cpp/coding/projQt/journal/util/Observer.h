#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>

class Observable;

typedef std::vector<Observable*> ListObservable;
typedef ListObservable::iterator ItListObservable;
typedef ListObservable::const_iterator ConstItListObservable;

class Observer
{
public:
    virtual ~Observer() = 0;

    void add(Observable&);
    void remove(Observable&);
    virtual void update(const Observable&) = 0;

protected:
    ListObservable _listObservable;
};

#endif // OBSERVER_H

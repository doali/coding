#ifndef _A_H
#define _A_H

#include <iostream>
#include <ostream>

template <class T> class A {
public:
  A() { std::cout << "A()" << std::endl; }
  A(T a) : _a(a) { std::cout << "A(" << a << ")" << std::endl; }

  void doSomething() { std::cout << "Doing something" << std::endl; }
  void compute() { std::cout << "Computing..." << std::endl; }

  friend std::ostream &operator<<(std::ostream &os, const A &a) {
    return os << "A::_a=" << a._a;
  }

private:
  T _a;
};

#endif

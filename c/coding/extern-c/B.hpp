#ifndef _B_HPP
#define _B_HPP

#include "A.hpp"

class B : public A {
public:
  B();
  B(int a);
  virtual ~B();

  virtual void do_something();
};

#endif

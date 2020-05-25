#ifndef _A_HPP
#define _A_HPP

#include <iostream>

class A {
public:
  A();
  A(int id);
  virtual ~A();

  A(const A &src);

  A &operator=(const A &src);

  virtual void do_something();

  friend std::ostream &operator<<(std::ostream &src, const A &a);

protected:
  int _id;
};

#endif

#include "B.hpp"
#include "macro.hpp"
#include <iostream>

B::B() : A() {
  //
  TRACE_FUNC(this);
}

B::B(int a) : A(a) { //
  TRACE_FUNC(this);
}

B::~B() {
  //
  TRACE_FUNC(this);
}

void B::do_something() { //
  std::cout << __func__ << " B " << std::endl;
}

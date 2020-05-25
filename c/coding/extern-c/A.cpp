#include "A.hpp"
#include "macro.hpp"

A::A()
    : _id(0) { // INTIALIZATION must be DONE !!
               // since no default initialization
  TRACE_FUNC(this);
}

A::A(int id) : _id(id) { //
  TRACE_FUNC(this);
}

A::~A() {
  //
  TRACE_FUNC(this);
}

A::A(const A &src) : _id(src._id) {
  //
  TRACE_FUNC(this);
}

A &A::operator=(const A &src) {

  if (&src == this) {
    return *this;
  }

  this->_id = src._id;
  return *this;
}

void A::do_something() { //
  std::cout << __func__ << " A " << std::endl;
}

std::ostream &operator<<(std::ostream &src, const A &a) {
  return src << "{id:" << a._id << "}" << std::endl;
}

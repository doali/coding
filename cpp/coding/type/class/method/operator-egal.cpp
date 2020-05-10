#include <iostream>
#include <string.h>

class ClassA {
public:
  int _a;
  int _b;

  virtual ~ClassA() {}
  ClassA(int a, int b) : _a(a), _b(b) {}

  ClassA(const ClassA &);
  ClassA &operator=(const ClassA &);

  friend std::ostream &operator<<(std::ostream &os, const ClassA &classA) {
    os << classA._a << ", " << classA._b;

    return os;
  }
};

ClassA::ClassA(const ClassA &classA) {
  this->_a = classA._a + 1;
  this->_b = classA._b + 1;
}

ClassA &ClassA::operator=(const ClassA &classB) {
  this->_a += 10 + classB._a;
  this->_b += 20 + classB._b;

  return *this;
}
int main(int argc, char **) {
  ClassA c = ClassA(1, 2); // contructor
  std::cout << c << std::endl;

  ClassA a(0, 0); // constructor
  std::cout << a << std::endl;

  ClassA b = a; // copy constructor
  std::cout << b << std::endl;

  ClassA d(100, 100);
  d = a; // operator=
  std::cout << d << std::endl;

  return EXIT_SUCCESS;
}

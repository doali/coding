#include <iostream>

class A {
public:
  A() : _a(0) {}

  int getTiti() const {
    std::cout << "_a=" << _a << std::endl;
    return _a;
  }

  void setTiti(const int a) { this->_a = a; }

private:
  int _a;
};

int main(int argn, char **argv) {
  std::cout << "Start" << std::endl;

  A a;
  int res = a.getTiti();
  std::cout << "res=" << res << std::endl;
  std::cout << "a.res=" << a.getTiti() << std::endl;
  a.setTiti(3);
  std::cout << "a.res=" << a.getTiti() << std::endl;

  std::cout << "End" << std::endl;

  return 0;
}

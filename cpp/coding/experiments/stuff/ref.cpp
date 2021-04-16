#include <iostream>
#include <memory>

class A
{
public:
  A() = default;

  A(int nA, std::string sA):
    _nA(nA),
    _sA(sA)
  {
    std::cout << __func__ << std::endl;
  }

  ~A()
  {
    std::cout << __func__ << std::endl;
  }

  inline const std::string& getSA() const
  {
    std::cout << __func__ << std::endl;
    return this->_sA;
  }

  static A& fetch(A& a)
  {
    std::cout << __func__ << std::endl;
    a._nA += 1;
    a._sA = "b";
    return a;
  }

  static int& doNothing(int& i)
  {
    return i;
  }

private:
  int _nA;
  std::string _sA;
};

int main(int narg, char** varg)
{
  A a(1, "a");
  std::string vA = a.getSA();
  std::cout << vA << std::endl;

  A b = A::fetch(a);
  std::string vB = b.getSA();
  std::cout << vB << std::endl;

  int i{10};
  int j = A::doNothing(i);
  std::cout << &i << '|' << i << std::endl;
  std::cout << &j << '|' << j << std::endl;

  std::cout << std::endl;

  int& k = A::doNothing(i);
  std::cout << &i << '|' << i << std::endl;
  std::cout << &k << '|' << k << std::endl;

  std::cout << std::endl;

  int* const l = &(A::doNothing(i));
  std::cout << &i << '|' << i << std::endl;
  std::cout << l << '|' << *l << std::endl;

  // RAII
  std::cout << "Hors block" << std::endl;
  {
    A(11, "c");
  }
  std::cout << "Hors block" << std::endl;

  std::shared_ptr<A> pA;

  return 0;
}

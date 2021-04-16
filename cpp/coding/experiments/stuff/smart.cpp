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
  std::shared_ptr<A> pA(new A(1, "a"));
  std::cout << pA->getSA() << std::endl;

  auto pB = std::make_shared<A>(2, "b");
  std::cout << pB->getSA() << std::endl;

  auto pC = pB;

  return 0;
}

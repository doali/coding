#include <iostream>
#include <string>
#include <vector>

void f(int *& p_r) {
  std::cout << p_r << std::endl;
  std::cout << *p_r << std::endl;
}

class A
{
public:
  std::string label;
  A(const std::string _a) : label(_a) {}
  friend std::ostream& operator<<(std::ostream& os, const A& _a)
  {
    os << _a.label;
    return os;
  }
  virtual ~A()
  {
    std::cout << *this << " is about to be free" << std::endl;
  }

  virtual void doSomething()
  {
    std::cout << *this << " is walking." << std::endl;
  }
};

class B : public A
{
public:
  std::string more;
  B(const std::string _a, const std::string _b) : A(_a), more(_b) {}
  ~B()
  {
    std::cout << *this << " subclass" << std::endl;
  }
  friend std::ostream& operator<<(std::ostream& os, const B& _b)
  {
    os << _b.label << " | " << _b.more;
    return os;
  }

  void doSomething()
  {
    std::cout << *this << " is running." << std::endl;
  }
};

int main(void) {
  int a = 3;
  int &b = a;
  int *p = &b;
  int *&rp = p;
  f(p);

  std::cout << A("a") << std::endl;

  A a0("a0");

  A* a1 = new A("a1");
  std::cout << *a1 << std::endl;

  A* a2 = new A("a2");
  std::cout << *a2 << std::endl;

  A& a3 = *a2;

  a2->label = "a2_";

  std::cout << a3 << std::endl;

  delete(a1);
  delete(a2);

  std::cout << B("b", "more") << std::endl;

  std::vector<A*> v;
  A la = A("_titi");
  B lb = B("_titi", "titou");

  v.push_back(&la);
  v.push_back(&lb);

  for (auto e: v)
  {
    e->doSomething();
  }

  return 0;
}

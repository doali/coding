#include <iostream>
#include <memory>
#include <vector>

struct A {
  virtual ~A() = default;
  virtual void doSomething() = 0;
};

struct B : A {
  ~B() override {} // std::cout << "some specific stuffs" << std::endl; }
  void doSomething() override {
    std::cout << "B:" << __func__ << " is doing something !!" << std::endl;
  }
};

struct C : A {
  ~C() override {} // std::cout << "some specific stuffs" << std::endl; }
  void doSomething() override {
    std::cout << "C:" << __func__ << " is doing something !!" << std::endl;
  }
};

int main(int argc, char **argv) {

  B().doSomething();
  C().doSomething();

  /*
  std::vector<std::shared_ptr<A>> v{std::make_shared<B>(),
                                    std::make_shared<C>()};

  for (auto const &e : v) {
    e->doSomething();
  }
  */

  /*
  A *t[] = {new B(), new C()};

  for (int i = 0; i < 2; ++i) {
    t[i]->doSomething();
  }

  delete t[0];
  delete t[1];
  */

  B b;
  C c;

  A *t_ref[] = {&b, &c};
  for (A *e : t_ref) {
    e->doSomething();
  }

  return 0;
}

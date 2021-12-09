#include <iostream>

struct A {
  static void doSomething() { std::cout << "doing something A" << std::endl; }
};

struct B : A {
  static void doSomething() {
    A::doSomething();
    std::cout << "doing something B" << std::endl;
  }
};

struct C : A {};

int main() {
  A::doSomething();
  B::doSomething();
  C::doSomething();

  return 0;
}

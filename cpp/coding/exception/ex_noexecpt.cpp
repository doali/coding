#include <iostream>
#include <stdio.h>
#include <vector>

struct A {
  std::string m_a = "a";
  virtual void affiche() noexcept { std::cout << this->m_a << std::endl; }

  static void terrible() { throw 42; }
};

struct B : A {
  std::string m_b = "b";
  void affiche() noexcept override { std::cout << this->m_b << std::endl; }
};

int main(int argc, char **argv) {
  A().affiche();
  B b;
  A *p_b = &b;
  p_b->affiche();
  B().affiche();

  try {
    B::terrible();
  } catch (int e) {
    std::cout << e << std::endl;
  } catch (...) {
    std::cout << "Ooops..." << std::endl;
  }

  return 0;
}

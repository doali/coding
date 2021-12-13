#include <iostream>
#include <memory>

template <typename T> struct Wrapper {
  T *_a;
  Wrapper(T a) : _a(new T(a)) {}
  ~Wrapper() { delete _a; }
};

int main() {
  {
    std::cout << "inside bloc" << std::endl; // bonne pratique
    std::unique_ptr<int> i_ptr(std::make_unique<int>(3));
    std::cout << *i_ptr << std::endl;

    int *bad_a(new int(4)); // mauvaise pratique
    std::cout << *bad_a << std::endl;
    delete bad_a;

    Wrapper<int> w(5); // approche de la bonne pratique (l'idée via Wrapper)
    std::cout << *w._a << std::endl;

    Wrapper<std::string> s("RAII");
    std::cout << *s._a << std::endl;
  }
  std::cout << "outside bloc" << std::endl;

  return 0;
}

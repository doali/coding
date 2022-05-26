// --------------------------------------------------------------------------------
// https://www.ltm.fr/les-smarts-pointers-avec-c11/
// https://www.invivoo.com/introduction-a-la-gestion-automatique-de-la-memoire-en-c11/
// --------------------------------------------------------------------------------

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

  std::unique_ptr<int> ptr_i(std::make_unique<int>(10));
  std::cout << *ptr_i << std::endl;

  std::unique_ptr<int> ptr_i_bis;
  //ptr_i_bis = ptr_i; // <= Ne fonctionne PAS car pointeur unique !!!
  ptr_i_bis = std::move(ptr_i); // <= OK, changement de propriétaire
  std::cout << *ptr_i_bis << std::endl;

  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm> // std::for_each

// Code récupéré et étendu

int main()
{
  std::vector<int> const tableau{-1, 28, 346};
  // Déclaration explicite d'un itérateur de std::vector d'entiers.
  
  std::vector<int>::const_iterator debut_tableau{std::begin(tableau)};
  
  // Déclaration plus courte en utilisant auto.
  auto fin_tableau{std::end(tableau)};

  // Good way
  for (auto const &e : tableau)
    std::cout << e << std::endl;

  // for_each
  std::for_each(tableau.begin(), tableau.end(), [](auto &e){ std::cout << e << std::endl; });

  // Old school...
  std::vector<int>::const_iterator it;
  for (it = tableau.begin(); it != tableau.end(); ++it) {
    std::cout << *it << std::endl;
  }

  // Very old school...
  for (int i = 0; i < tableau.size(); ++i) {
    std::cout << tableau[i] << std::endl;
  }

  return 0;
}

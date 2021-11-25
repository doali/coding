#include <iostream>
#include <stdio.h>

template <typename T> T add(T a, T b) { return a + b; }
template <typename T> void affiche(T res) { std::cout << res << std::endl; }

int main(int nargs, char **vargs) {
  std::cout << "It works !!" << std::endl;

  int res_i = add(4, 2);
  affiche(res_i);

  double res_d = add(2.1, 4.0);
  affiche(res_d);

  return 0;
}

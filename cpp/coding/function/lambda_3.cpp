#include <iostream>
#include <vector>

struct A {
  static int titi;
  static auto f(int);
};

int A::titi = 10;
auto A::f(int r) { return [r](int a) -> int { return r + a; }(30); }

int main()
{
  std::cout << A::titi << std::endl;
  std::cout << A::f(3) << std::endl;

  return 0;
}

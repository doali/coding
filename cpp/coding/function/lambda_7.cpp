#include <iostream>

auto g = [](int a) { return ([a](int b) -> int { return a + b; }); };

int main() {
  std::cout << g(4)(3) << std::endl;
  std::cout << g(40)(3) << std::endl;
  return 0;
}

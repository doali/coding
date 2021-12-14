#include <algorithm>
#include <iostream>
#include <vector>

void info(std::string const &msg) { std::cout << msg << std::endl; }

template <typename T>
auto display = ([](const std::vector<T> &v) {
  for (const int &e : v) {
    std::cout << e << std::endl;
  }
});

int main() {
  struct Foncteur {
    void operator()(int &e) { e *= 4; }
  };

  std::vector<int> v_i{1, 2, 3, 4};

  info("Lambda");
  std::for_each(v_i.begin(), v_i.end(), ([](int &a) { a *= 2; }));
  display<int>(v_i);

  info("Foncteur");
  std::for_each(v_i.begin(), v_i.end(), Foncteur());
  display<int>(v_i);

  return 0;
}

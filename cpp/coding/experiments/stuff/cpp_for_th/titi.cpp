#include "A.h"
#include "op.h"

#include <algorithm>
#include <chrono>
#include <iostream>
#include <map>
#include <stdio.h>
#include <thread>
#include <utility>
#include <vector>

template <typename T> void affiche(T a) { std::cout << a << std::endl; }

int mult(const int k, const int v) { return v * k; }

int main(int nargs, char **vargs) {
  std::cout << "It works !!" << std::endl;

  int res_i = bin_op(40, 2);
  affiche(res_i);

  double res_d = bin_op(2.1, 40.0);
  affiche(res_d);

  std::cout << "before" << std::endl;
  A<int> a_i(12);
  a_i.doSomething();
  A<double> a_f(1.0);
  a_f.doSomething();

  std::cout << "after" << std::endl;

  std::cout << a_i << std::endl;
  std::cout << a_f << std::endl;

  int (*f)(int, int) = &mult;

  std::vector<int> v = {1, 2, 3, 4};
  const int k = 10;
  for (auto &e : v) {
    std::cout << e;
    auto res = [](int a) { return a * 2; }(e);
    std::cout << " * 2 => " << res;
    std::cout << " * " << k << " => " << f(k, e) << std::endl;
  }

  typedef std::map<std::string, int> Tmap;
  Tmap map;
  map.insert(Tmap::value_type("A", 123456));
  map.insert(Tmap::value_type("B", 987654));
  std::cout << map.at("A") << std::endl;
  std::cout << map.at("B") << std::endl;

  a_i.compute();
  a_f.compute();

  std::thread t_a(
      [](int seed) {
        while (seed > 0) {
          //
          std::cout << --seed << std::endl;
        }
      },
      1000000);
  t_a.detach();

  std::thread t_b(
      [](int a) {
        while (a > 0) {
          //
          std::this_thread::sleep_for(std::chrono::seconds(1));
          std::cout << "Now =>" << a-- << "<=" << std::endl;
        }
      },
      1);
  t_b.join();

  std::cout << "Thread is terminated" << std::endl;

  return 0;
}

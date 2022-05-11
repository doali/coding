#include <iostream>
#include <thread>

static void do_something(const std::string msg) {
  std::cout << msg << std::endl;
}

void free_function(const std::string msg) {
  std::cout << __func__ << "|";
  do_something(msg);
}

struct Functor {
  void operator()(const std::string msg) {
    std::cout << __func__ << "|";
    do_something(msg);
  }
};

int main(int argc, char **argv) {
  std::thread l_t1(free_function, "ex_1");
  std::thread l_t2(Functor(), "ex_2");
  auto l_t3 = std::thread(
      [](const std::string msg) {
        std::cout << __func__ << "|" << msg << std::endl;
      },
      "ex_3");

  l_t1.join();
  l_t2.join();
  l_t3.join();

  return 0;
}

#include <functional>
#include <iostream>

#include <chrono>
#include <thread>

// static void timer(const unsigned int time_step) {
//   std::time_t start = std::time(nullptr);
//   std::localtime(&start);

//   while (true) {
//     std::time_t check = std::time(nullptr);
//     std::localtime(&check);

//     if ((check - start) >= time_step) {
//       break;
//     }
//   }
// }

template <typename T, typename U>
static void loop(std::function<bool(U)> interr, U interr_arg,
                 std::function<void(T)> f, T arg)
{
  if (interr(interr_arg))
    return;

  f(arg);
  // timer(1); // Bad way !!!
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  loop(interr, interr_arg, f, arg);
}

int main(int argc, char **argv)
{
  static unsigned int max{1000};
  static unsigned int step{0};
  loop<int, unsigned int>(
      [&](unsigned int max)
      { return step == max; },
      max,
      [](int a)
      { std::cout << max << ":" << step++ << std::endl; },
      step);

  return 0;
}

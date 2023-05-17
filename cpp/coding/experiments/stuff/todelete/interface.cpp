#include <array>
#include <vector>
#include <iostream>
#include <algorithm>

struct I
{
  virtual ~I() = 0;
  virtual void do_i() { std::cout << "->i"; }
};

I::~I() = default;

struct A : I
{
  A() { std::cout << __func__ << std::endl; }
  ~A() { std::cout << __func__ << std::endl; }
  void do_i() override
  {
    I::do_i();
    std::cout << "->a" << std::endl;
  }
};

struct B : I
{
  void do_i() override
  {
    I::do_i();
    std::cout << "->b" << std::endl;
  }
};

template <typename T>
T do_gen(T t, T u)
{
  return t + u;
}

int main(void)
{
  A a;
  B b;
  std::array<I *, 2> l_a{&a, &b};
  for (I *e : l_a)
  {
    e->do_i();
  }

  auto f = [](int x) -> int
  { return ++x; };
  std::cout << f(41) << std::endl;
  std::vector<int> l_v{1, 2};
  std::for_each(std::begin(l_v), std::end(l_v), [&f](const int &p)
                { std::cout << p << ":" << f(p) << std::endl; });

  auto r = do_gen<int>(4, 3);
  std::cout << r << std::endl;
}

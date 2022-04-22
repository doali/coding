#include <iostream>
#include <array>

class A
{
public:
  void test_display();

protected:
  virtual void display() const noexcept
  {
    std::cout << "A:" << __func__ << std::endl;
  }
};

class B : public A
{
protected:
  void display() const noexcept override
  {
    std::cout << "B:" << __func__ << std::endl;
  }
};

class C : public A
{
protected:
  void display() const noexcept override
  {
    std::cout << "C:" << __func__ << std::endl;
  }
};

void A::test_display()
{
  A().display();
  // B().display();
  // C().display();

  A *l_pA{nullptr};

  A a;
  B b;
  C c;

  l_pA = &a;
  l_pA->display();
  l_pA = &b;
  l_pA->display();

  std::cout << "START:" << __LINE__ << std::endl;

  std::array<A *, 3> l_arr{&a, &b, &c};
  for (auto element : l_arr)
  {
    element->display();
  }

  std::cout << "END:" << __LINE__ << std::endl;  
}

int main(int argc, char **argv)
{
  A().test_display();
}
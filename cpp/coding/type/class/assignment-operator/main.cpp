#include <iostream>
#include <string>
#include <memory>
#include <vector>

template <typename T>
void xlj_log(std::string p_f, void *p = nullptr, T *t = nullptr) {
  std::cout << __func__ << ":" << p_f << '|' << p << '|' << t << std::endl;
}

class A {
public:
  template <typename T> friend void xlj_log(std::string, void *, T *);
  A() : id(10) { xlj_log("A", this, this); }
  virtual ~A() { xlj_log("~A", this, this); }

  void doA() { xlj_log("doA", this, this); }
  virtual void doSomething() { std::cout << __func__ << " in A" << std::endl; }

private:
  int id;
};

class B : public A {
public:
  template <typename T> friend void xlj_log(std::string, void *, T *);
  B() : A() { xlj_log("B", this, this); }
  ~B() { xlj_log("~B", this, this); }

  void doA() { xlj_log("doB", this, this); };
  void doSomething() override { std::cout << __func__ << " in B" << std::endl; }
};

void display(int p_v) { std::cout << p_v << std::endl; }

int main(int argc, char **argv) {
  //{ A a; }
  //A().doA();
  B().doA();
  std::shared_ptr<A> a(std::make_shared<A>());
  a->doA();
  A* o(new A());
  o->doA();
  delete o;

  std::vector<A*> v{new A(), new B()};
  for (auto e: v)
  {
          e->doSomething();
  }
  for (auto e: v) { delete e; }

  std::vector<std::shared_ptr<A>> v_s{
          std::make_shared<A>(),
          std::make_shared<B>()
  };

  for (auto e: v_s) { e->doSomething(); }

  auto f = [](int a, int b) {
          return a + b;
  };

  display(f(40, 2));

  auto f_10 = ([](int a) {
          int backUp(a);
          std::cout << backUp << std::endl;
          return [=](int b) {
                  std::cout << backUp << std::endl;
                  return backUp + b;
          };
  })(10);

  display(f_10(32));

  return 0;
}

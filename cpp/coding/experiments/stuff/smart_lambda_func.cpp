#include <cstdint>
#include <functional>
#include <iostream>
#include <memory>

struct A {
    static uint16_t _cpt;
    uint16_t id;
    A(std::string message) : id{_cpt} {
        std::cout << __func__ << "::cpt=" << ++_cpt << "\n\tid=" << id
                  << "\n\tmessage=" << message << std::endl;
    }
    virtual ~A() {
        std::cout << __func__ << "::cpt=" << --_cpt << "\n\tid=" << id
                  << std::endl;
    }
    virtual void action() const { std::cout << "A:" << __func__ << std::endl; }
};

struct B : A {
  B(std::string message) : A(message) {
    }

  ~B() override {

  }
    void action() const override {
        std::cout << "<<<<<<<<<<<<<<<<<<" << std::endl;
        std::cout << "Parent" << std::endl;
        A::action();
        std::cout << "Enfant" << std::endl;
        std::cout << "B:" << __func__ << std::endl;
        std::cout << ">>>>>>>>>>>>>>>>>>" << std::endl;
    }
};

uint16_t A::_cpt = 0;

auto gen(int base) {
    static int _base;
    return []() -> int { return ++_base; };
}

int main(int, char **) {
    A a{"classique"};

    std::unique_ptr<A> upA{new A{"new"}};
    std::unique_ptr<A> upAA{std::make_unique<A>("make_unique")};

    ([](std::string message) { std::cout << message << std::endl; })("lambda");

    auto gen_10 = gen(10);
    std::cout << gen_10() << std::endl;
    std::cout << gen_10() << std::endl;
    std::cout << gen_10() << std::endl;
    std::cout << gen_10() << std::endl;
    std::cout << gen_10() << std::endl;
    std::cout << gen_10() << std::endl;
    std::cout << gen_10() << std::endl;
    std::cout << gen_10() << std::endl;
    std::cout << gen_10() << std::endl;
    std::cout << gen_10() << std::endl;
    std::cout << gen_10() << std::endl;

    int (*f)(void);
    f = gen_10;

    printf("=> %d\n", f());

    std::function<int()> g;
    g = gen_10;

    std::cout << "-> " << g() << std::endl;

  B b("classique dérivation");

  std::vector<const A*> l_E{&a, &b};
  std::cout << "Polymorphisme <<<" << std::endl;
  for (const A* element : l_E) {
    element->action();
  }
  std::cout << "Polymorphisme >>>" << std::endl;
    return 0;
}

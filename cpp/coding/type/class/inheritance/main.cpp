#include <iostream>

class A {
public:
  void public_methA() { std::cout << __func__ << std::endl; }

protected:
  void protected_methA() { std::cout << __func__ << std::endl; }

private:
  void private_methA() { std::cout << __func__ << std::endl; }
};

class B : public A {
public:
  void public_methB() {
    public_methA();
    protected_methA();
    // private_methA(); // KO
  }
};

class C : protected A {
public:
  void public_methC() {
    public_methA();
    protected_methA();
    // private_methA(); // KO
  }
};

class D : private A {
public:
  void public_methD() {
    public_methA();
    protected_methA();
    // private_methA(); // KO
  }
};

class M : private A {
public:
  // A::public_methA; // !! deprecated even if it works...
  void public_methM() {
    public_methA();
    protected_methA();
    // private_methA(); // KO
  }

  using A::public_methA; // !! this is the correct syntax ! // now it is public
                         // !!
};

int main() {
  std::cout << "--- Basics" << std::endl;
  A a;
  a.public_methA();
  // a.protected_methA(); // KO
  // a.private_methA(); // KO

  B b;
  b.public_methA();
  // b.protected_methA(); // KO
  // b.private_methA(); // KO
  b.public_methB();

  C c;
  // c.public_methA(); // KO since => C : protected A
  // c.protected_methA(); // KO
  // c.private_methA(); // KO
  c.public_methC();

  D d;
  // d.public_methA(); // KO since => D : private A
  // d.protected_methA(); // KO
  // d.private_methA(); // KO
  d.public_methD();

  std::cout << "--- Next basics..." << std::endl;
  C l;
  // l.public_methA(); // KO since => C : protected A
  // A *p_a = &l; // KO since => C : protected A

  D o;
  // o.public_methA(); // KO since => D : private A
  // A *p_a = &o; // KO since => D : private A

  M m;
  m.public_methA(); // OK despite => M : private A => since using keyword
  // A *p_a = &m; // KO since => D : private A

  return 0;
}

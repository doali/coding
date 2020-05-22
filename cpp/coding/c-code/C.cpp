#include <iostream>

#define TRACE std::cout << __func__ << std::endl;
#define DELETE(X)                                                              \
  {                                                                            \
    if (X) {                                                                   \
      TRACE                                                                    \
      delete X;                                                                \
      X = NULL;                                                                \
    }                                                                          \
  }

#define PRINT(X) std::cout << X << std::endl;

/*
 * function pointer !!
 */
typedef void (*p_f)(const char *);

/*
 * function declaration
 */
// extern "C" void do_nothing(const char *);
void do_nothing(const char *);

class C {
public:
  C() {
    TRACE
    this->_name = "";
    this->_firstname = "";
  }

  C(const std::string &name, const std::string &firstname)
      : _name(name), _firstname(firstname) {
    TRACE
  }

  void doSomething(p_f f, const char *message) {
    std::cout << "Message:" << message << std::endl;
    f(message);
  }

  virtual ~C() { TRACE }

  friend std::ostream &operator<<(const std::ostream &, const C &);

private:
  std::string _name;
  std::string _firstname;
};

std::ostream &operator<<(const std::ostream &os, const C &c) {
  return std::cout << "{" << c._firstname << " : " << c._name << "}"
                   << std::endl;
}

int main(int argc, char **argv) {
  std::cout << "C++" << std::endl;

  C();

  C c_0;
  PRINT(c_0)

  C c_1("titi", "A");
  PRINT(c_1)

  C *c_2 = new C("toto", "B");
  PRINT(*c_2)

  DELETE(c_2)

  c_0.doSomething(do_nothing, "from space");

  exit(EXIT_SUCCESS);
}

#include <iostream>
#include <memory>

class MyClass {
public:
  static unsigned int id;
  static unsigned int total;

  MyClass(int value) : value(value) {
    std::cout << __func__ << "|id:" << ++id << "/" << ++total << std::endl;
  }

  ~MyClass() {
    std::cout << __func__ << "|id:" << id << "/" << --total << std::endl;
  }

  void printValue() const { std::cout << "Value: " << value << std::endl; }

private:
  int value;
};

unsigned int MyClass::id = 0;
unsigned int MyClass::total = 0;

void useAfterMove() {
  std::unique_ptr<MyClass> ptr = std::make_unique<MyClass>(42);
  std::unique_ptr<MyClass> movedPtr = std::move(ptr);
  // ptr->printValue(); // SOLUTION : interdit !! car on a dépouillé ptr !!
  movedPtr->printValue();
}

int main() {
  useAfterMove();

  useAfterMove();
  return 0;
}

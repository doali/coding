#include <iostream>
#include <memory>

class Person {
public:
    Person(const std::string& name) : name(name) {
        std::cout << "Person created: " << name << std::endl;
    }
    ~Person() {
        std::cout << "Person destroyed: " << name << std::endl;
    }
    void display() const {
        std::cout << "Person: " << name << std::endl;
    }
private:
    std::string name;
};

void uniquePtrTest() {

}

int main() {
    uniquePtrTest();
    return 0;
}

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

    void setName(std::string name) { this->name = name; }
private:
    std::string name;
};

void uniquePtrTest(std::unique_ptr<Person> p_p) {
    p_p->setName("titi");
}

int& f()
{
    int j = 42;
    int &i = j;

    printf("i:%p\n", &i);
    std::cout << "j:" << &j << std::endl;

    return i;
}

int main() {
    std::unique_ptr<Person> u_p(std::make_unique<Person>("nom_personne"));
    uniquePtrTest(std::move(u_p));

    int k = f();
    std::cout << "k:" << k << std::endl;

    auto g = []() -> int { return 3; };

    // const int& h = 3;
    // int& h = g();

    int res = ([]() -> int { return 3; })();

    std::cout << res << std::endl;

    return 0;
}

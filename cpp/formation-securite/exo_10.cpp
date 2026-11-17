#include <iostream>
#include <memory>

// PROBLEME
// - on entremêle les pointeurs
// - on réalise une double désallocation

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

void foo(std::shared_ptr<Person>& ptr){
    std::shared_ptr<Person> pt = ptr;
    std::cout << "count dans foo : " << ptr.use_count() << std::endl;
}
int main() {
    auto l_ptr = new Person("Jane Doe"); // Sur le tas
    std::shared_ptr<Person> personPtr1(l_ptr); // ShardPtr sur la pile
    {
        foo(personPtr1);
        std::shared_ptr<Person> personPtr2 = personPtr1;
        personPtr2->display();
        std::cout << "personPtr1 : count : " << personPtr1.use_count() << std::endl;
    }
    // std::shared_ptr<Person> personPtr3(l_ptr);  // ShardPtr sur la pile <=== SOLUTION Problème double désallocation !!!
    std::shared_ptr<Person> personPtr3(personPtr1); // SOLUTION
    {
        foo(personPtr3);
        std::shared_ptr<Person> personPtr2 = personPtr3;
        personPtr2->display();
        std::cout << "personPtr3 : count : " << personPtr3.use_count() << std::endl;
    }
    return 0;
}

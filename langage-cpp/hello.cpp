#include <iostream>

/* Compilation
 * g++ -o hello_cpp hello.cpp
 */

/* Execution
 * ./hello_cpp
 */

class Main
{
public:
    Main();

    ~Main();

    void doSomething();

    void doOtherThing() 
    {
        std::cout << "another method" << std::endl;
    }
};

Main::Main()
{
    std::cout << "Constructor" << std::endl;
}

Main::~Main()
{
    std::cout << "Destructor" << std::endl;
}

void Main::doSomething()
{
    std::cout << "method" << std::endl;
}

int main()
{
    Main().doSomething();

    Main varPile;
    varPile.doOtherThing();

    return 1;
}

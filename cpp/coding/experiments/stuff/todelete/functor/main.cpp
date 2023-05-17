#include <iostream>
#include <stdlib.h>

class Functor 
{
public:
    Functor()
    {
        std::cout << __func__ << std::endl;
    }

    void operator()()
    {
        std::cout << __func__ << std::endl;
    }

    void titi()
    {
        std::cout << __func__ << std::endl;
    }
};

int main(int argc, char** argv)
{
    Functor l_f0;
    l_f0();
    l_f0.titi();

    // Functor l_f1(); // compilation OK MAIS déclaration de fonction !!!
    // l_f1.titi(); // error
    // l_f1(); // error

    Functor l_f2{};
    l_f2();

    Functor();
    Functor{};
    Functor()();
    Functor{}();

    Functor().titi();
    Functor{}.titi();

    return EXIT_SUCCESS;
}
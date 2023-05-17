#include <iostream>

struct Functor
{
    Functor & operator()()
    {
        _counter++;

        return *this;
    }

    Functor & info()
    {
        std::cout << __func__ << ":" << _counter << std::endl;

        return *this;
    }

    unsigned int _counter {0};
};

int main(int argc, char** argv)
{
    (Functor()().info())().info();

    return EXIT_SUCCESS;
}
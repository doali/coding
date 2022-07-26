#include <iostream>
#include <vector>
#include <memory>

static void update_info();

struct A
{
    static uint nb_call;
    virtual void do_something() = 0;
};

struct B : A
{
    void do_something() override
    {
        std::cout << "B:" << __func__ << std::endl;
        update_info();
    }

    virtual void do_better()
    {
        std::cout << "B:" << __func__ << std::endl;
        update_info();
    }
};

struct C : B
{
};

uint A::nb_call = 0;

static void update_info()
{
    std::cout << "Total of called functions:" << ++A::nb_call << std::endl;
}

int main(int argc, char **argv)
{
    B().do_something();
    C().do_better();

    std::vector<std::shared_ptr<A>> l_v{
        std::make_shared<B>(),
        std::make_shared<C>()};

    for (auto &element : l_v)
    {
        element->do_something();
    }

    return EXIT_SUCCESS;
}

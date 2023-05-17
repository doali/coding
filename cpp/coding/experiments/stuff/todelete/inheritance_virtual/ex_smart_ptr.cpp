#include <iostream>
#include <vector>
#include <memory>

struct A 
{
    virtual ~A() = default;
    virtual void do_something() const = 0;
};

struct B : A
{
    void do_something() const override
    {
        std::cout << "B:" << __func__ << std::endl;
    }
};

struct C : A
{
    void do_something() const override
    {
        std::cout << "C:" << __func__ << std::endl;
    }
};

int main(int argc, char** argv)
{
    std::vector<std::shared_ptr<A>> l_a = {
            std::make_shared<B>(),
            std::make_shared<C>()
    };

    for (auto element : l_a)
    {
        element->do_something();
    }

    return EXIT_SUCCESS;
}

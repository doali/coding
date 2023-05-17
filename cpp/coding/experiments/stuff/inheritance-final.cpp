#include <iostream>
#include <array>
#include <iterator>

struct A
{
    virtual void info() const
    {
        std::cout << "A " << __func__ << std::endl;
    }
};

struct B : A
{
    void info() const override final
    {
        std::cout << "calling...";
        A::info();
        std::cout << "- B " << __func__ << std::endl;
    }
};

struct C : B
{
    void spe_info() const
    {
        std::cout << "C " << __func__ << std::endl;
        B::info();
    }
};

int main(int argc, char **argv)
{
    const A a;
    const B b;

    const A *arr[] = {&a, &b};
    static const size_t sz_arr{2};

    for (unsigned int idx = 0; idx < sz_arr; ++idx)
    {
        (arr[idx])->info();
    }

    std::array<const A *, sz_arr> s_arr = {&a, &b};
    for (const A *e : s_arr)
    {
        e->info();
    }

    std::array<const A *, sz_arr>::iterator ite = s_arr.begin();
    while (ite != s_arr.end())
    {
        (*ite)->info();
        ite++;
    }

    C{}.info();
    C{}.spe_info();

    return EXIT_SUCCESS;
}